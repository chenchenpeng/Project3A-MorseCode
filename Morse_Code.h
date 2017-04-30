#include <iostream>
#include <fstream>
#include <sstream>
#include "Morse_Code_Tree.h"
#include "Node.h"

using namespace std;
Morse_Code_Tree::Morse_Code_Tree(){
Node* root;
	root = new Node("_", "_", NULL, NULL);
	buildtree();
}

void Morse_Code_Tree::buildtree()
{
	std::string line;
	std::ifstream morse_code;
	morse_code.open("morse.txt");
	while (!morse_code.eof())
	{
		if (morse_code.eof())
		{
			break;
		}
		else{
			getline(morse_code, line);
			addintree(line);
		}

		morse_code.close();

	}
}
	void Morse_Code_Tree::addintree(string l)
	{
		string a, c;
		ifstream line(l);

		line >> a >> c;
		Node* temp_node ;
	
		for (int i = 0; i < c.size(); i++){
			if (c[i] == '.'){
				if (temp_node->dot == NULL)
					temp_node->dot = new Node(c, a, NULL, NULL);
				else
					temp_node = temp_node->dot;
			}
			else if (c[i] == '-'){
				if (temp_node->dash == NULL)
					temp_node->dash = new Node(c, a, NULL, NULL);
				else
					temp_node = temp_node->dash;
			}
		
		}
	
	}

	