class Solution {
public:
    int result=0;
    void solve(vector<vector<int>>& grid, int currX, int currY, int destX, int destY, vector<vector<bool>>& visited) {
        int row = grid.size(), col = grid[0].size();
        if(currX==destX and currY==destY) {
            int count=0;
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    if(visited[i][j]==true) count++;
                }
            }
            if(count==row*col) {
                result++;
            }
        }
        else {
            if(currX-1>=0 and visited[currX-1][currY]==false) {
                visited[currX-1][currY] = true;
                solve(grid, currX-1, currY, destX, destY, visited);
                visited[currX-1][currY] = false;
            }
            if(currX+1<=row-1 and visited[currX+1][currY]==false) {
                visited[currX+1][currY] = true;
                solve(grid, currX+1, currY, destX, destY, visited);
                visited[currX+1][currY] = false;
            }
            if(currY-1>=0 and visited[currX][currY-1]==false) {
                visited[currX][currY-1] = true;
                solve(grid, currX, currY-1, destX, destY, visited);
                visited[currX][currY-1] = false;
            }
            if(currY+1<=col-1 and visited[currX][currY+1]==false) {
                visited[currX][currY+1] = true;
                solve(grid, currX, currY+1, destX, destY, visited);
                visited[currX][currY+1] = false;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int startingX, startingY, destX, destY;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j]==1) {
                    startingX=i;
                    startingY=j;
                }
                else if(grid[i][j]==2) {
                    destX=i;
                    destY=j;
                }
            }
        }
        visited[startingX][startingY] = true;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j]==-1) visited[i][j]=true;
            }
        }
        solve(grid, startingX, startingY, destX, destY, visited);
        return result;
    }
};