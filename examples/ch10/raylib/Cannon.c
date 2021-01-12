// Cannon.c
/* Cannon challenges you to destroy all the targets before time expires. 
  
   ----------------------------------
   Overview of this game's functions:
   ----------------------------------
   - main: Controls the game's lifecycle and contains the game loop.

   - InitGame: Loads the game's sounds, initializes the game elements
     and initializes the game's state variables. This is called when the 
     game launches and when the user chooses to play again.

   - UpdateGame: Called from main's game loop and defines the game logic 
     that updates the game elements for the next animation frame.

   - DrawGame: Draws the game elements for the next animation frame.

   - UnloadGame: Unloads the game's sounds.

   - alignBarrel: Aligns the cannon's barrel to the given angle.

   - alignAndFireCannon: Calls alignBarrel to align the cannon's barrel 
     then fires the cannonball in that direction.

   --------------------------------------
   Raylib functions used in this program:
   --------------------------------------
   - BeginDrawing: Prepare to begin drawing next animation frame in 
     memory--known as an off-screen buffer.

   - CheckCollisionCircleRec: Check if a circle and rectangle intersect.

   - ClearBackground: Set off-screen buffer's background color

   - CloseAudioDevice: Release the raylib audio system's resources.

   - CloseWindow: Release game window's resources and closes window.

   - DrawCircle: Draw a circle with the specified center (passed as
     individual x and y values), radius and color.

   - DrawCircleV: Draw a circle with the specified center (passed as a 
     Vector2 object containing x and y), radius and color.

   - DrawLineEx: Draw a line with a start point (specified as a Vector2), 
     an end point (specified as a Vector2), a line thickness and a color.

   - DrawRectangleRec: Draw a rectangle (specified by a Rectangle object 
     containing x, y, width and height) in the specified color.

   - DrawText: Draw text at the specified location using the specified  
     font size and color.

   - EndDrawing: Complete the current animation frame and display it on  
     the screen, replacing the previous animation frame.

   - GetFrameTime: Return the time in seconds when the last frame was 
     drawn; used to help keep track of elapsed game time.

   - GetMousePosition: Return the mouse's x-y coordinates.

   - GetRandomValue: Return a random integer in the range that includes 
     both its first argument and its second argument.

   - InitAudioDevice: Prepare raylib's audio system to play sounds.

   - InitWindow: Set window size and title.

   - IsKeyPressed: Check if user pressed a specified key.

   - IsMouseButtonPressed: Check if user pressed a specified mouse button.

   - LoadSound: Load a sound file. 

   - MeasureText: Determine the width in pixels of the specified text in  
     the specified font size--often used to help center text horizontally.

   - PlaySound: Play a sound.

   - SetTargetFPS: Set target frames-per-second to drive animation.

   - TextFormat: Create formatted text using a printf-style format string.

   - UnloadSound: Release a loaded sound's resources.

   - WindowShouldClose: Check if user closed the game window.

   Raylib is Copyright ©2013-2020 Ramon Santamaria (@raysan5).
*/
#include <math.h>
#include "raylib.h"

#define TARGETS 9

// struct for Blocker's information
typedef struct Blocker {
   Rectangle rect; // stores x, y, width, height
   Color color; // stores r (red), g (green), b (blue), a (alpha) 
   Sound sound; // stores sound loaded with LoadSound 
   double dy; // amount Blocker moves vertically each animation frame
   int missPenalty; // time deduction when cannonball hits the Blocker
} Blocker;

// struct for each Target's information
typedef struct Target {
   Rectangle rect; // stores x, y, width, height
   Color color; // stores r, g, b, a (red, green, blue, alpha)
   Sound sound; // stores sound loaded with LoadSound 
   double dy; // amount Target moves vertically each animation frame 
   bool destroyed; // whether the Target has been destroyed yet
   int hitReward; // time bonus when cannonball hits a Target
} Target;

// struct for Cannonball information
typedef struct Cannonball {   
   Vector2 position; // stores x, y
   double dx; // amount Cannonball moves horizontally each animation frame  
   double dy; // amount Cannonball moves vertically each animation frame 
   double radius; // Cannonball's radius
   bool onScreen; // whether the Cannonball is on the screen
   Color color; // stores r, g, b, a (red, green, blue, alpha)
} Cannonball;

