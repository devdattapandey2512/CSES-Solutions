/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna) 
Date: --/--/----

Finding logic and writing code is an art. It is once intellectual property. 
So please don't copy or use it only for reference. Try to solve the question yourself.
*/ 

#include <bits/stdc++.h>
#include <set>
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
    int n, m;
    cin >> n >> m;
    vector<int> t(m);
    set<pair<int, int>> h;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        h.insert({x, i});
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        auto it = h.lower_bound({t+1, 0});
        if(it == h.begin())
        cout << "-1" << endl;
        else
        {
            --it;
            cout << (*it).first << endl;
            h.erase(it);
        }
    }
    

}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    solve();

	return 0;
}