/**
  Student Name: Alan Benitez
  File Name: GeneticAlgorithm.cpp
  Assignment number 3

  This class is where I have my setter and getters needed for the simulation
**/

#include "GeneticAlgorithm.hpp"

//Getter for generations
int GeneticAlgorithm::getGeneration() {
    return generations;
}

//Setter for generations
void GeneticAlgorithm::setGeneration(int generations) {
    this->generations = generations;
}

//Tours setter
void GeneticAlgorithm::setTours(int tours){
    this->tours = tours;
}

//Tours getter
int GeneticAlgorithm::getTours(){
    return tours;
}

//Percentage setter
void GeneticAlgorithm::setPercentage(int percentage){
    this->percentage = percentage;
}

//Percentage getter
int GeneticAlgorithm::getPercentage(){
    return percentage;
}

