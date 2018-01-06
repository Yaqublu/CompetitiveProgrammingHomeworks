/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/
int maxSum(Node *root,int &sum)
{
    if(root==NULL)
        return 0;
//    if(root->left==0 && root->right==0)
//        return root->data;

    int leftSum=0;
    int rightSum=0;

    leftSum=maxSum(root->left,sum);
    rightSum=maxSum(root->right,sum);

    if(sum<leftSum+rightSum+root->data)
        sum=leftSum+rightSum+root->data;

    if(leftSum>=rightSum)
        return leftSum+root->data;
    else
        return rightSum+root->data;

}

int maxPathSum(struct Node *root)
{
    int SSum=0;
    if(root==NULL)
        return 0;

    maxSum(root,SSum);

   return SSum;
}
