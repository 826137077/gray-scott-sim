# Gray-Scott model simulation


## Project Introduction

This project implements the simulation of the Gray-Scott model, a mathematical model used to simulate the reaction and diffusion processes of two chemical substances.



## Test Module

##### Choose the Acutest Framework（https://github.com/mity/acutest）

- Unit tests in C or C++ are supported.
- Acutest is just a single header file.
- Minimal dependencies Core features only depend on few standard C headers.

##### Tests implemented

- [x] Test A : Check that the type of the model parameters (*F* , *k*) matches that of the element type of the *u* and *v* vectors.

- [x] Test B : Check that the variables *u* and *v* are the same size.

- [x] Test C : Check that the simulation produces the mathematically correct answer when *u* = 0 and *v* = 0.

- [x] Test D : Check that the function `init()` is correct .

- [x] Test E : Check if the values of *u* and *v* remain unchanged on the boundary.

- [x] Test F : Check that the function `writeVTKFile(int iteration)` is correct .

- [x] Test G : Check that the function `simulateStep()` is correct .

- [x] Test H : Check that the function `countElementsAboveThreshold(double threshold)` is correct .

  

## Installation Guide

#### To run this project, you need to install the following software:

- C++ compiler (such as GCC or Clang)
- CMake
- Git (optional, for version control)




## Build and Run

#### Building a project using CMake simplifies the build process and ensures consistency across platforms and environments. Follow the steps below:

1. Clone the repository ( `git clone [repository url]` )

2. Build a project with CMake 

```bash
mkdir build
cd build
cmake .. 
make 
```

3. Run simulation

```bash
# Basic test
./gs_test test_type test_size test_uvequalszero
# List all test
./gs_test --list
# Additional test
./gs_test test_init test_boundary test_writeVTKFile
```

4. Add  test (`ctest [- R/E/J..]`)


## Continuous Integration

#### This project utilizes GitHub Actions for automated workflows to scan, build and test the code. Below is a detailed description of the workflow configuration:

##### Trigger

On each push to the main branch.

##### Environment

Ubuntu latest version.

##### Steps:

0. **Scan Code:** Use CodeQL to identify vulnerabilities and errors in the code.
1. **Checkout Code:** Fetch the code from the GitHub repository.
2. **Install CMake:** Install CMake in the runtime environment.
3. **Build Project:** Create a build directory, configure, and build the project using CMake.
4. **Run Tests:** Execute the test program in the build directory.



## Contribution Guidelines

We welcome and encourage community contributions. If you wish to contribute code or documentation to the project, please follow these steps:

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



## Contributers

*Jiachen Xu ([dtqb57@durham.ac.uk]())*

*Yuhan Liu ([cxpx64@durham.ac.uk]())*

*Hao Zhu ([vdmg24@durham.ac.uk]())* 

*Yuqi Zhang ([mcpj88@durham.ac.uk]())*

*Xingyu Yan  ([dzbk34@durham.ac.uk]())*



## Conclusion

Thank you for your interest and support in the Gray-Scott model simulation project. We look forward to your feedback and contributions, pushing forward this interesting and valuable field of research.
