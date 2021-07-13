#ifndef NODE_H
#define NODE_H
namespace node
{
	class node
	{
	public:
		int value();
		node*& get_next();
		explicit node(const int& value = 0);
		~node();
	private:
		int data;
		node* next;
	};
}

#endif

