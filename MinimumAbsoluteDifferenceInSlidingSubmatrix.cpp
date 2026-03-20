//approach - 1
//time complexity - O(m * n * k^2 * log(k^2))
//space complexity - O(k^2)
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize a 2D result vector to store min absolute differences for each subgrid
        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1));

        // Iterate through all possible top-left corners of k x k subgrids
        for(int i = 0; i <= m - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                // Use a set to store unique values from the subgrid (automatically sorted)
                set<int> val;
                
                // Traverse the current k x k subgrid
                for(int r = i; r <= i + k - 1; r++) {
                    for(int c = j; c <= j + k - 1; c++) {
                        val.insert(grid[r][c]);
                    }
                }

                // If all elements are the same, the minimum absolute difference is 0
                if(val.size() == 1) {
                    result[i][j] = 0;
                    continue;
                }

                int minAbsDiff = INT_MAX;
                auto prev = val.begin();
                auto curr = next(prev);

                // Find the minimum difference between adjacent elements in the sorted set
                while(curr != val.end()) {
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }

                result[i][j] = minAbsDiff;
            }
        }

        return result;
    }
};
