#include <iostream>
#include <cassert>
using namespace std;
class BST
{
private:
	struct Node
	{
		string letter;
		string code;
		Node *l;
		Node *rt;
	};
	Node *root;

public:
	BST()
	{
		root = NULL;
	}
	void Insert(Node *&r, string letter, string code)
	{
		if (r == NULL)
		{
			r = new Node;
			r->letter = letter;
			r->code = code;
			r->l = r->rt = NULL;
		//	cout << "Inserting " <<letter << '-' << code << endl;
		}
	}
	void Insert(string letter, string code)
	{
		Node **r = &root;
		if (*r != NULL)
		{
			for (std::string::size_type i = 0; i < code.length(); i++)
			{
				assert(*r);
				if (code[i] == '.') r = &((*r)->l);
				else if (code[i] == '-') r = &((*r)->rt);
				else break;
			}
			Insert(*r, letter, code);
		}
		else Insert(root, letter, code);
	}
};