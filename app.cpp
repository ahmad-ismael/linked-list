/**
 * Name: احمد محمود اسماعيل احمد
 * code: 202400597
 * project: SIMPLE LINKED LIST
*/

#include <iostream>
#include "list.h"
using namespace std;

int main() {
    int k;
    list l;
    l.insertFirst(1, 'A');
    l.insertAfter(2, 'B');
    l.insertAfter(3, 'C');
    l.insertEnd(4, 'D');

    cout << "Search for key : ";
    cin >> k;
    cout << (l.search(k) ? "Found" : "Not Found") << endl;
    cout << "---- End Search ----" << endl;


    cout << "The Liked List Data (traverse): " << endl;
    l.traverse();

    return 0;
}