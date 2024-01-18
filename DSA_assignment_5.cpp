#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
};
class bst{
    public:
    node *root=nullptr;
    node* insert(node *root, int item);
    void display_inorder(node *root);
    void display_postorder(node *root);
    void display_preorder(node *root);
    node* insert_non_recursive(node *root, int item);
    node* search_item(node *root,int item);
    void leaf_nodes(node *root);
    int depth(node *root);
    void mirror_tree(node *root);
    void display_levelwise(node *root,int depth);
    void print_level(node *root);
    void print_paret_child(node *root);
    node* del_node(node *root, int del_key);
};
node* bst::del_node(node *root, int del_key)
{
    node *temp=root;
    if(temp==nullptr)
    {
        return temp;
    }
    else 
    {
        if(temp->data>del_key)
        {
            temp->left=del_node(temp->left,del_key);
        }
        else if(temp->data<del_key)
        {
            temp->right=del_node(temp->right,del_key);
        }
        else
        {
            if(temp->right==nullptr)
            {
                node *del_node=temp->left;
                delete temp;
                return del_node;
            }
            else if(temp->left==nullptr)
            {
                node *del_node=temp->right;
                delete temp;
                return del_node;
            }
            else
            {
                node *successor;
                successor=temp->right;
                while(successor!=nullptr && successor->left!=nullptr)
                {
                    successor=successor->left;
                }
                temp->data=successor->data;
                temp->right=del_node(temp->right, successor->data);
            }
        }
    }
    return root;
}
void bst::print_paret_child(node *root)
{
    node *temp=root;
    if(temp==nullptr)
    {
        return;
    }
    else
    {
        if(temp->right==nullptr && temp->left==nullptr)
        {
            cout<<"Parent node is: "<<temp->data<<endl;
            cout<<"No left and right child is present";
        }
        else if(temp->right!=nullptr && temp->left!=nullptr)
        {
            cout<<"Parent node is: "<<temp->data<<endl;
            cout<<"Left child of the parent node is: "<<temp->left->data<<endl;
            cout<<"Right child of the parent node is: "<<temp->right->data<<endl;
        }
        else if(temp->right==nullptr && temp->left!=nullptr)
        {
            cout<<"Parent node is: "<<temp->data<<endl;
            cout<<"Left child of the parent node is: "<<temp->left->data<<endl;
            cout<<"No right child is present"<<endl;
        }
        else if(temp->left==nullptr && temp->right!=nullptr)
        {
            cout<<"Parent node is: "<<temp->data<<endl;
            cout<<"Right child of the node is: "<<temp->right->data<<endl;
            cout<<"No left child is present"<<endl;
        }
    }
    print_paret_child(temp->left);
    print_paret_child(temp->right);
    cout<<endl;
}
void bst::display_levelwise(node *root, int depth)
{
    node *temp=root;
    if(temp==nullptr)
    {
        return ;
    }
    if(depth==1)
    {
        cout<<temp->data<<" ";
    }
    else if(depth>1)
    {
        display_levelwise(temp->left,depth-1);
        display_levelwise(temp->right,depth-1);
    }
}
void bst::print_level(node *root)
{
    int h=depth(root);
    for(int i=1;i<=h;i++)
    {
        display_levelwise(root,i);
        cout<<endl;
    }
}
void bst::mirror_tree(node *root)
{
    node *temp=root;
    if(temp!=nullptr)
    {
        mirror_tree(temp->right);
        cout<<temp->data<<" ";
        mirror_tree(temp->left);
    }
}
int bst::depth(node *root)
{
    node *temp=root;
    if(temp==nullptr)
    {
        return 0;
    }
    if(temp!=nullptr)
    {
        int l=depth(root->left);
        int r=depth(root->right);
        if(l>r)
        {
            return l+1;
        }
        else
        {
            return r+1;
        }
    }
}
void bst::leaf_nodes(node *root)
{
    node *temp=root;
    if(temp->left==nullptr && temp->right==nullptr)
    {
        cout<<temp->data<<" ";
    }
    else if(temp->right!=nullptr && temp->left==nullptr)
    {
        leaf_nodes(temp->right);
    }
    else if(temp->left!=nullptr && temp->right==nullptr)
    {
        leaf_nodes(temp->left);
    }
    else if(temp==nullptr)
    {
        cout<<"";
    }
    else if(temp!=nullptr)
    {
        leaf_nodes(temp->left);
        leaf_nodes(temp->right);
    }
}
node* bst::search_item(node *root,int item)
{
    node *current=root,*temp;
    while(current!=nullptr)
    {
        if(current->data==item)
        {
            cout<<"The item has been found "<<endl;
            return current;
        }
        else if(item>current->data)
        {
            temp=current;
            current=current->right;
        }
        else if(item<current->data)
        {
            temp=current;
            current=current->left;
        }
    }
    return nullptr;
}
void bst::display_preorder(node *root)
{
    node *temp=root;
    if(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        display_preorder(temp->left);
        display_preorder(temp->right);
    }
}
node* bst::insert_non_recursive(node *root, int item)
{
    node *temp=new node();
    temp->data=item;
    node *parent=nullptr, *current=root;
    while(current!=nullptr)
    {
        parent=current;
        if(item>current->data)
        {
            current=current->right;
        }
        else if(item<current->data)
        {
            current=current->left;
        }
        else 
        return root;
    }
    if(parent==nullptr)
    {
        return temp;
    }
    else if(item>parent->data)
    {
        parent->right=temp;
    }
    else if(item<parent->data)
    {
        parent->left=temp;
    }
    return root;
}
void bst::display_postorder(node *root)
{
    node *temp=root;
    if(temp!=nullptr)
    {
        display_postorder(temp->left);
        display_postorder(temp->right);
        cout<<temp->data<<" ";
    }
}
node* bst::insert(node *root, int item)
{
    if(root==nullptr)
    {
        node *temp=new node();
        temp->left=nullptr;
        temp->right=nullptr;
        temp->data=item;
        return temp;
    }
    else if(root->data>item)
    {
        root->left=insert(root->left,item);
    }
    else if(root->data<item)
    {
        root->right=insert(root->right,item);
    }
    return root;
}
void bst::display_inorder(node *root)
{
    node *temp=root;
    if(temp!=nullptr)
    {
        display_inorder(temp->left);
        cout<<temp->data<<" ";
        display_inorder(temp->right);
    }
}
int main()
{
    bst tree1;
    cout<<"How many elements you want in the tree: ";
    int number;
    cin>>number;
    cout<<endl;
    node *main_root=nullptr;
    int element;
    int choice;
    for(int i=0;i<number;i++)
    {
        cout<<"Enter the key you want in the tree: ";
        cin>>element;
        main_root=tree1.insert_non_recursive(main_root,element);
    }
    while(true)
    {
        cout<<"\n\n ****************************\n\n";
        cout<<"SELECT THE OPTIONS!!!"<<endl;
        cout<<"1.Display inorder , preorder & postorder of the tree."<<endl;
        cout<<"2.Delete an element in the tree."<<endl;
        cout<<"3.Display mirror image of the tree."<<endl;
        cout<<"4.Search specific number in the tree."<<endl;
        cout<<"5.Display the depth of the tree."<<endl;
        cout<<"6.Display parent and children of nodes in tree"<<endl;
        cout<<"7.Display tree level wise"<<endl;
        cout<<"8.Display leaf nodes of the tree"<<endl;
        cout<<"9.Exit programm"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"\t\t\t\t"<<endl;
            cout<<"Inorder display of the tree: ";
            tree1.display_inorder(main_root);
            cout<<"\nPreorder display of the tree: ";
            tree1.display_preorder(main_root);
            cout<<"\nPostorder display of the tree";
            tree1.display_postorder(main_root);
            cout<<"\t\t\t\t"<<endl;
            break;
            case 2:
            cout<<"\t\t\t\t"<<endl;
            cout<<"Enter the number you want to delete in tree: ";
            int del_k;
            cin>>del_k;
            main_root=tree1.del_node(main_root,del_k);
            cout<<"The number has been deleted in the tree: "<<endl;
            cout<<"\t\t\t\t"<<endl;
            break;
            case 3:
            cout<<"\t\t\t\t"<<endl;
            cout<<"Displaying the mirror image of the tree: ";
            tree1.mirror_tree(main_root);
            cout<<"\t\t\t\t"<<endl;
            break;
            case 4:
            cout<<"\t\t\t\t"<<endl;
            cout<<"Enter the element you want to search in the tree: ";
            int search_k;
            cin>>search_k;
            tree1.search_item(main_root,search_k);
            cout<<"\t\t\t\t"<<endl;
            break;
            case 5:
            cout<<"\t\t\t\t"<<endl;
            cout<<"The depth of the tree is: "<<tree1.depth(main_root)<<endl;
            cout<<"\t\t\t\t"<<endl;
            break;
            case 6:
            cout<<"\t\t\t\t"<<endl;
            cout<<"Displaying parent and children of the tree: "<<endl;
            tree1.print_paret_child(main_root);
            cout<<"\t\t\t\t"<<endl;
            break;
            case 7:
            cout<<"Displaying the tree level wise: "<<endl;
            tree1.print_level(main_root);
            cout<<"\t\t\t\t"<<endl;
            break;
            case 8:
            cout<<"Displaying leaf nodes of the tree: "<<endl;
            tree1.leaf_nodes(main_root);
            cout<<"\t\t\t\t"<<endl;
            break;
        }
        if(choice==9)
        {cout<<"Prgramm exited successfullly"<<endl;break;}
    }
    return 0;
}