# Gray-Scott model Simulation


## Project Introduction

This project implements the simulation of the Gray-Scott model, a mathematical model used to simulate the reaction and diffusion processes of two chemical substances.

#### Choose the Acutest Framework（https://github.com/mity/acutest）

- Unit tests in C or C++ are supported.
- Acutest is just a single header file.
- Minimal dependencies Core features only depend on few standard C headers.

#### Implement these three tests

- Check that the type of the model parameters (*F* , *k*) matches that of the element type of the *u* and *v* vectors.

- Check that the variables *u* and *v* are the same size.

- Check that the simulation produces the mathematically correct answer when *u* = 0 and *v* = 0.

  1. Initialization of Simulation Variables

     Iterates through arrays u and v, setting all elements to 0.0.

  2. Main Simulation Loop

     Performs iterations of the simulation.

  3. Result Calculation

     Calculates the number of elements in the *v* array that exceed a specified threshold.
  

## Installation Guide

#### To run this project, you need to install the following software:

- C++ compiler (such as GCC or Clang)
- CMake
- Git (optional, for version control)


## Build and Run

#### Building a project using CMake simplifies the build process and ensures consistency across platforms and environments. Follow the steps below:

1. Clone the repository ( if using Git )

```bash
git clone [repository url]
cd gray-scott-sim
```

2. Build a Project with CMake 

```bash
mkdir build
cd build
cmake .. 
make 
```

3. Run simulation

```bash
./gs_test
```

## Continuous Integration

#### This project utilizes GitHub Actions for automated workflows to build and test the code. Below is a detailed description of the workflow configuration:

##### Trigger

On each push to the main branch.

##### Environment

Ubuntu latest version.

##### Steps:

1. **Checkout Code:** Fetch the code from the GitHub repository.
2. **Install CMake:** Install CMake in the runtime environment.
3. **Build Project:** Create a build directory, configure, and build the project using CMake.
4. **Run Tests:** Execute the test program in the build directory.



## Contributers

*Jiachen Xu ([dtqb57@durham.ac.uk]())*

*Yuhan Liu ([cxpx64@durham.ac.uk]())*

*Hao Zhu ([vdmg24@durham.ac.uk]())* 

*Yuqi Zhang ([mcpj88@durham.ac.uk]())*

*Xingyu Yan  ([dzbk34@durham.ac.uk]())*

