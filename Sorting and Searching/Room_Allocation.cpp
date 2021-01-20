/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna) 
Date: --/--/----

Finding logic and writing code is an art. It is once intellectual property. 
So please don't copy or use it only for reference. Try to solve the question yourself.
*/ 

#include <bits/stdc++.h>
#include <iostream>
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
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int r = 0, lr = 0;
    vector<int> ans(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //for departure time
    // for(auto x: v)
    // cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    for (int i = 0; i < n; i++)
    {
        if(pq.empty())
        {
            lr = 1;
            pq.push({v[i].first.second, lr});
            ans[v[i].second] = lr;
        }
        else
        {
            pair<int, int> h = pq.top();
            
            if(v[i].first.first > h.first)
            {
                pq.push({v[i].first.second, h.second});
                ans[v[i].second] = h.second;
                pq.pop();
            }
            else
            {
                lr++;
                pq.push({v[i].first.second, lr});
                ans[v[i].second] = lr;
            }
        }
        r = max(r, lr);
    }
    cout << r << endl;
    for(auto x: ans)
    cout << x << " ";
    cout << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    ll tc = 1;
    //cin >> tc;
    //cout << "DEV" << endl;
    for (ll i = 1; i <= tc; i++)
    {
        //cout << "Case #" << tc << ": ";
        solve();
    }
    
	return 0;
}