class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    
    bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
       
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
            
            root->children[index] = child;
        }
         
        //recursion
        insertutil(child,word.substr(1));
    }

    void insertnode(string word){
        insertutil(root, word);
    }
    
    void printsuggestions(TrieNode* curr, vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
            //no return?   //because terminal can be present in between it doesnt always have to be present at the end
        }
        //return nhi hai to base case?
        //next!=NULL se ho jata hai
        
        //checking all child nodes that exist 
        for(char ch='a'; ch <='z'; ch++){
            
            //next is a child node
            TrieNode* next = curr->children[ch-'a']; //checking childd nodes
            
            if(next != NULL){                     //***very imp recusrive ( same like bracket recursion function)
                prefix.push_back(ch);      //pushback all elements of childrens 
                printsuggestions(next,temp,prefix);   //recursion
                prefix.pop_back();              //pop because when one complete branch is traversed if(curr->isTerminal)
            }                                   // will store the string in temp and with each return elements need to pop
        }
    }
    vector<vector<string> > getSuggestions(string str){
        TrieNode* prev = root;     //intially given to root
        vector<vector<string> > output;      //stores output for each letter and word
        string prefix ="";  // use doublle quotes
        
        for(int i=0; i<str.length(); i++){
            char lastch = str[i];
            
            prefix.push_back(lastch);   //stores charchter of commons which are checked of a string recursion wale charachter
                                        // recursion wale function me storee honge ye jo store hue hai vo fixed prefix hai
            TrieNode* curr = prev->children[lastch-'a'];   //for checking if the character is present in child or not
            //curr child node bhi prev node ka

            //if not present
            if(curr == NULL){
                break;
            }
            
            //present
            vector<string> temp;    //ye complete strings store karta hai jo finally output honge
            printsuggestions(curr,temp,prefix);
            
            output.push_back(temp);    //stores multiple vector of strings
            temp.clear();              //free up space
            prev = curr;              //increase prev for forward going
        }
        return output;
    } 
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t = new Trie('\0');
    
    //insert all strings in trie
    int n= contactList.size();
    for(int i=0; i<n; i++){
        string str = contactList[i];
        t->insertnode(str);
    }
    
    return t->getSuggestions(queryStr);
}