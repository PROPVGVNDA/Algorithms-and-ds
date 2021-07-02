#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <stdexcept>

struct node
{
	int m_Data;
	node* m_Left;
	node* m_Right;
	node(const int& value)
	{
		m_Data = value;
		m_Left = nullptr;
		m_Right = nullptr;
	}
	~node()
	{
		delete m_Left;
		delete m_Right;
	}
};

void create_tree(node*, const int&);
void change_direction(node*, const int&, char);
void preorder(node*);
void inorder(node*);
void postorder(node*);

void create_tree(node* root, const int& value)
{
	char direction = ' ';
	std::cout << "Left or Right (l/r)?" << std::endl;
	std::cin >> direction;
	if (direction == 'l')
	{
		if (root->m_Left == nullptr)
		{
			root->m_Left = new node(value);
			std::cout << "ADDED NODE WITH VALUE - " << value << std::endl;
		}
		else
		{
			std::cout << "This node is not empty, where to go?" << std::endl;
			std::cout << "Left or Right (l/r)?" << std::endl;
			std::cin >> direction;
			change_direction(root, value, direction);
			return;
		}
	}
	else if (direction == 'r')
	{
		if (root->m_Right == nullptr)
		{
			root->m_Right = new node(value);
			std::cout << "ADDED NODE WITH VALUE - " << value << std::endl;
		}
		else
		{
			std::cout << "This node is not empty, where to go?" << std::endl;
			std::cout << "Left or Right (l/r)?" << std::endl;
			std::cin >> direction;
			change_direction(root, value, direction);
			return;
		}
	}
	else throw std::bad_exception();
}

void change_direction(node* nd, const int& value, char direction)
{
	switch (direction)
	{
	case 'l':
		if (nd->m_Left == nullptr) throw std::bad_exception();
		create_tree(nd->m_Left, value);
		break;
	case 'r':
		if (nd->m_Right == nullptr) throw std::bad_exception();
		create_tree(nd->m_Right, value);
		break;
	default:
		throw std::bad_exception();
		break;
	}
	return;
}

void preorder(node* root)
{
	if (root == nullptr) return;
	std::cout << root->m_Data << std::endl;
	preorder(root->m_Left);
	preorder(root->m_Right);
}

void inorder(node* root)
{
	if (root == nullptr) return;
	inorder(root->m_Left);
	std::cout << root->m_Data << std::endl;
	inorder(root->m_Right);
}

void postorder(node* root)
{
	if (root == nullptr) return;
	postorder(root->m_Left);
	postorder(root->m_Right);
	std::cout << root->m_Data << std::endl;
}

#endif