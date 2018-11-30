# Week 9: Structs and Classes

## Structs
- traditionally in C, structs were just a collection of member variables; no member functions
- procedural programming paradigm emphasizes "list" of things program should do and does not focus on objects/data and their relationships to each other
- member variables public by default
- can have member functions in c++, but not generally part of the style
- passing by value, reference, pointers all the same as data types you have worked with

``` cpp
struct account{

 double total;

 double withdrawLimit;

};

  

//Doesn't work because this is a copy of a

void add_byValue(account a, double amount){

 if(amount >=0)

 a.total += amount;

 else{

cout << amount << " is a negative number." << endl;

 }

}

  
//Pass by reference when possible because copying large objects is inefficient
void add_byReference(account& a, double amount){

 if(amount >=0)

 a.total += amount;

 else{

cout << amount << " is a negative number." << endl;

 }

}

  
//Use arrow operator to dereference and access data within struct/class at the same time.
void subtract_pointer(account* a, double amount){

 if(amount >= a->withdrawLimit)

cout << amount << " is greater than the withdraw limit of " << a->withdrawLimit << endl;

 else  if (amount> a->total)

cout << "Funds exceeded." << endl;

 else

 a->total -= amount;

 }

  
void printTotal(account a){

 cout << a.total<< endl;

}
```
- **Question:** What are the potential issues if people directly add or subtract money from objects without using the defined functions?
  - They my forget to check bounds
  - There may be a security issue (not implemented in this example)

- encapsulation is one of the priorities of object oriented programming
  - hide data
  - keep implementation separate from the abstract data type (That way you can change/add functionality later)

## Classes
- classes were created when the object oriented paradigm was created
- classes have private member variables and functions by default
- can have multiple constructors for different situations
- 
```cpp
class Animal

{

 public:

 Animal(string n, string s);

Animal(string n, string s, int a);

  

 //functions to change private variables

 void setAge(int i);

 void setMother(Animal* m);

  

 //functions to get private variables

 string getName();

 string getSpecies();

 int getAge();

 Animal* getMother();

  

 //additional functions

 void print();

  

 private:

 string name;

 string species;

 int age;

 Animal* mother;

  

};

  

typedef Animal* AnimalPtr;
```


- **Question** Can we replace the type of mother with Animal instead of Animal*?  No, otherwise, each animal object would have to store information for itself and its mother. 
- **Question** Can you use AnimalPtr in the class definition for Animal?

- Can have multiple constructors for different cases. 
  - Find stray animal; don't know age
  - Your pet has children; do know age
 ```cpp

Animal::Animal(string n, string s){

 name = n;

 species = s;

}

  

Animal::Animal(string n, string s, int a){

 name = n;

 species = s;

 age = a;

}
 ```
 
 - writing functions for abstract data type (ADT) prevents errors (i.e, negative age)
 ```cpp
void Animal::setAge(int a){

 if (a<0)

cout << "Not valid age";

 else

 age = a;

}
 ```
 - function to find grandmother
 
```cpp

AnimalPtr findGrandmother(Animal& neville){

 AnimalPtr mother = neville.getMother();

 AnimalPtr grandmother = mother->getMother();

 return grandmother;

}```

- function to sort by age
```cpp
void sortAllAnimalsByAge(AnimalPtr* animals, int numAnimals){

  

 bool sorted = false;

 while (! sorted){

sorted = true;

 for(int i = 0; i<numAnimals-1; i++){

 if(animals\[i\]->getAge() > animals\[i+1\]->getAge()){

 AnimalPtr temp = animals\[i\];

 animals\[i\] = animals\[i+1\];

 animals\[i+1\] = temp;

sorted = false;

 }

 }

 }

cout << "sorted by age: " << endl;

 printAllAnimals(animals, numAnimals);

}  

```
- main function
```cpp 
int main(){

  

string name1 = "Luna";

string species1 = "cat";

 Animal luna = Animal(name1, species1);

 luna.setAge(3);

  

string name2 = "Jennifer";

string species2 = "human";

Animal jennifer = Animal(name2, species2, 26);

  

string name3 = "Neville";

string species3 = "cat";

Animal neville = Animal(name3, species3, 0);

  

  

 Animal* p1 = &luna;

 Animal* p2 = &jennifer;

 Animal* p3 = &neville;

  

 //set mothers

 luna.setMother(p2);

 neville.setMother(p1);

  

AnimalPtr* animals = new AnimalPtr\[3\];

 animals\[0\] = &luna;

 animals\[1\] = &jennifer;

 animals\[2\] = &neville;

  

sortAllAnimalsByAge(animals, 3);

  

 //Print Neville's grandmother

 AnimalPtr neville_grandmother = findGrandmother(neville);

cout << "Neville's grandmother is " << neville_grandmother->getName()<< endl;

  

 delete animals;

}
```