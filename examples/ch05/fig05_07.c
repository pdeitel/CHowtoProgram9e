// fig05_07.c
// Simulating the game of craps.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

enum Status {CONTINUE, WON, LOST}; // constants represent game status

int rollDice(void); // rollDice function prototype 

int main(void) {
   srand(time(NULL)); // randomize based on current time

   int myPoint = 0; // player must make this point to win
   enum Status gameStatus = CONTINUE; // may be CONTINUE, WON, or LOST
   int sum = rollDice(); // first roll of the dice

   // determine game status based on sum of dice
   switch(sum) {
      // win on first roll
      case 7: // 7 is a winner
      case 11: // 11 is a winner          
         gameStatus = WON; 
         break;
      // lose on first roll
      case 2: // 2 is a loser
      case 3: // 3 is a loser
      case 12: // 12 is a loser
         gameStatus = LOST; 
         break;
      // remember point
      default:                  
         gameStatus = CONTINUE; // player should keep rolling
         myPoint = sum; // remember the point
         printf("Point is %d\n", myPoint);
         break; // optional
   }

   // while game not complete
   while (CONTINUE == gameStatus) { // player should keep rolling
      sum = rollDice(); // roll dice again

      // determine game status
      if (sum == myPoint) { // win by making point
         gameStatus = WON; 
      } 
      else if (7 == sum) { // lose by rolling 7
         gameStatus = LOST; 
      } 
   } 

   // display won or lost message
   if (WON == gameStatus) { // did player win?
      puts("Player wins");
   } 
   else { // player lost
      puts("Player loses");
   } 
} 

// roll dice, calculate sum and display results
int rollDice(void) {
   int die1 = 1 + (rand() % 6); // pick random die1 value
   int die2 = 1 + (rand() % 6); // pick random die2 value

   // display results of this roll
   printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
   return die1 + die2; // return sum of dice
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
