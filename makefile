Lab2: main.o DoublyLinkedList.o Node.o
	g++ -std=c++11 main.o DoublyLinkedList.o Node.o -o Lab2
main.o: main.cpp DoublyLinkedList.h Node.h
	g++ -std=c++11 -c main.cpp
DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -std=c++11 -c DoublyLinkedList.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
clean:
	rm -f test *.o