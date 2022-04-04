/**
  Student Name: Alan Benitez
  File Name: GeneticAlgorithm.hpp
  Assignment number 3

  This class is the header file of GeneticAlgorithm.cpp where I declare the variables that I will be using.
  
**/

#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

using namespace std;

class GeneticAlgorithm{

    private:
        int generations;
        int tours;
        int percentage;

    public:
        void setGeneration(int generations);
        int getGeneration();
        void setTours(int tours);
        int getTours();
        void setPercentage(int percentage);
        int getPercentage();

};
#endif
