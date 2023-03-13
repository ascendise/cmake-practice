# CMake Practice

I created this project mainly for trying out CMake.

The project includes some code that can be built and tested with CMake and Unity.

# Build

Install CMake (min. VERSION 3.25)
Install build tool of your choice. I use make for this example

Create the build files using
```
cmake .
```

Build the project using 
```
make
```

# Tests
Run tests using
```
ctest
```

# About the code

The codebase contains an implementation of a Stack using a linked list.
The library contains functions to create a stack, push and pop elements and to destroy the stack, freeing the memory.

The code is mainly there to have something to build with CMake. (And because I wanted to do something fun with C :) )

It is obviously not meant for production use...

# Contribute
If you stumble upon this project and see any glaring issues with the CMakeLists.txt or my stack implementation, feel free to create an issue and let me know. I am always open for critique and opportunities to learn.