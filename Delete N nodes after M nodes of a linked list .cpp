// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */

void linkdelete(struct Node  *head, int M, int N);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}
// } Driver Code Ends


/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

void linkdelete(struct Node  *head, int M, int N)
{
    Node* curr = head;
    Node* temp;
   
    
    while(curr){
    for(int j=1; j<M && curr != NULL; j++){
        curr = curr->next;
    }
    //ex a b c d e f , to delete c d , we stop at b now

    if(curr == NULL){
        return;
    }
    
    //cout << curr->data << endl;
    
    temp=curr->next;       //move to c now
    
    for(int i=0; i<N && temp != NULL; i++){
        Node *temp2 = temp;  
        temp = temp->next;  
        free(temp2); 
    }  
    
    //now temp points to e, so link b e, now that c d are removed
    
    curr->next = temp;
    
    curr = temp;      //or curr = temp;
    }
   
}

