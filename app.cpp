/**
 * Name: احمد محمود اسماعيل احمد
 * code: 202400597
 * project: SIMPLE LINKED LIST
*/

#include <iostream>
#include "list.h"
using namespace std;

int countZeros(list &l) {
    int count = 0, k;
    if(! l.listIsEmpty()) {
        l.toFirst();
        while(! l.curIsEmpty()) {
            l.retrieveKey(k);
            if(k == 0) count++;
            l.advance();
        }
    }
    return count;
}

int countEven(list &l) {
    int count = 0, k;
    if(! l.listIsEmpty()) {
        l.toFirst();
        while(! l.curIsEmpty()) {
            l.retrieveKey(k);
            if(k%2 == 0) count++;
            l.advance();
        }
    }
    return count;
}

int sumData(list &l) {
    int sum = 0, k;
    if(! l.listIsEmpty()) {
        l.toFirst();
        while(! l.curIsEmpty()) {
            l.retrieveKey(k);
            sum+=k;
            l.advance();
        }
    }
    return sum;
}

void split(list &l,list &l1,list &l2) {
    int k;
    char d;
    if(!l.listIsEmpty()) {
        l1.makeListEmpty();
        l2.makeListEmpty();
        l.toFirst();
        l.log("SPLIT");
        while(! l.curIsEmpty()) {
            l.retrieveKey(k);
            l.retrieveData(d);
            if(k >= 0) l1.insertEnd(k,d);
            else l2.insertEnd(k,d);
            l.deleteNode(); // fn will make advance
            //l.advance();
        }
        //l.makeListEmpty();
    }
}

void append(list &l,list &l1,list &l2) {
    int k;
    char d;

    l.makeListEmpty();

    l1.toFirst();
    while(! l1.curIsEmpty()) {
        l1.retrieveKey(k);
        l1.retrieveData(d);
        l.insertEnd(k,d);
        l1.advance();
    }

    l2.toFirst();
    while(! l2.curIsEmpty()) {
        l2.retrieveKey(k);
        l2.retrieveData(d);
        l.insertEnd(k,d);
        l2.advance();
    }
}

int main() {
    list l, lp, ln;
    l.orderInsert(0, 'A');
    l.orderInsert(20, 'B');
    l.orderInsert(-2, 'C');
    l.orderInsert(3, 'D');
    l.orderInsert(5, 'E');
    l.orderInsert(0, 'F');
    l.orderInsert(-10, 'G');
    l.orderInsert(-1, 'H');

    cout << "LIST SIZE: " << l.listSize() << endl;
    cout << "LIST SIZE (recursive): " << l.recursive_list_size() << endl;
    cout << "Zeros count: " << countZeros(l) << endl;
    cout << "Even count: " << countEven(l) << endl;
    cout << "Data sum: " << sumData(l) << endl;
    cout << endl;

    cout << "The Linked List Data (traverse): " << endl;
    l.traverse();
    cout << "The Linked List Data (recursive) ASC: " << endl;
    l.displayList(false);
    cout << "The Linked List Data (recursive) DESC: " << endl;
    l.displayList(true);
    cout << endl;
    
    cout << "############## SPLIT" << endl;
    split(l,lp,ln);
    cout << "L data after split:" << endl;
    l.traverse();
    cout << "LP data after split:" << endl;
    lp.traverse();
    cout << "LN data after split:" << endl;
    ln.traverse();
    cout << endl;
    
    cout << "############## APPEND" << endl;
    append(l,lp,ln);
    cout << "L data after append:" << endl;
    l.traverse();
    cout << "LP data after append:" << endl;
    lp.traverse();
    cout << "LN data after append:" << endl;
    ln.traverse();
    cout << endl;

    return 0;
}