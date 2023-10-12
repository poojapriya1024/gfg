class Solution{

public:
    void inOrderTraversal(Node* root, int x, int& solution) {
        if(root == nullptr)
            return;
        
        if(root->data > x) //search in left subtree
            inOrderTraversal(root->left,x,solution);
        else if(root->data < x) {
            if(root->data > solution)
                solution = root->data;
                inOrderTraversal(root->right,x,solution);
        }
        else {
            solution = x;
            return; 
        }
            
    }
    
    int floor(Node* root, int x) {
        // Code here
        int solution = -1;
        inOrderTraversal(root,x,solution);
        return solution;
        
        
    }
};
