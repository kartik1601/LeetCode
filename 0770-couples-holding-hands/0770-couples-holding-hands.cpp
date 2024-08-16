class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        /*
        KEY POINTS:
            1. Couples are of the order: (even,even+1) || (odd,odd-1)
            2. Matched pairs and Unmatched pairs
            3. Unmatched pairs can be swapped with anybody
            4. Matched pair (i,j) => _i-1_(i,j)_j+1_ only two free pos resp.
            5. An unmatched pair can have 2 possible ways of swapping
            6. Undirected graph can be made for each pairs
        */

        int n = (int)row.size();
        vector<int> cp(n), seat(n);
        for(int i=0 ; i<n ; i++){
            seat[row[i]] = i;
            if(i%2){cp[i] = i-1;}
            else {cp[i] = i+1;}
        }
        
        int swaps=0;
        for(int i=0 ; i<n ; i+=2){
            int node = row[i], nbr = cp[node];
            if(seat[nbr] != i+1){
                swaps++;
                int next = row[i+1];
                swap(row[i+1],row[seat[nbr]]);
                swap(seat[nbr],seat[next]);
            }
        }
        return swaps;
    }
};