/**
  Student Name: Alan Benitez
  File Name: Simulation.cpp
  Assignment number 3

  This class is where I implement the program and call the needed methods to run the program.
  
**/

#include "Simulation.hpp"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

void Simulation::Run(){

    //Creating objects needed to perform calculations, costs, etc
    GeneticAlgorithm genAl;
    Parse parse;

    /*Prompting the user the number of cities to run and setting them and also 
    calling the method to load the data on distances.txt and load the array*/
    int numCities;
    cout << "Please enter the number of cities to run: " << endl;
    cin >> numCities;
    parse.setCities(numCities);
    parse.loadData();
    parse.fillStartArray();

    //Prompting the user to enter the number of tours and setting it
    int numTours;
    cout << "Please enter the number of tours: " <<  endl;
    cin >> numTours;
    genAl.setTours(numTours);

    //Prompting the user to enter the number of generations and setting it
    int numGen;
    cout << "Please enter the number of generations to run: " << endl;
    cin >> numGen;
    genAl.setGeneration(numGen);

    //Prompting the user about the percentage that will want to use it
    cout << "What percentage of a generation should be comprised of mutations?" << endl;
    int numPer;
    cin >> numPer;
    genAl.setPercentage(numPer);
    cout << "-------------------------------------------"<< endl;
    cout << "Number of cities run: " << parse.getCities()<< endl;
    cout << "-------------------------------------------"<< endl;

    //Allocating memory on the heap and also the setting the timer structure   
    struct timeval * t;
    t = (struct timeval *)malloc(sizeof(struct timeval));
    gettimeofday(t,NULL);
    time_t startSeconds = t->tv_sec;

    //Computing the number of mutated tours needed
    int numMut = genAl.getTours() * genAl.getPercentage() / 100;
    double gaCost = 100000;
    double gaLowest = 10000;

    for (int i = 0; i < genAl.getGeneration(); i++) {
        vector<string> temp1 = parse.perm1(genAl.getTours());
        vector<string> elites;
        vector<string> total;
        string elite;

        //selecting two elites from each generation
        for (int j = 0; j < 2; j++) {
            double lowest = 100000;
            double cost = 100000;
            int index;

            for (int k = 0; k < temp1.size(); k++) {
                string tempS = temp1.at(k);
                cost = parse.findCost(tempS);
                if(cost < lowest){
                    lowest = cost;
                    elite = temp1.at(k);
                    elites.push_back(elite);
                    index = k;
                }
            }
            elites.at(j) = temp1.at(index);
            temp1.erase(temp1.begin() + index);
        }
        
        //Doing the mutations by switching 3 cities
        SwitchCities(numMut, elites, total);
        

        //Fresh permutations used to fill the rest of the tour
        vector<string> permutations = parse.perm1(genAl.getTours() - total.size());
        for(int i = 0; i < permutations.size(); i++) {
            total.push_back(permutations.at(i));
        }

        //Doing the genetic algorithm lowest cost tour
        for(int i = 0; i < genAl.getTours(); i++){
            string stringTemp = total.at(i);
            gaCost = parse.findCost(stringTemp);
            if(gaCost < gaLowest){
                gaLowest = gaCost;
            }
        }
    }

    //Time spent to run the genetic algorithm and the cost
    gettimeofday(t,NULL);
    cout << "It took the Genetic algorithm: " << t->tv_sec - startSeconds << " seconds and " << t->tv_usec << " microseconds." << endl;
    cout << "Genetic algorithm cost: "<< gaLowest << endl << endl;


    //Finding the optimal brute force cost
    vector<string> bruteVector = parse.perm1(parse.factorial(parse.getCities()));
    double bruteCost = 10000;
    double bruteLowest = 10000;
    for(int i = 0; i < bruteVector.size(); i++){
        string temp = bruteVector.at(i);
        bruteCost = parse.findCost(temp);
        if(bruteCost < bruteLowest){
            bruteLowest = bruteCost;
        }
    }

    //Time spent to run the brute force algorithm and the cost
    gettimeofday(t,NULL);
    cout << "It took the Brute force algorithm: " << t->tv_sec - startSeconds << " seconds and " << t->tv_usec << " microseconds." << endl;
    cout << "Optimal Brute force cost: " << bruteLowest << endl << endl;

    //Total percentage of the optimal solution
    int totalPercentage;
    totalPercentage = (gaLowest/bruteLowest) * 100;
    cout << "The Genetic algorithm produced a solution that is " << totalPercentage << "% of the optimal solution." << endl;

}

//Doing the mutations by switching 3 cities
void Simulation::SwitchCities(int numMut, vector<string> elites, vector<string> total){
    for (int i = 0; i < numMut; i++) {
            char tc1, tc2, tc3;
            string tempString;
            if(i % 2 == 0){
                tempString = elites.at(1);
                tc1 = tempString[1];
                tc2 = tempString[2];
                tc3 = tempString[3];
                tempString[1] = tc2;
                tempString[2] = tc3;
                tempString[3] = tc1;
                total.push_back(tempString);
            }else{
                tempString = elites.at(0);
                tc1 = tempString[1];
                tc2 = tempString[2];
                tc3 = tempString[3];
                tempString[1] = tc3;
                tempString[2] = tc1;
                tempString[3] = tc2;
                total.push_back(tempString);
            }
    }

}


