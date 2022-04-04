/**
  Student Name: Alan Benitez
  File Name: Parse.hpp
  Assignment number 3

  This class is where I do the permutations as well as "printing" the array S.
  Also, it has some getters and setters, in addition to the factorial method that we will use
  to perform the simulation. Pretty much everything I need in order to run the program.
  
**/

#include "Parse.hpp"
#include <iostream>
#include <fstream>
#include <vector>

//Setter for cities
void Parse::setCities(int city) {
    this->city = city;
}

//Getter of cities
int Parse::getCities(){
    return city;
}

//Filling the s array with the number of city values
void Parse::fillStartArray(){
    for (int i = 1; i < city; ++i) {
        s[i] = i;
    }
}

//Loading the adjacency matrix with the information given in the distances.txt
void Parse::loadData(){
    ifstream inputFile;
    string source = "distances.txt";
    inputFile.open(source);
    if (!inputFile){
        cout << "Unable to open file " << source << endl;
    }else{
        for(int i = 0; i < 20; ++i) {
            for(int j = 0; j < 20; ++j) {
                if(i == j){
                    this->adjacencyMatrix[i][j] = 0;
                }else{
                    inputFile >> this->adjacencyMatrix[i][j];
                }
            }
        }
    }
    inputFile.close();
}

//Returns a formatted string of the tour destinations
string Parse::printS() {
    string tempString;
    s[0] = 0;
    s[city + 1] = 0;
    for(int i = 0; i < city + 1; i++) {
        tempString.push_back(s[i] + '0');
    }
    return tempString;
}

//Pseudocode given in the directives, with some changes, returning a vector of strings
vector<string> Parse::perm1(int permsThisCall) {
    vector<string> storage;
    int m, k, p, q, i;
    int NUMELEMENTS = city;
    string temp = printS();
    storage.push_back(temp);
    for(i = 1; i < permsThisCall; i++)
    {
        m = NUMELEMENTS-2;
        while(s[m] > s[m+1]){
            m = m - 1;
        }
        k = NUMELEMENTS-1;
        while(s[m] > s[k]){
            k = k - 1;
        }
        swap(s[m],s[k]);
        p = m + 1;
        q = NUMELEMENTS-1;
        while(p < q){
            swap(s[p],s[q]);
            p++;
            q--;
        }
        string temp = printS();
        storage.push_back(temp);
    }
    return storage;
}

//Factorial of a given n number
int Parse::factorial(int num) {
    if(num <= 1){
        return 1;
    }else{
        return num * factorial(num - 1);
    }
}

//Method to find the cost of a given tour
double Parse::findCost(string temp) {
    int tempArr[city];
    double cost;
    for (int i = 0; i < temp.length(); i++){
        tempArr[i] = temp[i] - '0';
    }
    for (int j = 0; j < city; j++){
        cost = adjacencyMatrix[tempArr[j]][tempArr[j+1]] + cost;
    }
    return cost;
}

