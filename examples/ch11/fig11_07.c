// fig11_07.c
// Transaction-processing program reads a random-access file sequentially, 
// updates data already written to the file, creates new data to 
// be placed in the file, and deletes data previously stored in the file.
#include <stdio.h>

// clientData structure definition               
struct clientData {                              
   int account; 
   char lastName[15]; 
   char firstName[10];
   double balance; 
}; 

// prototypes
int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

int main(void) {
   FILE *cfPtr = NULL; // accounts.dat file pointer

   // fopen opens the file; exits if file cannot be opened
   if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL) {
      puts("File could not be opened.");
   } 
   else { 
      int choice = 0; // user

      // enable user to specify action
      while ((choice = enterChoice()) != 5) { 
         switch (choice) { 
            case 1: // create text file from record file
               textFile(cfPtr);
               break;
            case 2: // update record
               updateRecord(cfPtr);
               break;
            case 3: // create record
               newRecord(cfPtr);
               break;
            case 4: // delete existing record
               deleteRecord(cfPtr);
               break;
            default: // display message for invalid choice
               puts("Incorrect choice");
               break;
         } 
      } 

      fclose(cfPtr); // fclose closes the file
   } 
} 

// create formatted text file for printing 
void textFile(FILE *readPtr) {
   FILE *writePtr = NULL; // accounts.txt file pointer

   // fopen opens the file; exits if file cannot be opened
   if ((writePtr = fopen("accounts.txt", "w")) == NULL) {
      puts("File could not be opened.");
   } 
   else { 
      rewind(readPtr); // sets pointer to beginning of file
      fprintf(writePtr, "%-6s%-16s%-11s%10s\n", 
         "Acct", "Last Name", "First Name","Balance");

      // copy all records from random-access file into text file
      while (!feof(readPtr)) { 
         // create clientData with default information
         struct clientData client = {0, "", "", 0.0};
         size_t result = 
            fread(&client, sizeof(struct clientData), 1, readPtr);

         // write single record to text file
         if (result != 0 && client.account != 0) {
            fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n", client.account, 
               client.lastName, client.firstName, client.balance); 
         } 
      } 

      fclose(writePtr); // fclose closes the file
   } 
} 

// update balance in record

void updateRecord(FILE *fPtr) { 
   // obtain number of account to update
   printf("%s", "Enter account to update (1 - 100): ");
   int account = 0; // account number
   scanf("%d", &account);

   // move file pointer to correct record in file              
   fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);

   // read record from file
   struct clientData client = {0, "", "", 0.0}; 
   fread(&client, sizeof(struct clientData), 1, fPtr);

   // display error if account does not exist
   if (client.account == 0) {
      printf("Account #%d has no information.\n", account);
   } 
   else { // update record
      printf("%-6d%-16s%-11s%10.2f\n\n", client.account, client.lastName,
         client.firstName, client.balance);
      
      // request transaction amount from user 
      printf("%s", "Enter charge (+) or payment (-): ");
      double transaction = 0.0; // transaction amount
      scanf("%lf", &transaction);
      client.balance += transaction; // update record balance
      
      printf("%-6d%-16s%-11s%10.2f\n", client.account, client.lastName, 
         client.firstName, client.balance);
      
      // move file pointer to correct record in file             
      fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET); 

      // write updated record over old record in file         
      fwrite(&client, sizeof(struct clientData), 1, fPtr);
   } 
} 

// create and insert record
void newRecord(FILE *fPtr) { 
   // obtain number of account to create
   printf("%s", "Enter new account number (1 - 100): ");
   int account = 0; // account number
   scanf("%d", &account);

   // move file pointer to correct record in file                 
   fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);

   // read record from file 
   struct clientData client = {0, "", "", 0.0}; 
   fread(&client, sizeof(struct clientData), 1, fPtr);

   // display error if account already exists
   if (client.account != 0) {
      printf("Account #%d already contains information.\n",
         client.account);
   } 
   else { // create record
      // user enters last name, first name and balance
      printf("%s", "Enter lastname, firstname, balance\n? ");
      scanf("%14s%9s%lf", &client.lastName, &client.firstName, 
         &client.balance);

      client.account = account;
      
      // move file pointer to correct record in file   
      fseek(fPtr, (client.account - 1) * sizeof(struct clientData), 
         SEEK_SET);                                                

      // insert record in file 
      fwrite(&client, sizeof(struct clientData), 1, fPtr);
   } 
} 

// delete an existing record
void deleteRecord(FILE *fPtr) {
   // obtain number of account to delete
   printf("%s", "Enter account number to delete (1 - 100): ");
   int account = 0; // account number
   scanf("%d", &account);

   // move file pointer to correct record in file    
   fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);

   // read record from file 
   struct clientData client = {0, "", "", 0.0}; 
   fread(&client, sizeof(struct clientData), 1, fPtr);

   // display error if record does not exist
   if (client.account == 0) {
      printf("Account %d does not exist.\n", account);
   } 
   else { // delete record
      // move file pointer to correct record in file 
      fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);

      struct clientData blankClient = {0, "", "", 0}; // blank client
   
      // replace existing record with blank record
      fwrite(&blankClient, sizeof(struct clientData), 1, fPtr); 
   } 
} 

// enable user to input menu choice
int enterChoice(void) {
   // display available options
   printf("%s", "\nEnter your choice\n"
      "1 - store a formatted text file of accounts called\n"
      "    \"accounts.txt\" for printing\n"
      "2 - update an account\n"
      "3 - add a new account\n"
      "4 - delete an account\n"
      "5 - end program\n? ");

   int menuChoice = 0; // variable to store user
   scanf("%d", &menuChoice); // receive choice from user
   return menuChoice;
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