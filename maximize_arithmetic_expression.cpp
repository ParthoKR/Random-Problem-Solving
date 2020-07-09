/*
Maximum Value of an Arithmetic Expression
Problem Introduction
In this problem, your goal is to add parentheses to a given arithmetic
expression to maximize its value. max(5−8+7×4−8+9) =?
Problem Description
Task. Find the maximum value of an arithmetic expression by specifying the order of applying its arithmetic
operations using additional parentheses.
Input Format. The only line of the input contains a string 𝑠 of length 2𝑛 + 1 for some 𝑛, with symbols
𝑠0, 𝑠1, . . . , 𝑠2𝑛. Each symbol at an even position of 𝑠 is a digit (that is, an integer from 0 to 9) while
each symbol at an odd position is one of three operations from {+,-,*}.
Constraints. 0 ≤ 𝑛 ≤ 14 (hence the string contains at most 29 symbols).
Output Format. Output the maximum possible value of the given arithmetic expression among different
orders of applying arithmetic operations.

Problem source: Course - Algorithmic Toolbox at Coursera Week - 6 Problem no. - 03
*/
#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<long long>>
#define vi vector<long long>
#define pb(v) push_back(v)
#define all(arr) arr.begin(), arr.end()
#define mo make_operation
#define ll long long
vvi pairs(int m, int n)
{
    vvi res;
    for(int i = m; i < n; ++i)
    {
        res.push_back({m,i,i+1,n});
    }
    return res;
}
ll make_operation(ll a, ll b, char c)
{
    ll ans;
    if(c=='+')
        ans = a+b;
    else if(c=='-')
        ans = a-b;
    else if(c=='*')
        ans = a*b;
    return ans;
}
int main()
{
    string s; cin >> s;
    int num_of_operands = (s.size()+1)/2;
    vvi maxi(num_of_operands, vi(num_of_operands));
    vvi mini(num_of_operands, vi(num_of_operands));
    for(int i=0;i<num_of_operands;++i)
    {
        maxi[i][i] = s[i*2]-'0'; mini[i][i] = s[i*2]-'0';
    }
    for(int i=0;i<num_of_operands-1;++i)
    {
        for(int r=0,c=i+1;c<num_of_operands;++r,++c)
        {
            vi temp;
            for(auto p: pairs(r,c))
            {
                char op = s[p[1]*2+1];
                ll u = mo(maxi[p[0]][p[1]], maxi[p[2]][p[3]], op);
                ll v = mo(maxi[p[0]][p[1]], mini[p[2]][p[3]], op);
                ll w = mo(mini[p[0]][p[1]], maxi[p[2]][p[3]], op);
                ll x = mo(mini[p[0]][p[1]], mini[p[2]][p[3]], op);
                temp.pb(u);temp.pb(v);temp.pb(w);temp.pb(x);
            }
            maxi[r][c] = *max_element(all(temp));
            mini[r][c] = *min_element(all(temp));
        }
    }
    cout << maxi[0][num_of_operands-1];
}

