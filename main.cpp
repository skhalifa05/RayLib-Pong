/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Example complexity rating: [★☆☆☆] 1/4
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute 'raylib_compile_execute' script
*   Note that compiled executable is placed in the same folder as .c file
*
*   To test the examples on Web, press F6 and execute 'raylib_compile_execute_web' script
*   Web version of the program is generated in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <string>

#include "Ball.h"
#include "Paddle.h"
#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    Ball ball(screenWidth/2, screenHeight/2, 3, 4, 10);
    Paddle paddle((screenWidth/2)-35);
    InitWindow(screenWidth, screenHeight, "Bouncing Ball - Seif Khalfia");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        ball.update();
        paddle.update();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(ball.getColor() ? BLACK : RAYWHITE);
            DrawText("RayLib Bouncing Ball - Seif Khalifa!", 220, 200, 20, LIGHTGRAY);
            ball.draw(paddle);
            paddle.draw();
            //Draw Lives
            for (int i = 1; i<= ball.getLives(); i++) {
                DrawCircle(800 - (20*i), 20,5,RED);
            }
            DrawText(ball.getCounter().c_str(), 15, 20, 30, GRAY);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}