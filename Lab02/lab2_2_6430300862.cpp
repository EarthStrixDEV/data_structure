#include <bits/stdc++.h>
using namespace std;
int menu()
{
  int c;
  cout << endl;
  cout << "==Menu==" << endl;
  cout << "1.insert" << endl;
  cout << "2.delete" << endl;
  cout << "3.print" << endl;
  cout << "4.exit" << endl;
  cout << "Please choose: ";
  cin >> c;
  return c;
}

int findPos(int a[], int size, int data)
{
  int pos;
  for (int i = 0; i < size; i++)
  {
    if (data <= a[i])
    {
      pos = i;
      break;
    }
  }
  return pos;
}

int main()
{
  int c;
  int a[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  int size = 0;
  int data;
  int pos;
  while (true)
  {
    c = menu();
    switch (c)
    {
    case 1:
      cout << "Enter data: ";
      cin >> data;
      if (size == 0)
      {
        a[0] = data;
        size++;
      }
      else
      {
        if (data > a[size - 1])
        {
          a[size] = data;
          size++;
        }
        else
        {
          pos = findPos(a, size, data);
          for (int i = size - 1; i >= pos; i--)
          {
            a[i + 1] = a[i];
          }
          size++;
          a[pos] = data;
        }
      }
      for (int i = 0; i < size; i++)
      {
        cout << a[i] << " ";
      }
      break;
    case 2:
      cout << "Enter data: ";
      cin >> data;
      pos = findPos(a, size, data);
      if (pos < size)
      {
        size = size - 1;
        for (int j = pos; j < size; j++)
        {
          a[j] = a[j + 1];
        }
      }
      for (int i = 0; i < size; i++)
      {
        cout << a[i] << " ";
      }
      break;
    case 3:
      for (int i = 0; i < size; i++)
      {
        cout << a[i] << " ";
      }
      break;
    default:
      exit(0);
    }
  }
}