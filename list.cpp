#include <iostream>
#include <cstddef>
#include "list.h"
using namespace std;

list::list(){
    head = cursor = prev = NULL;
}

list::~list(){
    makeListEmplt();
}

bool list::isListEmpty() const{
    return (head == NULL);
}

bool list::curIsEmpty() const{
    return (cursor == NULL);
}

void list::toFirst(){
    cursor = head;
}

bool list::atFirst() const{
    return (cursor == head);
}

void list::advance(){
    if(!curIsEmpty()) {
        prev = cursor;
        cursor = cursor->next;
    }
}

void list::toEnd(){
    if(!isListEmpty()){
        toFirst();
        while(cursor->next != NULL){
            advance();
        }
    }
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

int list::listSize(){
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

void list::updateData(char d){
    cursor->data = d;
}

void list::updateKey(int k){
    cursor->key = k;
}

char list::retieveDate(){
    return cursor->data;
}

void list::retieveDate(char &x){
    x = cursor->data;
}

void list::insertFirst(int k, char d){
    node* p = new node;
    p->key = k;
    p->data = d;
    p->next = head;
    head = p;
    cursor = p;
    prev = NULL;
}

void list::insertAfter(int k, char d){
    node* p = new node;
    p->key = k;
    p->data = d;
    p->next = cursor->next;
    cursor->next = p;
    prev = cursor;
    cursor = p;
}

void list::insertBefore(int k, char d){
    node* p = new node;
    p->key = k;
    p->data = d;
    p->next = cursor;
    prev->next = p;
    cursor = p;
}

void list::insertEnd(int k, char d){
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

void list::makeListEmplt(){
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

void list::traverse(){
    toFirst();
    while(cursor != NULL) {
        cout << cursor->key << " - " << cursor->data << endl;
        advance();
    }
}