#include<iostream>

using namespace std;

class node
{
public:
int data;
node *parent, *left, *right;

	node(int a)
	{
		data = a;
		parent = left = right = NULL;
	}

};

int inorder(node *a)
{
	int n;
	if(a == NULL)
	{
		return 0;
	}
	if(a->left == NULL && a->right == NULL)
	{
		cout<<a->data<<" ";
		return 1;
	}
	if(a->left != NULL)
	{
		inorder(a->left);
		//cout<<a->data<<" ";
	}
	if(a->right != NULL)
	{
		cout<<a->data<<" ";
		inorder(a->right);
	}else
	{
		cout<<a->data<<" ";
	}
	return 1;
}

class tree
{
	public:           
	node *root;
	tree()
	{
		root = NULL;
	}

	void add(int a)
	{
		node *slider = root;
		node *temp = new node(a);
		if(root == NULL)
		{
			root = temp;
			return;
		}
		while(slider != NULL)
		{
			if(temp->data == slider->data)
			{
				return;
			}
			if(temp->data > slider->data)
			{
				if(slider->right == NULL)
				{
					slider->right = temp;
					temp->parent = slider;
					return;
				}else 
				{
					slider = slider->right;
				}
			}
			if(temp->data < slider->data)
			{
				if(slider->left == NULL)
				{
					slider->left = temp;
					temp->parent = slider;
					return;
				}else 
				{
					slider = slider->left;
				}
			}
		}
	}

	void display()
	{
		int a = inorder(root);
	}
};


int main()
{
tree t1;
t1.add(31);
t1.add(65);
t1.add(86);
t1.add(28);
t1.add(54);
t1.add(14);
t1.add(45);
t1.add(63);
t1.add(23);
t1.display();
return 0;
}

