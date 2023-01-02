#include <bits/stdc++.h>
using namespace std;
string db[20] = {"IS", "THIS", "HIS", "AT", "YOU", "HI", "IT", "TWO",
                 "OF", "FAT", "THAT", "HAT", "GOD", "CAT", "GO",
                 "HAT", "AN", "FOUR", "STAW"};
int i, k, l, j;
char a[4][4] = {
    {'T', 'H', 'I', 'S'},
    {'W', 'A', 'T', 'S'},
    {'O', 'A', 'H', 'G'},
    {'F', 'G', 'D', 'T'}
};
int menu()
{
  int c;
  cout << endl;
  cout << "==================\n";
  cout << "       Menu       \n";
  cout << "==================\n";
  cout << "1. Print from front\n";
  cout << "2. Print All\n";
  cout << "3. Match data base\n";
  cout << "4. Exit \n";
  cout << "Please choose: ";
  cin >> c;
  return c;
}
void printFromFront() {
  int line;
  cout << "input: ";
  cin >> line;
  switch (line)
  {
  case 1:
    for (i = 0; i < 4; i++)
    {
      for (j = i; j < 4; j++)
      {
        for (k = i; k <= j; k++)
        {
          cout << a[0][k];
        }
        cout << " ";
      }
      cout << endl;
    }
    break;
  case 2:
    for (i = 0; i < 4; i++)
    {
      for (j = i; j < 4; j++)
      {
        for (k = i; k <= j; k++)
        {
          cout << a[1][k];
        }
        cout << " ";
      }
      cout << endl;
    }
    break;
  case 3:
    for (i = 0; i < 4; i++)
    {
      for (j = i; j < 4; j++)
      {
        for (k = i; k <= j; k++)
        {
          cout << a[2][k];
        }
        cout << " ";
      }
      cout << endl;
    }
    break;
  case 4:
    for (i = 0; i < 4; i++)
    {
      for (j = i; j < 4; j++)
      {
        for (k = i; k <= j; k++)
        {
          cout << a[3][k];
        }
        cout << " ";
      }
      cout << endl;
    }
    break;
  default:
    break;
  }
}
void printAll() {
  for (l = 0; l < 4; l++)
  {
    for (i = 0; i < 4; i++)
    {
      for (j = i; j < 4; j++)
      {
        for (k = i; k <= j; k++)
        {
          cout << a[l][k];
        }
        cout << " ";
      }
      cout << endl;
    }
  }
}
void matchFromDB(){
  for (l = 0; l < 4; l++)
  {
    for (i = 0; i < 4; i++)
    {
      for (j = i; j < 4; j++)
      {
        string tempStr = "";
        for (k = i; k <= j; k++)
        {
          tempStr += a[l][k];
        }
        for (int m = 0; m < 20; m++)
        {
          if (tempStr == db[m])
          {
            cout << db[m] << endl;
          }
        }
      }
    }
  }
}
int main(){
  while (true)
  {
    switch (menu())
    {
    case 1:
      printFromFront();
      break;
    case 2:
      printAll();
      break;
    case 3:
      matchFromDB();
      break;
    default:
      exit(0);
    }
  }
}