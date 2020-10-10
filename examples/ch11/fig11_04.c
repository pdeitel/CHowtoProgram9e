// fig11_04.c
// Creating a random-access file sequentially
#include <stdio.h>

// clientData structure definition          
struct clientData {    
   int account;          
   char lastName[15];  
   char firstName[10]; 
   double balance;     
};                     
 
int main(void) {
   FILE *cfPtr = NULL; // accounts.dat file pointer

   // fopen opens the file; exits if file cannot be opened
   if ((cfPtr = fopen("accounts.dat", "wb")) == NULL) {
      puts("File could not be opened.");
   } 
   else { 
      // create clientData with default information      
      struct clientData blankClient = {0, "", "", 0.0};
   
      // output 100 blank records to file                          
      for (int i = 1; i <= 100; ++i) {                             
         fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);
      }                                                            

      fclose (cfPtr); // fclose closes the file
   } 
} 


/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
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
