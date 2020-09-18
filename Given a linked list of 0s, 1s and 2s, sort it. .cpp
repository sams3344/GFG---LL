// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

struct Node* segregate(struct Node *head);

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        struct Node *newHead = segregate(start);
        printList(newHead);
    }

    return 0;
}// } Driver Code Ends


/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


Node* segregate(Node *head) {
    
    // Add code here
    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0  
    Node *ptr = head;  
 
    while (ptr != NULL)  
    {  
        count[ptr->data] += 1;  
        ptr = ptr->next;  
    }  
  
    int i = 0;  
    ptr = head;  
  
    while (ptr != NULL)  
    {  
        if (count[i] == 0)  
            ++i;  
        else
        {  
            ptr->data = i;  
            --count[i];  
            ptr = ptr->next;  
        }  
    }  
    
    return head;
}
