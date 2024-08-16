class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        /*
        Key points:

        1. We want to make two cuts, separating nums1 into 
            [. . . . L1 | R1 . . . ] and nums2 into [. . . . L2 | R2 . . . ] 
            respectively, so that [. . . . L1] + [. . . . L2] has equal number 
            of elements as [R1 . . . ] + [R2 . . . ]. Our goal is to find 
            such cutting positions that give us the median values.
        2. For an array of length N, there are 2*N + 1 different cutting positions.
            Cutting on a gap is simple. Cutting on a number means both 
            left half and right half get the number.
        3. With two arrays, a valid cutting position that gives the median 
            can be ANY cutting position of the shorter array. This is not 
            true for the longer array. Therefore, we always cut the shorter 
            array, and then calculate the cutting position of longer array 
            directly(by using the fact that each half has the same number 
            of cutting positions). We want to make nums1 always point to the 
            shorter array for convenience.
        4. Using BS, If L1 > R2, we know current cutting position is incorrect. 
            A valid cutting position for median should be on the 
            left half of nums1.
        5. If L2 > R1, we know current cutting position is incorrect. 
            A valid cutting position for median should be on the 
            right half of nums1.
        6. If L1 < R2 and L2 < R1, we are good. median = 
                (max(L1, L2) + min(R1, R2)) / 2
        */
        int n=a.size(), m=b.size();
        if(n>m){swap(a,b); swap(n,m);}
        
        int s=0 , e=n;
        while(s<=e){
            int m1 = s+(e-s)/2;
            int m2 = (n+m+1)/2-m1;

            int l1 = m1==0 ? INT_MIN : a[m1-1];
            int r1 = m1==n ? INT_MAX : a[m1];
            int l2 = m2==0 ? INT_MIN : b[m2-1];
            int r2 = m2==m ? INT_MAX : b[m2];

            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0){
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
                return max(l1,l2);
            }

            if(l1>r2){e = m1-1;}
            else {s = m1+1;}
        }
        

        return 0.0;
    }
};