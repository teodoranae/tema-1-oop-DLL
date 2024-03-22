//
// Created by Teodora on 3/19/2024.
//

#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {              //constructor neparametrizat liste
    first= nullptr;                                 //lista creata cu acest constructor este vida
    last= nullptr;
    std::cout<<"S-a apelat constructorul neparametrizat pentru liste\n";
}

DoubleLinkedList::DoubleLinkedList(int length, char simboluri[255]) {      //constructor parametrizat liste

    first= nullptr;
    last= nullptr;
    for(int i=0; i<length; i++) {                                //se construieste lista, pornind de la
        Node *nou = new Node(simboluri[i]);                 //dimensiunea si simbolurile dorite
        if (first == nullptr) {                                  //daca lista este vida, adaugam primul nod,
            first=nou;                                           //fiind totodata si ultimul nod
            last = first;
        }
        else {                                                  //altfel, adaugam noduri in continuare,
            nou->set_prev(last);                          //stabilind legaturile dintre ele
            last->set_next(nou);
            last = nou;
        }
        last->set_next(nullptr);                           //pointerul next al ultimului nod va fi null
    }
    std::cout<<"S-a apelat constructorul parametrizat pentru liste\n";
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList &obj) {     //constructorul de copiere
    first= nullptr;
    last= nullptr;
    Node *curent(obj.first);
    while(curent!= nullptr)                                     //aici, se va construi o noua lista,
    {                                                           //copie a celei date ca parametru
        Node* nou(curent);
        if(first== nullptr)
        {                                                       //se adauga nodurile din lista data ca parametru
            first=nou;                                          //in lista curenta
            last=nou;
        }
        else
        {
            last->set_next(nou);
            nou->set_prev(last);
            last=nou;
        }
        curent=curent->get_next();
    }
    std::cout<<"Se apeleaza constructorul de copiere\n";
}

int DoubleLinkedList::size()                //va fi nevoie de dimensiunea listei,
{                                                               //de aceea am definit functia size
    int sz=0;
    Node *curent(this->first);
    while(curent!= nullptr) {
        sz++;
        curent = curent->get_next();
    }
    return sz;
}

void DoubleLinkedList::set_first(Node first)        //liniile 67-79 setters
{
    Node *ptr=new Node;
    ptr=&first;
    this->first==ptr;
}

void DoubleLinkedList::set_last(Node last)
{
    Node *ptr=new Node;
    ptr=&last;
    this->last==ptr;
}

Node* DoubleLinkedList::get_first() {                //liniile 81-91 getters
    if(first)
        return first;
    return NULL;
}

Node* DoubleLinkedList::get_last() {
    if(last)
        return last;
    return NULL;
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList &l2) //operatorul de atribuire
{
    while(this->first!= nullptr)                                           //daca operandul stang e nevid,
        this->sterge_poz();                                                 //ii stergem continutul
    Node *curent(l2.first);
    while(curent!= nullptr)                                                //in continuare, se copiaza
    {                                                                      //continutul listei date ca parametru
        this->adauga_poz( 1, curent->get_info());                           //in lista curenta
        curent=curent->get_next();
    }
    std::cout<<"Atribuire la liste\n";
    return *this;
}

DoubleLinkedList operator+(DoubleLinkedList l1, DoubleLinkedList l2){    //operatorul care efectueaza concatenarea
    DoubleLinkedList temp;                                              //a doua liste
    if(l1.first== nullptr)                                              //prin legarea ultimului nod din prima lista
        return l2;                                                      //(primul operand) cu primul nod din cea de-a
    temp=l1;                                                            //doua lista
    temp.last->set_next(l2.first);                                 //se returneaza rezultatul, astfel nefiind modificat
    l2.first->set_prev(temp.last);                                //niciun operand
    temp.last=l2.last;
    return temp;
}

void DoubleLinkedList::adauga_poz( int poz, char elem) {
    if(this->first== nullptr && poz==1)                            //functie care adauga un element pe o pozitie
    {                                                           //intai, se verifica daca lista e vida, caz in care
        Node *curent=new Node;                                  //se adauga primul element in aceasta, pe prima pozitie
        curent->set_info(elem);
        curent->set_next(nullptr);
        curent->set_prev(nullptr);
        first=curent;
        last=curent;
    }
    else
        if(poz<1 || (poz>this->size()+1 && this->first!= nullptr))       //se verifica daca pozitia e valida
        std::cout<<"Pozitie invalida\n";

        else                                                        //se adauga nodul nou pe pozitia ceruta
        {   Node *curent=new Node;
            curent->set_info(elem);
            curent->set_next(nullptr);
            curent->set_prev(nullptr);

                if(poz==1)                                         //daca pozitia e 1, nodul devine primul element
                {                                                  //al listei
                    this->first->set_prev(curent);
                    curent->set_next(this->first);
                    first=curent;
                }
                else
                    if(poz==this->size()+1)                            //daca pozitia este dimensiunea+1, nodul devine
                    {                                               //ultimul element
                        this->last->set_next(curent);
                        curent->set_prev(this->last);
                        last=curent;
                    }
                    else                                            //altfel, se cauta pozitia ceruta
                    {
                        Node *parcurg(this->first);                   //se insereaza nodul
                        for(int i=1; i<poz-1 && parcurg!= nullptr; i++)
                            parcurg=parcurg->get_next();
                        Node *dr(parcurg->get_next());
                        parcurg->set_next(curent);              //si se stabilesc legaturile intre nodul
                        curent->set_prev(parcurg);              //de dinainte, nodul curent si nodul de dupa
                        curent->set_next(dr);
                        dr->set_prev(curent);
                    }
        }
}

