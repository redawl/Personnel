#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "person.h"
#include "cstring"
const static int MAX_SIZE = 9973;

class hashtable{
private:
    struct node{
        person Person;
        node * next = NULL;
    };

    node ** table = new node*[MAX_SIZE];
public:
    hashtable();
    ~hashtable();
    person * lookUp(char * id);
    bool insert(const person &aPerson);
    int hash(char * id);
    int getSTAT();
    
    hashtable(const hashtable &aHashtable) = delete;
    hashtable &operator=(const hashtable &aHashtable) = delete;
};
#endif
