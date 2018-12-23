#include "Linear_Regression.h"

LinearRegression::LinearRegression (const vector<double> intialTheta, double alpha) {
    for (int i=0;i<intialTheta.size();i++) {
        theta.push_back(intialTheta[i]);
    }
    this->alpha = alpha;
}

LinearRegression::LinearRegression (const int size, double alpha) {
    for (int i=0;i<size+1;i++) {
        theta.push_back(0.0);
    }
    this->alpha = alpha;
}

LinearRegression::LinearRegression (const vector<double> intialTheta) {
    for (int i=0;i<intialTheta.size();i++) {
        theta.push_back(intialTheta[i]);
    }
    this->alpha = 0.01;
}

LinearRegression::LinearRegression (const int size) {
    for (int i=0;i<size+1;i++) {
        theta.push_back(0.0);
    }
    this->alpha = 0.01;
}

double LinearRegression::error (const vector <vector <double> > X, const vector <double> Y, const vector <double> theta) {
    assert (X.size() == Y.size());
    for (int i=0;i<X.size();i++) {
        assert (X[i].size() == theta.size());
    }

    double J = 0.0,temp = 0.0;
    for (int i=0; i<X.size(); i++) {
        
        temp = 0.0;
        for (int j=0; j<X[i].size(); j++) {
            temp += X[i][j] * theta[j];
        }
        temp = temp - Y[i];
        
        J += pow(temp, 2);
    }
    J = J/(2.0 * X.size());

    return J;
}

double LinearRegression::error (const vector <vector <double> > X, const vector <double> Y) {
    assert (X.size() == Y.size());
    for (int i=0;i<X.size();i++) {
        assert (X[i].size() == (this->theta).size());
    }

    double J = 0.0,temp = 0.0;
    for (int i=0; i<X.size(); i++) {

        temp = 0.0;
        for (int j=0; j<X[i].size(); j++) {
            temp += X[i][j] * (this->theta)[j];
        }
        temp = temp - Y[i];
        
        J += pow(temp, 2);
    }
    J = J/(2.0 * X.size());
    
    return J;
}

void LinearRegression::train (const vector< vector<double> > X,const vector <double> Y, int iteration) {
    double J = 0.0;
    double previousJ = 0.0;
    double m = (double)X.size();
    
    for (int k=0; k<iteration; k++) {
        previousJ = J;
        J = error (X,Y,this->theta);

        if (J > previousJ + 0.1) {
            alpha = alpha / 3;
            k = 0;
            continue;
        }

        for (int i=0;i<X.size();i++) {
            
            double temp = 0.0;
            for (int j=0;j<X[i].size();j++) {
                temp += X[i][j] * (this->theta)[j]; 
            }
            temp = temp - Y[i];

            for (int j=0; j<(this->theta).size(); j++) {
                (this->theta)[j] -= (alpha/m) * temp * X[i][j]; 
            }
        }
    }
}

void LinearRegression::train (const vector< vector<double> > X,const vector <double> Y) {
    double J = 0.0;
    double previousJ = 0.0;
    double m = (double)X.size();
    bool first = true;

    vector <double> tempTheta((this->theta).size(),0.0);
    while (J + EPSILON < previousJ || first) {
        
        for (int i=0;i<tempTheta.size();i++) {
            tempTheta[i] = 0;
        }
        previousJ = J;
        J = error (X,Y);

        cout << "Error = " << J << "\n";

        if (J > previousJ && !first) {
            alpha = alpha/3;
            continue;
        }

        for (int i=0;i<X.size();i++) {
            
            double temp = 0.0;
            for (int j=0;j<X[i].size();j++) {
                temp += X[i][j] * (this->theta)[j]; 
            }
            temp = temp - Y[i];

            for (int j=0;j<theta.size();j++) {
                tempTheta[i] = temp * X[i][j];
            }
        }

        for (int i=0;i<theta.size();i++) {
            theta[i] = theta[i] - (alpha/((double)X.size())) * tempTheta[i]; 
        }
        if (first) {
            first = false;
            previousJ = J + 1.0;
        }
    }
}

vector <double> LinearRegression::weightsCalculated () {
    vector <double> t;
    for (int i=0;i<(this->theta).size();i++) {
        t.push_back(this->theta[i]);
    }
    return t;
}

double LinearRegression::predict(const vector <double> X) {
    double H = 0.0;
    for (int i=0;i<X.size();i++) {
        H += X[i]*(this->theta)[i];
    }
}