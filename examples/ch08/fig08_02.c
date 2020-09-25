// fig08_02.c
// Using functions islower, isupper, tolower and toupper
#include <ctype.h>
#include <stdio.h>

int main(void) {
   printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "According to islower:",
      islower('p') ? "p is a " : "p is not a ", "lowercase letter",
      islower('P') ? "P is a " : "P is not a ", "lowercase letter",
      islower('5') ? "5 is a " : "5 is not a ", "lowercase letter",
      islower('!') ? "! is a " : "! is not a ", "lowercase letter");

   printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "According to isupper:",
      isupper('D') ? "D is an " : "D is not an ", "uppercase letter",
      isupper('d') ? "d is an " : "d is not an ", "uppercase letter",
      isupper('8') ? "8 is an " : "8 is not an ", "uppercase letter",
      isupper('$') ? "$ is an " : "$ is not an ", "uppercase letter");

   printf("%s%c\n%s%c\n%s%c\n%s%c\n",
      "u converted to uppercase is ", toupper('u'),
      "7 converted to uppercase is ", toupper('7'),
      "$ converted to uppercase is ", toupper('$'),
      "L converted to lowercase is ", tolower('L'));
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