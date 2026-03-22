//approach - 1
//time complexity - O(n ^ 2)
//space complexity - O(1)
class Solution {
public:
    // Helper function to rotate a square matrix 90 degrees clockwise in-place
    void rotate(vector<vector<int>> &mat) {
        int n = mat.size();

        // Step 1: Transpose the matrix (swap rows with columns)
        // We only iterate over the upper triangle (j = i) to avoid double-swapping
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Step 2: Reverse each row to complete the 90-degree clockwise rotation
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        // A matrix returns to its original state after 4 rotations (0, 90, 180, 270 degrees)
        for(int times = 0; times < 4; times++) {
            bool equal = true;

            // Manual check if current 'mat' matches 'target'
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] != target[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if(!equal) break;
            }

            // If a match is found at any rotation, return true
            if(equal) return true;

            // Rotate the matrix for the next check
            rotate(mat);
        }

        // If no match found after trying all 4 orientations
        return false;
    }
};
