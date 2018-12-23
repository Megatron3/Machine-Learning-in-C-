#include <iostream>
#include <vector>

#define epsilon 1e-30

using namespace std;

double alpha = 0.001;

int main() {
	double theta0,theta1,J;
	int m;
	cin >> m;
	vector <double> X(m);												// Input Variables of the dataset
	vector <double> Y(m);												// Output Variables of the dataset
	
	for (int i=0;i<m;i++) {
		cin >> X[i];
		cin >> Y[i];
	}

	theta0 = 0.0, theta1 = 0.0;											// Intial Prediction

	J = 0.0;
	double previousJ = 10.0;

	int total_iterations = 0;
	while (previousJ > J + epsilon || previousJ < J - epsilon) {
		previousJ = J;
		J = 0.0;

		for (int i=0;i<m;i++) {											// Calculating the Error
			J += (theta0 + theta1 * X[i] - Y[i]) 
				* (theta0 + theta1 * X[i] - Y[i]);	
		}		

		J = J/(2*m);																				

		double delta = 0.0;
		double temp0,temp1;

		for (int i=0;i<m;i++) {											// Calculating d(J(theta0,theta1))/d(theta0) 
			delta += theta0 + theta1 * X[i] - Y[i];
		}
		cout << "Delta0 = " << delta << "\n";
		temp0 = theta0 - (delta*alpha)/m;
		delta = 0.0;

		for (int i=0;i<m;i++) {											// Calculating d(J(theta0,theta1))/d(theta1) 
			delta += (theta0 + theta1 * X[i] - Y[i]) * X[i];
		}
		cout << "Delta1 = " << delta << "\n";
		temp1 = theta1 - (delta*alpha)/m;
		delta = 0.0;

		theta0 = temp0;
		theta1 = temp1;

		cout << "Theta0 = " << theta0 << "\n";
		cout << "Theta1 = " << theta1 << "\n";

		printf ("J(theta) = %0.10f\n\n",J);

		total_iterations++;
	}

	cout << "Total Iterations = " << total_iterations << "\n";			// Toatal number of iterations needed
	cout << "Final Equation H(theta) = "; 
	cout << theta0 << " + " << theta1 << "x\n";							// Final Answer
	return 0;
}