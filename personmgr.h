#ifndef PERSONMGR_H
#define PERSONMGR_H
#include "hashtable.h"
#include "person.h"
class personmgr{
private:
    hashtable table;
public:
    const person * findPerson(char * id);   
    bool addPerson(person aPerson);
    void printHtStats();
};
#endif
