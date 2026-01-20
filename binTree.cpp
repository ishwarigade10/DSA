#include <iostream>
#include <stack>
using namespace std;
int found=0;
struct Btree {
    int age;
    string name;
    long aadhaar;
    Btree* lchild;
    Btree* rchild;
    int flag;   // used for postorder
};

Btree* root = NULL;
void insertNode() {
    int vage;
    string vname;
    long vaadhar;
    
    cout<<"Enter age";
    cin>>vage;
    cout<<"Enter Name";
    cin>>vname;
    cout<<"Enter aadhar";
    cin>>vaadhar;
    Btree* temp = new Btree;
   
    temp->age=vage;
    temp->name=vname;
    temp->aadhaar=vaadhar;
    temp->lchild = NULL;
    temp->rchild = NULL;
    temp->flag = 0;

    if (root == NULL) {
        root = temp;
        cout << "Node inserted as root\n";
        return;
    }

    Btree* ptr = root;
    char dir;

    while (true) {
        cout << "Enter Direction (l/r): ";
        cin >> dir;

        if (dir == 'l' || dir == 'L') {
            if (ptr->lchild == NULL) {
                ptr->lchild = temp;
                break;
            }
            ptr = ptr->lchild;
        }
        else if (dir == 'r' || dir == 'R') {
            if (ptr->rchild == NULL) {
                ptr->rchild = temp;
                break;
            }
            ptr = ptr->rchild;
        }
        else {
            cout << "Invalid direction! Use l or r.\n";
        }
    }
}

void inorderTraversal() {
    stack<Btree*> s;
    Btree* temp = root;

    while (temp != NULL || !s.empty()) {
        while (temp != NULL) {
            s.push(temp);
            temp = temp->lchild;
        }

        temp = s.top();
        s.pop();

        cout<< "[ "<<temp->age<<" "<<temp->name<<" "<<temp->aadhaar<<"]";
        temp = temp->rchild;
    }
}

void preorderTraversal() {
    if (root == NULL) return;

    stack<Btree*> s;
    Btree* temp = root;

    while (temp != NULL || !s.empty()) {

        while (temp != NULL) {
            cout<< "[ "<<temp->age<<" "<<temp->name<<" "<<temp->aadhaar<<"]";   // print first

            if (temp->rchild != NULL)
                s.push(temp->rchild);   // push right

            temp = temp->lchild;        // go left
        }

        if (!s.empty()) {
            temp = s.top();
            s.pop();
        }
    }
}

void postorderTraversal() {
    if (root == NULL) return;

    stack<Btree*> s;
    Btree* temp = root;

    while (temp != NULL || !s.empty()) {

        while (temp != NULL) {
            if (temp->rchild != NULL)
                s.push(temp->rchild);

            s.push(temp);
            temp = temp->lchild;
        }

        temp = s.top();
        s.pop();

        if (!s.empty() && temp->rchild == s.top() && temp->flag == 0) {
            temp->flag = 1;
            s.pop();
            s.push(temp);
            temp = temp->rchild;
        }
        else {
            cout<< "["<<temp->age<<" "<<temp->name<<" "<<temp->aadhaar<<"]";
            temp = NULL;
        }
    } 
}
void Sibling(Btree* root)
{
    if(root==NULL)
    return;
    if(root->lchild!=NULL&&root->rchild!=NULL)
    cout<<"["<<root->lchild->age<<root->lchild->name<<root->lchild->aadhaar<<"] ""["<<root->rchild->age<<root->rchild->name<<root->rchild->aadhaar<<"]";
    Sibling(root->lchild);
    Sibling(root->rchild);
}
void leafNode(Btree* root)
{ 
    if(root==NULL)
    return;
    if(root->lchild==NULL&& root->rchild==NULL)
     {
        cout<<"["<<root->age<<" "<<root->name<<" "<<root->aadhaar<<"]\n";
        
        return;
    }
    leafNode(root->lchild);
    leafNode(root->rchild);   
}
int  HeightOfTree(Btree* root)
{   

    if(root==NULL)
    return -1;
    int hl=HeightOfTree(root->lchild);
    int hr=HeightOfTree(root->rchild);
    return 1+(max(hl,hr));
}
void SearchNode(Btree* root,long key)
{
    if(root==NULL)
    {
        return ;
    }
    SearchNode(root->lchild,key);
    if(root->aadhaar==key &&found==0)
    {
       cout<<"Aadhar found\nAadhaar details\n"<<"NAME:"<<root->name<<"\nAGE:"<<root->age;
       found=1;
       return ;
    }
     SearchNode(root->rchild,key);
}
void Ancestor(Btree* root)
{
if(root==NULL)    
return;
cout<<"["<<root->age<<" "<<root->name<<" "<<root->aadhaar<<"]";
}
int main() {
    int choice;
    while(1)
 {
    cout<<"\n1.Insert  Node\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Find LeafNode\n6.Height of Tree\n7.Search Aadhar\n8.Sibling\n9.Ancestor\n10.Exit";
cout<<"\nEnter choice";
 cin>>choice;   
 switch(choice)
 
{ 
    case 1:
    insertNode();
    break;
    case 2:
    cout << "\nInorder Traversal: ";
inorderTraversal();
break;
case 3:
cout << "\nPreorder Traversal: ";
preorderTraversal();
break;
case 4:
cout << "\nPostorder Traversal: ";
postorderTraversal();
break;
case 5:
cout<<"The Leaf Nodes are:\n";
leafNode(root);
break;
case 6:
cout<<"The height is:"<<HeightOfTree(root);
break;
case 7:
int key;
cout<<"ENter the Aadhar no to search";
cin>>key;
found=0;
SearchNode(root,key);
if(found==0)
    cout<<"Not found\n";
break;
case 8:
Sibling(root);
break;
case 9:
cout<<"Ancestor of tree is:\n";
Ancestor(root);
break;
case 10:
cout<<"Exiting....";
return 0;
 default:
 printf("invalid choice");
}
}
    return 0;
}
