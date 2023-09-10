class Solution {
public:
    bool isAnagram(string s, string t) {
        //hashing
        if(s.size()!=t.size())  return false;
        int freq[26]={0};
        for(char ch : s)    {freq[ch-'a']++;}
        for(char ch : t){
            if(freq[ch-'a'])    {freq[ch-'a']--;}
            else {return false;}
        }
        return true;
    }
};