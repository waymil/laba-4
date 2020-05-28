#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T field;
    Node<T> *next;
};

template <typename T>
class List
{
    Node<T> *head;
    int count = 0;

    Node<T>* Prev(Node<T> *node);
public:
    List();
    List(const T item);
    List(const List& obj);
    ~List();

    Node<T>* insertFirst(T item);
    Node<T>* insertAtPos(T item);
    Node<T>* insertLast(T item);

    Node<T>* deleteFirst();
    Node<T>* deleteAtPos();
    Node<T>* deleteLast();

    Node<T>* getFirst();
    Node<T>* getLast();

    void Clear();
    void Print();

    int Size();
    bool isEmpty();
    Node<T>* Next(Node<T> *node);

    T getValue(Node<T>* p) const;
    void setValue(const T val);
};

template <typename T>
List<T>::List()
{
    head = 0;
    count = 0;
}

template <typename T>
List<T>::List(const T item)
{
    Node<T> *p = insertFirst(item);
    p->next = 0;
}

template <typename T>
List<T>::List(const List& obj)
{
    Node<T>* p = obj.head;
    head = 0;
    while (p != 0)
    {
        this->insertLast(p->field);
        p = p->next;
    }
}

template <typename T>
List<T>::~List()
{
    Clear();
}

template <typename T>
Node<T>* List<T>::insertFirst(T item)
{
    Node<T> *p = new Node<T>;
    p->field = item;
    count++;
    if (head == 0)
    {
        p->next = 0;
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
    return p;
}

template <typename T>
Node<T>* List<T>::insertAtPos(T item)
{
    Node<T> *p = new Node<T>;
    Node<T> *pos = head;
    int i = 0, num;
    cout << "Choose the position after which to add the item >> ";
    cin >> num;
    while (i < num)
    {
        Next(pos);
        i++;
    }
    p->field = item;
    p->next = pos->next;
    pos->next = p;
    count++;
    return p;
}

template <typename T>
Node<T>* List<T>::insertLast(T item)
{
    Node<T> *p = new Node<T>;
    Node<T> *pos = getLast();
    p->field = item;
    count++;
    p->next = 0;
    if (head == 0)
    {
        head = p;
    }
    else
    {
        p->next = pos->next;
        pos->next = p;
    }
    return p;
}

template <typename T>
Node<T>* List<T>::deleteFirst()
{
    Node<T> *p = new Node<T>;
    if (p == 0)
        return 0;
    count--;
    p = getFirst();
    Next(p);
    head = p->next;
    delete p;
    return head;
}

template <typename T>
Node<T>* List<T>::deleteAtPos()
{
    Node<T> *pos = getLast();
    if (pos == 0)
        return 0;
    int i = 0, num, siz = Size();
    cout << "Choose the position after which to remove the item >> ";
    cin >> num;
    while (i < (siz-num))
    {
        Prev(pos);
        i++;
    }
    count--;
    Node<T>* prev = Prev(pos);
    prev->next = pos->next;
    delete pos;
    return prev;
}

template <typename T>
Node<T>* List<T>::deleteLast()
{
    Node<T> *p = new Node<T>;
    if (p == 0)
        return 0;
    count--;
    p = getLast();
    Node<T>* prev = Prev(p);
    prev->next = p->next;
    delete p;
    return prev;
}

template <typename T>
Node<T>* List<T>::Prev(Node<T>* node)
{
    if (isEmpty())
        return 0;
    if (node == head)
        return 0;
    Node<T> *p = head;
    while (p->next != node)
        p = p->next;
    return p;
}

template <typename T>
Node<T>* List<T>::Next(Node<T>* node)
{
    if (isEmpty())
        return 0;
    return node->next;
}

template <typename T>
int List<T>::Size()
{
    return count;
}

template <typename T>
bool List<T>::isEmpty()
{
    return head == 0;
}

template <typename T>
void List<T>::Clear()
{
    Node<T> *p = head;
    Node<T> *d;
    if (p == 0)
        return;
    while (p != 0)
    {
        d = p;
        p = Next(p);
        delete d;
    }
    count = 0;
    head = 0;
}

template <typename T>
void List<T>::Print()
{
    if (isEmpty()) { cout << "The list is empty" << endl; return; }
    cout << "|LIST|" << endl;
    Node<T> *p = head;
    while (p != 0)
    {
        cout << getValue(p) << endl;
        p = Next(p);
    }
    cout << "Total items: " << Size() << endl;
    cout << endl;
}

template <typename T>
Node<T>* List<T>::getFirst()
{
    return head;
}

template <typename T>
Node<T>* List<T>::getLast()
{
    Node<T>* p = head;
    while (Next(p) != 0)
        p = Next(p);
    return p;
}

template <typename T>
T List<T>::getValue(Node<T>* p) const
{
    return p->field;
}

template <typename T>
void List<T>::setValue(const T val)
{
    Node<T> *p;
    p->field = val;
}

#endif // TEST_H_INCLUDED
