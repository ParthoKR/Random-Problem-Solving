#include <iostream>
#include <string>
#include <algorithm>
int main()
{
	std::string a,b; std::cin >> a >> b;
	int matrix[101][101];
	matrix[0][0] = 0;
	for (int i = 1; i <= a.length(); ++i) matrix[0][i] = i;
	for (int i = 0; i <= b.length(); ++i) matrix[i][0] = i;
	for (int i = 1; i <= b.length(); ++i)
	{
		for (int j = 1; j <= a.length(); ++j)
		{
			if(a[j-1]==b[i-1])
			{
				matrix[i][j] = matrix[i-1][j-1];
			}
			else
			{
				matrix[i][j] = std::min(std::min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1])+1;				
			}
		}
	}
	std::cout << matrix[b.length()][a.length()];
	return 0;
}