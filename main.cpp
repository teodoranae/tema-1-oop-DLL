#include <iostream>
#include "DoubleLinkedList.h"
#include "NodeTest.h"
#include "DoubleLinkedListTest.h"
void citire_memo_afis(DoubleLinkedList arr[1001], int n)    //functia pentru citirea, memorarea si afisarea
{                                                           //a n (maxim 1000) de liste dublu inlantuite
    for(int i=1; i<=n; i++) {                               //memorarea se realizeaza sub forma de array
        std::cin >> arr[i];
        std::cout << arr[i];
    }
}

int main() {

    NodeTest elem;
    elem.CreareSiAfisareNoduri();
    DLLTest test;
    test.CreareSiAfisareLista();
    test.StergereSiAdaugareElemente();
    test.CitireDeLaTastatura();
    DoubleLinkedList v[100];
    int n;
    std::cout<<"Se citeste n:";
    std::cin>>n;
    citire_memo_afis(v, n );
    for(int i=1; i<=n; i++)
        std::cout<<v[i];
    return 0;
}
