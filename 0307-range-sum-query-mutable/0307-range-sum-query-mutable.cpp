class NumArray {
    int n;
    vector<int> st;
public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        st.resize(4*n,0);
        build(0,n-1,0,nums);
    }

    void build(int s,int e,int node,vector<int>&v){
        if(s==e){st[node]=v[s]; return;}

        int mid=s+(e-s)/2, l=2*node+1, r=2*node+2;
        build(s,mid,l,v);
        build(mid+1,e,r,v);

        st[node] = st[l] + st[r];
    }
    
    void update(int s,int e,int node,const int idx, const int val){
        if(s==e){st[node]=val; return;}
        
        int mid=s+(e-s)/2, l=2*node+1, r=2*node+2;
        if(idx>=s && idx<=mid){
            update(s,mid,l,idx,val);
        } else {
            update(mid+1,e,r,idx,val);
        }

        st[node] = st[l] + st[r];
    }
    void update(int index, int val) {
        update(0,n-1,0,index,val);
    }
    
    int sumRange(int s,int e,int node,const int a,const int b){
        if(s>b || e<a){return 0;}
        if(s>=a && e<=b){return st[node];}

        int mid=s+(e-s)/2, l=2*node+1, r=2*node+2;
        return sumRange(s,mid,l,a,b) + sumRange(mid+1,e,r,a,b);
    }
    int sumRange(int left, int right) {
        return sumRange(0,n-1,0,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */