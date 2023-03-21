#include <iostream>

using namespace std;

const int maxlength = 50;
typedef int elementtype;
typedef int position;

class Kolejka
{
    protected : 
        elementtype Queue[maxlength];
        position Front; // Indeks elementu czołowego
        position Rear; // Indeks ostatniego elementu 
        
    public:
        Kolejka();
        int AddOne(int i);
        void Enqueue(elementtype x);
        void Dequeue();
        elementtype FrontElem();
        void Makenul();
        bool Empty();
};

Kolejka::Kolejka()
{
    Front = 0;
    Rear = maxlength - 1;
}

int Kolejka::AddOne(int i)
{
    return ((i + 1) % maxlength);
}

void Kolejka::Enqueue(elementtype x)
{
    if(AddOne(AddOne(Rear)) != Front) //sprawdzenie czy kolejka jest pelna
    {
        Rear = AddOne(Rear);
        Queue[Rear] = x;
    }
}

void Kolejka::Dequeue()
{
    if(!Empty())
    {
        Front = AddOne(Front);
    }
}

elementtype Kolejka::FrontElem()
{
    if(!Empty())
    {
        return Queue[Front];
    }
}

void Kolejka::Makenul()
{
    Front = 0;
    Rear = maxlength - 1;
}

bool Kolejka::Empty()
{
    if(AddOne(Rear) == Front)
        return true;

    return false;
}

int main()
{
    Kolejka *kolejka = new Kolejka();
    if(kolejka -> Empty())
    {
        cout << "Kolejka jest pusta" << endl;
    }
    else
    {
        cout << "Kolejka nie jest pusta" << endl;
    }
    kolejka -> Enqueue(5);
    if(kolejka -> Empty())
    {
        cout << "Kolejka jest pusta" << endl;
    }
    else
    {
        cout << "Kolejka nie jest pusta" << endl;
    }
    cout << kolejka -> FrontElem() << endl;
    kolejka -> Dequeue();
    if(kolejka -> Empty())
    {
        cout << "Kolejka jest pusta" << endl;
    }
    else
    {
        cout << "Kolejka nie jest pusta" << endl;
    }
    kolejka -> Enqueue(4);
    kolejka -> Enqueue(3);
    kolejka -> Enqueue(2);
    cout << kolejka -> FrontElem() << endl;
    kolejka -> Enqueue(1);
    cout << kolejka -> FrontElem() << endl;
    kolejka -> Dequeue();
    cout << kolejka -> FrontElem() << endl;
    kolejka -> Enqueue(6);
    cout << kolejka -> FrontElem() << endl;
    kolejka -> Dequeue();
    kolejka -> Dequeue();
    cout << kolejka -> FrontElem() << endl;
    kolejka -> Makenul();
    if(kolejka -> Empty())
    {
        cout << "Kolejka jest pusta" << endl;
    }
    else
    {
        cout << "Kolejka nie jest pusta" << endl;
    }
}