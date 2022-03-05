#ifndef _FRUIT_CLASS
#define _FRUIT_CLASS

#include <iostream>
#include <iomanip>
using namespace std;

//typedef char FruitType;

const int MAX_NAME_LEN = 30;
const int CODE_LEN = 4;

class Fruit {
private:
   char* name;          // allocate memory (use new) - null-terminated
   char code[CODE_LEN]; // NOT null-terminated (be careful!)
public:
   //---------------------------------------------------------------------
   // default constructor for Fruit class
   //---------------------------------------------------------------------
   Fruit();

   //---------------------------------------------------------------------
   // destructor for Fruit class
   //---------------------------------------------------------------------
   ~Fruit();

   //---------------------------------------------------------------------
   // copy constructor for Fruit class
   //---------------------------------------------------------------------
   Fruit(const Fruit& copyIn);

   //---------------------------------------------------------------------
   // assignment operator for Fruit class
   //---------------------------------------------------------------------
   Fruit& operator= (const Fruit& f);

   //---------------------------------------------------------------------
   // returns true if name is lexicographically (dictionary order) less 
   // than the name of the passed Fruit, false otherwise.
   //---------------------------------------------------------------------
   bool operator< (const Fruit& f);

   //---------------------------------------------------------------------
   // returns true if name is the same as the name of the passed Fruit, 
   // false otherwise.
   //---------------------------------------------------------------------
   bool operator== (const Fruit& f);

   //---------------------------------------------------------------------
   // returns true if name is the not the same as the name of the passed 
   // Fruit, false otherwise (This is a one liner!)
   //---------------------------------------------------------------------
   bool operator!= (const Fruit& f);

   //---------------------------------------------------------------------
   // writes the name, left-justified, in a field of 30, then a space, 
   // then the PLU code.
   //---------------------------------------------------------------------
   friend ostream& operator<< (ostream& out, const Fruit& f);

   //---------------------------------------------------------------------
   // Reads, assuming the name and PLU code will be strings of characters
   // and they will be separated by white-space.
   //---------------------------------------------------------------------
   friend istream& operator>> (istream& in, Fruit& f);
};




#endif