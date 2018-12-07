#include <iostream>
#include <string>

using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 4;

class Seat{
	public:
		Seat(int r, int c);
		void setPrice(double p);
		int getRow() const;
		int getCol() const;
		double getPrice() const;
		void buySeat();
		bool isSold();
	private:
		int row;
		int col;
		double price;
		bool sold;
};

class Airplane{
	public: 
		Airplane();
		void buySeat(int r, int c);
		int countSeatsRemaining();
		Seat* findCheapestSeat();
	private:
		Seat* seats[MAX_ROWS][MAX_COLS];
};

//Implement member functions for Seat
Seat::Seat(int r, int c){
	if(r>=0 && r<MAX_ROWS && c>=0 && c<MAX_ROWS){
		
		row = r;
		col = c;
		sold = false;
	}
	else{
		cout << "Invalid rows/cols " << r << " " << c << endl;
	}
}
void Seat::setPrice(double p){
	price = p;
}
int Seat::getRow() const{
	return row;
}
int Seat::getCol() const{
	return col;
}
double Seat::getPrice() const{
	return price;
}

void Seat::buySeat(){
	if(sold){
		cout << "This seat is not available." << endl;
	}
	else{
		sold = true;
	}
}

bool Seat::isSold(){
	return sold;
}

//Implement member functions for Airplane
Airplane::Airplane(){

	//Maximum price for ticket is $1000.  Each seat after is $1 less
	double curPrice = 1000;
	//Initialize seats and prices
	for(int i=0; i<MAX_ROWS ; i++){
		for(int j=0; j<MAX_COLS ; j++){
			Seat* curSeat = new Seat(i, j);
			curSeat->setPrice(curPrice);
			seats[i][j] = curSeat;
			curPrice--;
		}
	}
}

int Airplane::countSeatsRemaining(){
	int count = 0; //Number of seats remaining
	for(int i=0; i<MAX_ROWS ; i++){
                for(int j=0; j<MAX_COLS ; j++){
			Seat* curSeat = seats[i][j];
			if (!curSeat->isSold()){
				count++;
			}
		}
	}
	return count;
}

Seat* Airplane::findCheapestSeat(){
	for(int i=MAX_ROWS-1; i>=0; i--){
		for(int j=MAX_COLS-1; j>=0; j--){
			Seat* curSeat = seats[i][j];
			if (!curSeat->isSold()){
				return curSeat;
			}
		}
	}

	cout << "No seats left on this plane" << endl;
	return nullptr;
}
void Airplane::buySeat(int r, int c){
	Seat* curSeat = seats[r][c];
	curSeat->buySeat();
}

int main(void) {

	Airplane* a = new Airplane();

	for(int i=0; i<MAX_ROWS-2 ; i++){
		for(int j=0; j<MAX_COLS ; j++){
			a->buySeat(i,j);
		}
	}


	int seatsRemaining = a->countSeatsRemaining();
	cout << "Seats remaining: " << seatsRemaining<< endl;


	Seat* cheapest = a->findCheapestSeat();
	cout << "The cheapest seat costs: " << cheapest->getPrice() << endl;

	//try to buy seat that is already purchased
	a->buySeat(0,0);
	return 0;
}
