#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <cassert>

#define EPSILON 1e-30

using namespace std;

class LinearRegression {
private:
    vector <double> theta;
    double alpha;
public:
    LinearRegression (const vector<double> intialTheta, const double alpha);
    LinearRegression (const int size, const double alpha);
    LinearRegression (const vector<double> intialTheta);
    LinearRegression (const int size);
    double error (const vector <vector <double> > X, const vector <double> Y, const vector <double> theta);
    double error (const vector <vector <double> > X, const vector <double> Y); 
    void train (const vector< vector<double> > X,const vector <double> Y, int iteration);
    void train (const vector< vector<double> > X,const vector <double> Y);
    vector <double> weightsCalculated ();
    double predict(const vector<double> X);
};