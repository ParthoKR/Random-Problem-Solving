#include <iostream>
#include <vector>
int main()
{
	int cap, item;
	std::cin >> cap >> item;
	std::vector<int> items(item);
	for (int i = 0; i < item; ++i)
	{
		std::cin >> items[i];
	}
	std::vector<std::vector<int>> dp(item+1, std::vector<int>(cap+1));
	for(int i=0;i<item+1;++i) dp[i][0]=0;
	for(int i=0;i<cap+1;++i) dp[0][i]=0;
	for (int i = 1; i < item+1; ++i)
	{
		for (int j = 1; j < cap+1; ++j)
		{
			int x = j-items[i-1];
			if (x<0)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-items[i-1]]+items[i-1]);
		}
	}
	std::cout << dp[item][cap];
	return 0;
}