#include "person.h"

person::person(){
    id = NULL;
    firstName = NULL;
    lastName = NULL;
    famId = NULL;
}

person::person(const person &aPerson){
    this->id = new char[strlen(aPerson.id) + 1];
    this->firstName = new char[strlen(aPerson.firstName) + 1];
    this->lastName = new char[strlen(aPerson.lastName) + 1];
    this->famId = new char[strlen(aPerson.famId) + 1];

    strcpy(this->id, aPerson.id);
    strcpy(this->firstName, aPerson.firstName);
    strcpy(this->lastName, aPerson.lastName);
    strcpy(this->famId, aPerson.famId);
}

person::person(char * id, char * firstName, char * lastName, char * famId){
    this->id = new char[strlen(id) + 1];
    this->firstName = new char[strlen(firstName) + 1];
    this->lastName = new char[strlen(lastName) + 1];
    this->famId = new char[strlen(famId) + 1];

    strcpy(this->id, id);
    strcpy(this->firstName, firstName);
    strcpy(this->lastName, lastName);
    strcpy(this->famId, famId);
}

person::~person(){
    if(id){
        delete[] id;
        id = NULL;
    }
    
    if(firstName){
        delete[] firstName;
        firstName = NULL;
    }

    if(lastName){
        delete[] lastName;
        lastName = NULL;
    }
    
    if(famId){
        delete[] famId;
        famId = NULL;
    }
}

char * person::getId()const{
    return id;
}

char * person::getFirstName()const{
    return firstName;
}

char * person::getLastName()const{
    return lastName;
}

char * person::getFamId()const{
    return famId;
}

ostream& operator<<(ostream &os, const person &aPerson){
    os << "ID: " << aPerson.getId() << "\nFirst Name: " <<
    aPerson.getFirstName() << "\nLast Name: " <<
    aPerson.getLastName() << "\n";

    return os;
}

person& person::operator=(const person &aPerson){
    if(this == &aPerson)
        return *this;
    else{
        this->id = new char[strlen(aPerson.id) + 1];
        this->firstName = new char[strlen(aPerson.firstName) + 1];
        this->lastName = new char[strlen(aPerson.lastName) + 1];
        this->famId = new char[strlen(aPerson.famId) + 1];
        strcpy(this->id, aPerson.id);
        strcpy(this->firstName, aPerson.firstName);
        strcpy(this->lastName, aPerson.lastName);
        strcpy(this->famId, aPerson.famId);
    }
}
