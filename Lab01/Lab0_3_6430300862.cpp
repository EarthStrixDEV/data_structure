#include <bits/stdc++.h>
using namespace std;
int i, j, k ,h;
string db[12] = {"IS", "THIS", "HIS", "AT", "HI","IT", "TWO", "OF", "FAT", "THAT", "HAT", "STAW"};

void menu() {
  cout << "=======================" << endl;
  cout << "         Menu          " << endl;
  cout << "=======================" << endl;
  cout << "1. Print from front" << endl;
  cout << "2. Print from back" << endl;
  cout << "3. Match data base" << endl;
  cout << "4. Exit" << endl;
  cout << "Please choose > ";
}

int main() {
  int c;
  char a[4][4] = {
      {'T', 'H', 'I', 'S'},
      {'W', 'A', 'T', 'S'},
      {'O', 'A', 'H', 'G'},
      {'H', 'G', 'D', 'T'},
  };

  while (true) {
    menu();
    cin >> c;
    switch (c) {
    case 1:
      for (k = 0; k < 4;k++) {
        for (i = 1; i < 5; i++)
        {
          for (j = 0; j < i; j++)
          {
            cout << a[k][j];
          }
          cout << " ";
        }
        cout << endl;
      }
      break;
    case 2:
      for (k = 0; k <= 3;k++) {
        for (i = -2; i > -6; i--)
        {
          for (j = -1; j > i; j--)
          {
            cout << a[k][j];
          }
          cout << " ";
        }
        cout << endl;
      }
      break;
    case 3:
      for (k = 0; k < 4; k++)
      {
        for (i = 1; i < 5; i++)
        {
          string tempStr = "";
          for (j = 0; j < i; j++)
          {
            tempStr += a[k][j];
            for (h = 0; h < 12;h++) {
              if (tempStr == db[h]) {
                cout << h << ". " << db[h] << endl;
              }
            }
          }
        }
      }
      break;
    default:
      exit(0);
    } 
  }
}