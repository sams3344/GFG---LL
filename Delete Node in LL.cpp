#include <iostream>
using namespace std;


void del(struct Node** head, int pos){
    if(head == NULL) 
     
    Node *temp = head;  
    
    for(int i=0; i < pos-1; i++){
        temp = temp-> text;
    }
    
    if(temp == NULL || temp->next == NULL){
        return;
    }
    temp->next = temp->next->next;
    
    freee(temp);
    }
    return;
}

// check leetcode for deleting wrt node->data

int main() {
	cout<<"GfG!";
	return 0;
}
