#include <string>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    // For user
    void add(string word)
    {
        if (add(root, word))
        {
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
    /*..................... Palindrome Pair................... */
    

    bool isPalindromePair(vector<string> words)
    {
		// insertion
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i]; 
            add(word); // add current word
            string revWord = reverse(word.begin(),word.end());
            // if the current word itself is a palindrome
            if (search(revWord))
            {
                return true;
            }
        }

        return false;
    }

};