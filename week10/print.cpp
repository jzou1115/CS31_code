#include <iostream>
using namespace std;

class Car {
	public:
		Car(string m, int y){
			model = m;
			year = y;
		}
		string getModel(){ 
			return model;
		}
		int getYear(){
			return year;
		}

	private:
		string model;
		int year;
};


class printData {
	public:
		void print(int i) {
			cout << i << endl;
		}

		void print(int arr[], int size){
			cout << "[ ";
			for(int i=0; i< size; i++){
				cout << arr[i]<<" ";
			}
			cout << "]" << endl;
	   	}

		void print(Car c){
			cout << c.getModel() << " " << c.getYear() << endl;
		}
};



int main(void) {
	printData pd;
 
	// Call to print integer
	pd.print(5);

   
	// Call to print array
	int array[] = {2, 4, 6, 8, 10};
	pd.print(array, 5);

	// Call to print Car
	Car c = Car("Toyota Camry", 2018);
	pd.print(c);
	return 0;
}
