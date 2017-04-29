#ifndef MORSE_CODE_TREE_H
#define MORSE_CODE_TREE_H

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <utility>

class Morse_Code_Tree {
private:
	struct treeNode {
		char letter;
		treeNode* left, right;
		treeNode(char ch) : letter(ch), left(nullptr), right(nullptr) { ; }
	};

	treeNode* root;  // default to root?

	// convert Morse code into text
	char _decode(const std::string& code) const {
		treeNode* pos = root;
		if (root == nullptr) {
			throw std::exception("The tree is not loaded");
		}
		else {
			for (unsigned int i = 0; i < code.size(); i++) {
				if (code[i] == '.') { // if code equals . go left
					pos = pos->left;
				}
				else {
					pos = pos->right;
				}
				// if code equals - go right
			}
		}
		return pos->letter;
	}


	std::string encode(char ch) const { //decode  a single character
		std::queue<std::pair<treeNode*, std::string>> Q;
		std::pair<treeNode*, std::string> current;
		if (root == nullptr) {
			throw std::exception("The tree is not loaded.");
		}
		else {
			Q.push(std::make_pair(root, ""));
			while (!Q.empty())
			{
				current = Q.front();
				Q.pop();
				if (current.first->letter) {
					return current.second; // keep track of the path from root to the character
				}
				else {
					if (current.first->left != nullptr) {
						Q.push(std::make_pair(current.first->left, current.second + "."));
					}
					if (current.first->right != nullptr) {
						Q.push(std::make_pair(current.first->right, current.second + "-"));
					}
				}
			}
		}
		return "";
	}


public:
	Morse_Code_Tree() : root(nullptr) { ;}
	
	std::string encode(const std::string& s) const {
		std::string result;
		for (unsigned int i = 0; i < s.size(); i++) {
			result += ' ' + encode(s[i]);
		}
		return result.substr(1);
	}
};


#endif