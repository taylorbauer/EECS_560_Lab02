Lab2: main.o LinkedList.o Node.o Menu.o HashTable.o
	g++ -std=c++11 main.o LinkedList.o Node.o Menu.o HashTable.o -o Lab2
main.o: main.cpp LinkedList.h Node.h
	g++ -std=c++11 -c main.cpp
LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -std=c++11 -c LinkedList.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp
HashTable.o: HashTable.cpp HashTable.h
	g++ -std=c++11 -c HashTable.cpp
clean:
	rm -f test *.o