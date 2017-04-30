

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
				add(line);
			}

			morse_code.close();

		}
		void::Morse_Code_Tree::add()
		{
			string a, c;
			ifstream line;
			line >> a >> c;
			MTNode* temp_node = get_root();

		}