#include<stdlib.h>
#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct Pair
{
    int x,y,z;
};
bool compare(Pair p1,Pair p2){
    return p1.x<p2.x;
}

int main(){

    vector<Pair> v;
    v.push_back({1,2,3});
    v.push_back({3,2,3});
    v.push_back({1,6,3});
    v.push_back({9,2,4});
    v.push_back({7,2,3});
    
    sort(v.begin(),v.end(),compare);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i].x;
    }
    




}