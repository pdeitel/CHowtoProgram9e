// fig15_04.c
// Using signal handling
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void signalHandler(int signalValue); // prototype

int main(void) {
   signal(SIGINT, signalHandler); // register signal handler
   srand(time(NULL));
   
   // output numbers 1 to 100
   for (int i = 1; i <= 100; ++i) { 
      int x = 1 + rand() % 50; // generate random number to raise SIGINT
      
      // raise SIGINT when x is 25
      if (x == 25) {
         raise(SIGINT);     
      } 

      printf("%4d", i);
      
      // output \n when i is a multiple of 10
      if (i % 10 == 0) {
         printf("%s", "\n");
      } 
   } 
} 

// handles signal 
void signalHandler(int signalValue) {
   printf("\n%s%d%s\n%s",
      "Interrupt signal (", signalValue, ") received.",
      "Do you wish to continue (1 = yes or 2 = no)? ");
   int response = 0; // user
   scanf("%d", &response);
   
   // check for invalid responses
   while (response != 1 && response != 2) { 
      printf("%s", "(1 = yes or 2 = no)? ");
      scanf("%d", &response);
   } 
   
   // determine whether it
   if (response == 1) {
      // reregister signal handler for next SIGINT
      signal(SIGINT, signalHandler);              
   } 
   else {
      exit(EXIT_SUCCESS);
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
