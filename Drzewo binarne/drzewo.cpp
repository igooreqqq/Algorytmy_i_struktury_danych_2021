#include <iostream>

using namespace std;

typedef int Telement;
struct Node
{
    Telement info;
    Node * left;
    Node * right;
};

typedef Node *PNode;

class BinaryTree
{
    protected:
        PNode T;
    public:
        BinaryTree();
        ~BinaryTree();
        PNode PARENT(PNode n, PNode T);
        PNode PARENT1(PNode n,PNode T);
        PNode LEFT_CHILD(PNode n);
        PNode RIGHT_CHILD(PNode n);
        Telement GetLabel(PNode n);
        PNode BuildTree1(int m);
        void BuildTree(int m);
        PNode ROOT();
        void MAKENULL(PNode p);
        void PreOrder(PNode t);
        void InOrder(PNode t);
        void PostOrder(PNode t);
};

BinaryTree::BinaryTree()
{
    T = NULL;
}
BinaryTree::~BinaryTree()
{
    MAKENULL(T);
}

void BinaryTree::MAKENULL(PNode p)
{
    if(p != NULL)
        {
            if(p -> left != NULL) 
                MAKENULL(p -> left);

            if(p -> right != NULL)
                MAKENULL(p -> right);

            delete p;
            p = NULL;
        }
}

PNode BinaryTree::BuildTree1(int m)
{
    if(m == 0)
        return NULL;

    int nodel, nodep;
        
    Telement wartosc;
    PNode temp;
    
    nodel = m / 2;
    nodep = m - nodel - 1;
        
    cout << "Podaj wartosc wezla: " << endl;
    cin >> wartosc;

    temp = new Node;
    temp -> info = wartosc;
    temp -> left = BuildTree1(nodel);
    temp -> right = BuildTree1(nodep);
    return temp;
}

void BinaryTree::BuildTree(int m)
{
    T = BuildTree1(m);
}

PNode BinaryTree::ROOT()
{
    return T;
}

PNode BinaryTree::PARENT1(PNode n, PNode T)
{
    if((T -> left == n) || (T -> right == n))
        return T;

    PNode temp1 = NULL;
    PNode temp2 = NULL;

    if(T -> left != NULL)
        temp1 = PARENT1(n, T -> left);

    if(T -> right != NULL)
        temp2 = PARENT1(n, T -> right);

    if(temp1 != NULL)
        return temp1;

    return temp2;
}

PNode BinaryTree::PARENT(PNode n, PNode T)
{
    if(n == T)
        return NULL;

    else
        return PARENT1(n, T);
}

PNode BinaryTree::LEFT_CHILD(PNode n)
{
    return n -> left;
}

PNode BinaryTree::RIGHT_CHILD(PNode n)
{
    return n -> right;
}

Telement BinaryTree::GetLabel(PNode n)
{
    if(n != NULL)
        return n -> info;
}

void BinaryTree::PreOrder(PNode t)
{
    if(t != NULL)
    {
        cout << t -> info;
        PreOrder(t -> left);
        PreOrder(t -> right);
    }
}

void BinaryTree::InOrder(PNode t)
{
    if(t != NULL)
    {
        InOrder(t -> left);
        cout << t -> info;
        InOrder(t -> right);
    }
}

void BinaryTree::PostOrder(PNode t)
{
    if(t != NULL)
    {
        PostOrder(t -> left);
        PostOrder(t -> right);
        cout << t -> info;
    }
}



int main()
{
    BinaryTree *binarytree = new BinaryTree();
    binarytree -> BuildTree(9);
    cout << binarytree -> GetLabel(binarytree -> ROOT()) << endl;
    cout << binarytree -> GetLabel(binarytree -> LEFT_CHILD(binarytree -> ROOT())) << endl;
    cout << binarytree -> GetLabel(binarytree -> RIGHT_CHILD(binarytree -> ROOT())) << endl;
    cout << binarytree -> GetLabel(binarytree -> PARENT(binarytree -> RIGHT_CHILD(binarytree -> ROOT()), binarytree -> ROOT())) << endl;
    cout << binarytree -> GetLabel(binarytree -> PARENT(binarytree -> RIGHT_CHILD(binarytree -> LEFT_CHILD(binarytree -> ROOT())), binarytree -> ROOT())) << endl;
    binarytree -> PreOrder(binarytree->ROOT());
    cout << endl;
    binarytree -> PostOrder(binarytree->ROOT());
    cout << endl;
    binarytree -> InOrder(binarytree->ROOT());
    cout << endl;
}