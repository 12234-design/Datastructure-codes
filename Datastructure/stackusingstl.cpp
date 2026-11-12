#include <iostream>
#include <stack> // Required header for STL stack

using namespace std;

int main() {
    stack<int> s;
    cout << "--- Pushing Elements ---" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Pushed 10, 20, and 30 onto the stack." << endl;
    if (!s.empty()) {
        cout << "The stack is NOT empty." << endl;
    }

    // 2. top() - Accesses the element at the top without removing it
    cout << "The element at the top is: " << s.top() << endl;

    cout << "\n--- Popping Elements ---" << endl;
    
    // Using a loop to empty the stack and show elements
    while (!s.empty()) {
        // Display the top element
        cout << "Current Top: " << s.top() << " | ";
        
        // 3. pop() - Removes the top element (returns nothing)
        s.pop();
        cout << "Popped!" << endl;
    }

    // Checking status again
    if (s.empty()) {
        cout << "\nAll elements removed. The stack is now empty." << endl;
    }

    return 0;
}