#include <iostream>
#include <stack>

using namespace std;

class CustomQueue {
private:
    stack<int> enqueueStack;
    stack<int> dequeueStack;

public:
    void enqueue(int x) {
        enqueueStack.push(x);
    }

    void dequeue() {
        if (dequeueStack.empty()) {
            // Transfer elements from enqueue stack to dequeue stack
            while (!enqueueStack.empty()) {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }

        if (!dequeueStack.empty()) {
            dequeueStack.pop();
        }
    }

    int front() {
        if (dequeueStack.empty()) {
            // Transfer elements from enqueue stack to dequeue stack
            while (!enqueueStack.empty()) {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }

        if (!dequeueStack.empty()) {
            return dequeueStack.top();
        }

        // Return -1 if the queue is empty
        return -1;
    }
};

int main() {
    CustomQueue customQueue;

    int query, x;
    while (cin >> query) {
        if (query == 1) {
            cin >> x;
            customQueue.enqueue(x);
        } else if (query == 2) {
            customQueue.dequeue();
        } else if (query == 3) {
            int frontElement = customQueue.front();
            if (frontElement != -1) {
                cout << frontElement << endl;
            }
        }
    }

    return 0;
}
