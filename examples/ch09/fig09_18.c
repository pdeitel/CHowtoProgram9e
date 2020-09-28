// fig09_18.c
// Reading and discarding characters from the input stream
#include <stdio.h>

int main(void) {
   int month = 0; 
   int day = 0;   
   int year = 0;  
   printf("%s", "Enter a date in the form mm-dd-yyyy: ");
   scanf("%d%*c%d%*c%d", &month, &day, &year);
   printf("month = %d  day = %d  year = %d\n\n", month, day, year);
   
   printf("%s", "Enter a date in the form mm/dd/yyyy: ");
   scanf("%d%*c%d%*c%d", &month, &day, &year);
   printf("month = %d  day = %d  year = %d\n", month, day, year);
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