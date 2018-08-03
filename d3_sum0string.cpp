//#include "stdafx.h"  
#include <iostream>
#include <vector>
#include <map>
//find max substring which sum of the substring is 0
using namespace std;

class Solution {
public:
    vector<int> max0substring(string s){
    int results_index[2];
    int sum=0;
    int maxlength=0;
    int temp;
    map<int,int> count_sum;
    count_sum[0]=-1;   
    vector<int> index_result(results_index,results_index+2);
    for(int i = 0; i < s.size(); i++){
            if(s[i]=='0'){
                temp=-1;
            }
            else temp=1;
            sum=sum+temp;
            map<int,int>::iterator l_it;
            l_it=count_sum.find(sum);
            if(l_it!=count_sum.end()){
                if((i-count_sum[sum])>maxlength){
                    index_result[0]=count_sum[sum]+1;
                    index_result[1]=i;
                    maxlength=i-count_sum[sum];
                }
            }
            else{
                count_sum[sum]=i;
                }
    }
    cout << maxlength<<" index_result "<<index_result[0]<<" "<<index_result[1]<<endl;
    return index_result;
}

};

int main()
{	
	string a="101101111";
	Solution SolutionA;
    SolutionA.max0substring(a);
    cout << "Hello, world!" << endl;
    return 0;
}