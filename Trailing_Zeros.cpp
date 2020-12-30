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
// ll no_of_power(ll x)
// {
//     ll count = 0;
//     if(x%5 == 0)
//     {
//         while(x%5 == 0)
//         {
//             count++;
//             x /= 5;
//         }
//         return count;

//     }
//     else
//     return count;
// }
void solve()
{
    ll n;
    scanf("%ld", &n);
    ll ans = 0;
    
    for(ll i = 5; n/i >= 1; i *= 5)
    ans += n/i;
    cout << ans << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    ll tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}