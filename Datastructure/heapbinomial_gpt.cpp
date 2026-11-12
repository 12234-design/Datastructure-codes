#include <iostream>
using namespace std;

// --------------------------------------------------
// NODE
// --------------------------------------------------

class Node
{
public:
    int key;
    int degree;

    Node* parent;
    Node* child;
    Node* sibling;

    Node(int value)
    {
        key = value;
        degree = 0;

        parent = NULL;
        child = NULL;
        sibling = NULL;
    }
};


// --------------------------------------------------
// BINOMIAL HEAP
// --------------------------------------------------

class BinomialHeap
{
public:
    Node* head;

    // MAKE BINOMIAL HEAP
    BinomialHeap()
    {
        head = NULL;
    }


    // --------------------------------------------------
    // BINOMIAL LINK
    // Makes y a child of z
    // --------------------------------------------------

    void binomialLink(Node* y, Node* z)
    {
        y->parent = z;

        y->sibling = z->child;

        z->child = y;

        z->degree++;
    }


    // --------------------------------------------------
    // MERGE TWO ROOT LISTS
    // Root lists are merged according to degree
    // --------------------------------------------------

    Node* binomialMerge(Node* h1, Node* h2)
    {
        if (h1 == NULL)
            return h2;

        if (h2 == NULL)
            return h1;

        Node* head = NULL;
        Node* tail = NULL;

        while (h1 != NULL && h2 != NULL)
        {
            Node* temp;

            if (h1->degree <= h2->degree)
            {
                temp = h1;
                h1 = h1->sibling;
            }
            else
            {
                temp = h2;
                h2 = h2->sibling;
            }

            temp->sibling = NULL;

            if (head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->sibling = temp;
                tail = temp;
            }
        }

        if (h1 != NULL)//last main h1 bacha toh temp main h1 ka last tree jaega
            tail->sibling = h1;

        if (h2 != NULL)// same with h2
            tail->sibling = h2;

        return head;
    }


    // --------------------------------------------------
    // UNION
    // --------------------------------------------------

    void binomialUnion(BinomialHeap& H2)
    {
        Node* newHead;

        newHead = binomialMerge(head, H2.head);

        head = newHead;

        if (head == NULL)
            return;

        Node* prevX = NULL;
        Node* x = head;
        Node* nextX = x->sibling;

        while (nextX != NULL)
        {
            // CASE 1
            // Degrees are different
            if (x->degree != nextX->degree)
            {
                prevX = x;
                x = nextX;
            }

            // CASE 2
            // Three consecutive trees have same degree
            else if (nextX->sibling != NULL &&
                     nextX->degree == nextX->sibling->degree)
            {
                prevX = x;
                x = nextX;
            }

            // CASE 3
            // x has smaller key
            else if (x->key <= nextX->key)
            {
                x->sibling = nextX->sibling;

                binomialLink(nextX, x);
            }

            // CASE 4
            // nextX has smaller key
            else
            {
                if (prevX == NULL)
                {
                    head = nextX;
                }
                else
                {
                    prevX->sibling = nextX;
                }

                binomialLink(x, nextX);

                x = nextX;
            }

            nextX = x->sibling;
        }

        // H2 is no longer needed
        H2.head = NULL;
    }


    // --------------------------------------------------
    // FIND MINIMUM
    // Returns pointer to minimum root
    // --------------------------------------------------

    Node* findMin()
    {
        if (head == NULL)
            return NULL;

        Node* minNode = head;
        Node* temp = head->sibling;

        while (temp != NULL)
        {
            if (temp->key < minNode->key)
            {
                minNode = temp;
            }

            temp = temp->sibling;
        }

        return minNode;
    }


    // --------------------------------------------------
    // INSERT
    // --------------------------------------------------

    void insert(int value)
    {
        BinomialHeap H2;

        Node* newNode = new Node(value);

        H2.head = newNode;

        binomialUnion(H2);
    }


    // --------------------------------------------------
    // REVERSE CHILD LIST
    // Used during EXTRACT-MIN
    // --------------------------------------------------

    Node* reverseChildren(Node* childList)
    {
        Node* previous = NULL;
        Node* current = childList;

        while (current != NULL)
        {
            Node* next = current->sibling;

            current->sibling = previous;
            current->parent = NULL;

            previous = current;
            current = next;
        }

        return previous;
    }


    // --------------------------------------------------
    // EXTRACT MINIMUM
    // --------------------------------------------------

