EXEC = dijkstra
CC = g++ 
CFLAGS = -c 
# $(EXEC) has the value of shell variable EXEC, which is run. CC = g++ -04 CFLAGS = -c -Wall
# run depends on the files main.o util.o heap.o
$(EXEC) :Main.o Util.o Heap.o Graph.o
# run is created by the command g++ -o run main.o util.o
# note that the TAB before $(CC) is REQUIRED...
		$(CC) -o $(EXEC) Main.o Util.o Heap.o Graph.o
# main.o depends on the files main.h main.cpp
Main.o : Main.cpp Util.h Heap.h Graph.h 
# main.o is created by the command g++ -c -Wall main.cpp
# note that the TAB before $(CC) is REQUIRED...
		$(CC) $(CFLAGS) Main.cpp
Util.o : Util.h Util.cpp
		$(CC) $(CFLAGS) Util.cpp
Heap.o : Heap.h Heap.cpp
		$(CC) $(CFLAGS) Heap.cpp
Graph.o : Graph.h Graph.cpp
		$(CC) $(CFLAGS) Graph.cpp


clean :
		rm *.o