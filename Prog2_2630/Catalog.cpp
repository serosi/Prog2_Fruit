#include "Catalog.h"
#include <iostream>
#include "LeakWatcher.h"
using namespace std;

//---------------------------------------------------------------------
// default constructor for Catalog class
//---------------------------------------------------------------------
Catalog::Catalog() {

}

//---------------------------------------------------------------------
// destructor for Catalog class
//---------------------------------------------------------------------
Catalog::~Catalog() {

}

//---------------------------------------------------------------------
// Runs the Catalog class and executes commands defined in private
// methods of the Catalog class, I, D, P, and S.
//---------------------------------------------------------------------
void Catalog::Run() {
   char cmd;
   int numData;

   cin >> numData;

   cout << "There are " << numData << " types of fruits initially in the list." << endl;
   cout << "They will be read in and inserted in the list in order." << endl;



   switch (cmd) {
   case 'I':
      //LList::Insert();
      break;
   case 'D':
      break;
   case 'P':
      break;
   case 'S':
      break;
   default:
      cout << "Invalid command!" << endl;
   }
}


//---------------------------------------------------------------------
// Inserts a name into the catalog
//---------------------------------------------------------------------
void Catalog::InsertName(InfoType* name) {

}

//---------------------------------------------------------------------
// Deletes a specific name from the catalog
//---------------------------------------------------------------------
void Catalog::DeleteName(InfoType* name) {

}

//---------------------------------------------------------------------
// Prints out the catalog
//---------------------------------------------------------------------
void Catalog::PrintCatalog() {

}

//---------------------------------------------------------------------
// Stops the program
//---------------------------------------------------------------------
void Catalog::Stop() {

}