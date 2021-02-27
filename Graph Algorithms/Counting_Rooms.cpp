/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna)
Date: --/--/---- 

Finding logic and writing code is an art. It is once intellectual property.
So please don't copy or use it only for reference. Try to solve the question yourself.
*/


#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <chrono>
#include <complex>
#define ll long long int
#define mod 1000000007
#define inf 1000000000000000001 

using namespace std; 

vector<string> v;
int n, m;

bool can_move(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < m)
    return v[i][j] == '.';
    return false;
}

void DFS(int i, int j)
{
    v[i][j] = '#';
    if(can_move(i-1, j))
    DFS(i-1, j);
    if(can_move(i+1, j))
    DFS(i+1, j);
    if(can_move(i, j+1))
    DFS(i, j+1);
    if(can_move(i, j-1))
    DFS(i, j-1);
    
}

void solve()
{
    
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(can_move(i, j))
            {
                DFS(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}