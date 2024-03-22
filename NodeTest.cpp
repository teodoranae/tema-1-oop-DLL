//
// Created by Teodora on 3/21/2024.
//

#include "NodeTest.h"

void NodeTest::CreareSiAfisareNoduri() {
    Node n1, n2('a');
    std::cout<<n1.get_info()<<' '<<n2.get_info()<<'\n';
    Node *n3=new Node;
    Node *n4=new Node;
    n3->set_info(n2.get_info());
    n4->set_info(n1.get_info());
    n3->set_prev(n4);
    n4->set_next(n3);
    std::cout<<n4->get_info()<<' '<<n3->get_info()<<'\n';
    Node n5(n2);
    Node n6;
    n6=n5;
    std::cout<<n5.get_info()<<'\n';
    std::cout<<n6.get_info()<<'\n';
}