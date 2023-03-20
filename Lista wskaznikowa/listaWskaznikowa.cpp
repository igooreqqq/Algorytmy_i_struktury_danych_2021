#include <iostream>

using namespace std;

typedef int  elementtype;

struct celltype {
    elementtype element;
    celltype * next;
};
typedef celltype  * position; 

class Lista
{
    protected : 
        position l; // wskaźnik do głowy listy

    public:
        Lista();    //konstruktor
        ~Lista();  //destruktor
        void Insert(elementtype x, position p);
        void Delete(position p);
        elementtype Retrieve(position p);
        position Locate(elementtype x);
        position First();
        position Next(position p);
        position Previous(position p);
        position END();
};

Lista::Lista() // w konstruktorze tworzymy głowę listy
{
    l = new celltype;
    l->next = NULL;
}

Lista::~Lista()
{
    position temp;
    if((l != NULL) && (l->next != NULL))
    {
        while(l->next != NULL)
        {
            temp = l->next;
            l->next = temp->next;
            delete temp;
        }
    }
}

void Lista::Insert(elementtype x, position p)
{
    position temp = p->next;
    p->next = new celltype;
    p->next->element = x;
    p->next->next = temp;
}

void Lista::Delete(position p)
{
    position temp = p->next;
    p->next = p->next->next;
    delete temp;
}

elementtype Lista::Retrieve(position p)
{
    if(p->next != NULL)
    {
        return p->next->element;
    }
}

position Lista::Locate(elementtype x)
{
    position temp = l;

    while(temp->next != NULL)
    {
        if(temp->next->element == x)
        {
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

position Lista::First()
{
    return l;
}

position Lista::Next(position p)
{
    return p->next;
}

position Lista::Previous(position p)
{
    position temp = l;

    while(temp->next != p)
    {
        temp = temp->next;
    }
    return temp;
}

position Lista::END()
{
    position end = l;

    while(end->next != NULL)
    {
        end = end->next;
    }
    return end;
}

void print(Lista l)
{
	position i = l.First();
	while (i != l.END())
	{
	    printf (" %d,", l.Retrieve(i));
		i = l.Next(i);
	}
	printf("\n");
}

int main()
{
    Lista l;
    l.Insert(5, l.First());
    cout << "Pierwszy element: " << l.Retrieve(l.First()) << '\n' << endl;

    l.Insert(2, l.First());
    cout << "Pierwszy element: " << l.Retrieve(l.First()) << endl;
    cout << "Drugi element: " << l.Retrieve(l.Next(l.First())) << '\n' << endl;

    l.Insert(1, l.First());
    cout << "Pierwszy element: " << l.Retrieve(l.First()) << endl;
    cout << "Drugi element: " << l.Retrieve(l.Next(l.First())) << endl;
    cout << "Trzeci element: " << l.Retrieve(l.Next(l.Next(l.First()))) << '\n' << endl;

    print(l);
}