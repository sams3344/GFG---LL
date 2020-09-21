// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
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
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// root: head node
Node *removeDuplicates(Node *head){
    Node* current = head;  
    Node* next_next;  
      
    if (current == NULL)  
        return NULL;  
  
    while (current->next != NULL)  {
    /* Compare current node with next node */
    if (current->data == current->next->data)  {
        /* The sequence of steps is important*/        
        next_next = current->next->next;  
        free(current->next);  
        current->next = next_next;  
        // And if you dont do this curr->next cant be freed. so just changing pointers wouldnt be enough
    }  
    
    else /* This is tricky: only advance if no deletion */
        current = current->next;  
    }
        
    return head;
}
