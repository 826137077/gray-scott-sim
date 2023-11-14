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
    }

    // count the amount of pixels above threshold at end.
    double n = countElementsAboveThreshold(threshold);

    std::cout << "Simulation completed: P(v > threshold) = " << n << std::endl;
    TEST_CHECK(n == 0.0);
    TEST_MSG("Produced n: %f", n);
}


TEST_LIST = {
    {"test_type", test_type},
    {"test_size", test_same_size },
    {"simulation_with_zero_initial_conditions", test_uvequalszero },
    { NULL, NULL } 
};
