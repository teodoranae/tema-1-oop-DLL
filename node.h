//
// Created by Teodora on 3/19/2024.
//

#ifndef TEMA_7_NODE_H
#define TEMA_7_NODE_H

#include <iostream>
#include <cstring>

class Node
{

    char info;                  //date private
    Node *next;
    Node *prev;

public:
    Node();                     //constructor neparametrizat
    Node(char info, Node* urm= nullptr, Node *prec= nullptr);            //constructor paramterizat
    Node(Node& n);              //constructor de copiere
    char get_info() const;            //getters
    Node* get_next();
    Node* get_prev();
    void set_info(char info);            //setters
    void set_prev(Node* prec);
    void set_next(Node* urm);
    Node& operator=(const Node& n);
    ~Node() {                                       //destructor
        std::cout<<"S-a apelat destructorul\n";
    }
};

#endif //TEMA_7_NODE_H