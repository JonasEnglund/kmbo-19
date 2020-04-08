#include <llist.h>

LList::LList()
{
    Size = 0;
    head = nullptr;
}

LList::~LList()
{

}

void LList::push_back(int val)
{
    if(head == nullptr)
    {
        head = new Node(val);
    }
    else {
        Node *current = this->head;
        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(val);
    }
    ++Size;
}

int LList::operator[](size_t idx) const
{
    if(head != nullptr) {
        Node *current = this->head;
        int counter = 0;
        while (counter < idx) {
            current = current->pNext;
            ++counter;
        }
        return current->data;
    }
}

size_t LList::size() const {
    return Size;
}

void LList::push_front(int val)
{
    if(head == nullptr)
    {
        head = new Node(val);
    }
    else {
        Node *current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node(val);
        ++Size;
    }
}

void LList::insert_at(size_t idx, int val)
{
    if(head == nullptr)
    {
        head = new Node(val);
    }
    else {
        int counter = 0;
        Node *current = this->head;
        while (counter < idx - 1) {
            current = current->pNext;
            ++counter;
        }
        Node *saved = current->pNext;
        current->pNext = new Node(val);
        current->pNext->pNext = saved;
        ++Size;
    }
}

void LList::erase_at(size_t idx)
{
    if(head != nullptr)
    {
        Node *current = this->head;
        int counter = 0;
        while (counter < idx - 1) {
            current = current->pNext;
            ++counter;
        }
        Node *saved = current->pNext->pNext;
        delete current->pNext;
        current->pNext = saved;
        --Size;
    }
}

void LList::reverse()
{
    if(head != nullptr) {
        Node *current = this->head, *next, *prev = nullptr;
        while (current) {
            next = current->pNext;
            current->pNext = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
}

void LList::pop_front()
{
    if(head != nullptr) {
        Node *current = this->head;
        head = current->pNext;
        delete current;
        --Size;
    }
}

void LList::pop_back()
{
    if(head != nullptr) {
        Node *current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        delete current;
        --Size;
    }
}

int& LList::operator[](size_t idx)
{
    if(head != nullptr) {
        Node *current = this->head;
        int counter = 0;
        while (counter < idx) {
            current = current->pNext;
            ++counter;
        }
        return current->data;
    }
}
