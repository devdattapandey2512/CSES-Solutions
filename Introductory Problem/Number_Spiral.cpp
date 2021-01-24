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
#define ll unsigned long long int
#define mod 1000000007
#define inf 1000000000000000001

using namespace std;

ll dis_even(ll a, ll b)
{
    ll mx = max(a, b);
    if(a >= b)
    {
        return mx*mx - (b-1);
    }
    else
    return (mx-1)*(mx-1) + a;
}

ll dis_odd(ll a, ll b)
{
    ll mx = max(a, b);
    if(a <= b)
    {
        return mx*mx - (a-1);
    }
    else
    return (mx-1)*(mx-1) + b;
}

void solve()
{
    ll row, col;
    cin >> row >> col;
    if(max(row, col)%2 == 0)
    {
        cout << dis_even(row, col) << endl;
    }
    else
    {
        cout << dis_odd(row, col) << endl;
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    ll tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}