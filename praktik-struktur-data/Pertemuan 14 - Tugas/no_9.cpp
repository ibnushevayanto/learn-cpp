#include <iostream>
#include <conio.h>
using namespace std;

const int MaxS = 10;

struct Stack
{
    char Isi[MaxS];
    unsigned int Top;
};

void INITS(Stack &S);
void PUSH(Stack &S, char elemen);
void CETAK(Stack &S);
void POP(Stack &S, char &Hsl);

main()
{
    char huruf;
    Stack S;
    int n;
    INITS(S);

    cout << "Masukkan jumlah nilai yang ingin anda input : ";
    cin >> n;
    if (n > 10)
        n = 10;

    for (size_t i = 0; i < n; i++)
    {
        cout << "Masukkan Karakter : ";
        cin >> huruf;
        PUSH(S, huruf);
    }
    CETAK(S);

    cout << endl
         << "Yang Dihapus... " << huruf;
    POP(S, huruf);
    CETAK(S);

    getch();
}

void INITS(Stack &S)
{
    S.Top = 0;
}

void PUSH(Stack &S, char elemen)
{
    if (S.Top < MaxS)
    {
        S.Isi[S.Top] = elemen;
        S.Top++;
    }
    else
        cout << "Stack Penuh...";
}

void CETAK(Stack &S)
{
    if (S.Top > 0)
    {
        cout << endl
             << "Isi Stack : ";
        for (size_t i = 0; i < S.Top; i++)
            cout << S.Isi[i] << " ";
    }
    else
        cout << "Stack Kosong...";
}

void POP(Stack &S, char &Hsl)
{
    if (S.Top > 0)
    {
        Hsl = S.Isi[S.Top];
        S.Top--;
    }
    else
        cout << "Stack Kosong...";
}