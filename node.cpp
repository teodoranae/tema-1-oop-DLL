//
// Created by Teodora on 3/19/2024.
//

#include "node.h"


Node:: Node()                           //constructor neparametrizat
{                                       //am folosit '\0' pentru initializarea info
    info='\0';
    prev=nullptr;
    next=nullptr;
    std::cout<<"S-a apelat constructorul neparametrizat\n";
}

Node:: Node(char info, Node* prec, Node *urm)                  //constructor parametrizat
{
    this->info=info;
    this->prev=prec;
    this->next=urm;
    std:: cout<<"S-a apelat constructorul parametrizat\n";
}

Node:: Node(Node &n)                    //constructor de copiere
{
    info=n.info;
    next=n.next;
    prev=n.prev;
    std::cout<<"S-a apelat constructorul de copiere\n";
}

char Node::get_info() const {                 //liniile 32-42: getters
    return info;
}

Node* Node::get_next() {
    return next;
}

Node* Node::get_prev() {
    return prev;
}

void Node::set_info(char info) {            //liniile 44-54 setters
    this->info=info;
}

void Node::set_next(Node *urm) {
    this->next=urm;
}

void Node::set_prev(Node *prec) {
    this->prev=prec;
}

Node& Node::operator=(const Node &n)        //supraincarcarea operatorului de atribuire pentru noduri
{
        if(this!= &n) {
            info = n.info;
            prev = n.prev;
            next = n.next;
        }
        std::cout <<"operator de atribuire\n";
        return (*this);
}

