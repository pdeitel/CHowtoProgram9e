// fig07_18.c
// Demonstrating an array of pointers to functions.
#include <stdio.h>

// prototypes
void function1(int a); 
void function2(int b); 
void function3(int c); 

int main(void) {
   // initialize array of 3 pointers to functions that each take an
   // int argument and return void                              
   void (*f[3])(int) = {function1, function2, function3};    

   printf("%s", "Enter a number between 0 and 2, 3 to end: ");
   int choice = 0; 
   scanf("%d", &choice);

   // process user's choice
   while (choice >= 0 && choice < 3) {
      // invoke function at location choice in array f and pass
      // choice as an argument                              
      (*f[choice])(choice);                                

      printf("%s", "Enter a number between 0 and 2, 3 to end: ");
      scanf("%d", &choice);
   } 

   puts("Program execution completed.");
} 

void function1(int a) {
   printf("You entered %d so function1 was called\n\n", a);
} 

void function2(int b) {
   printf("You entered %d so function2 was called\n\n", b);
} 

void function3(int c) {
   printf("You entered %d so function3 was called\n\n", c);  
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

