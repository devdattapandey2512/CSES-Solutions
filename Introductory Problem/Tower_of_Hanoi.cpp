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

vector<pair<int, int>> v;

void towerOfHanoi(int n, int from_rod,
                    int to_rod, int aux_rod, int* count) 
{ 
    if (n == 1) 
    { 
        (*count)++;
        v.push_back({from_rod, to_rod});
        //cout << from_rod << " " << to_rod << endl; 
        return; 
    } 
    
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, count); 
    (*count)++;
    v.push_back({from_rod, to_rod});
    //cout << from_rod << " " << to_rod << endl; 
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, count); 
} 
 

void solve()
{
    int n, count = 0;
    scanf("%d", &n);
    //cin >> n;
    towerOfHanoi(n, 1, 3, 2, &count); 
    printf("%d\n", count);
    //cout << count << endl;
    for(auto x: v)
    printf("%d %d\n", x.first, x.second);
    //cout << x.first << " " << x.second << endl;
    //code here
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