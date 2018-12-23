#include "Linear_Regression.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    LinearRegression lr(n);
    int m;
    cin >> m;
    vector <vector <double> > X(m);
    for (int i=0;i<X.size();i++) {
        X[i] = (vector<double>) (n+1);
    }
    vector <double> Y(m);

    cout << "Enter the data\n";
    for (int i=0;i<m;i++) {
        for (int j=0;j<n+1;j++) {
            cin >> X[i][j];
        }
        cin >> Y[i];
    }

    lr.train(X,Y);
    vector<double> theta = lr.weightsCalculated();
    cout << theta[0];
    for (int i=1;i<theta.size();i++) {
        cout << " + " << theta[i] << "X" << i;
    }
    return 0;
}