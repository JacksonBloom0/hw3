#include "heap.h"
#include <iostream>

using namespace std;
int main() {
    Heap<int> h(2);
    cout << "H is empty == " << boolalpha << h.empty() << endl;
    h.push(1);
    h.push(2);
    h.push(3);
    h.push(12);
    h.push(9);
    h.push(5);
    h.push(18);
    h.push(20);
    h.push(25);
    h.push(0);
    h.push(99);
    h.push(72);
    h.push(4);
    h.push(11);
    h.push(30);
    cout << "h.size == " << h.size() << endl;
    cout << "Printing h = " << endl;
    h.print();
    cout << endl;
    cout << "H is empty == " << boolalpha << h.empty() << endl;

    cout << "h.top == " <<  h.top() << endl;
    int n = h.size();
    for (int i = 0; i < n; i++) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;
    return 0;
}