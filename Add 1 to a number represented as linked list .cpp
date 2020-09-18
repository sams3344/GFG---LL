// { Driver Code Starts
//Initial template for C++

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

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

Node* addOne(Node *head);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        
        head = addOne(head);
        printList(head); 
    }
    return 0; 
} 
// } Driver Code Ends


//User function template for C++

/* 

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

 Node* reverse(struct Node *head)
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
    return prev;
}
    
Node *add(Node *head)  
{ 
 // res is head node of the resultant list  
    Node* res = head;  
    Node *temp;
    int carry = 1, sum;  
  
    while (head != NULL) //while both lists exist  
    {  
        sum = carry + head->data;  
        
        carry = (sum >= 10)? 1 : 0;           
        sum = sum % 10;  
 
        head->data = sum;  
  
        temp = head;  
        head = head->next;  
    }  

    if (carry > 0) {
        Node *curr = new Node(carry);
        temp->next = curr;
    }
          
        
        //ex 999 + 1 = 1000, rveverse = 999 -> 0001
        // last 1, carry =1, so temp has stopped at last 9, now temp->next = 1, a new node is made
        // and added to temp, which in turn is added to res :)
  
    return res;  
}

Node* addOne(Node *head) 
{
    head = reverse(head);  
    head = add(head);  
    return reverse(head);  
}
