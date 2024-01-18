#include <iostream>
using namespace std;
class node {
public:
int data;
node *left, *right;
bool lbit, rbit;
node(int d) {
data = d;
left = nullptr;
right = nullptr;
lbit = false;
rbit = false;
}
node() {
data = 9999;
left = nullptr;
right = nullptr;
lbit = false;
rbit = false;
}
};
class TBT {
node *dummy;
public:
node *root;
TBT() {
dummy = new node();
dummy->left = dummy;
dummy->right = dummy;
}
void insert(int d);
void inorder();
void preorder();
};
void TBT::insert(int d) {
if (root == nullptr) {
root = new node(d);
root->left = dummy;
root->right = dummy;
dummy->left = root;
dummy->lbit = true;
} else {
node *temp = root;
node *P = new node(d);
while (temp != dummy) {
if (d < temp->data) {
if (temp->lbit == false) {

P->left = temp->left;
P->right = temp;
temp->left = P;
temp->lbit = true;
break;
} else {
temp = temp->left;
}
}
if (d > temp->data) {
if (temp->rbit == false) {
P->right = temp->right;
P->left = temp;
temp->right = P;
temp->rbit = true;
break;
} else {
temp = temp->right;
}
}
}
}
}
void TBT::inorder() {
node *current = dummy->left;
do {
while (current->lbit == true) {
current = current->left;
}
cout << current->data << " ";
while (current->rbit == false) {
current = current->right;
if (current == dummy) {
return;
}
cout << current->data << " ";
}
current = current->right;
} while (current != dummy);
}
void TBT::preorder() {
node *temp = dummy->left;
bool flag = false;
while(temp != dummy){
if(!flag)
cout<<temp->data<<" ";
if(temp->lbit && !flag){
temp = temp->left;
}else{
while(1){
if(temp->rbit){

flag = false;
temp = temp->right;
break;
}else{
if(temp != nullptr){
flag = true;
temp = temp->right;
break;
}
}
}
}
}
}
int main() {
TBT *tree = new TBT();
int num, d;
cout<<"\nEnter Number of Elements in the TBT: ";
cin>>num;
cout<<"\n";
while(num--){
cout<<"Enter Integer Element: ";
cin>>d;
tree->insert(d);
}
cout << "\n0. EXIT\n1. INSERT\n2. INORDER\n3. PREORDER\n";
int c = -1;
while (c != 0) {
cout << "\nENTER CHOICE: ";
cin >> c;
switch (c) {
case 0:
cout << "EXITING....\n\n";
break;
case 1: {
cout << "ENTER VALUE: ";
cin >> d;
tree->insert(d);
cout << "INSERTED " << d << " in the TBT successfully!\n";
break;
}
case 2:
cout << "INORDER OF THE GIVEN TBT IS: ";
tree->inorder();
cout << "\n";
break;
case 3:
cout << "PREORDER OF THE GIVEN TBT IS: ";
tree->preorder();
cout << "\n";

break;
default:
cout << "ENTER VALID CHOICE CODE\n";
break;
}
}
}