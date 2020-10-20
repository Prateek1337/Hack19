//////////////////Scramble String Problem/////////////////////
//Problem Statment- We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

/////////////////////////////////////////////////////////////////////////
/*3 approches are discussed below- 1. Recursion 2. DP- Memorization 3. DP- Tabular*/
//////////////////////////////////////////////////////////////////////////

//1. Using Recursion Method
class Solution {
public:
    bool shouldMatch(string s1,string s2)
    {
        int arr1[26]={0};
        int arr2[26]={0};
        for(int i=0;i<s1.length();i++)
        {
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr1[i]-arr2[i]!=0)
                return false;
        }
        return true;
    }
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
        if(!shouldMatch(s1,s2))
            return false;
        bool b=false;
        for(int i=1;i<s1.length();i++)
        {
            b=b||(isScramble(s1.substr(0,i),s2.substr(0,i))&&(isScramble(s1.substr(i),s2.substr(i)))||(isScramble(s1.substr(0,i),s2.substr(s1.length()-i))&&(isScramble(s1.substr(i),s2.substr(0,s1.length()-i)))));
        }
        return b;
    }
};

//2. Using Dynamic Programming- Memorization Method
class Solution {
public:
    unordered_map<string,bool>stringmap;
    bool isScramble(string s1,string s2)
    {
        stringmap.clear();
        return Scramble(s1,s2);
    }
    bool Scramble(string s1, string s2) {
        if(s1==s2)return true;
        if( stringmap.count(s1+" "+s2)!=0 )
            return stringmap[s1+" "+s2];
        int n=s1.length();
        int map[26];
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
        {
            map[s1[i]-'a']++;
            map[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++)   
        {
            if(map[i]!=0)
                return false;
        }
        for(int i=1;i<n;i++)
        {
            if( ( isScramble(s1.substr(0,i),s2.substr(0,i)) && 
                  isScramble(s1.substr(i),s2.substr(i)) ) || 
                ( isScramble(s1.substr(0,i),s2.substr(n-i)) && 
                  isScramble(s1.substr(i),s2.substr(0,n-i)) ) )   
            {
                return stringmap[s1+" "+s2]=true;
            }
        }
        return stringmap[s1+" "+s2]=false;
    }
};

//3. Using Dynamic Programming- Tabular Method
class Solution {
public:
    int dp[30][30][30][30];
    bool isScramble(string s1, string s2) {
        int n =s1.length();
        memset(dp,-1,sizeof(dp));
       return solve(s1,s2,0,n-1,0,n-1);
    }
    
    
    bool solve(string &s1, string &s2,int i,int j,int l,int r)
    {
        if(i>j) return 1;
        if(i==j) return s1[i]==s2[l];
        if(dp[i][j][l][r]!=-1) return dp[i][j][l][r];
        for(int k=i;k<j;k++)
        {
            int x = (solve(s1,s2,i,k,l,l+k-i) & solve(s1,s2,k+1,j,l+k-i+1,r))
                     | (solve(s1,s2,i,k,r-(k-i),r) & solve(s1,s2,k+1,j,l,r-(k-i)-1));
            if(x)
            {
                dp[i][j][l][r]=1;return 1;
            }
            
        }
        
      dp[i][j][l][r]=0;
        return 0;
        
        
    }
    
};

//this code is contributed by Sharmila
