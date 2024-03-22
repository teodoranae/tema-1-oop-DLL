//
// Created by Teodora on 3/19/2024.
//

#ifndef TEMA_7_DOUBLELINKEDLIST_H
#define TEMA_7_DOUBLELINKEDLIST_H
#include <iostream>
#include "node.h"

class DoubleLinkedList{
    Node *first;
    Node *last;
public:
    DoubleLinkedList();                                     //constructor neparametrizat
    DoubleLinkedList(int length, char simboluri[255]);      //constructor parametrizat
    ~DoubleLinkedList()                                     //destructor
    {
        Node *parcurg=first;
        while(first!= nullptr)
        {
            parcurg=parcurg->get_next();
            delete first;
            first=parcurg;

        }
        first= nullptr;
        last= nullptr;

        std::cout<<"S-a apelat destructorul pentru liste\n";
    };
    DoubleLinkedList(DoubleLinkedList &obj);                        //constructor de copiere
    void set_first(Node first);                                     //setters, getters
    void set_last(Node last);
    Node* get_first();
    Node* get_last();
    void adauga_poz( int poz, char elem);     //functiile si operatorii din cerinta
    void sterge_poz(int poz=1);
    friend DoubleLinkedList operator+(DoubleLinkedList l1, DoubleLinkedList l2);
    friend DoubleLinkedList operator-(DoubleLinkedList l1, DoubleLinkedList l2);
    DoubleLinkedList& operator=(const DoubleLinkedList &l2);
    int size();             //avem nevoie si de dimensiunea listei
friend std::istream& operator>>(std::istream& in, DoubleLinkedList &obj);
friend std::ostream& operator<<(std::ostream& out, DoubleLinkedList &obj);


};


#endif //TEMA_7_DOUBLELINKEDLIST_H
