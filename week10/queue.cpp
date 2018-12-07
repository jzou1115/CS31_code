/*
 * C++ Program to Implement Queue using Linked List
 */

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

//Each customer is a "node" that contains:
//1. string name - string identifying the node
//2. Customer *next - pointer to the next customer in line 
class Customer
{
	public:
		Customer();
		void setName(string na);
		void setNext(Customer* ne);
		string getName() const;
		Customer* getNext() const;

	private:
		string name;
		Customer* next;

}*front, *rear, *p, *np;

Customer::Customer(){
	name = "Anonymous";
	next = nullptr;
}

void Customer::setName(string n){
	name = n;
}

void Customer::setNext(Customer* ne){
	next = ne;
}

string Customer::getName() const{
	return name;
}

Customer* Customer::getNext() const{
	return next;
}
//Adds new customer to the queue
void push(string name)
{
	//Pointer to next customer to add to the queue
	np = new Customer;
	np->setName(name);
 	np->setNext(nullptr);

	//If there are no customers in line, new customer is both first and last.  Otherwise, only change rear pointer
	if(front == nullptr){
		front = rear = np;
    	}
	else{
		rear->setNext(np);
  		rear = np;
	}
}

//Removes the customer at the front of the line and prints their name
void remove(){

	string n;
	if (front == nullptr){
		cout<<"Empty queue; no more customers\n";
	}
	else{
        	p = front;
        	n = p->getName();
        	front = front->getNext();
        	delete(p);

		cout << n << endl;
    	}
}

int main()
{
	//Get input data to put in queue
	int n, c = 0;
	string x;
	cout<<"Enter the number of values to be pushed into the queue\n";
	cin>>n;
    	while (c < n)
    	{
		cout<<"Enter the name of the next customer to be entered into the queue\n";
		cin>>x;
        	push(x);
        	c++;
    	}

	//Remove things from queue in the order that they were entered
    	cout<<"\n\nRemoved Values\n\n";
    	while(true)
    	{
		if (front != nullptr)
        	    remove();
		else
		    break; //No more customers
	}
}
