#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    void increaseEnd(){
        cntEndsWith++;
    }
    void deleteEnd(){
        cntEndsWith--;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void reducePrefix(){
        cntPrefix--;
    }
};

class Trie
{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    };
    ~Trie(){};

    /**  insert a word into the trie */
    void insert(string &word){
        Node* node = this->root;

        for (int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());

            }
            // move to the reference trie
            node = node->get(word[i]);
            node->increasePrefix();
        }

        node->increaseEnd();
        
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->cntEndsWith;
    }

    /** O(len)*/
    bool search(string word){
        Node* node  = this->root;
        for (int i = 0; i < word.length(); i++)
        {
            if(!node-> containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();
        
    }
    /** O(len)*/
    bool startWith(string prefix){
        Node* node = this->root;
        for (int i = 0; i < prefix.length(); i++)
        {   
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
        
    }
};

