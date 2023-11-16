// gs_test.cpp
#define TESTING
#include "gs.cpp" 
#include "acutest.h"


// Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors
void test_type() {
    TEST_CHECK(typeid(F) == typeid(double));	
    TEST_CHECK(typeid(k) == typeid(double));
}

// Check that the variables u and v are the same size
void test_same_size() {
    //test row
	TEST_CHECK(u.size() == v.size());
    //test col 
    for (size_t i = 0; i < u.size(); ++i) {
        TEST_CHECK(u[i].size() == v[i].size()); 
    }
}

//Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.
void test_uvequalszero() {
    // Simulation initiated to zero
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            u[x][y] = 0.0;
            v[x][y] = 0.0;
        }
    }

    // Main simulation loop
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();
    }

    // Verify that v remains 0
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            TEST_CHECK(v[x][y] == 0.0);
        }
    }

    // Verify that u is increased
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            TEST_CHECK(u[x][y] >= 0.0);
        }
    }

    // count the amount of pixels above threshold at end.
    double n = countElementsAboveThreshold(threshold);
    TEST_CHECK(n == 0.0);
    TEST_MSG("Produced n: %f", n);		
}

void test_init() {
    init();
    // check the value of u and v when call the function "init()"
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            TEST_CHECK(u[x][y] == 1.0);  
            if (x >= 100 && x <= 200 && y >= 100 && y <= 150) {
                TEST_CHECK(v[x][y] >= 0.0 && v[x][y] < 1.0);  // Random ~ U[0.0,1.0)
            } else {
                TEST_CHECK(v[x][y] == 0.0);  
            }
        }
    }
}

void test_stability() {
    init(); 

    const double stabilityThreshold = 0.08; 
    bool isStable = true;

    for (int i = 0; i < 100; ++i) {
        auto previousU = u;
        auto previousV = v;

        simulateStep(); 

        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                if (std::abs(u[x][y] - previousU[x][y]) > stabilityThreshold ||
                    std::abs(v[x][y] - previousV[x][y]) > stabilityThreshold) {
                    isStable = false;
                }
            }
        }

        TEST_CHECK(isStable);
    }
}


void test_writeVTKFile(){
    // up to the tester, wo just set 10 for one VTKfile
    int testIteration = 10;

    // call func
    writeVTKFile(testIteration);

    // the target file name
    std::stringstream expected_filename;
    expected_filename << "output_" << testIteration << ".vtk";

    // open the file
    std::ifstream vtkFile(expected_filename.str());
    
    // check open
    TEST_CHECK(vtkFile.good());

    // read the file
    std::string line;

    // check the first two line of the file
    std::getline(vtkFile, line);
    TEST_CHECK(line == "# vtk DataFile Version 3.0");
    std::getline(vtkFile, line);
    TEST_CHECK(line == "Gray-Scott Simulation Output");
    // close the file
    vtkFile.close();

    int remove_result = std::remove(expected_filename.str().c_str());

    // check delete or not
    TEST_CHECK(remove_result == 0);
}

void test_countElementsAboveThreshold(){
     init();

    v[50][50] = 0.45; // set value below
    v[60][60] = 0.55; // set value above

    // choose a thresholds
    double test_threshold = 0.50;

    // call func
    double caluculate_result = countElementsAboveThreshold(test_threshold);

    // verify the value
    int expected_count = 0;
    for (const auto& row : v) {
        for (const double& element : row) {
            if (element > test_threshold) {
                expected_count++;
            }
        }
    }
    // check countElementsAboveThreshold output
    TEST_CHECK(caluculate_result == (double)expected_count / (width * height));

}

void test_simulateStep(){
	//backup original u and v
	std::vector<std::vector<double>> originalU = u;
    std::vector<std::vector<double>> originalV = v;
	
	//changed u and v to fixed cases
	for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            u[x][y] = 0.5;
            v[x][y] = 0.5;
        }
    }
	
	//call function to be tested
	simulateStep();

	//check the results 
	for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1){
				TEST_CHECK(u[x][y] == 0.5);
				TEST_MSG("Test fail in u[%d][%d]: produced: %f, expected: 0.5", x, y, u[x][y]);
				TEST_CHECK(v[x][y] == 0.5);
				TEST_MSG("Test fail in v[%d][%d]: produced: %f, expected: 0.5", x, y, v[x][y]);
			}
			else{
				TEST_CHECK(u[x][y] == 0.4934);
				TEST_MSG("Test fail in u[%d][%d]: produced: %f, expected: 0.4934", x, y, u[x][y]);
				TEST_CHECK(v[x][y] == 0.504656);
				TEST_MSG("Test fail in v[%d][%d]: produced: %f, expected: 0.504656", x, y, v[x][y]);
			}
        }
    }
	
	//change u and v to original data
	u = originalU;
    v = originalV;
}


TEST_LIST = {
    {"test_type", test_type},
    {"test_size", test_same_size },
    {"test_uvequalszero", test_uvequalszero },
    {"test_init", test_init },
    {"test_stability", test_stability },
    {"test_writeVTKFile",test_writeVTKFile },
    {"test_countElementsAboveThreshold",test_countElementsAboveThreshold },  
    {"test_simulateStep", test_simulateStep },	
    { NULL, NULL } 
};
