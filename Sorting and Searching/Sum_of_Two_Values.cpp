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

bool mycmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    int i = 0, j = n-1;
    bool ans = false;
    while(j > i)
    {
        int sum = v[i].first + v[j].first;
        if(sum < x)
        i++;
        else if(sum > x)
        j--;
        else
        {
            cout << v[i].second+1 << " " << v[j].second+1;
            ans = true;
            break;
        }
        
    }
    if(!ans)
    cout << "IMPOSSIBLE" << endl; 
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin .tie(0);
    
    int tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}