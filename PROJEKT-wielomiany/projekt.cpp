#include <iostream>

using namespace std;

int *dodajWielomiany(int wielomian1[], int wielomian2[], int stopien1, int stopien2)
{
    int rozmiar = max(stopien1, stopien2); //wieksza wartosc
    int *suma = new int[rozmiar];

    if(stopien1 >= stopien2) //sprawdzenie, ktory wielomian ma wiekszy stopien, ten ktory jest wiekszy, temu przypisujemy nowa tablice
    {
        for(int i = stopien1 - 1; i >= 0; i--)
        {
            suma[i] = wielomian1[i]; //przypisz nowej tablicy takie same wartosci jak wielomian1
        }

        for(int i = 0; i < stopien2; i++)
        {
            suma[stopien1 - 1 - i] += wielomian2[stopien2 - 1 - i]; //do wartosci wielomianu1 dodaj wartosci wielomianu2
        }
    }
    else //wielomian2 ma wiekszy stopien
    {
        for(int i = stopien2 - 1; i >= 0; i--)
        {
            suma[i] = wielomian2[i]; //przypisz nowej tablicy takie same wartosci jak wielomian2
        }

        for(int i = 0; i < stopien1; i++)
        {
            suma[stopien2 - 1 - i] += wielomian1[stopien1 - 1 - i]; //do wartosci wielomianu2 dodaj wartosci wielomianu1
        }
    }

    return suma;
}

int *odejmijWielomiany(int wielomian1[], int wielomian2[], int stopien1, int stopien2) //dzialanie takie samo jak dodawanie, tylko tutaj odejmujemy
{
    int rozmiar = max(stopien1, stopien2);
    int *roznica = new int[rozmiar];

    if(stopien1 >= stopien2)
    {
        for(int i = stopien1 - 1; i >= 0; i--)
        {
            roznica[i] = wielomian1[i];
        }

        for(int i = 0; i < stopien2; i++)
        {
            roznica[stopien1 - 1 - i] -= wielomian2[stopien2 - 1 - i];
        }
    }
    else
    {
        for(int i = stopien2 - 1; i >= 0; i--)
        {
            roznica[i] = (-1) * wielomian2[i];
        }

        for(int i = 0; i < stopien1; i++)
        {
            roznica[stopien2 - 1 - i] += wielomian1[stopien1 - 1 - i];
        }
    }

    return roznica;
}

int *pomnozWielomiany(int wielomian1[], int wielomian2[], int stopien1, int stopien2)
{
    int rozmiar = stopien1 + stopien2 - 1;
    int *iloczyn = new int[rozmiar];

    for(int i = 0; i < rozmiar; i++)
    {
        iloczyn[i] = 0; //inicjalizujemy i przypisujemy nowej tablicy 0 na kazdym polu
    }

    for(int i = 0; i < stopien1; i++)
    {
        for(int j = 0; j < stopien2; j++)
        {
            iloczyn[i + j] += wielomian1[i] * wielomian2[j]; //mnozymy w odpowiedniej kolejnosci wielomian1 z wielomian2 i wartosci dodajemy do nowej tablicy na miejsce odpowiadajace danemu stopniu
        }
    }

    return iloczyn;
}

int wartoscWielomianu(int wielomian[], int stopien)
{
    int x; // wartosc x dla ktorej chcemy obliczyc wartosc wielomianu
    cout << "Podaj wartosc x: " << endl;
    cin >> x;

    int wynik;
    wynik = wielomian[0]; //przypisujemy wartosc rowna pierwszemu wspolczynnikowi

    for(int i = 1; i < stopien; i++)
    {
        wynik = wynik * x + wielomian[i]; //algorytm Hornera
    }

    return wynik;
}

void pokazWielomian(int wielomian[], int stopien)
{
    for(int i = 0; i < stopien; i++)
    {
        cout << wielomian[i];
        if(i != stopien - 1) // jesli i nie jest rowne ostatniemu wspolczynnikowi
        {
            cout << "x^" << (stopien - 1) - i;
        }

        if(i != stopien - 1)
        {
            if(wielomian[i + 1] >= 0) //jeslikolejny wielomian jest dodatni lub rowny 0
            {
                cout << " +";
            }
            else //jesli jest ujemny
                cout << " ";
        }
    }
}

