#include<iostream>
#include<fstream>
#include"bst.h"
#include<string>
using namespace std;
int main() {
	BST t;
	/*struct alphaTree
	{
	
		string letter;
		string code;
	};

	
	alphaTree tree[] = {*/
	string letter;
	string code;
				string line;
				std::ifstream morse_code;
				morse_code.open("morse.txt");
				while (!morse_code.eof())
				{
					if (morse_code.eof())
					{
						break;
					}
					else{
						morse_code >> letter >> code;
						for (int i = 0; i < 27; i++)
						{
							//t.Insert(tree[i].letter, tree[i].code);
							t.Insert(letter, code);
						}
					}
				}
					morse_code.close();

				//};


	// your code goes here
	return 0;
}