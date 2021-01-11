/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna) 
Date: --/--/----

Finding logic and writing code is an art. It is once intellectual property. 
So please don't copy or use it only for reference. Try to solve the question yourself.
*/ 

#include <bits/stdc++.h>
#include <stdio.h>
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

void solve()
{
    
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> weights(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }
    sort(weights.begin(), weights.end());
    int ans = 0;
    for (int i = 0, j = n - 1; j > i; )
    {
        while(i < j && weights[i]+weights[j] > x)
        --j;
        if(i >= j)
        break;
        ans++;
        ++i; --j;
    }
    cout << n  - ans << endl;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    solve();

	return 0;
}