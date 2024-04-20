# Particle Swarm Optimization
This is a university project for the course 'advanced algorithms'. Uses SFML for visualization.
## Features
- Step simulation: \[SPACE\] (hold or release)
## Prerequisites
- CMake (Version >= 3.16)
- C++ Compiler supporting C++11 standard or later
### Installing CMake
If you don't have CMake installed yet, follow these steps to install it:
#### Windows
1. Visit the [CMake download page](https://cmake.org/download/) and download the latest version of CMake for Windows.
2. Run the downloaded installer and follow the installation instructions.
3. Once installed, you can verify the installation by opening a command prompt and typing `cmake --version`.
#### Linux
1. Coming soon!
## Getting Started
1. Clone this repository to your local machine:
```bash
git clone --recursive https://github.com/infopek/particle-swarm-optimization.git
```
2. Navigate to the cloned directory:
```bash
cd ./particle-swarm-optimization/
```
3. Generate build files:
```bash
cmake --preset=x64-<debug/release>
```
4. Build the project:
### Debug
```bash
cd ./build-x64-debug/
cmake --build .
```
### Release
```bash
cd ./build-x64-release/
cmake --build . --config Release
```
This project is licensed under the MIT License - see the LICENSE file for details.
