# Week 6: C Strings & 2D Arrays

## Review

### C Strings
- A c string is an array of chars with a sentinal at the end ('/0')
- C libraries with useful functions for c strings (cstring)
  - pg 381 in book
- **Question**: What is the difference between s and s2?
```cpp
  char s[5] = {'H', 'e', 'l', 'l', 'o'};
  char s2[6] = "Hello";
  ```
- **Question**: What happens when you try the following?
```cpp
char s[5] = "Hello";
```

- **Question**: What is the output of 
```cpp
char s2[6] = "Hello";
cout << strlen(s2) << endl;
```
- C libraries with useful functions for dealing with chars (cctype)
  - pg 396

- You are supposed to ignore certain charactes in your homework, but you cannot change the input.  You may want to make a copy of various c strings using the strcpy and strncpy functions.  
- *Example of strcpy*
 ```cpp
char hi[3];
strcpy(hi, "hi");
```
- You can also copy a shorter string into a longer one.  However, if you do the reverse, you will get an error.
 ```cpp
char longCString[100];
strcpy(longCString, "hi");
```
- *Example of strncpy*
```cpp
char empty[100];
strncpy(empty, hi, 99)
```
- **Question**: What happens if we set the limit of charaters to copy to 100?

### 2D arrays of chars

- An array of strings can be represented as a 2D array of chars
- Make sure to leave enough space for the sentinal char
- printCharArray.cpp
```cpp
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
```
- ***Question:*** Why don't we need to specify the first dimension?  Do we need to specify the second dimension? Why?
- If we know the maximum length of each string, we can index the array easily in memory.

### Pointers and dereferencing

- Memory is split into two main parts: stack and heap
- The stack is temporary. *"static memory allocation"*
  - Each function allocates a portion of memory on the stack and deallocates it when the function is done running.
  - When the function is done running, variables created on the stack do not exist anymore.
- The heap is more permanent. *"dynamic memory allocation"**
  - variables created on the heap can be used after function finishes executing
  - You can create a variable on the heap using "new" (ex, int *p1 = new int)
  - The new operator creates a new variable of the specified type on the heap and returns a pointer to the variable.
- Example from page 432 (pointers.cpp)
```cpp
int main(){
        int *p1, *p2;

        //make p1 point to an int located on the heap
        p1=new int;

        //set the variable that p1 points to
        *p1=42;

        //Make p2 point to the same variable as p1
        p2 = p1;

        //Should both print 42
        cout << "*p1== " << *p1 << endl;
        cout << "*p2== " << *p2 << endl;

        //Set the variable that p2 points to
        *p2=53;

        //Should both print 53
        cout << "*p1== " << *p1 << endl;
        cout << "*p2== " << *p2 << endl;

        //Make p1 point to a new int located on the heap;
        p1 = new int;
        //Set the variable that p1 points to
        *p1=88;

        //p1 and p2 now point to different places in the heap
        //p1=88
        //p2=53
        cout << "*p1== " << *p1 << endl;
        cout << "*p2== " << *p2 << endl;

        return 0;
}
```

## Worksheet 5

### Question 1

Write a function that inserts a character 'c' into a c string (str) at index ind.  Let the maximum length of the array be max.  If the insertion is successful, return true.  Otherwise, return false.

Example:
```cpp
char test[20] = "aaaaaa";
bool res = insert(test, 20, 1, 'b'); // res should now store "abaaaaa"
```
**Question:** When does this function return false?
- ind < 0
- ind > max
- the length of the string is already max -1

```cpp
bool insert(char str[], int max, int ind, char c){
  //Invalid index
  if(ind<0) 
     return false;
  int len = strlen(str);
  
  //The insertion place is outside of the string OR 
  //The length of the string is already max-1.  Adding another character would get rid of the sentinel.
  if(ind > len || len+1 >= max)
    return false;
  
  //Starting from position ind, insert c
  //Then, repeatedly shift characters by one position to the left
  char charToInsert = c;
  do{
    char temp = str[ind];
    str[ind] = charToInsert;
    charToInsert = temp;
    ind++;
  } while (charToInsert != '\0');  // Stop shifting characters when sentinel is reached
  
  //Add sentinel to the end of the c string
  str[ind+1] = '\0';
  
  return true;
      
}
```

