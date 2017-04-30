#ifndef NODE_H
#define NODE_H

#include<string>
 std::string;
 class Morse_Code_Tree{
 public:
	 void buildtree();
	 void addintree(string a);
 
	 struct Node{
		 std::string cd;
		 std::string letter;
		 Node* dot;
		 Node* dash;
		 //void addintree(string a);
		
		 Node(const std::string c, const std::string l, Node* left = NULL,
			 Node* right = NULL) : cd(c), letter(l), dot(left), dash(right) {}
		

		
		 virtual ~Node() {}


		 std::string get_code(){
			 return cd;
		 }

		 std::string get_letter(){
			 return letter;
		 }
	 };
 


#endif 