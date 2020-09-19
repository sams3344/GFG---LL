// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 


// } Driver Code Ends



/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    // Your Code Here
     // Base cases 
    if (head == NULL) 
        return NULL; 
    if (head->next == NULL) { 
        delete head; 
        return NULL; 
    } 
  
  
     Node* slow_ptr = head; 
     Node* fast_ptr = head; 
  
     
     Node* prev;  
    while (fast_ptr != NULL  && fast_ptr->next != NULL) { 
        fast_ptr = fast_ptr->next->next;  //step 1
        prev = slow_ptr;                //step 2
        slow_ptr = slow_ptr->next;       //step 3
    }           //order is very important
  
    // Delete the middle node 
    prev->next = slow_ptr->next; 
    delete slow_ptr; 
  
    return head; 
}
