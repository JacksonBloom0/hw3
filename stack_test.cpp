#include "stack.h"
#include <iostream>

using namespace std;
int main() {
    Stack<int> s;
    cout << "S is empty == " << boolalpha << s.empty() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "S.size == " << s.size() << endl;
    cout << "S = ";
    for (int item : s) {
        cout << item << " ";
    }
    cout << endl;
    cout << "S is empty == " << boolalpha << s.empty() << endl;

    cout << "S.top == " <<  s.top() << endl;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

}