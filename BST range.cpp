#include<iostream>
using namespace std;
int p=0;
int q=0;
int r=0;
int u;
int l;
class node{
public:
int data;

node*parent;
node*left;
node*right;

node(){
parent=NULL;
left=NULL;
right=NULL;
}
};
class Btree{
public:
node*root;

Btree(){
root=NULL;
}

void insert(int x){
node*temp=new node;
temp->data=x;
temp->parent=NULL;
temp->left=NULL;
temp->right=NULL;

if(root==NULL){
root=temp;
}
else{
node*current=new node;
current=root;
while(1){
 if(x<current->data)
{ if(current->left==NULL){
  temp->parent=current;
  current->left=temp;
break;}
else {current=current->left;
}
}
else if(x>current->data)
{
if(current->right==NULL)
{temp->parent=current;
current->right=temp;
break;}
else
{current=current->right;
}
}
}
}
}
void display(node*temp)
	{
		if(temp==NULL)
		return;                                                                                                                                                                              
		display(temp->left);
		cout<<temp->data<<endl;
	    display(temp->right);
	    
	}
node* search(node*temp,int key)
{
if(temp!=NULL)
		{
        if(temp->data==key)
        return temp;
        else if(temp->data > key)
        return search(temp->left,key);
		else
		return search(temp->right,key);
	    }
	    else
	    {
	    return NULL;
	    }
}
void deletenode(node*current)
{
if(current->left==NULL && current->right==NULL)
{if(current->parent->left==current)
  {current->parent->left=NULL;}
else current->parent->right=NULL;
    }

else if(current->left==NULL)
{if(current->parent->left=current)
   {current->parent->left=current->right;}
else current->parent->right=current->right;
current->right->parent=current->parent;
}
else if(current->right==NULL)
{if(current->parent->left=current)
   {current->parent->left=current->left;
}
else current->parent->right=current->left;
current->left->parent=current->parent;
}

else{
node*p;
p=current->left;
while(p->right!=NULL)
{p=p->right;}
if(p->left==NULL){
p->parent=current->parent;
p->left=current->left;
p->right=current->right;
{if(current->parent->left=current)
   {current->parent->left=p;}
else current->parent->right=p;

current->left->parent=p;
current->right->parent=p;
}
}
else
{if(current->parent!=NULL){
current->left->parent=p;
current->right->parent=p;
p->left->parent=p->parent;
p->parent->right=p->left;

p->parent=current->parent;

p->left=current->left;
p->right=current->right;
if(current->parent->left=current)
   {current->parent->left=p;}
else current->parent->right=p;

}

else

{root=p;
current->left->parent=p;
current->right->parent=p;
p->left->parent=p->parent;
p->parent->right=p->left;
p->left=current->left;
p->right=current->right;

}
}
}
}
void countnode(node*temp){
if(temp==NULL)
                return;                                                                                                                                
                countnode(temp->left);
                                p++;
               countnode(temp->right);

}
void countintnode(node*temp){
if(temp==NULL)
return;
countintnode(temp->left);
if(temp->left!=NULL || temp->right!=NULL)
{q++;}
countintnode(temp->right);

}
void countleaf(node*temp){
if(temp==NULL)
return;
countleaf(temp->left);
if(temp->left==NULL && temp->right==NULL)
r++;
countleaf(temp->right);
}
	void rangesearch(node*temp,int u,int l)
{if(temp==NULL)
    return;
    rangesearch(temp->left,u,l);
    if(temp->data<=u && temp->data>=l)
    cout<<temp->data<<endl;
    rangesearch(temp->right,u,l);
    
}
};

int main(){
Btree a;
a.insert(5);
a.insert(6);
a.insert(2);
a.insert(9);
a.insert(4);
a.insert(8);
a.insert(3);
a.display(a.root);
cout<<"Enter the element to search";
int s;
cin>>s;
 if(a.search(a.root,s)==NULL)
{cout<<"the element is not found"<<endl;}
else cout<<"the element is found"<<endl;
a.deletenode(a.root);
a.display(a.root);
a.countnode(a.root);
a.countintnode(a.root);
a.countleaf(a.root);

cout<<"the total number of nodes="<<p<<endl;
cout<<"the total number of internal nodes="<<q<<endl;
cout<<"the total number of leaf nodes="<<r<<endl;
	cout<<"enter the upper limit for range search";
	cin>>u;
	cout<<"enter the lower limit for range search";
	cin>>l;
	a.rangesearch(a.root,u,l);
}

