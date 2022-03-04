#include "Fruit.h"
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
   if (name != nullptr) delete[] name;
   if (code != nullptr) delete[] code;
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
   }
   else {
      name = nullptr;
   }
}

//---------------------------------------------------------------------
// assignment operator for Fruit class
//---------------------------------------------------------------------
Fruit& Fruit::operator=(const Fruit& f) {
   if (f.name != nullptr) {
      for (int i = 0; i < MAX_NAME_LEN + 1; i++) {
         name[i] = f.name[i]; // deep copy fruit & passed in fruit
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
   int flag = 0;
   while (name[i] != '\n' || f.name[i] != '\0') {
      if (name[i] == f.name[i]) {
         i++; // the chars are equal, continue
      } else {
         return false;
      }
      flag = 1;
   }
   if (flag == 1) return true;
   else return false;
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
ostream& operator<< (ostream& out, Fruit& f) {
   if (f.name != nullptr) {
      out << setiosflags(ios::left) << setw(MAX_NAME_LEN) << f.name << " ";
      for (int i = 0; i < CODE_LEN; i++) {
         cout << f.code[i]; // cout PLU array char by char
      }
   }
   return out; // return the ostream
}

//---------------------------------------------------------------------
// Reads, assuming the name and PLU code will be strings of characters
// and they will be separated by white-space.
//---------------------------------------------------------------------
istream& operator>> (istream& in, Fruit& f) {
   string tmp;  // create new temp string for name
   string tmpC; // new temp string for PLU
   in >> tmp;   // write fruit name to tmp
   in >> tmpC;

   if (f.name != nullptr) {
      delete[] f.name;
   }
   f.name = new char[MAX_NAME_LEN + 1];
   f.code[MAX_NAME_LEN];

   for (int i = 0; i < tmp.length(); i++) {
      f.name[i] = tmp[i];  // assign tmp to name
   }
   f.name[tmp.length()] = '\0';
   for (int i = 0; i < CODE_LEN; i++) {
      f.code[i] = tmpC[i]; // assign tmp code to code
   }

   return in; // return the ostream
}