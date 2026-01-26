#include<iostream>
using namespace std;
class Btree{
    public:
    string ename;
    int eid;
    int salary;
    string DOJ;
    string pos;
    Btree* lchild;
    Btree* rchild;
};
Btree* root=NULL;
Btree* createNode()
{
    Btree* temp=new Btree();
    cout<<"Enter Name:";
    cin>>temp->ename;
    cout<<"Enter Employee ID: ";
    cin>>temp->eid;
    cout<<"Enter Salary: ";
    cin>>temp->salary;
    cout<<"Enter Date of Joining";
    cin>>temp->DOJ;
    cout<<"Enter The Employees Position: ";
    cin>>temp->pos;

    temp->lchild=NULL;
    temp->rchild=NULL;

    return temp;
}
void BST()
{    
    Btree* temp=createNode();
    if(root==NULL)
    {
        cout<<"Node inserted as Root";
        root=temp;
        return;
    }
    Btree* ptr=root;
   while(ptr!=NULL){
    if(ptr->salary>temp->salary)
    {
        if(ptr->lchild==NULL)
        {
            ptr->lchild=temp;
            break;
        }
        else
        {
            ptr=ptr->lchild;
        }
    }
    else{
        if(ptr->rchild==NULL)
        {
            ptr->rchild=temp;
            break;

        }
        else
        {
            ptr=ptr->rchild;
        }
    }
   }
}
void inorder(Btree* root)
{
 if(root==NULL)
 return ;
 inorder(root->lchild);
 cout<<"["<<root->ename<<" "<<root->eid<<" "<<root->salary<<" "<<root->DOJ<<" "<<root->pos<<"]";
 inorder(root->rchild);
}
void preorder(Btree* root)
{
    if(root==NULL)
    {
        return ;
    }
     cout<<"["<<root->ename<<" "<<root->eid<<" "<<root->salary<<" "<<root->DOJ<<" "<<root->pos<<"]";

    preorder(root->lchild);
    preorder(root->rchild);
     
}
void postorder(Btree* root)
{
    if(root==NULL)
    return ;
    postorder(root->lchild);
    postorder(root->rchild);
     cout<<"["<<root->ename<<" "<<root->eid<<" "<<root->salary<<" "<<root->DOJ<<" "<<root->pos<<"]";

}
void Search(Btree* root,int key)
{   Btree* ptr=root;
    if(root==NULL)
    return;
    while(ptr!=NULL)
    {
      if(ptr->eid==key)
      {  
        cout<<"Employee with ID "<<ptr->eid<<" Found:\nEmployee Details are:\n"<<"Employee Name:"<<ptr->ename<<"\nEmployee Salary:"<<ptr->salary;
        cout<<"\nEmployees Position:"<<ptr->pos<<"\nEmployee Date of Joining:"<<ptr->DOJ;
        return;
      }
       
      else if(key>ptr->salary)
      {
        ptr=ptr->rchild;
       }
     else 
       ptr=ptr->lchild;
      
    }
}
void MinSAlary(Btree* root)
{  
    Btree* ptr=root;
    if(root==NULL)
    return;
    while(ptr->lchild!=NULL)
    {
        ptr=ptr->lchild;
    }
    cout<<"The Minimum Salary is "<<ptr->salary<<" of "<<ptr->ename;
}
void Maxsalary(Btree* root)
{   Btree* ptr=root;
    if(root==NULL)
    return;
    while(ptr->rchild!=NULL)
    {
        ptr=ptr->rchild;
    }
     cout<<"The Maximum Salary is "<<ptr->salary<<" of "<<ptr->ename;
}
int main()
{
   int ch;
   while(1)
   {
   cout<<"\n1.Insert Node\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Search\n6.Minimum Salary\n7.Maximum Salary\n8.Exit";
   cout<<"\nEnter your choice";
   cin>>ch;
   switch(ch)
   {
    case 1:
    BST();
    break;
    case 2:
    cout<<"Records will display in sorted order:\n"<<"Inorder Traversal: ";
    inorder(root);
    break;
    case 3:
    preorder(root);
    break;
    case 4:
    postorder(root);
    break;
    case 5:
    int key;
    cout<<"Enter a Employee ID to search";
    cin>>key;
    Search(root,key);
    break;
    case 6:
    MinSAlary(root);
    break;
    case 7:
    Maxsalary(root);
    break;
    case 8:
    cout<<"Exiting.....";
    return 0;
    default:
    cout<<"Invalid choice";
    break;

   } 
   }
    return 0;

}