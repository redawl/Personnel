#include "hashtable.h"

hashtable::hashtable(){
    for(int i = 0; i < MAX_SIZE; i++)
        table[i] = NULL;
}

hashtable::~hashtable(){
    for(int i = 0; i < MAX_SIZE; i++){
        while(table[i]){
            node * temp = table[i];
            table[i] = table[i]->next;
            delete temp;
            temp = NULL;
        }
    }

    delete[] table; 
    table = NULL;
}

person * hashtable::lookUp(char * id){
    int i = 0;
    int index = hash(id);

    node * current = table[index];
    
    while(strcmp(current->Person.getId(),id) != 0 && current->next != NULL){
        current = current->next;
    }
        return & current->Person;
}

bool hashtable::insert(const person &aPerson){
    char * id = aPerson.getId();
    int index = hash(id);
    
    node * newNode = new node;
    newNode->Person = aPerson;

    if(!table[index]){
        table[index] = newNode;
    }
    else{
        node * current = table[index];
    
        while(current->next)
            current = current->next;
        current->next = newNode; 
    }
}

int hashtable::hash(char * id){
    int ret = 0;
    int size = strlen(id);
    
    for(int i = 0; i < size; i++)
        ret += int(id[i]) * int(id[i]);

    return ret % MAX_SIZE;
}

int hashtable::getSTAT(){

    int ret = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        if(table[i])
            ret++; 
    }

    return ret;
}
