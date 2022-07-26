#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data  = ch;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }
    void  insertutil(TrieNode* root, string word){

        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //assumption word will be in CAPS
        int index = word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //not present
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
         
        //recursion
        insertutil(child,word.substr(1));
    }

    void insertnode(string word){
        insertutil(root, word);
    }

    bool searchutil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;  //if terminal returns true else false
        }

        //index
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];   //this child is used in next recursive loop
        }
        else{
            return false;
        }

        //recursion
        searchutil(child,word.substr(1));
    }







    void search(string word){
        return searchutil(root,word);
    }
};

int main(){

}