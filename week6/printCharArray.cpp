#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int N=10;
const int M=4;


//This print statement has undefined behavior.  The positions after the sentinel are meaningless.
void print(char arr[][N]){
  for(int i=0; i<M; i++){
    for(int j=0; j<N; j++)
      cout << arr[i][j];

    cout << endl;
  }
}

//This print statement should print all c strings as intended.
void print2(char arr[][N]){
	for(int i=0; i<M; i++)
		cout << arr[i] << endl;
}

int main(){
  char scientists[4][10] = {"Newton", 
                          "Maxwell", 
                          "Einstein", 
                          "Feynman"};

  cout << "printing by character: " << endl;
  print(scientists);
  cout << "printing by index: " << endl;
  print2(scientists);
}
