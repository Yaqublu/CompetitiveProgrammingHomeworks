#include <iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

vector <int> v;
int T, n, i, t, a[1000], x;


struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
};

struct node *insertNode(struct node *node, int key)
{
    if(node==0)
        return newNode(key);
    else if(key<node->key)
        node->left=insertNode(node->left, key);
    else
        node->right=insertNode(node->right, key);
    return node;
};

void preorderOfTree(struct node *root)
{
    if(root!=NULL)
    {
        v.push_back(root->key);
        preorderOfTree(root->left);
        preorderOfTree(root->right);
    }
}

bool checkPreorder(int n)
{
    for(int j=0; j<n; j++)
    {
        if(a[j]!=v[j])
            return 0;
    }
    return 1;
}

int main()
{
    cin>>T;
    for(t=0; t<T; t++)
    {
        struct node *root=NULL;
        cin>>n;

        cin>>x;
        a[0]=x;
        root=insertNode(root,a[0]);

        for(i=1; i<n; i++)
        {
            cin>>x;
            a[i]=x;
            insertNode(root, a[i]);
        }

        preorderOfTree(root);
        bool k = checkPreorder(n);
        cout<<k<<endl;
        v.clear();

    }

    return 0;
}
