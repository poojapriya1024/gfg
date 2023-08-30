/* Link list Node 
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

Node* deleteNode(Node *head,int x)
{    
    if(x == 1) //if the first node needs to be deleted  
    { 
        Node* curr = head;
        head = head->next;
        curr->next = NULL;
        delete curr;
        return head;
        
    }
        
    int count = 1; // this represents the index of the current node
    Node* curr = head;

    // else, find the node just before the node to be deleted
    while(curr != NULL && count < x - 1)
    {
        curr = curr->next;
        count++;
    }
    
    // now curr can either be null or point to the node just before the node to be deleted
    
    if(curr == NULL) // then, the given index is out of bounds
        return head;
        
    Node* nodeToBeDeleted = curr->next; 
    curr->next = nodeToBeDeleted->next;
    nodeToBeDeleted->next = NULL;
    delete nodeToBeDeleted;
    
    return head;
    
}
