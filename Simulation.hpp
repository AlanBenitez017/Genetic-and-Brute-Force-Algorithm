/**
  Student Name: Alan Benitez
  File Name: GeneticAlgorithm.hpp
  Assignment number 3

  This class is the header file of Simulation.cpp where I declare a variable that will be used
  to run the program and a function to do the mutations by swapping some cities.
  
**/

#ifndef SIMULATION_HPP
#define SIMULATION_HPP
#include "GeneticAlgorithm.hpp"
#include "Parse.hpp"

using namespace std;

class Simulation{
    
    public:
        void Run();
        void SwitchCities(int numMut, vector<string> elites, vector<string> total);
};
#endif
