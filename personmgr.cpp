#include "personmgr.h"

const person * personmgr::findPerson(char * id){
    return table.lookUp(id);
}

bool personmgr::addPerson(person aPerson){
    return table.insert(aPerson);
}

void personmgr::printHtStats(){
    printf("Table uses %d out of 9973 entries.\n", table.getSTAT());
}