void DoubleLinkedList::sterge_poz( int poz) {
    if(this->first== nullptr || poz<1 || poz>this->size())               //se verifica daca se pot sterge elemente
        std::cout << "Nu se poate sterge elementul\n";
    else
        if(this->first==this->last && poz==1) {
            delete this->first;                                           //daca lista are un element, dupa stergere,
            this->first= nullptr;                                         //aceasta devine vida
            this->last=nullptr;
            std:: cout << "Dupa apel, lista este vida\n";
        }
    else {
        Node *curent(this->first);                                        //se verifica daca poz este 1
        if (poz == 1) {
            this->first = this->first->get_next();                      //caz in care se sterge primul nod
            this->first->set_prev(nullptr);
            delete curent;
        }
        else {
            for (int i = 1; i < poz && curent != nullptr; i++)
                curent = curent->get_next();
            if(curent== nullptr)
                std::cout<<"Pozitia nu exista\n";
            else
                if(curent==this->last){                                   //in acest caz, se sterge ultimul nod
                    std::cout<<"Este ultimul\n";
                    this->last = this->last->get_prev();
                    this->last->set_next(nullptr);
                    delete curent;
                }
                else {                                                  //altfel, se gaseste pozitia ceruta,
                    Node *st(curent->get_prev());                       //se sterge nodul si se stabilesc legaturile
                    Node *dr(curent->get_next());
                    st->set_next(dr);
                    dr->set_prev(st);
                    delete curent;
                }
        }
    }
}

DoubleLinkedList operator-(DoubleLinkedList l1, DoubleLinkedList l2)     //operatorul -
{
    DoubleLinkedList temp;
    if(l1.get_first() == nullptr) {                                     //daca prima lista este vida, o returneaza pe a doua
        std::cout << "Prima lista este vida\n";
        return l2;
    }
    if(l2.get_first()== nullptr)                                        //daca a doua lista este vida, o returneaza pe prima
    {
        std::cout<<"A doua lista este vida\n";
        return l1;
    }
    Node *pointer1=l1.get_first();
    Node *pointer2=l2.get_first();                                     //altfel, sunt parcurse simultan listele
    while(pointer1!= nullptr && pointer2!= nullptr && pointer1->get_info()==pointer2->get_info())
    {                                                                  //cat timp informatiile nodurilor coincid
        pointer1=pointer1->get_next();
        pointer2=pointer2->get_next();
    }
    while(pointer1!= nullptr) {                                         //cand s-a gasit primul element diferit, se opreste parcurgerea
        temp.adauga_poz( 1, pointer1->get_info());
        pointer1 = pointer1->get_next();                                //se adauga elementele ramase din lista l1 in lista temp
    }

    return temp;                                                        //se returneaza; astfel, niciun operand nu este modificat
}

std::istream& operator>>(std::istream& in, DoubleLinkedList &obj)   //citim caracterele si formam o lista cu ele,
{
    std::cout<<"Dorim sa formam o lista cu elementele:";            //folosind functia de adaugare definita
    char elem[255];
    in>>elem;                                                       //anterior
    while(obj.first!=nullptr)
        obj.sterge_poz();
    int i=0;
    while(elem[i]!='\0')
    {
        obj.adauga_poz( i+1, elem[i]);
        i++;
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, DoubleLinkedList &obj) {    //daca lista este vida, afisam
    if (obj.first == nullptr)                                           //mesajul corespunzator
        std::cout << "Lista este vida\n";
    else {                                                              //altfel, afisam lista intr-un sens
        std::cout << "Lista este:\n";
        std::cout << "De la stanga la dreapta:\n";
        Node *curent(obj.first);
        while (curent != nullptr) {
            std::cout << curent->get_info() << ' ';
            curent = curent->get_next();
        }
        std::cout << '\n';
        std::cout << "De la dreapta la stanga:\n";                      //si in celalalt sens
        curent = obj.last;
        while (curent != nullptr) {
            std::cout << curent->get_info() << ' ';
            curent = curent->get_prev();
        }
        std::cout << '\n';
    }
    return out;
}
