class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childcount;
    bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        childcount=0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    
    Trie(char ch){
        root = new TrieNode(ch);
    }
    void  insertutil(TrieNode* root, string word){

        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //assumption word will be in CAPS
        int index = word[0]-'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //not present
        else{
            child = new TrieNode(word[0]);
            root->childcount++;
            root->children[index] = child;
        }
         
        //recursion
        insertutil(child,word.substr(1));
    }

    void insertnode(string word){
        insertutil(root, word);
    }
    
    void lcp(string str, string &ans){
        
        //process first string to check others
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            
            //if root has only one chilnode
            if(root->childcount == 1){
                ans.push_back(ch);
                
                //root ko aage badhana hai
                int index = ch -'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{    
    //creating a null root
    Trie* t = new Trie('\0');
    
    //inserting all strings in trie
    for(int i=0; i<n; i++){
        t->insertnode(arr[i]);
    }
    
    //passing first to check because other need to have same prefix
    string first = arr[0];
    string ans="";
    
    t->lcp(first,ans);
    return ans;
    
}


