/**
  Student Name: Alan Benitez
  File Name: Parse.hpp
  Assignment number 3

  This class is the header file of parse.cpp where I declare the variables that I will be using
**/

#ifndef PARSE_HPP
#define PARSE_HPP
#include <string>
#include <vector>

using namespace std;

class Parse{
    private:
        int city;
        int s[20];
        double adjacencyMatrix[20][20];
    public:
        void setCities(int city);
        int getCities();
        void fillStartArray();
        string printS();
        void loadData();
        int factorial(int num);
        double findCost(string temp);
        vector<string> perm1(int permsThisCall);
};
#endif
