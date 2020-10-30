// fig15_03.c
// Using the exit and atexit functions
#include <stdio.h>
#include <stdlib.h>

void print(void); // prototype

int main(void) {
   atexit(print); // register function print
   puts("Enter 1 to terminate program with function exit\n"
        "Enter 2 to terminate program normally");
   int answer = 0; // user
   scanf("%d", &answer);

   // call exit if answer is 1
   if (answer == 1) { 
      puts("\nTerminating program with function exit");
      exit(EXIT_SUCCESS);
   } 

   puts("\nTerminating program by reaching the end of main");
} 

// display message before termination              
void print(void) {
   puts("Executing function print at program termination\n"
        "Program terminated");     
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
