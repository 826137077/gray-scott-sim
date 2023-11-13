// gs_test.cpp
#define TESTING
#include "acutest.h"
#include "../gs.cpp" 

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

void test_simulation_with_zero_initial_conditions(void) {
    
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            u[x][y] = 0.0;
            v[x][y] = 0.0;
        }
    }

    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();
    }

    bool uIsZero = true;
    bool vIsZero = true;

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (u[x][y] != 0.0) {
                uIsZero = false;
                break;
            }
            if (v[x][y] != 0.0) {
                vIsZero = false;
                break;
            }
        }
        if (!uIsZero && !vIsZero) {
            break;
        }
    }

    TEST_CHECK(uIsZero);
    TEST_CHECK(vIsZero);

}


TEST_LIST = {
    {"test_type", test_type},
    { "test_size", test_same_size },
    { "test_simulation_with_zero_initial_conditions", test_simulation_with_zero_initial_conditions },
    { NULL, NULL } 
};