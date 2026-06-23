/*Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.
The rotation must be done in place, meaning the input 2D matrix must be modified directly.
[[1,2,3][4,5,6][7,8,9]]->[[7,4,1][8,5,2][9,6,3]] */

//Brute Force->Store the rotated values in new matrix then map them
//Time=O(n^2)
//Space=O(n^2)
class Solution {
public:
    void rotateClockwise(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Place the element at its new rotated position
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }
        for (auto row : rotated) {
        for (int val : row) {
            cout << val << " ";
        }
        cout<<endl;
    }
    }
};


//Optimal Solution->Transpose by swapping the values and then reverse the rows
//Time=O(n^2)
//Space=O(1)
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        } 
    }
};