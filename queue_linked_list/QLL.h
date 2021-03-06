#ifndef QLL_H
#define QLL_H

using namespace std;

template <typename T>
class QLL
{
    struct Node // creating a Node structure
    {
        T value;
        Node* next;
    };

    int len; // initializing len

    Node* head; //initializing the head pointer

    Node* tail; // initializing the tail pointer

    public:
        QLL()
        {
            len = 0; // initializing with len 0
        };

        bool empty_() { return len == 0; }; // returns 1 if empty, 0 otherwise

        void enqueue(T value) // add values to the end of the list
        {
            Node* n;
            if(empty_() == 1) {
                n = new Node;
                n->value = value;
                n->next = nullptr;

                head = n;
                tail = n;
                len++;
            }else {
                n = new Node;
                n->value = value;
                n->next = nullptr;

                tail->next = n;
                tail = n;
                len++;
            }
        };

        T dequeue() // remove values from the front of the list, returns -1 if empty
        {
            if(empty_() == 1) {
                return -1;
            }else {
                Node* trvl = head;

                T data = trvl->value;

                head = head->next;

                delete trvl;

                len--;

                return data;
            }
        };

};

#endif // QLL_H
