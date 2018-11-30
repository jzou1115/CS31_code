#include <iostream>
#include <string>
using namespace std;



class Animal
{
	public:
		Animal(string n, string s);
		Animal(string n, string s, int a);

		//functions to change private variables
		void setAge(int i);
		void setMother(Animal* m);

		//functions to get private variables
		string getName() const;
		string getSpecies() const;
		int getAge() const;
		Animal* getMother() const;

		//additional functions
		void print() const;
		
	private:
		string name;
		string species;
		int age;
		Animal* mother;
	
};


typedef Animal* AnimalPtr;

Animal::Animal(string n, string s){
	name = n;
	species = s;
}

Animal::Animal(string n, string s, int a){
	name = n;
	species = s;
	age = a;
}

void Animal::setAge(int a){
	if (a<0)
		cout << "Not valid age";
	else
		age = a;
}

void Animal::setMother(AnimalPtr m){
	mother = m;
}

string Animal::getName() const{
	return name;
}	
string Animal::getSpecies() const{
	return species;
}
int Animal::getAge() const{
	return age;
}

AnimalPtr Animal::getMother() const{
	return mother;
}

void Animal::print() const{
	cout << name << " the " << species << endl;
}

void printAllAnimals(AnimalPtr animals[], int numAnimals){
	for(int i = 0 ; i<numAnimals; i++){
		animals[i]->print();
	}
}

void sortAllAnimalsByAge(Animal* animals[], int numAnimals){

	bool sorted = false;
	while (! sorted){
		sorted = true;
		for(int i = 0; i<numAnimals-1; i++){
			if(animals[i]->getAge() > animals[i+1]->getAge()){
				AnimalPtr temp = animals[i];
				animals[i] = animals[i+1];
				animals[i+1] = temp;
				sorted = false;
			}
		}		
	}
	cout << "sorted by age: " << endl;
	printAllAnimals(animals, numAnimals);
}

AnimalPtr findGrandmother(Animal* neville){
	AnimalPtr mother = neville->getMother();
	AnimalPtr grandmother = mother->getMother();
	return grandmother;
}

int main(){

	string name1 = "Luna";
	string species1 = "cat";
	AnimalPtr luna = new Animal(name1, species1);
	luna->setAge(3);

	string name2 = "Jennifer";
	string species2 = "human";
	AnimalPtr jennifer = new Animal(name2, species2, 26);
	
	string name3 = "Neville";
	string species3 = "cat";
	AnimalPtr neville = new Animal(name3, species3, 0);


	//set mothers
	luna->setMother(jennifer);
	neville->setMother(luna);

	Animal* animals[3];
	animals[0] = luna;
	animals[1] = jennifer;
	animals[2] = neville;

	sortAllAnimalsByAge(animals, 3);

	//Print Neville's grandmother
	AnimalPtr neville_grandmother = findGrandmother(neville);
	cout << "Neville's grandmother is " << neville_grandmother->getName()<< endl;

	delete luna;
	delete jennifer;
	delete neville;
}

