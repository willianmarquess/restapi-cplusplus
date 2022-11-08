# C++ Restapi with SOLID based on Clean Architecture

![GitHub repo size](https://img.shields.io/github/repo-size/willianmarquess/restapi-cplusplus?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/willianmarquess/restapi-cplusplus?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/willianmarquess/restapi-cplusplus?style=for-the-badge)

## 💻 Requirements
* vcpkg to add external libraries
* msbuild to run in cmd
* visual studio (IDE) to open solution, build and run
* use this tutorial to config visual studio with c++ support (https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170)

**Project uses C++20

## Build and run (visual studio)

1. install crow framework using: vcpkg install crow
2. open solution in visual studio
3. build project
4. run application

## Build and run (CommandLine)

1. install crow framework using: vcpkg install crow
2. open project folder in terminal
3. run this command: msbuild .\restapi-cplusplus.sln
4. open debug folder: cd x64/Debug
5. execute command: .\restapi-cplusplus.exe

## Framework/libs used in project
* CROW C++ (https://crowcpp.org/master/)
