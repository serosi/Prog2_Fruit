#ifndef _CATALOG_CLASS
#define _CATALOG_CLASS

#include "LList.h"
#include <iostream>

//typedef InfoType Catalog;

class Catalog {
public:
   //---------------------------------------------------------------------
   // default constructor for Catalog class
   //---------------------------------------------------------------------
   Catalog();

   //---------------------------------------------------------------------
   // destructor for Catalog class
   //---------------------------------------------------------------------
   ~Catalog();

   //---------------------------------------------------------------------
   // Runs the Catalog class and executes commands defined in private
   // methods of the Catalog class, I, D, P, and S.
   //---------------------------------------------------------------------
   void Run();

private:
   LList FruitList;
   //---------------------------------------------------------------------
   // Inserts a name into the catalog
   //---------------------------------------------------------------------
   void InsertName();

   //---------------------------------------------------------------------
   // Deletes a specific name from the catalog
   //---------------------------------------------------------------------
   void DeleteName();

   //---------------------------------------------------------------------
   // Prints out the catalog
   //---------------------------------------------------------------------
   void PrintCatalog();

   //---------------------------------------------------------------------
   // Stops the program
   //---------------------------------------------------------------------
   void Stop();
};




#endif