//approach - 1
//time complexity - O(m * n)
//space complexity - O(1)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Apply 2D Prefix Sum: Current = Top + Left - Diagonal (to avoid double counting)
                if(i - 1 >= 0) {
                    grid[i][j] += grid[i - 1][j];
                }
                if(j - 1 >= 0) {
                    grid[i][j] += grid[i][j - 1];
                }
                if(i - 1 >= 0 && j - 1 >= 0) {
                    grid[i][j] -= grid[i - 1][j - 1];
                }

                // grid[i][j] now stores the sum of the submatrix from (0,0) to (i,j)
                if(grid[i][j] <= k) {
                    count++;
                }
                else {
                    // Since values are non-negative, further expanding the submatrix 
                    // in this row will only increase the sum, so we can stop.
                    break;
                }
            }
        }

        return count;
    }
};
