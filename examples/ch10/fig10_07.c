// fig10_07.c
// Representing cards with bit fields in a struct
#include <stdio.h>
#define CARDS 52

// bitCard structure definition with bit fields
struct bitCard {                          
   unsigned int face : 4; // 4 bits; 0-15 
   unsigned int suit : 2; // 2 bits; 0-3  
   unsigned int color : 1; // 1 bit; 0-1  
};                                        

typedef struct bitCard Card; // new type name for struct bitCard   

void fillDeck(Card * const deck); // prototype
void deal(const Card * const deck); // prototype

int main(void) {
   Card deck[CARDS]; // create array of Cards

   fillDeck(deck);

   puts("Card values 0-12 correspond to Ace through King");
   puts("Suit values 0-3 correspond to Hearts, Diamonds, Clubs and Spades");
   puts("Color values 0-1 correspond to red and black\n");
   deal(deck);
}

// initialize Cards
void fillDeck(Card * const deck) {
   // loop through deck
   for (size_t i = 0; i < CARDS; ++i) { 
      deck[i].face = i % (CARDS / 4); 
      deck[i].suit = i / (CARDS / 4); 
      deck[i].color = i / (CARDS / 2);
   }
}

// output cards in two-column format; cards 0-25 indexed with 
// k1 (column 1); cards 26-51 indexed with k2 (column 2)
void deal(const Card * const deck) {
   // loop through deck
   for (size_t k1 = 0, k2 = k1 + 26; k1 < CARDS / 2; ++k1, ++k2) { 
      printf("Card:%3d  Suit:%2d  Color:%2d   ",
         deck[k1].face, deck[k1].suit, deck[k1].color);
      printf("Card:%3d  Suit:%2d  Color:%2d\n",
         deck[k2].face, deck[k2].suit, deck[k2].color);
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
