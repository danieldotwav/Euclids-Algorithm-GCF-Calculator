#include "Calculations.h"
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

// Constants
const int w = 12; // setw width
const int MAX = 100; // max array size (max number of factors)


// Function Definitions
void GetValues(int* x, int* y) {
    int n1, n2;

    std::cout << "Enter the first number: ";
    std::cin >> n1;
    *x = n1;

    std::cout << "Enter the second number: ";
    std::cin >> n2;
    *y = n2;

    std::cout << std::endl;
}

void SortNum(int* x, int* y) {
    int numLarge, numSmall;
    numSmall = *x;
    numLarge = *y;

    if (numSmall > numLarge) {
        *x = numLarge;
        *y = numSmall;
    }
}

void FindCommonFactors(int numSmall, int numLarge, vector<int> &cFactors) {
    vector<int> sFactors;
    vector<int> lFactors;
    int remainder{ 0 };

    // store vfactors of small number in vector
    cout << "Factors of " << numSmall << ": " << setw(w);
    for (int i = 1; i <= numSmall; i++) {
        remainder = numSmall % i;
        if (remainder == 0) {
            sFactors.push_back(i);
            cout << i << " ";
        }
    }
    cout << "\n";
    remainder = 0; // reset value of remainder

    // store factors of large number in vector
    cout << "Factors of " << numLarge << ": " << setw(w);
    for (int i = 1; i <= numLarge; i++) {
        remainder = numLarge % i;
        if (remainder == 0) {
            lFactors.push_back(i);
            cout << i << " ";
        }
    }
    cout << "\n";
    
    // resize common factors vector to ensure enough memory is available to hold all common factors
    cFactors.resize(sFactors.size() + lFactors.size());
    // create an iterator (acts like a pointer to an element in the container - can be used to modify elements as well)
    vector<int>::iterator it;
    
    // set_intersection takes in two input ranges and returns an iterator that points to
    // the element one past the last element of the output range - in this case cFactors
    // It additionally stores elements that are present in both input ranges in cFactors,
    // starting at the first memory location of cFactors: cFactors.begin()
    int count = set_intersection(
        sFactors.begin(), sFactors.end(), // specifies the range of sFactors vector
        lFactors.begin(), lFactors.end(), // specifies the range of lFactors vector
        cFactors.begin()) - cFactors.begin(); // we're then subtracting the new output range (which is the size of cFactors) by the  

    // resize common factors vector again to discard any unused memory 
    cFactors.resize(count);

    // TEST
    cout << "Common Factors: " << setw(w);
    for (it = cFactors.begin(); it != cFactors.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n\n";
}

int CalculateGFC(int numSmall, int numLarge) {
    int remainder{ 0 };
    int count{ 0 };

    do {
        remainder = numLarge % numSmall;
        numLarge = numSmall;
        numSmall = remainder;
        count++;
    } while (remainder != 0);

    return numLarge;
}

void Print(int GCF, int num1, int num2) {
    std::cout << "/////////////////////\n";
    std::cout << "The Greatest Common Factor of " << num1 << " and " << num2 << " is " << GCF << std::endl;
    std::cout << "//////////////\n\n";
}

void UpdateChoice(bool& choice) {
    int input;

    std::cout << "Would you like to run the program again?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n";

    std::cin >> input;
    std::cout << std::endl;

    while (input != 1 && input != 2) {
        std::cout << "Invalid input\n\n";
        std::cout << "Would you like to run the program again?\n";
        std::cout << "1. Yes\n";
        std::cout << "2. No\n";

        std::cin >> input;
    }

    if (input == 1) {
        choice = true;
    }
    else {
        choice = false;
    }
}