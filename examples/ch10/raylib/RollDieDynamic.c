// RollDieDynamic.c
/* RollDieDynamic visualizes the law of large numbers. 
   This simulation's code consists of the following functions:
  
   ---------------------
   Functions we created:
   ---------------------
   - main: Controls the simulation's lifecycle and contains the 
     "game loop," which in this application, repeatedly updates die-face 
     frequencies and displays the visualization.

   - InitSimulation: Initializes the simulation's elements and state 
     variables. This is called when the simulation launches.

   - Update: Called from main's game loop. Defines the simulation 
     logic that updates the die-face frequency counters and uses them
     to update the visualization elements for the next animation frame.

   - DrawFrame: Draws the next animation frame's simulation elements.

   - Unload: Releases the resources for the simulation's die-image 
     Texture2D objects.

   ----------------------------------------
   Raylib functions we use in this program:
   ----------------------------------------
   - BeginDrawing: Prepare to begin drawing next animation frame in memory--
     known as an off-screen buffer.
     
   - ClearBackground: Set off-screen buffer's background color

   - CloseWindow: Release game window's resources and close window.

   - DrawRectangleRec: Draw a rectangle (specified by a Rectangle object 
     containing x, y, width and height) in the specified color.

   - DrawText: Draw text at the specified location using the specified  
     font size and color.

   - DrawTextureEx: Draw a Texture2D at specified position (a Vector2),
     with the specified rotation, scale and tint color.     

   - EndDrawing: Complete the current animation frame and display it on the 
     screen, replacing the previous animation frame.

   - GetRandomValue: Return a random integer in the range that includes both
     its first argument and its second argument.

   - GetScreenWidth: Returns screen width in pixels. Used to help position
     and scale bars.
     
   - GetScreenHeight: Returns screen height in pixels. Used to help 
     position each row of the output.
     
   - LoadTexture: Load a texture or image into the graphics processing
     unit (GPU) memory.
   
   - TextFormat: Create formatted text using a printf-style format string.

   - InitWindow: Set window size and title.

   - IsKeyPressed: Check if user pressed a specified key.

   - MeasureText: Determine the width in pixels of the specified text in the 
     specified font size--often used to help center text horizontally.

   - SetTargetFPS: Set target frames-per-second to drive animation.
   
   - UnloadTexture: Release the resources for a loaded Texture2D.
   
   - WindowShouldClose: Returns true if the user closed the game window and
     the program should terminate.

   Raylib is Copyright ©2013-2020 Ramon Santamaria (@raysan5).
*/
#include <math.h>
#include <stdlib.h>
#include "raylib.h"

#define FACES 6

// struct to maintain Bar information
typedef struct Bar {
   Rectangle rect; // stores x, y, width, height
   Color color; // stores r, g, b, a (red, green, blue, alpha)
} Bar;

// global constants 
static const int screenWidth = 800;
static const int screenHeight = 450;
static const int fontSize = 30; 
static const int barX = 350; // starting x-coordinate for each Bar

// global state and visual elements
static bool simulationOver = false;
static bool pause = false;
static int barMaxWidth = 0; // calculated in InitSimulation
static int totalRolls = 0; // number of die rolls so far
static int maxFrames = 0; // total animation frames; command-line argument
static int rollsPerFrame = 0; // die rolls per frame; command-line argument
static int counts[FACES + 1] = {0}; // die counts (ignore element 0)
static Texture2D dice[FACES + 1]; // die images (ignore element 0)
static Bar bars[FACES + 1] = {0}; // Bars (ignore element 0)

// function prototypes
static void InitSimulation(void); 
static void Update(void); 
static void DrawFrame(void); 
static void Unload(void); 

// main's arguments argc and argv enable main to receive command-line
// arguments, which are discussed in Section 15.3. 
int main(int argc, char *argv[]) {
    
   // convert command-line args for maxFrames and rollsPerFrame from
   // strings to integers; argv[1] is the number of animation frames;
   // argv[2] is the number of dice to roll per animation frame
   maxFrames = atoi(argv[1]); 
   rollsPerFrame = atoi(argv[2]); 

   // prepare window
   InitWindow(screenWidth, screenHeight, "Die Rolling Simulation"); 
   InitSimulation(); // initialize simulation elements
   SetTargetFPS(30); // target animation frame rate

   // main animation loop
   while (!WindowShouldClose()) { // loop until user closes window
      Update(); // update die counts
      DrawFrame(); // draw next animation frame
   }

   // release resources and close application window
   Unload(); 
   CloseWindow(); 
}

