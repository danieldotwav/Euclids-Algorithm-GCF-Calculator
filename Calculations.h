#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <iostream>
#include <vector>
using namespace std;

// Function Prototypes
void GetValues(int* x, int* y);
void SortNum(int* x, int* y);
void FindCommonFactors(int numSmall, int numLarge, vector<int> &cFactors);
int CalculateGFC(int numSmall, int numLarge);
void Print(int GCF, int num1, int num2);
void UpdateChoice(bool& choice);


#endif