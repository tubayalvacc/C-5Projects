//----------------PROJE 1---------------------
//Write a program in C++ to implement stack using array, push 5 values [10,20,30,40,50] in the stack and display them.

#include <iostream> // This allows us to use cout for output
using namespace std;

// Define the maximum size of the stack
#define MAX 100

// The Stack class has two main variables: top (to track the top element) and arr (the array to store stack elements).
// The constructor Stack() initializes top to -1, indicating the stack is empty.
class Stack {
    int top; // Index of the top element
    int arr[MAX]; // Array to hold stack elements

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1; // Initial top index is -1 indicating stack is empty
    }

    // Push Method:
    // void push(int value) adds a new element to the stack.
    // If top is greater than or equal to MAX - 1, it means the stack is full, and we print "Stack Overflow".
    // Otherwise, we increment top and add the value to the stack.
    void push(int value) {
        if (top >= MAX - 1) { // Check if stack is full
            cout << "Stack Overflow" << endl;
        } else {
            top++; // Move top to the next position
            arr[top] = value; // Add the value to the stack
        }
    }

    // Display Method:
    // void display() prints all elements of the stack from top to bottom.
    // If top is -1, it means the stack is empty, and we print "Stack is empty".
    // Otherwise, we print the elements of the stack starting from the top.
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements are: " << endl;
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " "; // Print stack elements
            }
            cout << endl;
        }
    }
};

// Main Function: we will display and test the algorithm and project
// In main(), we create a Stack object.
// We push the values 10, 20, 30, 40, 50 onto the stack.
// Finally, we call stack.display() to print the elements of the stack.
int main() {
    Stack stackObj; // Create a stack object

    stackObj.push(10); // Push values onto the stack
    stackObj.push(20);
    stackObj.push(30);
    stackObj.push(40);
    stackObj.push(50);

    stackObj.display(); // Display stack elements

    return 0;
}



//-------------------------PROJE 2-------------------------
//Write a program in C++ to calculate Factorial of a given number (below 10) using recursion.



#include <iostream> // Include iostream library for input and output
using namespace std;

// Function to calculate factorial using recursion
int factorial(int num) {
    if (num <= 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    } else {
        return num * factorial(num - 1); // Recursive case: num * factorial of (num - 1)
    }
}

// Main function to test the factorial function and display the result
int main() {
    int number; // Variable to store user input

    // Ask the user to enter a number
    cout << "Enter a number below 10 to calculate its factorial: ";
    cin >> number; // Read the number from the user

    // Validate the input
    if (number < 0 || number >= 10) {
        cout << "Please enter a valid number between 0 and 9" << endl;
        return 1; // Exit the program if the input is invalid
    }

    // Call the factorial function and store the result
    int result = factorial(number);

    // Display the result
    cout << "Factorial of " << number << " is: " << result << endl;

    return 0; // Indicate that the program ended successfully
}


//----------------------------------PROJE 3----------------------
//Write a program in C++ to bubble sort an array.


#include <iostream>
using namespace std;

// Function to perform bubble sort on an array
void bubbleSorting(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j]; // Temporary variable to hold the value of array[j]
                array[j] = array[j + 1]; // Swap elements
                array[j + 1] = temp; // Continue swapping
            }
        }
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    // Define and sort multiple arrays
    int array1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    cout << "Unsorted array1: ";
    printArray(array1, size1);
    bubbleSorting(array1, size1);
    cout << "Sorted array1: ";
    printArray(array1, size1);

    int array2[] = {2, 4, 6, 8};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    cout << "Unsorted array2: ";
    printArray(array2, size2);
    bubbleSorting(array2, size2);
    cout << "Sorted array2: ";
    printArray(array2, size2);

    int array3[] = {-5, -2, 6, 7, 14};
    int size3 = sizeof(array3) / sizeof(array3[0]);
    cout << "Unsorted array3: ";
    printArray(array3, size3);
    bubbleSorting(array3, size3);
    cout << "Sorted array3: ";
    printArray(array3, size3);

    int array4[] = {5, 9, 11, 15, 23};
    int size4 = sizeof(array4) / sizeof(array4[0]);
    cout << "Unsorted array4: ";
    printArray(array4, size4);
    bubbleSorting(array4, size4);
    cout << "Sorted array4: ";
    printArray(array4, size4);

    return 0;
}

/* NOTES OF THE CODES:

bubbleSorting Function:
- Takes an array of integers (int array[]) and its size (int size) as arguments.
- Uses two nested loops to compare and swap adjacent elements if they are in the wrong order.
- The outer loop runs from 0 to size-1, and the inner loop runs from 0 to size-i-1 to avoid rechecking the already sorted part of the array.

printArray Function:
- Takes an array of integers (int array[]) and its size (int size) as arguments.
- Prints each element of the array.

main Function:
- Defines multiple example arrays to be sorted.
- Calculates the size of each array.
- Prints each unsorted array.
- Calls the bubbleSorting function to sort each array.
- Prints each sorted array.

Running the Code:
- Compile the code using a C++ compiler (e.g., g++ -o bubble_sort bubble_sort.cpp).
- Run the executable (e.g., ./bubble_sort) to see the output.
*/



//-------------------------------PROJE 4----------------------
//Write a C++ program to reverse the elements [1 2 3 4 5] of a queue.


#include <iostream>
#include <queue>
#include <stack>

// Function to reverse the elements of a queue
void reverseQueue(std::queue<int>& q) {
    std::stack<int> s;

    // Move all elements from the queue to the stack
    while (!q.empty()) {
        s.push(q.front()); // Transfer elements from queue to stack
        q.pop();
    }

    // Move all elements back to the queue from the stack
    while (!s.empty()) {
        q.push(s.top()); // Transfer elements from stack back to queue
        s.pop();
    }
}

int main() {
    std::queue<int> q;

    // Add elements [1, 2, 3, 4, 5] to the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Print original queue
    std::cout << "Original queue: ";
    std::queue<int> temp = q; // Use a temporary queue to print elements
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    // Reverse the queue
    reverseQueue(q);

    // Print reversed queue
    std::cout << "Reversed queue: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;

    return 0;
}


//-----------------------------PROJE 5------------------
//Write a C++ program to insert a new node at the beginning of a Singly Linked List with the values 13 11 9 7 5 3 1 . The node value to be inserted is 0


#include <iostream>

// Node structure definition
struct Node {
    int data;        // Data part of the node holds integer value
    Node* next;      // Pointer to the next node in the linked list
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();   // Create a new node
    newNode->data = newData;      // Assign data to the new node
    newNode->next = head;         // Point new node's next to current head
    head = newNode;               // Update head to point to the new node
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;         // Start from the head
    while (current != nullptr) {  // Traverse until the end of the list
        std::cout << current->data << " ";  // Print current node's data
        current = current->next;   // Move to the next node
    }
    std::cout << std::endl;       // Print newline after printing the list
}

int main() {
    Node* head = nullptr;         // Initialize head pointer to nullptr

    // Insert nodes with values 13, 11, 9, 7, 5, 3, 1 at the beginning
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 7);
    insertAtBeginning(head, 9);
    insertAtBeginning(head, 11);
    insertAtBeginning(head, 13);

    std::cout << "Original Linked list:" << std::endl;
    printList(head);  // Print the original linked list

    // Insert a new node with value 0 at the beginning
    insertAtBeginning(head, 0);

    std::cout << "Linked list after inserting 0 at the beginning:" << std::endl;
    printList(head);  // Print the updated linked list

    return 0;  // End of the program
}