    int extractMin()
    {
        if (head == NULL)
        {
            cout << "Heap is empty.\n";
            return -1;
        }

        Node* minNode = findMin();

        // Remove minNode from root list

        Node* previous = NULL;
        Node* current = head;

        while (current != minNode)
        {
            previous = current;
            current = current->sibling;
        }

        if (previous == NULL)
        {
            head = minNode->sibling;
        }
        else
        {
            previous->sibling = minNode->sibling;
        }

        // Take children of minimum node
        Node* childList = minNode->child;

        // Reverse children
        childList = reverseChildren(childList);

        // Create a new heap from children
        BinomialHeap H2;

        H2.head = childList;

        // Union remaining heap with children heap
        binomialUnion(H2);

        int minimum = minNode->key;

        delete minNode;

        return minimum;
    }


    // --------------------------------------------------
    // SEARCH
    // Finds a node having given key
    // --------------------------------------------------

    Node* search(Node* root, int value)
    {
        if (root == NULL)
            return NULL;

        if (root->key == value)
            return root;

        Node* result;

        // Search in children
        result = search(root->child, value);

        if (result != NULL)
            return result;

        // Search in siblings
        result = search(root->sibling, value);

        return result;
    }


    // --------------------------------------------------
    // SEARCH WHOLE HEAP
    // --------------------------------------------------

    Node* searchHeap(int value)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            Node* result = search(temp, value);

            if (result != NULL)
                return result;

            temp = temp->sibling;
        }

        return NULL;
    }


    // --------------------------------------------------
    // DECREASE KEY
    // --------------------------------------------------

    void decreaseKey(int oldValue, int newValue)
    {
        if (newValue > oldValue)
        {
            cout << "New key must be smaller than old key.\n";
            return;
        }

        Node* x = searchHeap(oldValue);

        if (x == NULL)
        {
            cout << "Key not found.\n";
            return;
        }

        x->key = newValue;

        Node* y = x;
        Node* z = y->parent;

        while (z != NULL && y->key < z->key)
        {
            // Swap keys manually
            int temp = y->key;
            y->key = z->key;
            z->key = temp;

            y = z;
            z = y->parent;
        }
    }


    // --------------------------------------------------
    // DELETE NODE
    // --------------------------------------------------

    void deleteNode(int value)
    {
        Node* x = searchHeap(value);

        if (x == NULL)
        {
            cout << "Key not found.\n";
            return;
        }

        // Make the key extremely small
        decreaseKey(value, -1000000000);

        // Remove the minimum
        extractMin();
    }


    // --------------------------------------------------
    // DISPLAY ONE TREE
    // --------------------------------------------------

    void displayTree(Node* root, int space)
    {
        if (root == NULL)
            return;

        for (int i = 0; i < space; i++)
        {
            cout << " ";
        }

        cout << root->key
             << " (degree = "
             << root->degree
             << ")"
             << endl;

        Node* child = root->child;

        while (child != NULL)
        {
            displayTree(child, space + 4);

            child = child->sibling;
        }
    }


    // --------------------------------------------------
    // DISPLAY WHOLE BINOMIAL HEAP
    // --------------------------------------------------

    void display()
    {
        if (head == NULL)
        {
            cout << "Heap is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "\nBINOMIAL HEAP\n";
        cout << "-------------\n";

        while (temp != NULL)
        {
            cout << "\nB" << temp->degree << " Tree:\n";

            displayTree(temp, 0);

            temp = temp->sibling;
        }
    }
};


// --------------------------------------------------
// MAIN
// --------------------------------------------------

int main()
{
    BinomialHeap H;

    int choice;
    int value;
    int oldValue;
    int newValue;

    do
    {
        cout << "\n\n";
        cout << "==============================\n";
        cout << "       BINOMIAL HEAP\n";
        cout << "==============================\n";

        cout << "1. Insert\n";
        cout << "2. Find Minimum\n";
        cout << "3. Extract Minimum\n";
        cout << "4. Decrease Key\n";
        cout << "5. Delete Node\n";
        cout << "6. Display Heap\n";
        cout << "7. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:

                cout << "Enter value: ";
                cin >> value;

                H.insert(value);

                cout << "Value inserted.\n";

                break;


            case 2:
            {
                Node* minNode = H.findMin();

                if (minNode == NULL)
                {
                    cout << "Heap is empty.\n";
                }
                else
                {
                    cout << "Minimum = "
                         << minNode->key
                         << endl;
                }

                break;
            }


            case 3:

                value = H.extractMin();

                if (value != -1)
                {
                    cout << "Extracted Minimum = "
                         << value
                         << endl;
                }

                break;


            case 4:

                cout << "Enter old value: ";
                cin >> oldValue;

                cout << "Enter new smaller value: ";
                cin >> newValue;

                H.decreaseKey(oldValue, newValue);

                cout << "Key decreased.\n";

                break;


            case 5:

                cout << "Enter value to delete: ";
                cin >> value;

                H.deleteNode(value);

                cout << "Delete operation completed.\n";

                break;


            case 6:

                H.display();

                break;


            case 7:

                cout << "Program ended.\n";

                break;


            default:

                cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}