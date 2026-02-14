#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* arr;

public:
    Queue(int size) {
        capacity = size;
        front = 0;
        rear = -1;
        arr = new int[capacity];
    }

    bool isEmpty() {
        return (rear < front);
    }

    bool isFull() {
        return (rear == capacity - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[++rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
