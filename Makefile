CC = g++

#Executable
Runner.o: main.cpp
	$(CC) -o runner main.cpp

clean:
	rm -f *.o

run:
	make clean
	make Runner.o
	./runner
