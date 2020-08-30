// #include "TrieNode.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
    public :
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

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


    TrieNode *findWord(TrieNode *root, string word)
    {
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            if (word.size()==0)
            {
                return root->children[index];
            }
        }

        else
        {
            return NULL;
        }

        child = root->children[index];
        return findWord(child,word.substr(1));
    }

    TrieNode *findWord(string word)
    {
        return findWord(root, word);
    }

    void printPossibleWords(TrieNode *root, string word, string output)
    {   
        // Base Case
        if(root->isTerminal)
        {
            output.push_back(root->data);
            cout << word + output << endl;
            return;
        }

        // Small Calc and Recursion
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                output.push_back((root->children[i])->data);
                printPossibleWords(root->children[i], word, output);
            }
        }
    }

    void autoComplete(vector<string> input, string pattern)
    {
        // insertion
        for (int i = 0; i < input.size(); i++)
        {
            string word = input[i]; 
            insertWord(word); // add current word
        }

        TrieNode *node = findWord(pattern);
        if (node == NULL)
        {
            string output;
            printPossibleWords(root, pattern, output);
        }
    }

};


int main() {
    Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}