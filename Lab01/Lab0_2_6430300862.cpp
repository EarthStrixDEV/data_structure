#include <bits/stdc++.h>
using namespace std;
int i, j, k;

int main() {
  int c;
  char a[4][4] = {
      {'T', 'H', 'I', 'S'},
      {'W', 'A', 'T', 'S'},
      {'O', 'A', 'H', 'G'},
      {'F', 'G', 'D', 'T'},
  };
  
  while (true) {
    cout << endl;
    cin >> c;
    switch (c)
    {
    case 1:
      for (i = 1; i < 5; i++)
      {
        for (j = 0;j < i;j++)
        {
          cout << a[0][j];
        }
        cout << " ";
      }
      break;
    case 2:
      for (i = 1; i < 5; i++)
      {
        for (j = 0;j < i;j++)
        {
          cout << a[1][j];
        }
        cout << " ";
      }
      break;
    case 3:
      for (i = 1; i < 5; i++)
      {
        for (j = 0;j < i;j++)
        {
          cout << a[2][j];
        }
        cout << " ";
      }
      break;
    case 4:
      for (i = 1; i < 5; i++)
      {
        for (j = 0;j < i;j++)
        {
          cout << a[3][j];
        }
        cout << " ";
      }
      break;
    default:
      exit(0);
    }
  }
}