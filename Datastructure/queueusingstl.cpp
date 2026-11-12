#include <iostream>
#include <queue> // Required for STL queue

using namespace std;

int main() {
    // Declaring a queue of integers
    queue<int> q;

    // 1. push(element): Adds elements to the back
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Elements 10, 20, 30, and 40 have been pushed." << endl;

    // 2. empty(): Checks if the queue is empty
    if (!q.empty()) {
        cout << "The queue is NOT empty." << endl;
    }

    // 3. front(): Access the first element
    cout << "The element at the front is: " << q.front() << endl;

    // 4. back(): Access the last element
    cout << "The element at the back is: " << q.back() << endl;

    // 5. pop(): Deletes the first element (the one at the front)
    cout << "\n--- Deleting elements ---" << endl;
    while (!q.empty()) {
        cout << "Popping front element: " << q.front() << endl;
        q.pop();
    }

    // Final check
    if (q.empty()) {
        cout << "All elements deleted. Queue is now empty." << endl;
    }

    return 0;
}