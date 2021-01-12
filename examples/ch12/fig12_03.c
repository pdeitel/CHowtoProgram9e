// fig12_03.c
// Operating and maintaining a queue
#include <stdio.h>
#include <stdlib.h>

// self-referential structure                     
struct queueNode {                                 
   char data; // define data as a char             
   struct queueNode *nextPtr; // queueNode pointer 
};                                                 

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

// function prototypes
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void instructions(void);

int main(void) {
   QueueNodePtr headPtr = NULL; // initialize headPtr
   QueueNodePtr tailPtr = NULL; // initialize tailPtr
   char item = '\0'; // char input by user

   instructions(); // display the menu
   printf("%s", "? ");
   int choice = 0; // user's menu choice
   scanf("%d", &choice);

   // while user does not enter 3
   while (choice != 3) { 
      switch(choice) { 
         case 1: // enqueue value
            printf("%s", "Enter a character: ");
            scanf("\n%c", &item);
            enqueue(&headPtr, &tailPtr, item);
            printQueue(headPtr);
            break;
         case 2: // dequeue value
            // if queue is not empty
            if (!isEmpty(headPtr)) { 
               item = dequeue(&headPtr, &tailPtr);
               printf("%c has been dequeued.\n", item);
            } 

            printQueue(headPtr);
            break;
         default:
            puts("Invalid choice.\n");
            instructions();
            break;
      } 

      printf("%s", "? ");
      scanf("%d", &choice);
   } 

   puts("End of run.");
} 

// display program instructions to user
void instructions(void) {
   printf ("Enter your choice:\n"
           "   1 to add an item to the queue\n"
           "   2 to remove an item from the queue\n"
           "   3 to end\n");
} 

// insert a node at queue tail
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value) {
   QueueNodePtr newPtr = malloc(sizeof(QueueNode));

   if (newPtr != NULL) { // is space available?
      newPtr->data = value;
      newPtr->nextPtr = NULL;

      // if empty, insert node at head
      if (isEmpty(*headPtr)) {
         *headPtr = newPtr;
      } 
      else {
         (*tailPtr)->nextPtr = newPtr;

      } 

      *tailPtr = newPtr;
   } 
   else {
      printf("%c not inserted. No memory available.\n", value);
   } 
} 

// remove node from queue head
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
   char value = (*headPtr)->data;  
   QueueNodePtr tempPtr = *headPtr;
   *headPtr = (*headPtr)->nextPtr; 

   // if queue is empty
   if (*headPtr == NULL) {
      *tailPtr = NULL;
   } 

   free(tempPtr);
   return value;
} 

// return 1 if the queue is empty, 0 otherwise
int isEmpty(QueueNodePtr headPtr) {
   return headPtr == NULL;
} 

// print the queue
void printQueue(QueueNodePtr currentPtr) {
   if (currentPtr == NULL) { // if queue is empty
      puts("Queue is empty.\n");
   } 
   else { 
      puts("The queue is:");

      while (currentPtr != NULL) { // while not end of queue

         printf("%c --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      } 

      puts("NULL\n");
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
