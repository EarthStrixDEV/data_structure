#include <bits/stdc++.h>
using namespace std;
struct node {
    int value;
    struct node *left;
    struct node *right;
};
struct node *insert(struct node *tree, int x)
{
    if (tree == NULL) {
        tree = new struct node;
        tree->value = x;
        tree->left = tree->right = NULL;
    }
    else
    {
        // ถ้า x น้อยกว่าค่าของโหนดก่อนหน้า ให้ insert ไปทาาซ้าย
        if (x < tree->value)
            tree->left = insert(tree->left, x);
        else if (x > tree->value)
            // ถ้า x มากกว่าค่าของโหนดก่อนหน้า ให้ insert ไปทางขวา
            tree->right = insert(tree->right, x);
    }
    return tree;
}
void printPre(struct node *tree)
{
    if (tree == NULL)
        return;
    else {
        cout << tree->value << " ";
        printPre(tree->left);
        printPre(tree->right);
    }
    return;
}
void printIn(struct node *tree)
{
    if (tree == NULL)
        return;
    else {
        printIn(tree->left);
        cout << tree->value << " ";
        printIn(tree->right);
    }
    return;
}
void printPost(struct node *tree)
{
    if (tree == NULL)
        return;
    else {
        printPost(tree->left);
        printPost(tree->right);
        cout << tree->value << " ";
    }
    return;
}
struct node *find_min(struct node *tree)
{
    if (tree == NULL)
        return NULL;
    else if (tree->left == NULL)
        return tree;
    else
        return (find_min(tree->left));
}
int main(){
    struct node *tree = NULL;
    tree = insert(tree, 5);
    tree = insert(tree, 2);
    tree = insert(tree, 10);

    cout << "Preorder: ";
    printPre(tree);
    cout << endl;
    cout << "Inorder: ";
    printIn(tree);
    cout << endl;
    cout << "Postorder: ";
    printPost(tree);
}