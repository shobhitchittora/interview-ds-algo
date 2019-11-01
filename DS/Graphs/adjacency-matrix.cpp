#include <bits/stdc++.h>

using namespace std;

int main()
{
  int m = 3, n = 3;

  int matrix[m][n];

  srand(time(NULL));

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matrix[i][j] = rand() % 10;
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}