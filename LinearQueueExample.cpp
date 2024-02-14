
#include <iostream>
#include <queue>
using namespace std;

int main() {
    std::queue<int> myQueue;

    // Enqueue three elements
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Get the front and back elements
    cout << "Front element: " << myQueue.front() << endl;
    cout << "Back element: " << myQueue.back() << endl;

    // Dequeue an element
    myQueue.pop();

    // Check if the queue is empty
    if (myQueue.empty()) {
        cout << "The queue is empty." << endl;
    }
    else {
        cout << "The queue is not empty." << endl;
    }

    // Get the size of the queue
    cout << "Queue size: " << myQueue.size() << endl;

    // Swap two queues
    queue<int> otherQueue;
    otherQueue.push(4);
    otherQueue.push(5);
    cout << "Before swap, myQueue size: " << myQueue.size() << ", otherQueue size: " << otherQueue.size() << endl;
    myQueue.swap(otherQueue);
    cout << "After swap, myQueue size: " << myQueue.size() << ", otherQueue size: " << otherQueue.size() << endl;
    cout << endl << endl;
    // Get the front and back elements after swap
    cout << "Front element myQueue: " << myQueue.front() << endl;
    cout << "Back element  myQueue: " << myQueue.back() << endl;

    cout << "Front element otherQueue: " << otherQueue.front() << endl;
    cout << "Back element  otherQueue: " << otherQueue.back() << endl;


    return 0;
}

