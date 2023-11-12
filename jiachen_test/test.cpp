#define TESTING
#include "acutest.h"  
#include "../gs.cpp"    

void test_parameter_types() {
    // Check if F and k are of type double
    TEST_CHECK(typeid(F) == typeid(double));
    TEST_CHECK(typeid(k) == typeid(double));

    // Check the element types of u and v
    TEST_CHECK(typeid(u[0][0]) == typeid(double));
    TEST_CHECK(typeid(v[0][0]) == typeid(double));
}

void test_uv_size_consistency(void) {
    init();  // Initialise u and v
    TEST_CHECK(u.size() == v.size());  // Check if the number of rows is the same
    for (size_t i = 0; i < u.size(); ++i) {
        TEST_CHECK(u[i].size() == v[i].size());  // Check that the number of columns in each row is the same
    }
}

void test_simulation_with_zero_initial_conditions(void) {
    // Initialise all values of u and v to 0.
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            u[x][y] = 0.0;
            v[x][y] = 0.0;
        }
    }

    // Operational simulation
    for (int iteration = 0; iteration < 10; ++iteration) {
        simulateStep();
    }

    // Check whether u has been increased
    bool uIncreased = false;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (u[x][y] > 0) {
                uIncreased = true;
                break;
            }
        }
        if (uIncreased) break;
    }

    // Check that v is held at 0
    bool vRemainsZero = true;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (v[x][y] != 0) {
                vRemainsZero = false;
                break;
            }
        }
        if (!vRemainsZero) break;
    }

    // Assertion results
    TEST_CHECK(uIncreased && vRemainsZero);
}


TEST_LIST = {
    {"parameter_types", test_parameter_types},
    { "UV Size Consistency", test_uv_size_consistency },
    { "simulation_with_zero_initial_conditions", test_simulation_with_zero_initial_conditions },
    { NULL, NULL } 
};

