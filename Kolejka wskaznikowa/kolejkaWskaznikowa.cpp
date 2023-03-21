#include <iostream>

using namespace std;

typedef int  elementtype; 
struct celltype  
{ 
    elementtype element; 
    celltype * next; 
}; 
 
typedef celltype * position;  
 
class Queue 
{ 
    protected: 
        position Front;      // wskaźnik do głowy listy 
        position Rear;    // wskaźnik do ostatniego elementu 
    
    public: 
        Queue();    //konstruktor 
        ~Queue();  //destruktor 
        void Enqueue(elementtype x); 
        void Dequeue(); 
        elementtype FrontElem(); 
        bool Empty(); 
};

Queue::Queue()
{
    Front = new celltype;
    Rear = Front;
    Front -> next = NULL;
}

Queue::~Queue()
{
    position toDelete;

    while(Front -> next != NULL)
    {
        toDelete = Front;
        Front = Front -> next;
        delete toDelete;
    }
    delete Front;
}

void Queue::Enqueue(elementtype x)
{
    position newelement = new celltype;
    newelement -> element = x;
    newelement -> next = NULL;
    Rear -> next = newelement;
    Rear = newelement;
}

void Queue::Dequeue()
{
    if(!Empty())
    {
        position toDelete = new celltype;
        toDelete = Front;
        Front = Front -> next;
        delete toDelete;
    }
}

elementtype Queue::FrontElem()
{
    if(!Empty())
    {
        elementtype frontelem;
        frontelem = Front -> next -> element;
        return frontelem;
    }
}

bool Queue::Empty()
{
    if(Front -> next == NULL)
    {
        return true;
    }

    return false;
}

int main()
{
    Queue *queue = new Queue();
    if(queue -> Empty())
    {
        cout << "Kolejka jest pusta" << endl;
    }
    else
    {
        cout << "Kolejka nie jest pusta" << endl;
    }
    queue -> Enqueue(5);
    if(queue -> Empty())
    {
        cout << "Kolejka jest pusta" << endl;
    }
    else
    {
        cout << "Kolejka nie jest pusta" << endl;
    }
    cout << queue -> FrontElem() << endl;
    queue -> Dequeue();
    if(queue -> Empty())
    {
        cout << "Kolejka jest pusta" << endl;
    }
    else
    {
        cout << "Kolejka nie jest pusta" << endl;
    }
    queue -> Enqueue(4);
    queue -> Enqueue(3);
    queue -> Enqueue(2);
    cout << queue -> FrontElem() << endl;
    queue -> Enqueue(1);
    cout << queue -> FrontElem() << endl;
    queue -> Dequeue();
    cout << queue -> FrontElem() << endl;
    queue -> Enqueue(6);
    cout << queue -> FrontElem() << endl;
    queue -> Dequeue();
    queue -> Dequeue();
    cout << queue -> FrontElem() << endl;
}