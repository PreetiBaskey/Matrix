//approach - 1
//time complexity - O(m * n)
//space complexity - O(m * n)
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 2D Prefix Sum matrices to store counts of 'X' and 'Y' from (0,0) to (i,j)
        vector<vector<int>> cumSumX(m, vector<int>(n, 0));
        vector<vector<int>> cumSumY(m, vector<int>(n, 0));

        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Initialize current cell count based on grid value
                cumSumX[i][j] = (grid[i][j] == 'X');
                cumSumY[i][j] = (grid[i][j] == 'Y');

                // Add count from the cell above
                if(i - 1 >= 0) {
                    cumSumX[i][j] += cumSumX[i - 1][j];
                    cumSumY[i][j] += cumSumY[i - 1][j];
                }
                
                // Add count from the cell to the left
                if(j - 1 >= 0) {
                    cumSumX[i][j] += cumSumX[i][j - 1];
                    cumSumY[i][j] += cumSumY[i][j - 1];
                }
                
                // Subtract the diagonal (top-left) to fix double-counting
                if(i - 1 >= 0 && j - 1 >= 0) {
                    cumSumX[i][j] -= cumSumX[i - 1][j - 1];
                    cumSumY[i][j] -= cumSumY[i - 1][j - 1];
                }

                // Problem condition: 'X' count equals 'Y' count AND there is at least one 'X'
                if(cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