// struct for Cannon information
typedef struct Cannon {   
   double baseRadius; // radius of semicircle representing Cannon base
   double barrelLength; // length of line representing the Cannon barrel
   Vector2 barrelStart; // stores x, y  
   Vector2 barrelEnd; // stores x, y
   double barrelAngle; // used to calculate barrelEnd to aim the Cannon
   double barrelThickness; // line thickness for drawing the barrel
   Cannonball ball; 
   Color color; // stores r, g, b, a (red, green, blue, alpha)
   Sound sound; // stores sound loaded with LoadSound 
} Cannon;

// global static constants for the Raylib screen size
static const int screenWidth = 800;
static const int screenHeight = 450;

// global static constants used to update the time reamining
static const int missPenalty = 2; // seconds deducted on a miss
static const int hitReward = 3; // seconds added on a hit

// global static constants for scaling Cannon size, based on screen size
static const double cannonBaseRadiusPercent = 3.0 / 40;
static const double cannonBarrelWidthPercent = 3.0 / 40;
static const double cannonBarrelLengthPercent = 1.0 / 10;

// global static constants for scaling Cannonball's size and speed
// based on screen size
static const double cannonballSpeedPercent = 1.0 / 25;

// global static constants for scaling Target size/speed,
// based on screen size
static const double targetWidthPercent = 1.0 / 40;
static const double targetHeightPercent = 3.0 / 20;
static const double targetFirstXPercent = 3.0 / 5;
static const double targetSpacingPercent = 1.0 / 60;
static const double targetMinSpeedPercent = 1.0 / 200;
static const double targetMaxSpeedPercent = 1.0 / 50;

// global static constants for scaling Blocker size/speed, 
// based on screen size
static const double blockerWidthPercent = 1.0 / 40;
static const double blockerLengthPercent = 1.0 / 4;
static const double blockerXPercent = 1.0 / 2;
static const double blockerSpeedPercent = 1.0 / 50;

// global static constant for scaling the font size based on screen size
static const double textSizePercent = 1.0 / 18;

// game element objects
static Cannon cannon;
static Blocker blocker;
static Target targets[TARGETS];

// variables for the game loop and tracking statistics
static bool gameOver = false; 
static bool soundsLoaded = false; 
static bool pause = false;
static double timeLeft = 10.0; // time specified in seconds
static int shotsFired = 0;
static double elapsedTime = 0; 
static int targetsHit = 0; 

// global variables to store sounds loaded in InitGame
static Sound targetHit;
static Sound cannonFire;
static Sound blockerHit;

// function prototypes
static void InitGame(void); 
static void UpdateGame(void); 
static void DrawGame(void); 
static void UnloadGame(void); 
static void alignBarrel(double angle);
static void alignAndFireCannonball(Vector2 point);

// controls the game's lifecycle
int main(void) {
   InitWindow(screenWidth, screenHeight, "Cannon"); // prepare window
   InitGame(); // load sounds and initialize game elements and variables
   SetTargetFPS(60); // target animation frame rate

   // main game loop
   while (!WindowShouldClose()) { // loop until user closes window
      UpdateGame(); // update game element positions
      DrawGame(); // draw next animation frame
   }

   UnloadGame(); // release game resources
   CloseWindow(); // close game window
}

