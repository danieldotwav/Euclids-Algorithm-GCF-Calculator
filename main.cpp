#include <iostream>
#include <vector>
#include "Calculations.h"

using namespace std;

int main() {
    // Variable Declaration
    int num1{0};
    int num2{0};
    int GCF;
    bool choice = true;
  
    vector<int> cFactors; // vector to store common factors
    
    int *num1Ptr = &num1;
    int *num2Ptr = &num2;
  
    // Welcome Prompt
    cout << "Welcome User\n\n";
    cout << "This program allows you to find the greatest common factor of any two integers\n\n";

    // Get the two numbers
    while(choice) {
        GetValues(num1Ptr, num2Ptr);
        SortNum(num1Ptr, num2Ptr); // now num1 is the smaller value
        GCF = CalculateGFC(num1, num2);
        FindCommonFactors(num1, num2, cFactors);
        Print(GCF, num1, num2);
        UpdateChoice(choice);
    }

    // Exit Prompt
    cout << "Goodbye...\n";
    cout << "Zzz" << endl;
  
    return 0;
}

/**************************
Euclid's Algorithm

If you want the find the greatest common divisor of two numbers, divide the bigger number by the smaller number and record the remainder

remainder = numerator / denominator 
(remainder = largeNum % smallNum)

You then shift the values left such that the denominator is now the numerator and the numerator is now the remainder.
Repeat this until you no longer have a remainder. At this point, the divisor will be the greatest common factor between the two numbers you started with. 
This is known as Euclid's algorithm.
**************************/ 