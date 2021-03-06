#include <iostream>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node {
    int value;
    char version;
};

void printaheap(struct node arr[], int n)
{
    
    int en = n;
    int ct = 0;

    while (en > 0)
    {
        en = (int)(en / 2);
        ct++;
    }
    cout << endl
         << endl;
    int print = 0;
    for (int i = 0; i < ct; i++)
    {
        for (int z = 0; z < 2 * ((10 - i * 2)); z++)
        {
            cout << " ";
        }
        for (int j = 0; j < pow(2, i); j++)
        {
            if (print < n)
            {
                cout << "   [" << arr[print].value << "" << arr[print].version << "]  ";
                print++;
            }
        }
        cout << endl
             << endl;
    }
    cout << endl
         << endl;
}

void heapify(struct node arr[], int n, int i)
{
    int maior = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].value > arr[maior].value)
        maior = l;

    if (r < n && arr[r].value > arr[maior].value)
        maior = r;

    if (maior != i)
    {
        swap(arr[i], arr[maior]);

        heapify(arr, n, maior);
    }
}

void heapSort(struct node arr[], int n)
{
    cout<<"Primeiramente, fazemos o build Heap max"<<endl; 
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        printaheap(arr, n);
        heapify(arr, n, i);
        printaheap(arr, n);
    }
    cout << "Aqui acaba o build heap max" << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        printaheap(arr, n);
        heapify(arr, i, 0);
        printaheap(arr, n);
    }
}

void printArray(struct node arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i].value << "" << arr[i].version << " ";
    cout << "\n\n";
}

int main() {
    cout << "\n\n";
    cout << "----------" << endl;
    cout << "Prova de instabilidade do algoritmo Heapsort" << endl;
    cout << "----------";
    cout << "\n\n";

    std::srand (std::time(0));
    int length = 8;
    int numbers[length];
    for(int i = 0; i < length; i+=2) {
        std::srand (std::time (0) - i);
        int random = 1 + (std::rand() % (65 - 1 + 1));
        numbers[i] = random;
        if(i < length) {
            numbers[i+1] = random;
        }
    }

    std::sort(numbers, numbers + (sizeof(numbers)/sizeof(numbers[0])));

    struct node arr[length];

    for(int i = 0; i < length; i+=2) {
        struct node no = {numbers[i], 'a'};
        arr[i] = no;
        no.version = 'b';
        arr[i+1] = no;
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Ordem do array antes da ordenação" << endl;
    printArray(arr, n);
    heapSort(arr, n);
    cout << "Ordem do array depois da ordenação" << endl;
    printArray(arr, n);
}