int menu()
{
    cout << "1. Wyswietl wielomiany." << endl;
    cout << "2. Dodaj wielomiany do siebie." << endl;
    cout << "3. Odejmij wielomiany od siebie." << endl;
    cout << "4. Pomnoz wielomiany." << endl;
    cout << "5. Znajdz wartosc wielomianu(Horner)." << endl;
    cout << "6. Wszystkie dzialania powyzej." << endl;
    cout << "7. Koniec programu." << endl;

    int opcje = 7;
    cin >> opcje;
    return opcje;
}

int main()
{
    int stopien1, stopien2;
    cout << "Wprowadz stopien pierwszego wielomianu: " << endl;
    cin >> stopien1;

    cout << "Wprowadz stopien drugiego wielomianu: " << endl;
    cin >> stopien2;

    int wielomian1[stopien1];
    int wielomian2[stopien2];
    
    cout << "Uzupelnij wspolczynniki pierwszego wielomianu: " << endl;
    for(int i = 0; i < stopien1; i++)
    {
        cout << "Wspolczynnik przy potedze: " << stopien1 - 1 - i << endl;
        cin >> wielomian1[i];
    }
    
    cout << "Uzupelnij wspolczynniki drugiego wielomianu: " << endl;
    for(int i = 0; i < stopien2; i++)
    {
        cout << "Wspolczynnik przy potedze: " << stopien2 - 1 - i << endl;
        cin >> wielomian2[i];
    }

    int *suma;
    int *roznica;
    int *iloczyn;

    while(1)
    {
        switch(menu())
        {
            case 1:
                cout << "Pierwszy wielomian to: " << endl;
                pokazWielomian(wielomian1, stopien1);
                cout << endl;

                cout << "Drugi wielomian to: " << endl;
                pokazWielomian(wielomian2, stopien2);
                cout << endl;
            break;

            case 2:
                suma = dodajWielomiany(wielomian1, wielomian2, stopien1, stopien2);
                cout << "Suma podanych wielomianow wynosi: " << endl;
                pokazWielomian(suma, max(stopien1, stopien2));
                cout << endl;
            break;

            case 3:
                roznica = odejmijWielomiany(wielomian1, wielomian2, stopien1, stopien2);
                cout << "Roznica podanych wielomianow wynosi: " << endl;
                pokazWielomian(roznica, max(stopien1, stopien2));
                cout << endl;
            break;
            
            case 4:
                iloczyn = pomnozWielomiany(wielomian1, wielomian2, stopien1, stopien2);
                cout << "Wynik mnozenia podanych wielomianow: " << endl;
                pokazWielomian(iloczyn, stopien1 + stopien2 - 1);
                cout << endl;
            break;
            
            case 5:
                cout << "Wartosc wielomianu dla podanego x wynosi: " << wartoscWielomianu(wielomian2, stopien2) << endl;
            break;

            case 6:
                suma = dodajWielomiany(wielomian1, wielomian2, stopien1, stopien2);
                cout << "Suma podanych wielomianow wynosi: " << endl;
                pokazWielomian(suma, max(stopien1, stopien2));
                cout << endl;

                roznica = odejmijWielomiany(wielomian1, wielomian2, stopien1, stopien2);
                cout << "Roznica podanych wielomianow wynosi: " << endl;
                pokazWielomian(roznica, max(stopien1, stopien2));
                cout << endl;

                iloczyn = pomnozWielomiany(wielomian1, wielomian2, stopien1, stopien2);
                cout << "Wynik mnozenia podanych wielomianow: " << endl;
                pokazWielomian(iloczyn, stopien1 + stopien2 - 1);
                cout << endl;

                cout << "Wartosc wielomianu dla podanego x wynosi: " << wartoscWielomianu(wielomian1, stopien1) << endl;
            break;

            case 7:
                cout << "Zakonczono program!" << endl;
            exit(0);

            default:
                cout << "Nie ma takiej opcji!" << endl;
        }
    }
    return 0;
}