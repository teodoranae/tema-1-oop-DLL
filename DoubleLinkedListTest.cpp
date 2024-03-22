//
// Created by Teodora on 3/21/2024.
//
#include "DoubleLinkedListTest.h"
void DLLTest::CreareSiAfisareLista() {
    DoubleLinkedList l1;
    std::cout<<"Lista 1:\n"<<l1<<'\n';
    DoubleLinkedList l2(5, "12356");
    std::cout<<"Lista 2:\n"<<l2<<'\n';
    l1=l2;
    std::cout<<"Dupa atribuire, lista 1 devine:\n"<<l1<<'\n';
    DoubleLinkedList l3(l2);
    std::cout<<"Lista 3:\n"<<l3<<'\n';
    DoubleLinkedList l4(4, "abcd");
    std::cout<<"\nConcatenarea a doua liste:\n";
    DoubleLinkedList l5=l1+l4;
    std::cout<<l5;DoubleLinkedList l7(6, "123456");
    DoubleLinkedList l6(l2-l7);
    std::cout<<l6;
    std::cout<<l2;
}

void DLLTest::StergereSiAdaugareElemente() {
    DoubleLinkedList l(10, "programare");
    std::cout<<"Dupa stergerea primului element:\n";
    l.sterge_poz();
    std::cout<<l;
    std::cout<<"Dupa stergerea elementului 6:\n";
    l.sterge_poz(6);
    std::cout<<l;
    std::cout<<"Dupa stergerea elementului 10:\n";
    l.sterge_poz(10);
    std::cout<<l;
    std::cout<<"Dupa adaugare:\n";
    l.adauga_poz(3, 'm');
    std::cout<<l;

}

void DLLTest::CitireDeLaTastatura()
{   DoubleLinkedList l;
    std::cin>>l;
    std::cout<<l;
}