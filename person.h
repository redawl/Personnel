#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cstring>

using namespace std;
class person{
private:
    char * id;
    char * firstName;
    char * lastName;
    char * famId;
public:
    person();
    person(const person &aPerson);
    person(char * id, char * firstName, char * lastName, char * famId);
    ~person();
    char * getId() const;
    char * getFirstName() const;
    char * getLastName() const;
    char * getFamId() const;
    friend ostream& operator<<(ostream &os, const person &aPerson);
    person& operator=(const person &aPerson);
};
#endif
