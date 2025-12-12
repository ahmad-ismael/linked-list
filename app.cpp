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

int main() {
    list l, l1, l2;
    l.orderInsert(0, 'A');
    l.orderInsert(20, 'B');
    l.orderInsert(-2, 'C');
    l.orderInsert(3, 'D');
    l.orderInsert(5, 'E');
    l.orderInsert(0, 'F');
    l.orderInsert(-10, 'G');
    l.orderInsert(-1, 'H');

    cout << "The Linked List Data (traverse): " << endl;
    l.traverse();

    cout << "Zeros count: " << countZeros(l) << endl;
    cout << "Data sum: " << sumData(l) << endl;

    cout << "############## SPLITING THE LIST" << endl;
    split(l,l1,l2);
    //cout << "L data after split:" << endl;
    //l.traverse();
    cout << "L1 data after split:" << endl;
    l1.traverse();
    cout << "L2 data after split:" << endl;
    l2.traverse();
    

    return 0;
}