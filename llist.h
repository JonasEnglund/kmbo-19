#ifndef LLIST_H
#define LLIST_H

#include <cstddef>

class LList
{
private:

    class Node{

    public:
        Node(int data = int(), Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }

        Node *pNext;
        int data;
    };
    int Size;
    Node *head;

public:

	LList();                         // construct new collection
	~LList();                        // free resources

	void push_back(int val);         // add new value at the end:  [1 2 3 4] -> [1 2 3 4 5]
    int  operator[](size_t idx) const; //get read-only access
    size_t size() const;             // get actual number of items [1 2 3 4] -> 4
	void push_front(int val);        // add new value at the begin [1 2 3 4] -> [5 1 2 3 4]
    void insert_at(size_t idx, int val); // insert item at specific position: [1 2 3 4], 1, 5 -> [1 5 2 3 4]
    void erase_at(size_t idx);       // remove item at specific position: [1 2 3 4], 2 -> [1 2 4]
    void reverse();                  // reverse item sequense: [1 2 3 4] -> [4 3 2 1]
    void pop_front();         // remove at the front        [1 2 3 4] -> [2 3 4]
	void pop_back();          // remove at the end          [1 2 3 4] -> [1 2 3]
	int& operator[](size_t idx);     // get rw access ot specific item addressing by idx

};



#endif //LLIST_H
