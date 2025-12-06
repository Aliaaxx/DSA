class TrieNode{
private:
    TrieNode* links[26]; // a pointer to a class (each element of the array is a pointer to another TrieNode)
    bool isEnd;

public:
    TrieNode() {// constructor
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        isEnd = false;
    }

    bool containsKey(char c) {
        return links[c - 'a'] != nullptr;
    }

    void put(char c, TrieNode* node) {
        links[c - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEndOfWord () {
        return isEnd;
    }
};

class Trie{
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) { // if not exists
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->containsKey(word[i])) {
                return false;
            }
            curr = curr->get(word[i]);
        }
        return curr->isEndOfWord();
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!curr->containsKey(prefix[i])) {
                return false;
            }
            curr = curr->get(prefix[i]);
        }
        return true;
    }
};
