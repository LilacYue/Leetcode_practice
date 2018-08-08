//#include "stdafx.h"  
#include <iostream>
//#include <math.h>
//#include <map>
//find max substring which sum of the substring is 0
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0,k=0;
        string temp="";
        string sub;
        for(int i=0;i<s.size();i++){
            temp=sub;
            for(int j=0;j<temp.size();j++){
                if(k==1){
                    sub=sub+temp[j];
                } 
                if(s[i]==temp[j]){
                    sub="";
                    k=1;
                }
            }
            k=0;
            sub=sub+s[i];
            cout<<"2 "<<sub<<endl;
            if(sub.size()>max_len){
                max_len=sub.size();
            }
            //cout<<"1 "<<sub<<endl;
        }
        return max_len;
    }
};
int main()
{	
	string s="abcabcbb";
	Solution SolutionA;
    int out;
    out=SolutionA.lengthOfLongestSubstring(s);
    cout<<out<<endl;
    cout << "Hello, world!" << endl;
    return 0;
}