#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int ile;

clock_t start, stop;
double czas;

void sortowanie_babelkowe(int *tab, int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=n-1; j>=1; j--)
        {
            if(tab[j]<tab[j-1])     // sortowac malejaco - zmienic znak tutaj [default: rosnaco]
            {
                int bufor;
                bufor=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=bufor;
            }
        }
    }
}

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<v)
            i++;
        while (tablica[j]>v)
            j--;
        if (i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>lewy)
        quicksort(tablica,lewy, j);
    if (i<prawy)
        quicksort(tablica, i, prawy);
}

int main()
{
    cout << "Porownanie czasow sortowania v.1: " << endl;
    cout << "Ile losowych liczb w tablicy: ";
    cin >> ile;

    int *tablica;   // dynamiczna alokacja tablicy
    tablica = new int [ile];

    int *tablica2;  // kopia dla quicksort
    tablica2 = new int [ile];

    srand(time(NULL));  // inicjowanie generatora

    for(int i=0; i<ile; i++)    // wczytywanie liczb losowych do tablicy
    {
        tablica[i] = rand()%100000+1;   // 0-99999 (+1)
        // cout << tablica[i] << " ";
    }
    for(int i=0; i<ile; i++)    // wykonanie dokladnej kopii tablicy do tablica2
    {
        tablica2[i] = tablica[i];
    }
    /*
        cout << "Przed posortowaniem: " << endl;
        for(int i=0; i<ile; i++)
        {
            cout << tablica[i] << " ";
        }
    */
    cout << endl << "Sortowanie babelkowe w toku..." << endl;
    start = clock();
    sortowanie_babelkowe(tablica,ile);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;

    /*   cout << "Po posortowaniu: " << endl;
       for(int i=0; i<ile; i++)
       {
           cout << tablica[i] << " ";
       }
    */
    cout << endl << "Czas sortowania babelkowego: " << czas << " s" << endl;

    cout << endl;

    cout << endl << "Sortowanie quicksort w toku..." << endl;
    start = clock();
    quicksort(tablica2, 0, ile-1);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;

    /*   cout << "Po posortowaniu: " << endl;
       for(int i=0; i<ile; i++)
       {
           cout << tablica[i] << " ";
       }
    */
    cout << endl << "Czas sortowania quicksort: " << czas << " s" << endl;

    delete [] tablica;
    delete [] tablica2;

    return 0;
}
