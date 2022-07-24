class Solution {
public:
// Check for the valid row and column indexes
	bool isValid(int r, int c, int row, int col) {
		if (r >=0 && r < row && c >= 0 && c < col)
			return true;
		return false;
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		int col = matrix[0].size();

		// Starting from first row and last column 
		int i = 0, j = col - 1;
		while (true) {
			if (isValid(i, j, row, col)) {
				// Target found
				if (matrix[i][j] == target)
					return true;
				// Target is greater 
				// Move to next row (top -> bottom)
				else if (matrix[i][j] < target)
					i++;
				// Target is smaller
				// Move to next column (right -> left)
				else
					j--;
			} 
			else {
				return false;
			}
		}        
    }
};