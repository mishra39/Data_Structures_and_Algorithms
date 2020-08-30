class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

	bool search(TrieNode *root, string word)
	{
		int index = word[0] - 'a';
		TrieNode *child;
		if (root->children[index] != NULL)
		{
			if (word.size() == 0) 
			{
				if (root->isTerminal ==true)
				{
					return true;
				}

				else
				{
					return false;
				}
			}
		}

		else
		{
			return false;
		}

		child = root->children[index];
		search(child,word.substr(1));
	}
	
	bool search(string word)
	{
		return search(root, word);
	}

	bool patternSearching(TrieNode *root, string word)
	{
		int index = word[0] - 'a';
		TrieNode *child;

		if (root->children[index] != NULL)
		{
			if (word.size() == 0)
			{
				return true;
			}
		}

		else
		{
			return false;
		}

		child = root->children[index];
		patternSearching(child, word);
	}

	bool patternSearching(string word)
	{
		return patternSearching(root, word);
	}
	bool patternMatching(vector<string> vect, string pattern) {
		// insertion
		for (int i = 0; i < vect.size(); i++)
		{
			string word = vect[i]; // current word for building suffix tree
			
			// insert word and all suffixes
			while(word.size()!=0)
			{
				insertWord(word);
				word = word.substr(1);
			}
		}

		return patternSearching(pattern);
	}
	void removeWord(TrieNode *root, string word)
	{
		// Base Case
		if (word.size()==0)
		{
			root->isTerminal = false;
		}

		// Small Calc
		TrieNode *child;
		int index = word[0] - 'a';

		if (root->children[index]!=NULL)	
		{
			child = root->children[index];
		}

		else
		{
			return;
		}

		removeWord(child, word.substr(1));

		// Remove child node if it is useless
		if (child->isTerminal == false)
		{
			for (int i = 0; i < 26; i++)
			{
				if (child->children[i]!=NULL)
				{
					return;
				}
			}

			delete child;
			root->children[index] = NULL;
		}
	}
	void removeWord(string word)
	{
		removeWord(root, word);
	}
};