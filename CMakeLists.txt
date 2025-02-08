cmake_minimum_required(VERSION 3.30)
project(Lecture1_Raylib)

set(CMAKE_CXX_STANDARD 20)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add library directory
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Find all static and dynamic libraries in lib/
file(GLOB LIBS "${CMAKE_SOURCE_DIR}/lib/*.a" "${CMAKE_SOURCE_DIR}/lib/*.so")

# Add executable
add_executable(Lecture1_Raylib main.cpp
        Ball.cpp
        Ball.h
        Paddle.cpp
        Paddle.h
        GameManager.cpp
        GameManager.h)

# Link libraries
if (LIBS)
    target_link_libraries(Lecture1_Raylib PRIVATE ${LIBS})
else()
    message(WARNING "No libraries found in lib/ folder!")
endif()

# Fix: Link macOS system frameworks (CoreFoundation, IOKit, CoreGraphics, AppKit)
if(APPLE)
    target_link_libraries(Lecture1_Raylib PRIVATE
            "-framework CoreFoundation"
            "-framework IOKit"
            "-framework CoreGraphics"
            "-framework AppKit"  # Required for `_NSApp` symbol
    )
endif()