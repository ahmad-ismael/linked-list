/**
 * Name: احمد محمود اسماعيل احمد
 * code: 202400597
 * project: SIMPLE LINKED LIST
*/

#include <iostream>
#include "list.h"
using namespace std;

int main() {
    list l;
    l.orderInsert(30, 'A');
    l.orderInsert(2, 'B');
    l.orderInsert(5, 'C');
    l.orderInsert(1, 'D');

    cout << "The Linked List Data (traverse): " << endl;
    l.traverse();

    return 0;
}