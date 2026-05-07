#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};

BSTNode *ROOT = NULL;


BSTNode* insertBST(BSTNode *curr, int value)
{
    if (curr == NULL)
    {
        BSTNode *temp = new BSTNode();
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (value < curr->data)
    {
        curr->left = insertBST(curr->left, value);
    }
    else
    {
        curr->right = insertBST(curr->right, value);
    }

    return curr;
}


void InOrder(BSTNode *curr)
{
    if (curr != NULL)
    {
        InOrder(curr->left);
        cout << curr->data << " ";
        InOrder(curr->right);
    }
}

// Preorder Traversal (NLR)
void PreOrder(BSTNode *curr)
{
    if (curr != NULL)
    {
        cout << curr->data << " ";
        PreOrder(curr->left);
        PreOrder(curr->right);
    }
}

// Postorder Traversal (LRN)
void PostOrder(BSTNode *curr)
{
    if (curr != NULL)
    {
        PostOrder(curr->left);
        PostOrder(curr->right);
        cout << curr->data << " ";
    }
}

// Function to find minimum value node in right subtree
BSTNode* findMin(BSTNode* curr)
{
    // Loop to find the leftmost node
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}



BSTNode* deleteBST(BSTNode* curr, int value)
{
    // If tree is empty
    if (curr == NULL)
    {
        return NULL;
    }

    // If value is smaller, go to left subtree
    if (value < curr->data)
    {
        curr->left = deleteBST(curr->left, value);
    }

    // If value is greater, go to right subtree
    else if (value > curr->data)
    {
        curr->right = deleteBST(curr->right, value);
    }

    // Node found
    else
    {
        // Case 1: No child (Leaf node)
        if (curr->left == NULL && curr->right == NULL)
        {
            delete curr;
            return NULL;
        }

        // Case 2: One child (Right child only)
        else if (curr->left == NULL)
        {
            BSTNode* temp = curr->right;
            delete curr;
            return temp;
        }

        // Case 2: One child (Left child only)
        else if (curr->right == NULL)
        {
            BSTNode* temp = curr->left;
            delete curr;
            return temp;
        }

        // Case 3: Two children
        else
        {
            // Find minimum value from right subtree
            BSTNode* temp = findMin(curr->right);

            // Replace current node data with minimum value
            curr->data = temp->data;

            // Delete the duplicate node from right subtree
            curr->right = deleteBST(curr->right, temp->data);
        }
    }

    return curr;
}

int main()
{
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        ROOT = insertBST(ROOT, value);
    }

    cout << "\nInOrder Traversal (LNR): ";
    InOrder(ROOT);

    cout << "\nPreOrder Traversal (NLR): ";
    PreOrder(ROOT);

    cout << "\nPostOrder Traversal (LRN): ";
    PostOrder(ROOT);

    int delValue;
    cout << "\nEnter value to delete: ";
    cin >> delValue;

    ROOT = deleteBST(ROOT, delValue);

    cout << "\nInOrder After Deletion: ";
    InOrder(ROOT);

    return 0;
}