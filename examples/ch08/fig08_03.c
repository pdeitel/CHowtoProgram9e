// fig08_03.c
// Using functions isspace, iscntrl, ispunct, isprint and isgraph
#include <ctype.h>
#include <stdio.h>

int main(void) {
   printf("%s\n%s%s%s\n%s%s%s\n%s%s\n\n", "According to isspace:", 
       "Newline", isspace('\n') ? " is a " : " is not a ",
       "whitespace character", 
       "Horizontal tab", isspace('\t') ? " is a " : " is not a ", 
       "whitespace character",
       isspace('%') ? "% is a " : "% is not a ", "whitespace character");

   printf("%s\n%s%s%s\n%s%s\n\n", "According to iscntrl:", 
       "Newline", iscntrl('\n') ? " is a " : " is not a ",
       "control character",  
       iscntrl('$') ? "$ is a " : "$ is not a ", "control character");

   printf("%s\n%s%s\n%s%s\n%s%s\n\n", "According to ispunct:",
       ispunct(';') ? "; is a " : "; is not a ", "punctuation character",
       ispunct('Y') ? "Y is a " : "Y is not a ", "punctuation character",
       ispunct('#') ? "# is a " : "# is not a ", "punctuation character");
       
   printf("%s\n%s%s\n%s%s%s\n\n", "According to isprint:",
       isprint('$') ? "$ is a " : "$ is not a ", "printing character", 
       "Alert", isprint('\a') ? " is a " : " is not a ",
       "printing character");

   printf("%s\n%s%s\n%s%s%s\n",  "According to isgraph:",
       isgraph('Q') ? "Q is a " : "Q is not a ",
       "printing character other than a space",
       "Space", isgraph(' ') ? " is a " : " is not a ",
       "printing character other than a space");
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