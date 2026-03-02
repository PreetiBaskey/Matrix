//approach - 1
//time complexity - O(n^2)
//space complexity - O(n)
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        // PHASE 1: Pre-process the grid
        // We only care about the number of trailing zeros in each row.
        // Transform the 2D grid into a 1D array of trailing zero counts.
        vector<int> zeroCountFromEnd(n, 0);
        for(int i = 0; i < n; i++) {
            int count = 0;
            int j = n - 1;
            while(j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }
            zeroCountFromEnd[i] = count;          
        }

        // PHASE 2: Greedy Row Placement
        // For a valid "triangular" grid, row 'i' needs at least (n - 1 - i) trailing zeros.
        int steps = 0;
        for(int i = 0; i < n; i++) {
            int need = n - i - 1; // Required zeros for the current row position

            // Find the first row at or below index 'i' that satisfies the requirement
            int j = i;
            while(j < n && zeroCountFromEnd[j] < need) {
                j++;
            }

            // If we checked all rows and found no match, the grid cannot be transformed
            if(j == n) {
                return -1;
            }

            // Calculate the distance to move the found row 'j' up to position 'i'
            steps += j - i;

            // Bubble Sort: Move the row from index 'j' to index 'i' by shifting intermediate rows
            while(j > i) {
                swap(zeroCountFromEnd[j], zeroCountFromEnd[j - 1]);
                j--;
            }
        }

        return steps;
    }
};
