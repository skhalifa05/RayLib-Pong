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
add_executable(Lecture1_Raylib src/main.cpp
        src/Ball.cpp
        src/Ball.h
        src/Paddle.cpp
        src/Paddle.h
        src/GameManager.cpp
        src/GameManager.h
        src/LivesManager.cpp
        src/LivesManager.h
        src/PowerUpsManager.cpp
        src/PowerUpsManager.h
        src/PowerUps/PowerUp.h
        src/PowerUps/LargerPaddle.h
        src/PowerUps/ExtraLife.h
        src/PowerUps/LargerPaddle.cpp
        src/PowerUps/ExtraLife.cpp)

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