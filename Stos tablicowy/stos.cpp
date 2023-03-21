#include <iostream>

using namespace std;

const int maxlegth = 20;
typedef int elementtype;
typedef int position;

class Stos
{
    protected:
        int S[maxlegth];
        position Top;

    public:
        Stos();
        void Push(elementtype x);
        void Pop();
        bool Empty();
        elementtype TopElem();
        void Makenul();
};

Stos::Stos()
{
    Top = -1;
}

void Stos::Push(elementtype x)
{
    if(Top < maxlegth - 1)
    {
        Top++;
        S[Top] = x;
    }
}

void Stos::Pop()
{
    if(Top >= 0)
    {
        Top--;
    }
}

bool Stos::Empty()
{
    if(Top == -1)
    {
        cout << "Stos jest pusty." << endl;
        return true;
    }

    cout << "Stos zawiera elementy." << endl;
    return false;
}

elementtype Stos::TopElem()
{
    if(Top >= 0)
    {
        return S[Top];
    }
}

void Stos::Makenul()
{
    Top = -1;
}

int main()
{
    Stos stos;
    stos.Empty();
    stos.Push(5);
    cout << stos.TopElem() << endl;
    stos.Empty();
    stos.Pop();
    stos.Empty();
    stos.Push(2);
    stos.Push(3);
    cout << stos.TopElem() << endl;
    stos.Makenul();
    stos.Empty();
}