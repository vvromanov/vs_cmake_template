# vs_cmake_template
Template for simple test projects
* Microsoft Visual Studio
* JetBrains CLion
* CMake
* Google test
* WSL
* vcpkg


A simple C++ project template for writing tests and test assignments.
It consists of three parts:
1) a library where the main code should be located
2) tests for this code using Google Test
3) the main application.

The project can be used for Visual Studio and CLion. It is built using the VS compiler and gcc on WSL and others. vcpkg is used to install Google Test.
The project also includes support for Github Actions. After each commit, the project is automatically compiled and tests are run on GitHub. The test run result is published.
You can simply fork or clone it and use it for yourself

## Linux setup
sudo apt-get update
sudo apt-get install cmake gdb build-essential libgtest-dev ninja-build