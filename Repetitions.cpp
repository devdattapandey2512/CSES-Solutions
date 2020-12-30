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

void solve()
{
    string s;
    cin >> s;
    ll ans = 1, temp = 0;
    ll n = s.length();
    for (ll i = 0; i < n; i++)
    {
        if(i > 0)
        {
            if(s[i] != s[i-1])
            {
                ans = max(temp, ans);
                temp = 1;
            }
            else
            temp++;
        }
        else
        temp++;
    }
    ans = max(ans, temp);
    cout << ans << endl;
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