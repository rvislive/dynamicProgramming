/*
    Question: 
    https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

*/

bool isSubsetSum(vector<int>arr, int sum){
    // code here 
    vector<vector<bool> > t((arr.size() + 1), vector<bool> (sum+1));
    
    for(int i=0; i<=arr.size(); i++) {
        t[i][0] = true; 
    }
    
    for(int j=1; j<=sum; j++) {
        t[0][j] = false; 
    }
    
    for(int i=1; i<=arr.size(); i++) {
        for(int j=1; j<=sum; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = (t[i-1][j-arr[i-1]]) || (t[i-1][j]); 
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[arr.size()][sum];
}