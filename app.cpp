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
    l.insertFirst(1, 'A');
    l.insertAfter(2, 'B');
    l.insertAfter(3, 'C');
    l.insertEnd(4, 'D');

    cout << l.search(3) << endl;
    cout << l.search(5) << endl;

    l.traverse();

    return 0;
}