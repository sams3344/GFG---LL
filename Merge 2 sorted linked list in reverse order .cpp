// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}
// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

struct Node* rev(struct Node *head)
{
    // code here
    Node *curr, *next, *prev;
    curr = head;
    prev= NULL;
    
     
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // return head of reversed list
    return prev;
}

Node* SortedMerge(Node* a, Node* b) 
{ 
	Node* result = NULL; 
	
	/* Base cases */
	if (a == NULL) 
		return(b); 
	else if (b == NULL) 
		return(a); 
	
	/* Pick either a or b, and recur */
	if (a->data >= b->data) 
	{ 
		result = a; 
		result->next = SortedMerge(a->next, b); 
	} 
	else
	{ 
		result = b; 
		result->next = SortedMerge(a, b->next); 
	} 
	return(result); 
} 

struct Node * mergeResult(Node *a,Node *b)
{
    a = rev(a);
    b = rev(b);
    Node* res = SortedMerge(a, b) ;
    //Node* res2 = rev(res);
	return res; 
} 