// initialize game state and elements
void InitSimulation(void) {    
   simulationOver = false;
   totalRolls = 0;
   barMaxWidth = GetScreenWidth() - barX - 10;
   
   // set counts to 0 on simulation start
   for (int i = 1; i <= FACES; ++i) { 
      counts[i] = 0;
   }
   
   // load die images from dice folder as raylib Texture2D objects
   for (int i = 1; i <= FACES; ++i) {       
      dice[i] = LoadTexture(FormatText("dice/die%d.png", i));
   }
   
   // initialize Bar objects
   int y = 10; // starting y-coordinate for the first bar
   int dy = (GetScreenHeight() - y) / 8; // y increment for each row     
  
   for (int i = 1; i <= FACES; ++i) {
      bars[i].rect.x = barX;
      bars[i].rect.y = y + dy * i;    
      bars[i].rect.width = 0; // width will be set in Update()
      bars[i].rect.height = fontSize; // bar height same as font size
      bars[i].color = PURPLE; // raylib pre-defined color 
   }
}

// update all game elements before next frame is displayed
void Update(void) {
   if (!simulationOver) {
      // allow simulation to be paused
      if (IsKeyPressed('P')) { 
         pause = !pause;
      }

      // if the game is not paused, update the simulation elements
      if (!pause) { 
      
         // roll dice for this animation frame and update counters
         for (int i = 1; i <= rollsPerFrame; ++i) {
            ++counts[GetRandomValue(1, 6)]; // roll die
            ++totalRolls;
         }
                  
         // determine index of widest bar for this frame
         int index = 0; 
         int largest = 0; 
         
         for (int i = 1; i <= FACES; ++i) {
            if (counts[i] > largest) {
               largest = counts[i];
               index = i;
            }
         }
         
         // scale all bars based on largest bar       
         for (int i = 1; i <= FACES; ++i) {
            // counts[i] and counts[index] are integers, so we multiply 
            // by 1.0 enable floating-point arithmetic
            bars[i].rect.width = 
               (int) (counts[i] * 1.0 / counts[index] * barMaxWidth);
         }
      }

      // check whether simulation completed
      if (totalRolls == maxFrames * rollsPerFrame) {
         simulationOver = true;
      }
   }
}

// draw one animation frame
void DrawFrame(void) {
   BeginDrawing(); // set up offscreen canvas for current animation frame
   ClearBackground(WHITE); // start with a white background
   
   // variables used to determine simulation element positions
   int x = 10; // starting x-coordinate for text elements
   int y = 10; // starting y-coordinate for text elements
   int dy = (GetScreenHeight() - y) / 8; // y increment for each row
  
   // display column heads
   DrawText("Die", x, y, fontSize, BLACK);
   DrawText("Rolls", x + 70, y, fontSize, BLACK);
   DrawText("%", x + 240, y, fontSize, BLACK);
   
   // draw each row's die image, data and Bar
   for (int i = 1; i <= FACES; ++i) {      
   
      // die position; bars[i].rect.y - 5 for better vertical alignment
      Vector2 position = {x, bars[i].rect.y - 5}; 

      // display die with no rotation (0) and 75% scale (0.75); the last 
      // argument allows you to tint the texture with a different color
      DrawTextureEx(dice[i], position, 0, 0.75, WHITE); 
      
      // display current die's count, % of total rolls, and bar
      DrawText(FormatText("%d", counts[i]), 
         x + 70, y + dy * i, fontSize, BLACK);
      DrawText(FormatText("%.2f", counts[i] * 100.0 / totalRolls), 
         x + 240, y + dy * i, fontSize, BLACK);
      DrawRectangleRec(bars[i].rect, bars[i].color); 
   }
  
   // draw total number of dice rolled so far
   DrawText(FormatText("%d", totalRolls), 
      x + 70, y + dy * 7, fontSize, BLACK);

   // if simulation is paused, display instructions to continue
   if (pause) {
      DrawText("SIMULATION PAUSED", 
         screenWidth / 2 - MeasureText("SIMULATION PAUSED", fontSize) / 2, 
         screenHeight / 2 - fontSize / 2, fontSize, GRAY);
   }
  
   EndDrawing(); // display the animation frame 
}

// release resources
void Unload(void) {
   for (int i = 1; i <= FACES; ++i) {       
      UnloadTexture(dice[i]); // unload the die textures
   }
}


/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/


