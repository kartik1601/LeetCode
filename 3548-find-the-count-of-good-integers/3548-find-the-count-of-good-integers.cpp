class Solution {
    using ll = long long;
    ll fact(int a){
        ll res = 1LL;
        for(int i=2 ; i<=a ; i++){
            res *= i;
        }
        return res;
    }
    ll pnc(vector<int>&a){
        int n = (int)a.size();
        map<int,int> f;
        for(int x : a){f[x]++;}
        
        ll res = 1LL * fact(n-1) * (n-f[0]);
        for(auto&[x,freq] : f){
            if(freq > 1){res /= fact(freq);}
        }
        return res;
    }
    ll conv(vector<int>&a){
        ll num=0LL,p=1LL;
        for(int i=(int)a.size()-1 ; i>=0 ; i--){
            num += a[i]*p; p*=10;
        }
        return num;
    }
public:
    ll cntGood = 0LL;
    set<map<int,int>> vis;

    ll countGoodIntegers(int n, int k) {
        vector<int> num(n,0);
        memo(0,n-1,num,k);
        return cntGood;
    }
    void memo(int l, int r,vector<int>&num,int k){
        if(l>r){
            ll val = conv(num);
            if(val%k == 0){
                map<int,int> m;
                while(val){
                    m[val%10]++; val /= 10;
                }

                if(vis.find(m) == vis.end()){
                    cntGood += pnc(num);
                    vis.insert(m);
                }
            }
            return;
        }

        for(int i=0 ; i<=9 ; i++){
            if(l==0 && i==0){continue;}
            num[l] = num[r] = i;
            memo(l+1,r-1,num,k);
        }
        
    }
};