// fig08_07.c
// Using functions fgets and putchar
#include <stdio.h>
#define SIZE 80

void reverse(const char * const sPtr); 
   
int main(void) {
   char sentence[SIZE] = ""; 

   puts("Enter a line of text:");
   fgets(sentence, SIZE, stdin); // read a line of text

   printf("\n%s", "The line printed backward is:");
   reverse(sentence);
   puts("");
} 

// recursively outputs characters in string in reverse order
void reverse(const char * const sPtr) {
   // if end of the string
   if ('\0' == sPtr[0]) { // base case
      return; 
   }  
   else { // if not end of the string 
      reverse(&sPtr[1]); // recursion step                
      putchar(sPtr[0]); // use putchar to display character
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
