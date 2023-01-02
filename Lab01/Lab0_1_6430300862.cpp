#include <bits/stdc++.h>
using namespace std;

int i, j, k;
void checkPrime(int number) {
  int count = 0;
  for (i = 1; i < 999; i++)
  {
    if (number % i == 0)
    {
      count++;
    }
  }
  
  if (count > 2) {
    cout << "Not prime";
  } else {
    cout << "Prime";
  }
}

int main(){
  int number;
  cout << "input: ";
  cin >> number;
  checkPrime(number);
}