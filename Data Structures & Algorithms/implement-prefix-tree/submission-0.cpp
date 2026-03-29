class PrefixTree {
public:
    PrefixTree* children[26];
    bool isEndOfWord;

    PrefixTree() : children(nullptr), isEndOfWord(false) {}

    void insert(string word) {
        PrefixTree* curr = this;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) curr->children[index] = new PrefixTree();
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        PrefixTree* curr = this;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(string prefix) {
        PrefixTree* curr = this;
        for (char c : prefix) {
            int index = c - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }
        return true;
    }
};
