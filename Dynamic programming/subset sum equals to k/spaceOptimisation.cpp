bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k + 1, false);
    prev[0] = true;
    
    for(int i = 0; i < n; i++) {
        vector<bool> cur(k + 1, false);
        for(int j = 0; j <= k; j++) {
            bool notTake = prev[j];
            bool take = false;
            if(arr[i] <= j) take = prev[j - arr[i]];
            cur[j] = take || notTake;
        }
        prev = cur;
    }
    return prev[k];
}