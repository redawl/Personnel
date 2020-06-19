#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "personmgr.h"
#include "person.h"

using namespace std;


int main(int argc,char** argv)
{
    if (argc != 2) 
    {
	cout << "Usage: " << argv[0] << " <datafile>" << endl;
	exit(0);
    }

    personmgr personMgr;

    char* datafile = argv[1];
    ifstream infile(datafile);

    if (infile.is_open())
    {
	cout << "======= Loading personnel data =======" << endl;
	int addCount = 0;
	bool done = false;
	while (!done )
	{
	    char id[100];
	    char fname[100];
	    char lname[100];
	    char familyId[100];

	    infile >> id;
	    infile >> fname;
	    infile >> lname;
	    infile >> familyId;

	    if (strcmp(id,"=======")==0)
	    {
		done = true;
	    }
	    else
	    {
		person per(id,fname,lname,familyId);
		personMgr.addPerson(per);
		addCount++;
	    }
	}
	cout << "Added " << addCount << " persons to the person manager." << endl << endl;;

	cout << "======= Exercising lookups ===========" << endl;

	// To exercise lookups and make sure that they are fast enough, we are going
	// to read the lookup requests out of the data file. We will print the results
	// from the first NUM_PRINTS records. We will look up the same ID NUM_LOOKUPS
	// times so that we are evaluating the lookup time of the hashtable, not the
	// IO time of reading the file.

	const int NUM_PRINTS = 10;
	const int NUM_LOOKUPS = 100;

	cout << "Showing the first " << NUM_PRINTS << " records." << endl << endl;

	int lookupCount = 0;
	while (!infile.eof() )
	{
	    char id[100];
	    infile >> id;
	    if (!infile.eof())
	    {
		for (int i=0;i<NUM_LOOKUPS;i++)
		{
		    const person* perPtr = personMgr.findPerson(id);

		    // If this is the first lookup for this person and we
		    // haven't printed NUM_PRINTS persons yet, then print
		    // this person.
		    if (i == 0 && lookupCount < NUM_PRINTS)
		    {
			cout << *perPtr << endl;
		    }
		}
	    }
	    lookupCount++;
	}
	infile.close();
    }

    // Normally a main application wouldn't know anything about how the person
    // manager is storing data but since this application is investigating to
    // find a faster way to store data, we want to print out these diagnostics
    // to help make sure we're being as efficient as possible.
    cout << "======= Hashtable stats ===========" << endl;
    personMgr.printHtStats();

    return(0);
}
