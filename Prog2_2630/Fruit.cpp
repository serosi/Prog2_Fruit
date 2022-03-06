#include "Fruit.h"
#include <string>
#include <istream>
#include "LeakWatcher.h"
using namespace std;

//---------------------------------------------------------------------
// default constructor for Fruit class
//---------------------------------------------------------------------
Fruit::Fruit() {
   name = nullptr;
   code[0] = ' ';
}

//---------------------------------------------------------------------
// destructor for Fruit class
//---------------------------------------------------------------------
Fruit::~Fruit() {
   delete name;
}

//---------------------------------------------------------------------
// copy constructor for Fruit class
//---------------------------------------------------------------------
Fruit::Fruit(const Fruit& copyIn) {
   if (copyIn.name != nullptr) {
      name = new char[MAX_NAME_LEN + 1];
      for (int i = 0; i < MAX_NAME_LEN + 1; i++) {
         name[i] = copyIn.name[i]; // creates deep copy of Fruit object
      }
      name[MAX_NAME_LEN] = '\0';
      for (int i = 0; i < CODE_LEN; i++) {
         code[i] = copyIn.code[i];
      }
   }
   else {
      name = nullptr;
   }
}

//---------------------------------------------------------------------
// assignment operator for Fruit class
//---------------------------------------------------------------------
Fruit& Fruit::operator=(const Fruit& f) {
   if (this != &f) {
      *name = *f.name;
      for (int i = 0; i < CODE_LEN; i++) {
         code[i] = f.code[i];
      }
   }
   return *this;
}

//---------------------------------------------------------------------
// returns true if name is lexicographically (dictionary order) less 
// than the name of the passed Fruit, false otherwise.
//---------------------------------------------------------------------
bool Fruit::operator< (const Fruit& f) {
   int i = 0;
   while (name[i] != '\0' && f.name[i] != '\0') {
      if (name[i] > f.name[i]) {
         return false; // char is greater than other char
      }
      if (name[i] < f.name[i]) {
         return true;  // char is less than other char
      }
      i++; // if chars are not > or <, increment & check again
   }
   return false; // default return value
}

//---------------------------------------------------------------------
// returns true if name is the same as the name of the passed Fruit, 
// false otherwise.
//---------------------------------------------------------------------
bool Fruit::operator== (const Fruit& f) {
   int i = 0;
   bool flag = true;
   while (f.name[i] != '\0' && flag) {
      if (name[i] == f.name[i])
         flag;
      else {
         flag = false;
      }
         
      i++;    
   }
   return flag;
}

//---------------------------------------------------------------------
// returns true if name is the not the same as the name of the passed 
// Fruit, false otherwise (This is a one liner!)
//---------------------------------------------------------------------
bool Fruit::operator!= (const Fruit& f) {
   if (!operator==(f)) return true; else return false;
}

//---------------------------------------------------------------------
// writes the name, left-justified, in a field of 30, then a space, 
// then the PLU code.
//---------------------------------------------------------------------
ostream& operator<< (ostream& out, const Fruit& f) {
   out << setiosflags(ios::left) << setw(MAX_NAME_LEN + 1) << f.name; // printing format and prints the fruit name, has a null character 
                                                                       // so no need to iterate letter by letter 
   for (int i = 0; i < CODE_LEN; i++)                              // adds the PLU code from the code array to the output stream 
   {                                                                      // character by character
      out << f.code[i];
   }

   return out;
}

//---------------------------------------------------------------------
// Reads, assuming the name and PLU code will be strings of characters
// and they will be separated by white-space.
//---------------------------------------------------------------------
istream& operator>> (istream& in, Fruit& f) {
   string tmp; 
   in >> tmp;

   if (f.name != nullptr) {
      delete f.name; 
   }

   f.name = new char[tmp.length() + 1];

   for (int i = 0; i < tmp.length(); i++) {
     f.name[i] = tmp.at(i);
   }
 
   f.name[tmp.length()] = '\0'; // set end of name to be null terminating char

   char tmpC; // temp char array for PLU code
   for (int i = 0; i < CODE_LEN; i++) {
      in >> tmpC;
      f.code[i] = tmpC;
   }

   return in;
}