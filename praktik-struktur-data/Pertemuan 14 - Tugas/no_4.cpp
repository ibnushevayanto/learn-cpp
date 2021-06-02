#include <iostream>
#include <conio.h>

using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

main()
{
    int arr[5], n;
    cout << "Masukkan jumlah nilai yang ingin di input (max:5) = ";
    cin >> n;
    if (n > 5)
    {
        n = 5;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan elemen ke-" << i << " = ";
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    cout << "Sorted Array : \n";
    printArray(arr, n);
    getch();
}