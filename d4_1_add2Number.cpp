//#include "stdafx.h"  
#include <iostream>
#include <math.h>
#include <map>
//find max substring which sum of the substring is 0
using namespace std;

/**
 * Definition for singly-linked list.

 */

struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num=0;
        int num2=0;
        int result;
        ListNode* pHead;
        ListNode* out= new ListNode(NULL);
        pHead=out;
        l1=l1->next;
        l2=l2->next;
        //ListNode* temp1=l1,temp2=l2;
        int k=0,t=0;
        while(l1 != nullptr||l2 != nullptr||t!=0){
            if(l1!=nullptr && l2!=nullptr){
                num=l1->val+l2->val+t;
                l1=l1->next;
                l2=l2->next;
            }else if(l1!=nullptr){
                num=l1->val+t;
                l1=l1->next;
            }else if(l2!=nullptr){
                num=l2->val+t;
                l2=l2->next;
            }else if(t==1){
                num=1;
            }

            if(num>9){
                num=num-10;
                t=1;
            }else{
                t=0;
            }
            if(k==0){
                out->val=num;
                out->next=NULL;
            }else{
                ListNode* pNewNode = new ListNode(0);
                pNewNode->val=num;
                pNewNode->next=NULL;
                out->next = pNewNode; // 上一个节点指向这个新建立的节点
                out = pNewNode;
            }
            k++;
        }
        return pHead;
    }
};

void createList(ListNode* pHead,int a[]){
    ListNode* p = pHead;
    for (int i = 0; i <3; ++i) {
        ListNode* pNewNode = new ListNode(0);
        pNewNode->val = a[i]; // 将新节点的值赋值为i
        //cout<<"i: "<<i<<" a[i] "<<a[i]<<endl;
        pNewNode->next = NULL;
        p->next = pNewNode; // 上一个节点指向这个新建立的节点
        p = pNewNode; // p节点指向这个新的节点
    }
}

int main()
{	
	int a[]={2,4,3},b[]={5,6,4};
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    ListNode* out=NULL;
    l1 = new ListNode(0);
    l1->val = 0;
    l1->next = NULL;
    createList(l1,a);
    l2 = new ListNode(0);
    l2->val = 0;
    l2->next = NULL;
    createList(l2,b);
	Solution SolutionA;
    out=SolutionA.addTwoNumbers(l1,l2);
    cout << "Hello, world!" << endl;
    return 0;
}