// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// Rearranges given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head);

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }

        head = rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends


/* Node structure

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


Node *rearrangeEvenOdd(Node *head)
{
  
    if (head == NULL)  
        return NULL;  
 
    Node *odd = head;  
    Node *even = head->next;  
  
    Node *evenFirst = even;  
  
    while (1)  
    {  
        if (!odd || !even || !(even->next))  
        {  
            odd->next = evenFirst;  
            break;  
        }  
  
        odd->next = even->next;  
        odd = even->next;  
 
        if (odd->next == NULL)  
        {  
            even->next = NULL;  
            odd->next = evenFirst;  
            break;  
            
            // if n = odd
            // ex 1 - 2 - 3 - null...odd = 1 - 3, even = 2 - null, 
            //odd now point to 3 , odd->next = null
            //3 shoukd now connect to 2, ie 
            // odd->next = evenFirst;
            
            
            
            // if n = even 1 - 2 - 3 - 4...  
            //odd now point to 3 , odd->next = 4
            //even->next = odd->next;     ie 2 must point to 4
            // 1 - 3,  2 - 4,    
            // even = odd->next;        even now becomes 4
            // next in this line if (!odd || !even || !(even->next))   even->next == null, so break
            
        }  
        
        even->next = odd->next;  
        even = odd->next;  
    }  
  
    return head;  
}
