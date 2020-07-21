FLAGS = -Wall -O3 -c
CC = g++

.PHONY : all clean

all: main.exe

main.exe: main.o ngon_random.o
	$(CC) main.o ngon_random.o -o main.exe

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

ngong_random.o: ngon_random.cpp
	$(CC) $(FLAGS) ngon_random.cpp

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.out

print-%  : ; @echo $* = $($*)
