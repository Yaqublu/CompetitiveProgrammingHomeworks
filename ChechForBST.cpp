/*
struct Node {
    int data;
    Node* left, * right;
}; */

bool checkIsBST(Node* root, Node* left, Node* right)
{
    if (root == NULL)
        return true;
    if (left != NULL and root->data < left->data)
        return false;
    if (right != NULL and root->data > right->data)
        return false;
    return checkIsBST(root->left, left, root) && checkIsBST(root->right, root, right);
}

bool isBST(Node* root)
{
    return( checkIsBST(root, NULL, NULL));

}
