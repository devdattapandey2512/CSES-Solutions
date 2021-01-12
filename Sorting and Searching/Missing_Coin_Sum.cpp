/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna) 
Date: --/--/----

Finding logic and writing code is an art. It is once intellectual property. 
So please don't copy or use it only for reference. Try to solve the question yourself.
*/ 

#include <bits/stdc++.h>
#include <unordered_set>
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
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0, ans;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < n; i++)
    {
        if(v[i] > sum+1)
        {
            break;
        }
        else
        {
            sum += v[i];
        }
    }
    ans = sum + 1;
    cout << ans << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    int tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}