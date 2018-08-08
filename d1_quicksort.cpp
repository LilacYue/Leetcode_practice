//#include "stdafx.h"  
#include <iostream>
#include <vector>
#include <stack>  


using namespace std;

class Solution {
public:
    //"
    //int arrayPairSum(vector<int>& nums);
    //int arrayPairSum(vector<int>& nums){
        //nums=Partition(nums);
        //for(int i = 0; i < 5; i++){
      		//cout << "value of vec [" << i << "] = " << nums[i] << endl;
   		//}
        //return nums[0];
    //};
    //int Partition(vector<int>& nums, int start, int end);"
    int Partition(vector<int>& nums, int start, int end){
    if(start==end){
        return start;
    }
    int index = end;
    int small = start-1;
    for(int i=start;i<end;i++){
        if(nums[i]<nums[index]){
            small++;
            if(i!=small){
                swap(nums[i],nums[small]);
            }
        }
    }
    swap(nums[small+1],nums[end]);
    cout<<endl<<"after111:  ";
    for(int i = 0; i < nums.size(); i++){
      		cout<< nums[i] << " ";

   		}
   		cout<<endl;
    return small+1;
}
	void QuickSort_Recur(vector<int>& nums, int start, int end){
	    if(start>=end){
	        return;
	    }
	    int index = Partition(nums,start,end);
	    QuickSort_Recur(nums,start,index-1);
	    QuickSort_Recur(nums,index+1,end);

}

void QuickSort_Loop(vector<int>& nums){
    stack<int> indexs;
    int start=0, end=nums.size()-1;
    int index = Partition(nums,start,end);
    cout<<"temp0: "<<start<<" "<<end<<" "<<index<<endl;
    if(start<index-1){
        indexs.push(start);
        indexs.push(index-1);
    }
    if(index+1<end){
        indexs.push(index+1);
        indexs.push(end);
    }
    for(int i = 0; i < indexs.size(); i++){
          cout << " 11[" << i << "] = " << indexs[i]<<" ";
      }
    while(!indexs.empty()){
        int high = indexs.top();

        indexs.pop();
        int low = indexs.top();
        
        indexs.pop();
        int index = Partition(nums,low,high);
        cout<<"temp: "<<high<<" "<<low<<" "<<index<<endl;
        if(low<index-1){
            indexs.push(low);
            indexs.push(index-1);
        }
        if(index+1<high){
            indexs.push(index+1);
            indexs.push(high);
        }
        for(int i = 0; i < nums.size(); i++){
          cout << " [" << i << "] = " << nums[i]<<" ";
      }
    }
    cout<<endl<<"end"<<endl;
}

};
int main()
{	
	int a[6]={14,12,11,19,15,13};
	//int a[6]={1,3,2,4,5,6};
	int l=6;
	//int a[9] = {44,1,4,55,0,9,3,2,56};
	std::vector<int> v(a,a+l);
	cout << "before";
	for(int i = 0; i < l; i++){
      		cout << " [" << i << "] = " << v[i]<<" ";
   		}
   	cout<<endl;
	int begin=0;
	int end=l;
	Solution SolutionA;
	int k=0;
	/*while(begin!=end){
		k=k+1;
		cout<<k<<" "<<endl;
		temp=SolutionA.Partition(v,begin,end);
		if(temp==end){
			end=temp-1;
		}
		else if(temp==begin){
			begin=temp+1;
		}
		else{

		}
	}*/
	//SolutionA.QuickSort_Recur(v,begin,end);
    SolutionA.QuickSort_Loop(v);
	//cout<<begin<<endl<<"after:  ";
	cout<<endl<<"after333:  ";
    for(int i = 0; i < v.size(); i++){
      		cout<< v[i] << " ";

   		}

	//for(int i = 0; i < l; i++){

			//c=SolutionA.Partition(v,begin,end);
			//for(int i = 0; i < l; i++){
				//cout << v[i]<<" ";
   		//}
   		//cout<<endl<<c<<endl;
	//}
      		
    cout << "Hello, world!" << endl;
    return 0;
}