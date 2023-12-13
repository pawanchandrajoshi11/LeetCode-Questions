class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // OPTIMAL APPROACH: TC-O(M*N)
        int m = mat.size(); //row
        int n = mat[0].size(); //col

        //vectors to store count of '1's in each row and column
        vector<int> rowCount(m, 0); // initialising every element as 0
        vector<int> colCount(n, 0);


        // Counting 1's for each row and column
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int count = 0;
        // Checking for "special" element
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){ //if the element is 1
                    if(rowCount[i] == 1 && colCount[j] == 1){
                        //if the row and column containing this '1' have exactly one '1', (i.e., the element is "special")
                        count++;
                    }
                }
            }
        }

        return count;
    }
};