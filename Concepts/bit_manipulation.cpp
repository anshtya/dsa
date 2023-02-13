#include <iostream>
using namespace std;

int main(){
    // ^ XOR operator (if both same -> 0, if both different ->1)
    // ~ inverse operator -> inverses the bits -> also called 1's complement
    // >> right shift operator
    // << left shift operator
    
    int a = 3 << 1; //similar to multiply 3 x 2. shift bits to left 1 times
    int c = 3 << 2; //similar to multiply 3 x 4. shift bits to left 2 times
    int b = 4 >> 1; //similar to divide 4 / 2 shifts bits to right 1 times
    int d = 4 >> 2; //similar to divide 4 / 4 shifts bits to right 2 times
    //these are faster than * and / respectively.
    //these work directly on bits rather than converting from decimal to binary then working on it
    //only for working with 2.
    cout << c << b;

    //swap using bitwise operators
    int e = 5, f = 7;   //5 -> 101, 7 -> 111
    e = e ^ f; //2, 010
    f = e ^ f; //5, 010 ^ 111 = 101 -> 7
    e = e ^ f; //7, 010 ^ 101 = 111 -> 5
    return 0;
}