// Initialize a new game: All game element sizes are calculated based on the 
// screen's width and height, using various global static constants. This
// enables them to scale if you change the screen's width or height. 
void InitGame(void) {
   // load sounds: performed once
   if (!soundsLoaded) {
      InitAudioDevice(); // prepare the raylib audio system
      targetHit = LoadSound("sounds/hit.wav");
      cannonFire = LoadSound("sounds/cannon_fire.wav");
      blockerHit = LoadSound("sounds/miss.wav");
      soundsLoaded = true;
   }
   
   // reset game state
   gameOver = false;
   timeLeft = 10.0; // seconds
   elapsedTime = 0.0; // seconds
   targetsHit = 0;
   shotsFired = 0; 

   // configure the Cannon
   cannon.baseRadius = cannonBaseRadiusPercent * screenHeight;
   cannon.barrelLength = cannonBarrelLengthPercent * screenWidth;
   cannon.barrelStart.x = 0; // left edge of screen
   cannon.barrelStart.y = screenHeight / 2; // vertical center of screen
   alignBarrel(PI / 2); // straight right; sets barrelAngle & barrelEnd
   cannon.barrelThickness = cannonBarrelWidthPercent * screenHeight;
   cannon.color = DARKGRAY; // Cannon color
   cannon.sound = cannonFire; // sound to play when Cannon fires
   
   // configure the Blocker by specifying its Rectangle's dimensions,
   // its dy (change in y for each animation frame) and other components
   blocker.rect.x = blockerXPercent * screenWidth;
   blocker.rect.y = (0.5 - blockerLengthPercent / 2) * screenHeight;
   blocker.rect.width = blockerWidthPercent * screenWidth;
   blocker.rect.height = blockerLengthPercent * screenHeight;
   blocker.color = BLACK; // Blocker color 
   blocker.sound = blockerHit; // sound to play when Blocker is hit
   blocker.dy = blockerSpeedPercent * screenHeight;
   blocker.missPenalty = missPenalty; // time penalty for hitting the Blocker

   // calculate initial targetX and targetY for setting up Targets
   double targetX = targetFirstXPercent * screenWidth; // leftmost Target x
   double targetY = (0.5 - targetHeightPercent / 2) * screenHeight;

   // set up the Targets
   for (int i = 0; i < TARGETS; ++i) {
      // determine random vertical velocity
      double velocity = 
         GetRandomValue(screenHeight * targetMinSpeedPercent,
            screenHeight * targetMaxSpeedPercent);
      velocity *= GetRandomValue(0, 1) ? 1 : -1; // random direction

      // configure a target by specifying its Rectangle's dimensions,
      // its dy (change in y for each animation frame) and other components
      targets[i].rect.x = targetX;
      targets[i].rect.y = targetY;
      targets[i].rect.width = targetWidthPercent * screenWidth;
      targets[i].rect.height = targetHeightPercent * screenHeight;
      targets[i].color = (i % 2 == 0) ? VIOLET : ORANGE; // choose color
      targets[i].sound = targetHit; // sound to play when Target is hit
      targets[i].dy = velocity; // y change for each animation frame
      targets[i].destroyed = false; // Target has not yet been destroyed
      targets[i].hitReward = hitReward; // time bonus for hitting a Target

      // calculate the next Target's x-coordinate
      targetX += (targetWidthPercent + targetSpacingPercent) * screenWidth;
   }
}

