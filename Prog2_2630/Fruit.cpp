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
   //if (name != nullptr) delete[] name;
   //if (code != nullptr) delete[] code;
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
   //if (f.name != nullptr) {
   //   out << setiosflags(ios::left) << setw(MAX_NAME_LEN+1) << f.name << " ";
   //   for (int i = 0; i < CODE_LEN; i++) {
   //      out << f.code[i]; // cout PLU array char by char
   //   }
   //}
   //return out; // return the ostream
   out << setiosflags(ios::left) << setw(MAX_NAME_LEN) << f.name; // printing format and prints the fruit name, has a null character 
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
   //string tmp;  // create new temp string for name
   //string tmpC; // new temp string for PLU
   //in >> tmp;   // write fruit name to tmp
   //in >> tmpC;

   //if (f.name != nullptr) {
   //   delete[] f.name;
   //}
   //f.name = new char[MAX_NAME_LEN + 1];
   //f.code[MAX_NAME_LEN];

   //for (int i = 0; i < tmp.length(); i++) {
   //   f.name[i] = tmp[i];  // assign tmp to name
   //}
   //f.name[tmp.length()] = '\0';
   //for (int i = 0; i < CODE_LEN; i++) {
   //   f.code[i] = tmpC[i]; // assign tmp code to code
   //}

   string fruitName;                                                      // holds the fruit name in a string buffer
   in >> fruitName;                                                       // reads in the fruit name

   if (f.name != nullptr)                                                 // checks for self assignment 
      delete f.name;                                                     // deletes the pointer if so

   f.name = new char[fruitName.length() + 1];                             // makes a character array to hold every letter of the fruit name  
                                                                          // and a null character
   for (int i = 0; i < fruitName.length(); i++)                           // assigns the caratcters
      f.name[i] = fruitName.at(i);
   f.name[fruitName.length()] = '\0';

   char fruitCode;                                                        // holds the number of the PLU code
   for (int i = 0; i < CODE_LEN; i++)                              // reads the numbers of the PLU and adds them to the code array
   {
      in >> fruitCode;
      f.code[i] = fruitCode;
   }



   return in; // return the ostream
}