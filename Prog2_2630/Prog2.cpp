//---------------------------------------------------------------------
// Name:    Maggie Nordquist
// Project: Maintain and Manipulate a Catalog of Fruit products.
// Purpose: Run Catalog, with Memory Leak detection.
//---------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "LList.h"
#include "Fruit.h"

int main() {

   _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
   _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
   _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

   int num = 10;
   Fruit* nFruit = new Fruit[num];

   for (int i = 0; i < 10; i++) {
      cin >> nFruit[i];
   }
   for (int i = 0; i < 10; i++) {
      cout << nFruit[i] << endl;
   }

   
      


   
}