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
		treeNode *left, *right;
		treeNode(char ch) : letter(ch), left(nullptr), right(nullptr) { ; }
	};
	treeNode* root;

	char _decode(const std::string& code) const {
		treeNode* pos = root;
		if (root == nullptr) {
			throw std::exception("The tree is not loaded.");
		}
		else {
			for (unsigned int i = 0; i < code.size(); i++) {
				if (code[i] == '.') {
					pos = pos->left;
				}
				else {
					pos = pos->right;
				}
			}
		}
		return pos->letter;
	}

	std::string encode(char ch) const {
		std::queue<std::pair<treeNode*, std::string>> Q;
		std::pair<treeNode*, std::string> current;
		if (root == nullptr) {
			throw std::exception("The tree is not loaded.");
		}
		else {
			Q.push(std::make_pair(root, ""));
			while (!Q.empty()) {
				current = Q.front();
				Q.pop();
				if (current.first->letter == ch) {
					return current.second;
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

	Morse_Code_Tree() : root(nullptr) { ; }

	void build_tree(const std::string& filename) {
		std::ifstream fin;
		std::string line;
		char ch;
		std::string code;
		treeNode *pos;
		fin.open(filename.c_str());
		if (!fin.good()) {
			throw std::exception("The input file is not correct!");
		}
		else {
			while (!fin.eof()) {
				fin >> line;
				ch = line[0];
				code = line.substr(1);
				pos = root;
				for (unsigned int i = 0; i < code.size(); i++) {
					if (root == nullptr) {
						root = new treeNode(' ');
						pos = root;
					}
					if (code[i] == '.') {
						if (pos->left == nullptr) {
							pos->left = new treeNode(' ');
						}
						pos = pos->left;
					}
					else {
						if (pos->right == nullptr) {
							pos->right = new treeNode(' ');
						}
						pos = pos->right;
					}
				}
				pos->letter = ch;
			}
		}
	}


	std::string encode(const std::string& s) const {
		std::string result;
		for (unsigned int i = 0; i < s.size(); i++) {
			result += ' ' + encode(s[i]);
		}
		return result.substr(1);
	}

	std::string decode(const std::string& codes) const {
		std::string result;
		std::string current = "";
		for (unsigned int i = 0; i < codes.size(); i++) {
			if (codes[i] != ' ') {
				current += codes[i];
			}
			else {
				result += _decode(current);
				current = "";
			}
		}
		result += _decode(current);
		return result;
	}
};

#endif
