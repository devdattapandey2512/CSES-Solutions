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

bool mycmp(pair<ll, ll > a, pair<ll, ll> b)
{
    return a.first < b.second;
}

void solve()
{
    ll x, p;
    cin >> x >> p;
    vector<ll> v(p);
    set<ll> s;
    s.insert(x);
    s.insert(0);
    map<ll, ll> mp;
    mp[x]++;
    for (ll i = 0; i < p; i++)
    {
        cin >> v[i];
        auto it = s.lower_bound(v[i]);
        ll r = *it;
        --it;
        ll l = *it;
        //cout << v[i] << " " << l << " " << r << endl;
        mp[r-l]--;
        if(!mp[r-l])
        mp.erase(r - l);
        mp[r - v[i]]++;
        mp[v[i] - l]++;
        s.insert(v[i]);
        cout << (--mp.end())->first << " ";

    }
    

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