/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna) 
Date: --/--/----

Finding logic and writing code is an art. It is once intellectual property. 
So please don't copy or use it only for reference. Try to solve the question yourself.
*/ 

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define mod 1000000007
#define inf 1000000000000000001

using namespace std;

ll find_min_diff(vector<ll> v, int i, ll total_sum, ll curr_sum)
{
    if(i == 0)
    return abs(total_sum - 2*curr_sum);

    else
    return min(find_min_diff(v, i - 1, total_sum, curr_sum  + v[i-1]), find_min_diff(v, i - 1, total_sum, curr_sum));
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    ll total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total_sum += v[i]; 
    }
    cout << find_min_diff(v, n, total_sum, 0);
}
int main()
{
	std::ios::sync_with_stdio(false);
	
    int tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}