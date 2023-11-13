// gs_test.cpp
#define TESTING
#include "acutest.h"
#include "gs.cpp"  // 包含你要测试的源文件

// Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors
void test_typeofFK() {
    TEST_CHECK(typeid(F) == typeid(double));
	TEST_MSG("Expected: %s", typeid(double).name());
    TEST_MSG("Produced: %s", typeid(F).name());
	
    TEST_CHECK(typeid(k) == typeid(double));
	TEST_MSG("Expected: %s", typeid(double).name());
    TEST_MSG("Produced: %s", typeid(k).name());
	//getchar();
}

// Check that the variables u and v are the same size
void test_sizeofuv() {
	size_t u_rows = u.size();
	size_t v_rows = v.size();
	TEST_CHECK(u_rows == v_rows);
	
	size_t u_cols = (u_rows > 0) ? u[0].size() : 0;
	size_t v_cols = (v_rows > 0) ? v[0].size() : 0;	
	TEST_CHECK(u_cols == v_cols);
	//getchar();
}

// Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.
void test_uvequalszero() {
	
    std::srand(static_cast<unsigned int>(std::time(nullptr)));    
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            u[x][y] = 0.0;
            v[x][y] = 0.0;
        }
    }
    std::cout << "Simulation initiated to zero." << std::endl;

    // Main simulation loop
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();
        
        // Periodically write to VTK file
        if (iteration % outputInterval == 0) {
            writeVTKFile(iteration);
        }
    }

    // count the amount of pixels above threshold at end.
    double n = countElementsAboveThreshold(threshold);
    std::cout << "Simulation completed: P(v > threshold) = " << n << std::endl;
	TEST_CHECK(n == 0.0);
    TEST_MSG("Produced: %f", n);
	//getchar();
	//getchar();
}

void test_pause() {
	getchar();
}

// 主测试函数
TEST_LIST = {
    { "test_typeofFK", test_typeofFK },
	{ "test_sizeofuv", test_sizeofuv },
	{ "test_uvequalszero", test_uvequalszero},
	{ "test_pause", test_pause},
    { NULL, NULL }  
};

