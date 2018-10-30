#include <iostream>
#include <cstdlib>

using namespace std;

//simulate two random breaks
//store the first (smaller number) break in break1 and the second break in break2
//hint:  (RAND_MAX - rand())/static_cast<double>(RAND_MAX) chooses a random double between 0 and 1
void breakStick(double& break1, double& break2){

}

//Use the triangle inequality to test pieces
bool testPieces(double p1, double p2, double p3){

}
//I have a stick that is 1 foot long
//If I randomly break it into two spots, what is the probability that the pieces form a triangle
int main ()
{
	int numSimulations = 1000;
	double triangle = 0;
	for ( int i =0 ; i < numSimulations; i++){
		//simulate two breaks
		double break1;
		double break2;

		//calculate the lengths of the sticks
		double piece1;
		double piece2;
		double piece3;

		//test whether the pieces make a triangle
		bool formTriangle = testPieces(piece1, piece2, piece3);

		if( formTriangle){
			triangle += 1;
		}
	}

	//probability that pieces make a triangle
	double probability = triangle / numSimulations;

	cout << "The empirical probability is " << probability << endl;

	return 0;
}


