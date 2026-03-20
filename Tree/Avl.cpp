#include<iostream>
using namespace std;
struct AvlNode{
    int data;
    AvlNode* left;
    AvlNode* right;
    int height;
};
// get height of the node
int getheight(AvlNode* node){
    if(node==nullptr){
        return 0;
    }
    return node->height;
}


// get balance factor of the node
int getbalance(AvlNode* node){
    if(node==nullptr){
        return 0;
    }
    return getheight(node->left)-getheight(node->right);
}

// Function to update height of a node
void updateHeight(AvlNode* node)
{
    if (node != nullptr) {
        node->height = 1 + max(getheight(node->left), getheight(node->right));
    }
}








// 1---> Right rotate
// Left subtree is heavy & insertion in left of left

AvlNode* rightrotate(AvlNode* y){
    AvlNode* x=y->left;  // left child of y  

    AvlNode* T2=x->right; // subtree

    // Perform rotation
    x->right=y;
    y->left=T2;

    // Update heights
    y->height=1+max(getheight(y->left),getheight(y->right));
    x->height=1+max(getheight(x->left),getheight(x->right));

    // Return new root
    return x;
}


// 2----> left rotate
// Right subtree is heavy & insertion in right of right
AvlNode* leftrotate(AvlNode* x){
    AvlNode* y=x->right; // right child of x
    AvlNode* T2=y->left; // subtree

    // Perform rotation
    x->right=y;
    y->left=T2;

    // Update heights
    x->height=1+max(getheight(x->left),getheight(x->right));
    y->height=1+max(getheight(y->left),getheight(y->right));
   

    // Return new root
    return y;
}
// 3----> Double Shift Left-Right
// Left subtree heavy BUT insertion in right of left

AvlNode* leftrightrotate(AvlNode* y)
{
    y->left=leftrotate(y->left);
    return rightrotate(y);
}


// 4----> Double Shift Right-Left
// Right subtree heavy BUT insertion in left of right

AvlNode* rightleftrotate(AvlNode* y){
    y->right=rightrotate(y->right);
    return leftrotate(y);
}

AvlNode* insert(AvlNode* node,int key)
{
    if(node==NULL)
    {
        AvlNode* newNode=new AvlNode();
        newNode->data=key;
        newNode->left=NULL;
        newNode->right=NULL;
        newNode->height=1;  // New node is initially added at leaf position
        return newNode;
    }


    if(key<node->data){
        node->left=insert(node->left,key);
    }
    else if(key>node->data){
        node->right=insert(node->right,key);
    }
    else
    {
        // Duplicate keys not allowed
        return node;
    }

    // Update height 
    node->height=1+max(getheight(node->left),getheight(node->right));



    // Get the balance factor to check whether this node became unbalanced
    int balance=getbalance(node);

    // If this node becomes unbalanced, then there are 4 cases


    // 1--->Left of Left Case
    if(balance>1  && key<node->left->data)
    {
        return rightrotate(node);
    }

    // 2----> Right of  Right Case
    if(balance<-1 && key>node->right->data){
        return leftrotate(node);
    }

    // 3-----> Left  Right Case
    if(balance>1 && key>node->left->data){
        return leftrightrotate(node);
    }

    //  4----> Right Left Case
    if(balance<-1 && key<node->right->data){
        return rightleftrotate(node);
    }


    return node;
}

AvlNode * findMinNode(AvlNode *node)
{
    AvlNode* current=node;

    // Keep going left until we find the leftmost node
    while (current && current->left!=nullptr)
    {
        current=current->left;

    }
    return current;
    
}

// Main function to delete a node from AVL tree

AvlNode* deleteNode(AvlNode* root ,int key)
{
    if (root ==nullptr)
    {
        return root;   // tree is empty
    }

    // If key is smaller than root's data, go to left subtree
    if (key< root->data)
    {
        root->left=deleteNode(root->left,key);
    }

    // If key is greater than root's data, go to right subtree
    else if (key> root->data)
    {
        root->right=deleteNode(root->right,key);

    }
    else
    {
        if (root->left==nullptr || root->right== nullptr)
        {
            // Node with only one child or no child

            AvlNode* temp;
            if (root->left != nullptr)
                temp = root->left;
            else
            temp = root->right;

            if (temp == nullptr)
            {
            // No child case
            temp = root;
            root = nullptr;
            }
            else
            {
            // One child case
            *root = *temp; // Copy the contents of the non-empty child
            }
            delete temp;

        }

        else
        {

            // Node with two children
            AvlNode *temp=findMinNode(root->right);


            root->data=temp->data;

            root->right= deleteNode(root->right,temp->data);

        }
       
    }

    if (root==nullptr)
    {
        return root;
    }
    // STEP 2: Update height of current node
    updateHeight(root);


    // STEP 3: get balanced check if height is  unbalanced
    int balance= getbalance(root);



    // STEP 4: Rebalanced the tree
     // 1--->Left of Left Case
    if(balance>1 && getbalance(root->left)>=0 )
    {
        return rightrotate(root);
    }

    // 2----> Right of  Right Case
    if(balance<-1 && getbalance(root->right)<=0){
        return leftrotate(root);
    }

    // 3-----> Left  Right Case
    if(balance>1 && getbalance(root->left)<0){
        return leftrightrotate(root);
    }

    //  4----> Right Left Case
    if(balance<-1 && getbalance(root->right)>0){
        return rightleftrotate(root);
    }
   
    return root;
}






void display(AvlNode* root, int space = 0, int indent = 5)
{
    if (root == nullptr)
        return;

    // Increase distance between levels
    space = space + indent;

    // Display right child first
    display(root->right, space);

    // Print current node after space count
    cout << endl;
    for (int i = indent; i<space; i++)
        cout << " ";
    cout << root->data << "(" << root->height << ")" << endl;

    // Display left child
    display(root->left, space);
}




int main()
{
    AvlNode* root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);  
    root=insert(root,12); 

    display(root);


   
    root=deleteNode(root,10);
    cout<<"After deletion of 10:"<<endl;
    display(root);
  






    return 0;
}