// update all game elements before next frame is displayed
void UpdateGame(void) {
   if (!gameOver) {
      if (IsKeyPressed('P')) { // allow user to toggle pausing
         pause = !pause;
      }

      if (!pause) {
         // update elapsed time and time remaining
         double time = GetFrameTime();
         elapsedTime += time; 
         timeLeft -= time; 
         
         // if mouse clicked and no Cannonball on screen, fire cannon
         if (!cannon.ball.onScreen &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { 
            ++shotsFired;
            alignAndFireCannonball(GetMousePosition());
         }
         else if (cannon.ball.onScreen) { // move Cannonball
            cannon.ball.position.x += cannon.ball.dx;
            cannon.ball.position.y += cannon.ball.dy;
            
            // check if Cannonball is no longer on the screen 
            if (cannon.ball.position.x > screenWidth ||
               cannon.ball.position.x < 0 ||
               cannon.ball.position.y > screenHeight || 
               cannon.ball.position.y < 0) {
               cannon.ball.onScreen = false; 
            }
            
            // check for Cannonball/Blocker collision
            else if (CheckCollisionCircleRec(cannon.ball.position, 
                   cannon.ball.radius, blocker.rect)) {
               PlaySound(blocker.sound); 
               cannon.ball.dx *= -1; // reverse ball direction
               timeLeft -= blocker.missPenalty; // subtract time penalty
            }
            
            // check for Cannonball/Target collision
            else {
               for (int i = 0; i < TARGETS; ++i) {
                  if (!targets[i].destroyed && 
                     CheckCollisionCircleRec(cannon.ball.position,
                        cannon.ball.radius, targets[i].rect)) {

                     PlaySound(targets[i].sound); 
                     cannon.ball.onScreen = false; 
                     targets[i].destroyed = true; 
                     ++targetsHit;
                     timeLeft += targets[i].hitReward; // add time bonus
                     break;
                  }
               }
            }
         }
         
         // move blocker
         blocker.rect.y += blocker.dy; 
         
         // reverse blocker direction if it hit top or bottom of screen
         if (blocker.rect.y <= 0 || 
            blocker.rect.y + blocker.rect.height >= screenHeight) {
            blocker.dy *= -1;
         }
         
         // move targets
         for (int i = 0; i < TARGETS; ++i) {
            targets[i].rect.y += targets[i].dy;

            // reverse target direction if it hit top or bottom of screen
            if (targets[i].rect.y <= 0 || targets[i].rect.y + 
               targets[i].rect.height >= screenHeight) {

               targets[i].dy *= -1;
            }
         }

         // check if game ended because time ran out
         if (timeLeft <= 0.0) { 
            timeLeft = 0.0;
            gameOver = true;
         }
         else if (targetsHit == TARGETS) { // all targets destroyed
            gameOver = true;
         }
      }
   }
   // game over 
   else {
      cannon.ball.onScreen = false; 
      
      // start new game?
      if (IsKeyPressed(KEY_ENTER)) { 
         InitGame(); // reset all game elements
      }
   }
}

// draw one animation frame, replacing the previous animation frame on screen
void DrawGame(void) {
   static int fontSize = (int) (textSizePercent * screenHeight);
   BeginDrawing(); // set up offscreen canvas for current animation frame
   ClearBackground(WHITE); // start with a black canvas
      
   // draw cannon's base (circle) and barrel (line)
   DrawCircle(0, screenHeight / 2, cannon.baseRadius, cannon.color);
   DrawLineEx(cannon.barrelStart, cannon.barrelEnd, 
      cannon.barrelThickness, cannon.color);
   
   // draw blocker
   DrawRectangleRec(blocker.rect, blocker.color); 
      
   // if a cannonball was fired, draw it
   if (cannon.ball.onScreen) {
      DrawCircleV(cannon.ball.position, 
         cannon.ball.radius, cannon.ball.color);
   }
   
   // draw targets
   for (int i = 0; i < TARGETS; ++i) {
      if (!targets[i].destroyed) {
         DrawRectangleRec(targets[i].rect, targets[i].color);
      }
   }
     
   // if game paused, display instructions to continue
   if (pause) {
      static char *paused = "PAUSED: PRESS P TO CONTINUE";
      DrawText(paused, screenWidth / 2 - MeasureText(paused, fontSize) / 2, 
         screenHeight / 2 - fontSize / 2, fontSize, GRAY);
   }

   // display time remaining
   DrawText(TextFormat("TIME REMAINING: %.1f", timeLeft), 
      15, 15, fontSize, DARKGRAY);

   // if game over, display final stats and instructions to play again
   if (gameOver) {
      DrawText(targetsHit == TARGETS ? "YOU WIN!" : "YOU LOSE.", 
         15, screenHeight - 15 - (fontSize + 5) * 5, fontSize, DARKGREEN); 
      DrawText(TextFormat("SHOTS: %d", shotsFired),
         15, screenHeight - 15 - (fontSize + 5) * 4, fontSize, DARKGREEN);  
      DrawText(TextFormat("HITS: %d", targetsHit),
         15, screenHeight - 15 - (fontSize + 5) * 3, fontSize, DARKGREEN);  
      DrawText(TextFormat("ELAPSED TIME: %.1f SECONDS", elapsedTime),
         15, screenHeight - 15 - (fontSize + 5) * 2, fontSize, DARKGREEN);   
      DrawText("PRESS ENTER TO PLAY AGAIN", 
         15, screenHeight - 15 - (fontSize + 5), fontSize, DARKGREEN);   
   }
   
   // overwrite the on-screen animation frame with off-screen buffer contents
   EndDrawing(); 
}

// release game resources
void UnloadGame(void) {
   UnloadSound(targetHit);    
   UnloadSound(cannonFire);
   UnloadSound(blockerHit);
   CloseAudioDevice(); // release raylib audio resources
}

// aligns the Cannon's barrel to the given angle
void alignBarrel(double barrelAngle) {
   cannon.barrelAngle = barrelAngle;
   cannon.barrelEnd.x = cannon.barrelLength * sin(barrelAngle);
   cannon.barrelEnd.y = 
      -cannon.barrelLength * cos(barrelAngle) + screenHeight / 2;
}

// align the barrel and fire a Cannonball 
void alignAndFireCannonball(Vector2 point) {
   // compute point's distance from vertical center of screen
   double centerMinusY = (screenHeight / 2 - point.y);

   // TRIGONOMETRY: calculate barrel angle from horizontal and align barrel
   double angle = atan2(point.x, centerMinusY);
   alignBarrel(angle); // aim barrel
      
   // reset cannon ball
   cannon.ball.position.x = 0; 
   cannon.ball.position.y = screenHeight / 2;
   cannon.ball.radius = cannon.barrelThickness / 2;
   cannon.ball.onScreen = true; // cannot fire again until this is false
   cannon.ball.color = cannon.color;
   
   // TRIGONOMETRY: calculate the Cannonball velocity's x and y components
   cannon.ball.dx = 
      cannonballSpeedPercent * screenWidth * sin(cannon.barrelAngle);
   cannon.ball.dy = 
      cannonballSpeedPercent * screenWidth * -cos(cannon.barrelAngle);

   PlaySound(cannon.sound);
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
 **************************************************************************/





