#include "Catalog.h"
#include "LList.h"
#include <iostream>
#include "LeakWatcher.h"
using namespace std;

//---------------------------------------------------------------------
// default constructor for Catalog class
//---------------------------------------------------------------------
Catalog::Catalog() {
   FruitList;
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
   char cmd = ' '; // user defined command
   int numData; // number of fruits to be initially inserted
   bool stopped = false; // loop program while false

   cin >> numData;

   cout << "There are " << numData << " types of fruits initially in the list." << endl;
   cout << "They will be read in and inserted in the list in order.";

   for (int i = 0; i < numData; i++) {
      InsertName(); // insert the initil items
   }

   cout << endl;
   
   while (!stopped) {
      cin >> cmd;
      switch (cmd) {
      case 'I': // insert command
         InsertName();
         cout << endl;
         break;
      case 'D': // delete command
         DeleteName();
         break;
      case 'P': // print command
         PrintCatalog();
         break;
      case 'S': // stops the program
         Stop();
         stopped = true;
         break;
      default:
         cout << "\nInvalid command!" << endl;
      }
   }
}


//---------------------------------------------------------------------
// Inserts a name into the catalog
//---------------------------------------------------------------------
void Catalog::InsertName() {
   Fruit* fruitObj = new Fruit;
   cin >> *fruitObj;
   // creates a new copy of fruit object because object no longer exists
   Fruit* copyfruitObj = new Fruit(*fruitObj);

   if (FruitList.Insert(fruitObj)) {
      cout << "\nAdded to list:     " << *copyfruitObj;
   }
   else {
      cout << "\nAlready in list:   " << *copyfruitObj;
   }
   delete copyfruitObj;
}

//---------------------------------------------------------------------
// Deletes a specific name from the catalog
//---------------------------------------------------------------------
void Catalog::DeleteName() {
   Fruit deleteFruit;
   cin >> deleteFruit;

   if (FruitList.Delete(deleteFruit)) { // delete fruit object from list
      cout << "\nDeleted from list: " << deleteFruit;
   }
   else {
      cout << "\nWasn't in list:    " << deleteFruit;
   }
   cout << endl;
}

//---------------------------------------------------------------------
// Prints out the catalog
//---------------------------------------------------------------------
void Catalog::PrintCatalog() {
   cout << "\nBelow are the fruits currently in the list" << endl;
   FruitList.Display(cout); // print entire catalog
}

//---------------------------------------------------------------------
// Stops the program
//---------------------------------------------------------------------
void Catalog::Stop() { // stop program
   cout << "\nNormal Termination of program 2!" << endl;
}