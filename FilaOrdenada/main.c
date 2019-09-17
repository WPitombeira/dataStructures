#include "includes/filaOrdenada.h"

void initList(List *list){
    list->first = NULL;
    list->size = 0;
}

void insert(List *list, Object x){
    NodeList new;

    new = (NodeList) malloc(sizeof(NodeList));

    new.element = x;

    if(isEmpty(list)){
        list->first = &new;
        list->size++;
    } else {
        Pointer aux = list->first;
        while(aux->next != NULL && x > aux->next->element){
            aux = aux->next;
            new.next = &aux->next;
            aux->next = &new;
            list->size++;
        }
    }
    // se fila ja tem coisa
    // while aux!=NULL || obj>aux->prox->key
    // aloca o novo objeto
    // faz com que o ponteiro auxiliar receba o ponteiro próximo do objeto anterior
    // faz com que o ponteiro auxiliar do objeto anterior receba o seu próprio valor de referencia
}

void printList(List *list){
    
}

void destroyList(List *list){

}

bool isEmpty(List *list){
    return (list->size==0) ? true : false;
}

bool search(List *list, int key){

}

bool searchFaster(List *list, int key){

}

int size(List *list){

}

void removeElement(List *list, int key, Object *item){
    if(isEmpty(list)){
        printf("## The List is Empty!!");
        return;
    }
    if(list->first->element.key > key){
        printf("## This element isn't in the list");
        return;
    }
    if(first(list) == item){
        removeFirst(list, item);
    } else {
        if(search(list, item)){

        } else {
            printf("## Object isn't in the list");
            return;
        }
    }
}

void removeFirst(List *list, Object *item){
}

void removeLast(List *list, Object *item){

}

Object first(List *list){

}

Object last(List *list){

}

int main() {


    return 0;
}