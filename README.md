# C++ OpenGL Boilerplate

## Installation requirements Windows
- [Cmake (min. version 3.10)](https://cmake.org/download/)
- [Microsoft C++ Compiler](https://visualstudio.microsoft.com/vs/features/cplusplus/)
- [Git](https://git-scm.com/)

## Installation requirements Linux
- [Cmake](https://cmake.org/download/)
- [Git](https://git-scm.com/)
- make
- g++ and any specific libs for opengl

# Create Visual Studio project
```
git clone --recurse-submodules https://github.com/Lexikus/cpp-opengl-boilerplate.git
cd cpp-opengl-boilerplate
mkdir build
cd build
cmake ..
```

# Create Makefile on Linux
```
git clone --recurse-submodules https://github.com/Lexikus/cpp-opengl-boilerplate.git
cd cpp-opengl-boilerplate
mkdir build
cd build
cmake ..
make
```