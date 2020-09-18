// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


Node *compute(Node *head);

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Node *result = compute(head);
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
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*Node *reverseList(Node* head) 
{ 
        Node* curr = head; 
        Node* prev = NULL; 
        Node* next; 
    
    while (curr != NULL)  
    { 
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } 
    
    return prev; 
} */

Node *compute(Node *head)
{
    Node *temp=head;
    Node *next;

while(temp->next!=NULL){
    Node *curr=temp->next;
    if(temp->data < curr->data)
    {
        *temp = *(temp->next);
        temp=head;
    }
    else
     temp = curr;
}
    return head;
}
