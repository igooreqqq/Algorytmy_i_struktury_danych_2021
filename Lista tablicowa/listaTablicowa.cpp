#include <iostream>

using namespace std;

const int MIN = -1000000;

typedef int elementtype, position ;
const int maxlength=10;
struct List
{
	elementtype elements[maxlength];
	int last;           //indeks ostatniego elementu listy
};

position END(List l)
{ 
    return l.last + 1;
}

position First(List l) 
{
    return 0;
}

position Next(position p,List l)
{
    if((p < First(l)) || (p > l.last))
    {
        return -1;
    }

    else
    {
        return p + 1;
    }
}


position Previous(position p,List l) 
{
    if((p <= First(l)) || (p > END(l)))
        return -1;

    else
        return p - 1;
}



position Locate(elementtype x, List l) 
{ //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
    for(int i = 0; i < END(l); i++)
    {
        if(l.elements[i] == x)
        {
            return i;
        }
    }
    return END(l);
}

elementtype Retrieve(position p, List l) 
{
    if((p >= 0) || (p < END(l)))
    {
        return l.elements[p];
    }

    else
    {
        return MIN;
    }

}

bool Insert(int x, position p, List &l)
{
    if(END(l) > maxlength)
    {
        return false;
    } 

    else if((p < First(l)) || (p > END(l)))
    {
        return false;
    }

    else
    {
        for(int i = l.last; i >= p; i--)
        {
            l.elements[i + 1] = l.elements[i];
        }
        l.elements[p] = x;
        l.last = l.last + 1;
        
        return true;
    }
}

bool Delete(position p, List &l)
{
    if((p < First(l)) || (p > l.last))
        return false;

    for(p; p < l.last; p++)
    {
        l.elements[p] = l.elements[p + 1];
    }
    l.last--;

    return true;
}

void print(List l)
{
	position i=First(l);
	while (i!=END(l))
	{
		printf ("  %d,", Retrieve(i,l));
		i=Next(i,l);
	}
	printf("\n");

}

int main()
{

List l;
l.last=-1;
Insert(100,First(l),l);
print (l);

for (int i=0; i<3;i++)
Insert(i,First(l),l);
print (l);

Insert (20,Previous(END(l),l) ,l);
print(l);
Delete( Locate(20,l),l);
print(l);
}