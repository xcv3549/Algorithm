#include <iostream>

using namespace std;

using node = struct node
{
    char data;
    node* left;
    node* right;
};

node tree[26];

void pre_order(node parent);
void post_order(node parent);
void in_order(node parent);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N,i,root_num;
    char root,left,right;
    cin >> N;
    
    for(i=0; i<N; i++)
        tree[i].data = (char)(i+'A');

    for(i=0; i<N; i++)
    {
        cin >> root >> left >> right; 
        
        if(left != '.')
            tree[root-'A'].left = &tree[(left - 'A')];
        if(right != '.')
            tree[root-'A'].right = &tree[(right - 'A')];
    }
    
    pre_order(tree[0]);
    cout << "\n";
    
    in_order(tree[0]);
    cout << "\n";
    
    post_order(tree[0]);
    cout << "\n";
}

void pre_order(node parent)
{
    cout << parent.data;
    if(parent.left != NULL)     pre_order(*parent.left);
    if(parent.right != NULL)    pre_order(*parent.right);
}

void post_order(node parent)
{
    if(parent.left != NULL)     post_order(*parent.left);
    if(parent.right != NULL)    post_order(*parent.right);
    cout << parent.data;
}

void in_order(node parent)
{
    if(parent.left != NULL)     in_order(*parent.left);
    cout << parent.data;
    if(parent.right != NULL)    in_order(*parent.right);
}
