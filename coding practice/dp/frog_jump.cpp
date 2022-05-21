// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

// Easy

#include <bits/stdc++.h>
using namespace std;
int frogJump(int n, vector<int> &heights) {
    vector<int> arr(n, -1);
	if(n==1) return 0;
	else if(n==2) return abs(heights[1]-heights[0]);
	arr[0]=0;
	arr[1]=abs(heights[1]-heights[0]);
	for(int i=2; i<n; i++) {
		arr[i]=min(arr[i-2]+abs(heights[i-2]-heights[i]), arr[i-1]+abs(heights[i-1]-heights[i]));
	}
	return arr[n-1];
}