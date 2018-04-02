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

node *look(node *a, int key)
{
	node *ret;
	if(a == NULL)
	{
		return NULL;
	}
	if(a->data == key)
	{
		return a;
	}
	if(key < a->data)
	{
		ret = look(a->left, key);
	}
	
	else if(key > a->data)
	{
		ret = look(a->right, key);
	}
	return ret;
}

node *smallest(node *root)
{
	node *slider = root;
	while(slider->left != NULL)
	{
		slider = slider->left;
	}
	return slider;
}


node *biggest(node *root)
{
	node *slider = root;
	while(slider->right != NULL)
	{
		slider = slider->right;
	}
	return slider;
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

	node *search(int key)
	{
		node *result;
		result = look(root,key);
		if(result == NULL)
		{
			cout<<"node not found";
		}else
		{
			cout<<"node found";
		}
		return result;	
	}
	
	int deletion(int key)
	{
		node *keyn = NULL;
		node *replace = NULL;
		keyn = search(key);
		if(keyn != NULL)
		{
			if(keyn->right != NULL)
			{	
				replace = smallest(keyn->right);
				if(replace->right != NULL)
				{
					replace->right->parent = replace->parent;
					replace->parent->left = replace->right;
				}
				if(keyn->parent->left == keyn)
				{
					keyn->parent->left = replace;
					replace->parent = keyn->parent;
					replace->left = keyn->left;
					replace->right = keyn->right;
					keyn->left->parent = replace;
					keyn->right->parent = replace;
				}else
				{
					keyn->parent->right = replace;
					replace->parent = keyn->parent;
					replace->left = keyn->left;
					replace->right = keyn->right;
					keyn->left->parent = replace;
					keyn->right->parent = replace;
				}
				delete keyn;
			}else
			if(keyn->left != NULL)
			{	
				replace = biggest(keyn->left);
				if(replace->left != NULL)
				{
					replace->left->parent = replace->parent;
					replace->parent->right = replace->left;
				}
				if(keyn->parent->left == keyn)
				{
					keyn->parent->left = replace;
					replace->parent = keyn->parent;
					replace->left = keyn->left;
					replace->right = keyn->right;
					keyn->left->parent = replace;
					keyn->right->parent = replace;
				}else
				{
					keyn->parent->right = replace;
					replace->parent = keyn->parent;
					replace->left = keyn->left;
					replace->right = keyn->right;
					keyn->left->parent = replace;
					keyn->right->parent = replace;
				}
				delete keyn; 
			}else
			{
				if(keyn->parent->left == keyn)
				{
					keyn->parent->left = NULL;
				}else
				{
					keyn->parent->right = NULL;
				}
				delete keyn;
			} 	
		}
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
t1.add(17);
t1.add(57);
t1.add(36);
t1.add(85);
t1.add(46);
t1.display();
t1.search(59);
t1.deletion(36);
t1.display();
return 0;
}
