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

bool list::listIsEmpty() const{
    return (head == NULL);
}

bool list::curIsEmpty() const{
    return (cursor == NULL);
}

bool list::atFirst() const{
    return (cursor == head);
}

bool list::atEnd() const{
    if(listIsEmpty())       return true;
    else if(curIsEmpty())   return false;
    else                    return (cursor->next == NULL);
}

void list::advance(){
    if(!curIsEmpty()) {
        prev = cursor;
        cursor = cursor->next;
    }
}

void list::toFirst(){
    cursor = head;
    prev = NULL;
}

void list::toEnd(){
    toFirst();
    if (!listIsEmpty())
        while (cursor->next != NULL)
            advance();
}

int list::listSize() const{
    node* p;
    int count = 0;

    p = head;
    while(p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

void list::updateData(const char &d){
    cursor->data = d;
}

void list::updateKey(const int &k){
    cursor->key = k;
}

void list::retrieveData(char &d, int &k) const{
    d = cursor->data;
    k = cursor->key;
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
	if(atFirst()) {
		insertFirst(k,d);
	}
    else {
        node* p = new node;
        p->key = k;
        p->data = d;

        p->next = cursor;
        prev->next = p;
        cursor = p;
    }
    
}

void list::insertEnd(const int &k, const char &d){
    if(listIsEmpty())
        insertFirst(k, d);
    else { 
        toEnd();
        insertAfter(k, d);
    }
}

void list::deleteNode(){
    if(!curIsEmpty()) {
        node * p;
        p = cursor;
        cursor = cursor->next;

        if(atFirst())
            head = cursor;
        else
            prev->next = cursor;

        delete p;
    }    
}

void list::deleteFirst(){
	if(! listIsEmpty()) {
        toFirst(); 
        deleteNode();
    }
}

void list::deleteEnd(){
    if(!listIsEmpty()) {
        toEnd();
        deleteNode();
    }
}

void list::makeListEmpty(){
    toFirst();
    while(!listIsEmpty())
        deleteNode();
}

bool list::search(int k){
    bool found = false;
    toFirst();
    while(!found && !curIsEmpty()) {
        if (k == cursor->key)
            found = true;
        else
            advance();
    }
    return found;
}

void list::orderInsert(const int &k, const char &d){
    toFirst();
    while(!curIsEmpty() && (k > cursor->key))
        advance();
        
    if(curIsEmpty())
        insertEnd(k,d);
    else
        insertBefore(k,d);
}

// void List::orderInsert(const char &d, const int &k)
// {
// 	toFirst();
// 	while ((cursor != NULL) && (k > cursor->key))
// 		advance();

// 	if (atFirst())  insertFirst(k,d);
// 	else insertBefore(k,d);
// }

void list::traverse(){
    log("TRAVERSE");
    toFirst();
    while(! curIsEmpty()) {
        log("TRAVERSE");
        cout << cursor->key << " - " << cursor->data << endl;
        advance();
    }
}

void list::log(const std::string &name) const {
    cout << name << " LOG ===> HEAD=" << head << ", CURSOR=" << cursor << ", PREV=" << prev << endl;
}