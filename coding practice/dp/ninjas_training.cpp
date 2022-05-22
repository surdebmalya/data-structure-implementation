// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

// Medium

#include <bits/stdc++.h>
using namespace std;

int maxEle(vector<int>& arr) {
	int result = INT_MIN;
	for(int i=0; i<arr.size(); i++) {
		if(arr[i]>result) result=arr[i];
	}
	return result;
}

int f(vector<vector<int>> &points, int currRow, string prevActivity, vector<vector<int>>& dp) {
	if(currRow>=0) {
		int running, fighting, learning;
		if(currRow==points.size()-1) {
			running = points[currRow][0] + f(points, currRow-1, "running", dp);
			fighting = points[currRow][1] + f(points, currRow-1, "fighting", dp);
			learning = points[currRow][2] + f(points, currRow-1, "learning", dp);
		}
		else {
			int col;
			if(prevActivity=="running") col=0;
			else if(prevActivity=="fighting") col=1;
			else col=2;
			if(dp[currRow][col]!=-1) return dp[currRow][col];
			if(prevActivity=="running") {
				running = INT_MIN;
				fighting = points[currRow][1] + f(points, currRow-1, "fighting", dp);
				learning = points[currRow][2] + f(points, currRow-1, "learning", dp);
			}
			else if(prevActivity=="fighting") {
				running = points[currRow][0] + f(points, currRow-1, "running", dp);
				fighting = INT_MIN;
				learning = points[currRow][2] + f(points, currRow-1, "learning", dp);
			}
			else {
				running = points[currRow][0] + f(points, currRow-1, "running", dp);
				fighting = points[currRow][1] + f(points, currRow-1, "fighting", dp);
				learning = INT_MIN;
			}
		}
		
		vector<int> total={running, fighting, learning};
		int col;
		if(prevActivity=="running") col=0;
		else if(prevActivity=="fighting") col=1;
		else col=2;
		return dp[currRow][col]=maxEle(total);
	}
}

int ninjaTraining(int n, vector<vector<int>> &points) {
	if(n==1) return maxEle(points[0]);
	// running -> 0, fighting -> 1, learning -> 2;
	vector<vector<int>> dp(n, vector<int>(3, -1));
	return f(points, n-1, "", dp);
}