
main : main.o hash_table.o
	g++ hash_table.o main.o  -o main

main.o : main.cpp
	g++ -c main.cpp

hash_table.o : ../src/hash_table.cpp ../src/hash_table.h 
	g++ -c ../src/hash_table.cpp

clean :
	rm *.o main
