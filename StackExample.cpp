
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Accessing the top element
    cout << "Top element: " << myStack.top() << endl;

    // Removing the top element
    myStack.pop();

    // Checking if the stack is empty
    if (myStack.empty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack is not empty" << endl;
    }

    // Size of the stack
    cout << "Size of stack: " << myStack.size() << endl;

    return 0;
}
