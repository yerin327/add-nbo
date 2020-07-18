all : add-nbo

add-nbo : main.o
		g++ -o add-nbo main.o

main.o : 
		g++ -c -o main.o main.cpp

clean : 
		rm add-nbo *.o
