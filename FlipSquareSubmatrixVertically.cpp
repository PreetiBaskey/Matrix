//approach - 1
//time complexity - O(k ^ 2)
//space complexity - O(1)
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // Define the boundaries of the k x k submatrix starting at (x, y)
        int startRow = x;
        int endRow = x + k - 1;

        int startCol = y;
        int endCol = y + k - 1;

        // Perform a vertical flip of the submatrix by swapping rows
        for(int i = startRow; i <= endRow; i++) {
            for(int j = startCol; j <= endCol; j++) {
                // Swap current element with the corresponding element in the symmetric row
                swap(grid[i][j], grid[endRow][j]);
            }
            // Move the bottom boundary upward as we move the top boundary downward
            endRow--;
        }

        return grid;
    }
};
