#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

const int B = 127;
typedef char * elementtype;

struct celltype
{
    elementtype element;
    celltype * next;
};

typedef celltype * position;
class dictionary
{
    protected :
        position D[B];//tablica nagłówków list
    public:
        dictionary();
        ~dictionary();
        void Makenul();
        bool Member(elementtype x);
        void Insert(elementtype x);
        void Delete(elementtype x);
        int H(elementtype x);
};

dictionary::dictionary()
{
    for(int i = 0; i < B; i++)
    {
        D[i] = NULL;
    }
}

dictionary::~dictionary()
{
    position tmp;
    for(int i = 0; i < B; i++)
    {
        while(D[i] != NULL)
        {
            tmp = D[i];
            D[i] = D[i] -> next;
            delete tmp;
        }
    }
}

void dictionary::Makenul()
{
    position tmp;
    for(int i = 0; i < B; i++)
    {
        while(D[i] != NULL)
        {
            tmp = D[i];
            D[i] = D[i] -> next;
            delete tmp;
        }
    }
}

bool dictionary::Member(elementtype x)
{
    position tmp;
    tmp = D[H(x)];
    while(tmp != NULL)
    {
        if(tmp -> element == x)
            return true;
        else
            tmp = tmp -> next;
    }
    return false;
}

void dictionary::Insert(elementtype x)
{
    int bucket;
    position tmp;
    if(!Member(x))
    {
        bucket = H(x);
        tmp = D[bucket];
        D[bucket] = new celltype;
        D[bucket] -> element = x;
        D[bucket] -> next = tmp;
    }
}

void dictionary::Delete(elementtype x)
{
    position p;
    position current;

    int bucket;
    bucket = H(x);
    if(D[bucket] != NULL)
    {
        if(D[bucket] -> element == x)
        {
            p = D[bucket];
            D[bucket] = D[bucket] -> next;
            delete p;
        }

        else
        {
            current = D[bucket];
            while(current -> next != NULL)
            {
                if((current -> next -> element) == x)
                {
                    p = current -> next;
                    current -> next = current -> next -> next;
                    delete p;
                    break;
                }
                else
                {
                    current = current -> next;
                }
            }
        }
    }
}

int dictionary::H(elementtype x)
{
    return (int(x[0])) % B;
}

int main()
{
    dictionary *dic = new dictionary();

    char *Ala = (char* ) "Ala";
    char *As = (char* ) "As";
    char *nazwisko = (char* ) "Tyszer";
    
    cout << "Dla wyrazu Ala: " << endl;

    dic -> Insert(Ala);
    cout << dic -> Member(Ala) << endl;
    cout << dic -> H(Ala) << endl;

    cout << "Dla wyrazu As: " << endl;

    dic -> Insert(As);
    cout << dic -> Member(As) << endl;
    cout << dic -> H(As) << endl;

    cout << "Dla wyrazu Ala: " << endl;

    cout << dic -> Member(Ala) << endl;
    cout << dic -> H(Ala) << endl;

    cout << "Dla mojego nazwiska: " << endl;
    dic -> Insert(nazwisko);
    cout << dic -> Member(nazwisko) << endl;
    cout << dic -> H(nazwisko) << endl;

    cout << endl;

    dic -> Delete(Ala);
    cout << dic -> Member(As) << endl;
    cout << dic -> Member(Ala) << endl;
    dic -> Makenul();
    cout << dic -> Member(As) << endl;
    cout << dic -> Member(nazwisko) << endl;
    
    return 0;
}