class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
         int m = matrix.size(), n = matrix[0].size();
  
  // prefix sum precomputation
  vector<vector<int>> ps(m + 1, vector<int>(n + 1));
  for(int i = 0 ; i < m ; i++){
    int cur_sum = 0;
    for(int j = 0 ; j < n ; j++){
      cur_sum += matrix[i][j];
      ps[i + 1][j + 1] = ps[i][j + 1] + cur_sum;
    }
  }
  
  int ans = 0;
  // bruteforce finding all possible (x1, y1, x2, y2)s
  for(int x1 = 1 ; x1 <= m ; x1++){
    for(int y1 = 1 ; y1 <= n ; y1++){
      for(int x2 = x1 ; x2 <= m ; x2++){
        for(int y2 = y1 ; y2 <= n ; y2++){
		  // O(1) finding submatrix sum
          if(ps[x2][y2] - ps[x2][y1 - 1] - ps[x1 - 1][y2] + ps[x1 - 1][y1 - 1] == target) ans++;
        }
      }
    }
  }
  
  return ans;
    }
};