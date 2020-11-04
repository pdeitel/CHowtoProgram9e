// Randomly generate numbers between 1 and 1000 for user to guess.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessGame(void); // function prototype
int isCorrect(int guess, int answer); // function prototype

int main(void) {
   srand(time(0)); // seed random number generator
   guessGame();
} // end main

// guessGame generates numbers between 1 and 1000
// and checks user's guess
void guessGame(void) {
   int response; // 1 or 2 response to continue game

   // loop until user types 2 to quit game
   do {
      // generate random number between 1 and 1000
      // 1 is shift, 1000 is scaling factor
      int answer = 1 + rand() % 1000;

      // prompt for guess
      puts("I have a number between 1 and 1000.\n" 
           "Can you guess my number?\n" 
           "Please type your first guess.");
      printf("%s", "? ");
      int guess; // user's guess
      scanf("%d", &guess);

      // loop until correct number
      while (!isCorrect(guess, answer)) {
         scanf("%d", &guess);
      }

      // prompt for another game
      puts("\nExcellent! You guessed the number!\n"
         "Would you like to play again?");
      printf("%s", "Please type (1=yes, 2=no)? ");
      scanf("%d", &response);

      puts("");
   } while (response == 1);
} // end function guessGame

// isCorrect returns true if guess equals answer
// if guess does not equal answer, displays hint
int isCorrect(int guess, int answer) {
   // guess is correct
   if (guess == answer) {
      return 1;
   }

   // guess is incorrect; display hint
   if (guess < answer) {
      printf( "%s", "Too low. Try again.\n? " );
   }
   else {
      printf( "%s", "Too high. Try again.\n? " );
   }

   return 0;
} // end function isCorrect



/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
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
