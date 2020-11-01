#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	while(n--)
	{
		int m, sum=0; cin >> m;
		vector<int> coins(m);
		for(int &v: coins) 
		{
			cin >> v; sum += v;
		}	
		vector<vector<int>> dp(m+1, vector<int>(sum/2+1));
		for(int i=0;i<=m;++i)
		{
			for(int j=0;j<=sum/2;++j)
			{
				if(i==0 || j ==0)
				{
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = (j-coins[i-1]>-1)?
							max(dp[i-1][j], dp[i-1][j-coins[i-1]]+coins[i-1]):
							dp[i-1][j];
			}
		}
		cout << sum - 2*dp[m][sum/2] << endl;
	}
}