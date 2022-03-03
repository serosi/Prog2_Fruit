//---------------------------------------------------------------------
// Name:    Maggie Nordquist
// Project: Maintain and Manipulate a Catalog of Fruit products.
// Purpose: Run Catalog, with Memory Leak detection.
//---------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Fruit.h"

int main() {
   int num = 10;
   Fruit* nFruit = new Fruit[num];

   for (int i = 0; i < 10; i++) {
      cin >> nFruit[i];
   }
   for (int i = 0; i < 10; i++) {
      cout << nFruit[i] << endl;
   }



      


   
}