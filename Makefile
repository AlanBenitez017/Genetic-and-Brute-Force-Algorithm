#Alan Benitez
run: main.o GeneticAlgorithm.o Parse.o Simulation.o
		g++ -Wall -o $@ $^
main.o: main.cpp
		g++ -Wall -c main.cpp
GeneticAlgorithm.o: GeneticAlgorithm.hpp GeneticAlgorithm.cpp
		g++ -Wall -c GeneticAlgorithm.cpp
Parse.o: Parse.hpp Parse.cpp
		g++ -Wall -c Parse.cpp
Simulation.o: Simulation.hpp Simulation.cpp
		g++ -Wall -c Simulation.cpp
