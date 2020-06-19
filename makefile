compile: personnel.o person.o personmgr.o hashtable.o
	g++ personnel.o person.o personmgr.o hashtable.o -o personnel
	rm *.o

personnel.o: personnel.cpp
	g++ -g -c personnel.cpp

person.o: person.cpp
	g++ -g -c person.cpp

personmgr.o: personmgr.cpp
	g++ -g -c personmgr.cpp

hashtable.o: hashtable.cpp
	g++ -g -c hashtable.cpp

clean: 
	rm *.o
