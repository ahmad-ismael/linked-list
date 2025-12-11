#include <iostream>
#include "list.h"
using namespace std;
using std::string;

list::list(){
    head = cursor = prev = NULL;
}

list::~list(){
    makeListEmpty();
}

bool list::isListEmpty() const{
    return (head == NULL);
}

bool list::curIsEmpty() const{
    return (cursor == NULL);
}

bool list::atFirst() const{
    return (cursor == head);
}

bool list::atEnd() const{
    if(isListEmpty()) {
        if(curIsEmpty())
            return true;
        else 
            return false;
    }
    else {
        return (cursor != NULL && cursor->next == NULL);
    }
}

void list::advance(){
    if(!curIsEmpty()) {
        prev = cursor;
        cursor = cursor->next;
    }
}

void list::toFirst(){
    cursor = head;
}

void list::toEnd(){
    if(!isListEmpty()){
        toFirst();
        while(cursor->next != NULL){
            advance();
        }
    }
}

int list::listSize() const{
    node* p;
    int s = 0;
    if(!isListEmpty()) {
        toFirst();
        p = cursor;
        while(p != NULL) {
            s++;
            p = p->next;
        }
    }
    return s;
}

void list::updateData(const char &d){
    cursor->data = d;
}

void list::updateKey(const int &k){
    cursor->key = k;
}

void list::retrieveData(char &d) const{
    d = cursor->data;
}

void list::retrieveKey(int &k) const{
    k = cursor->key;
}

void list::insertFirst(const int &k, const char &d){
    node* p = new node;
    p->key = k;
    p->data = d;
    p->next = head;
    head = p;
    cursor = p;
    prev = NULL;
}

void list::insertAfter(const int &k, const char &d){
    node* p = new node;
    p->key = k;
    p->data = d;
    p->next = cursor->next;
    cursor->next = p;
    prev = cursor;
    cursor = p;
}

void list::insertBefore(const int &k, const char &d){
    node* p = new node;
    p->key = k;
    p->data = d;
    p->next = cursor;
    prev->next = p;
    cursor = p;
}

void list::insertEnd(const int &k, const char &d){
    if(isListEmpty())
        insertFirst(k, d);
    else { 
        toEnd();
        insertAfter(k, d);
    }
}

void list::deleteNode(){
    node * p;
    p = cursor;

    if(!curIsEmpty()) {
        if(atFirst()) {
            cursor = cursor->next;
            head = cursor;
            delete p;
        } else {
            cursor = cursor->next;
            prev->next = cursor;
        }
    }    
}

void list::deleteFirst(){
    node * p;
    p = head;

    toFirst();
    
    head = head->next;
    cursor = head;
    prev = NULL;
    delete p;
}

void list::deleteEnd(){
    if(!isListEmpty()) {
        toEnd();
        deleteNode();
    }
}

void list::makeListEmpty(){
    toFirst();
    while(!isListEmpty())
        deleteNode();

    // if(!isListEmpty()) {
    //     toFirst();
    //     while(cursor != NULL) {
    //         node* p;
    //         p = cursor;
    //         cursor = cursor->next;
    //         delete p;
    //     }
    // }
    // head = NULL;
    // prev = NULL;
}

bool list::search(int k){
    bool found = false;
    toFirst();
    while(!found && !curIsEmpty()) {
        if (k == cursor->key){
            found = true;
        }
        else
            advance();
    }
    return found;
}

bool list::orderInsert(const char &d, const int &k){
    // Insert in ascending order based on key
}

void list::traverse(){
    toFirst();
    while(cursor != NULL) {
        cout << cursor->key << " - " << cursor->data << endl;
        advance();
    }
}