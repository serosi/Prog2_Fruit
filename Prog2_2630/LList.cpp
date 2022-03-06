#include "LList.h"
#include "LeakWatcher.h"
using namespace std;

//---------------------------------------------------------------------
// destructor for Linked List class
//---------------------------------------------------------------------
LList::~LList() {
   Node* tmp;
   while (list != nullptr) {
      tmp = list;
      list = tmp->next;
      delete tmp;
   }
}

//---------------------------------------------------------------------
// Checks if the linked list is empty
//---------------------------------------------------------------------
bool LList::IsEmpty() const {
   if (list != nullptr) {
      return false;
   }
   else
      return true;
}

//---------------------------------------------------------------------
// Inserts an item into the linked list
//---------------------------------------------------------------------
bool LList::Insert(InfoType* x_ptr) {
   Node* tmp = new Node(x_ptr);

   if (list == nullptr) { // if the list is empty, add the first item
      list = tmp;
      return true;
   }

   Node* curr = list;
   Node* prev = nullptr;

   while (curr != nullptr) {
      if (*x_ptr == *curr->infoPtr) { // if the item already exists
         delete tmp;
         return false; // item was not added
      }
      if (*x_ptr < *curr->infoPtr) { // if the item wanting to be added is less than curr
         if (prev == nullptr) {
            tmp->next = list; // if the item is going to be added at the start of the list
            list = tmp;
            return true;
         }
         else {
            tmp->next = curr; // if them item is going to be added anywhere else in the list
            prev->next = tmp;
            return true;
         }
      }
      prev = curr; // traverse to the next item in the list and check again
      curr = curr->next;
   }

   tmp->next = curr;
   prev->next = tmp;

   return true;
}

//---------------------------------------------------------------------
// Deletes an item from the linked list
//---------------------------------------------------------------------
bool LList::Delete(const InfoType& x) {
   Node* tmp = nullptr;
   Node* curr = list;
   
      while (curr != nullptr) {
         if (*curr->infoPtr == x) { // found the item to be deleted
            if (tmp == nullptr) {
               list = list->next;
               delete curr;
               return true; // item was deleted
            }
            else {
               tmp->next = curr->next;
               delete curr;
               return true;
            }
         }
         tmp = curr;
         curr = curr->next; // traverse to next item in list and check again
      }
   
   return false; // item was not deleted
}

//---------------------------------------------------------------------
// Displays the entire linked list
//---------------------------------------------------------------------
void LList::Display(ostream& out_stream) const {
   if (list != nullptr) { // displays the list if the list is not empty
      Node* curr = list;
      while (curr != nullptr) {
         out_stream << *curr->infoPtr << endl; // displays list in order
         curr = curr->next;
      }
      out_stream;
   }
}