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


   if (list == nullptr) {
      list = tmp;
      return true;
   }

   Node* curr = list;
   Node* prev = nullptr;

   while (curr != nullptr) {
      if (*x_ptr == *curr->infoPtr) {
         delete tmp;
         return false;
      }
      if (*x_ptr < *curr->infoPtr) {
         if (prev == nullptr) {
            tmp->next = list;
            list = tmp;
            return true;
         }
         else {
            tmp->next = curr;
            prev->next = tmp;
            return true;
         }
      }
      prev = curr;
      curr = curr->next;
   }

   tmp->next = curr;
   prev->next = tmp;
   //delete tmp;
   //delete curr;
   //delete prev;
   return true;


}

//---------------------------------------------------------------------
// Deletes an item from the linked list
//---------------------------------------------------------------------
bool LList::Delete(const InfoType& x) {
   Node* tmp = nullptr;
   Node* curr = list;
   

      while (curr != nullptr) {
         if (*curr->infoPtr == x) {
            if (tmp == nullptr) {
               list = list->next;
               delete curr;
               return true;
            }
            else {
               tmp->next = curr->next;
               delete curr;
               return true;
            }
         }
         tmp = curr;
         curr = curr->next;
      }
   
   //delete tmp;
   return false;
}

//---------------------------------------------------------------------
// Displays the entire linked list
//---------------------------------------------------------------------
void LList::Display(ostream& out_stream) const {
   if (list != nullptr)                          // traverse the list and adds the data to the output stream
   {
      Node* curr = list;
      while (curr != nullptr) {
         out_stream << *curr->infoPtr << " " << endl;
         curr = curr->next;
      }
      out_stream;
   }

}