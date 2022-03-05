#include "Catalog.h"
#include "LList.h"
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
   char cmd = ' ';
   int numData;
   bool stopped = false;

   cin >> numData;

   cout << "There are " << numData << " types of fruits initially in the list." << endl;
   cout << "They will be read in and inserted in the list in order." << endl;

   for (int i = 0; i < numData; i++) {
      InsertName();
   }
   
   while (!stopped) {
      cin >> cmd;
      switch (cmd) {
      case 'I':
         InsertName();
         break;
      case 'D':
         DeleteName();
         break;
      case 'P':
         PrintCatalog();
         break;
      case 'S':
         Stop();
         stopped = true;
         break;
      default:
         cout << "Invalid command!" << endl;
      }
   }
   
}


//---------------------------------------------------------------------
// Inserts a name into the catalog
//---------------------------------------------------------------------
void Catalog::InsertName() {
   Fruit* fruitObj = new Fruit;
   cin >> *fruitObj;

   Fruit* copyfruitObj = new Fruit(*fruitObj);

   if (FruitList.Insert(fruitObj)) {
      cout << "Added to list:     " << *copyfruitObj << endl;
   }
   else {
      cout << "Already in list:   " << *copyfruitObj << endl;
   }
   delete copyfruitObj;
}

//---------------------------------------------------------------------
// Deletes a specific name from the catalog
//---------------------------------------------------------------------
void Catalog::DeleteName() {
   Fruit deleteFruit;
   cin >> deleteFruit;

   if (FruitList.Delete(deleteFruit)) {
      cout << "Deleted from list: " << deleteFruit << endl;
   }
   else {
      cout << "Was not in list:   " << deleteFruit << endl;
   }
}

//---------------------------------------------------------------------
// Prints out the catalog
//---------------------------------------------------------------------
void Catalog::PrintCatalog() {
   cout << "\nBelow are the fruits currently in the list" << endl;
   FruitList.Display(cout);
}

//---------------------------------------------------------------------
// Stops the program
//---------------------------------------------------------------------
void Catalog::Stop() {
   cout << "Normal Termination of program 2!" << endl;
}