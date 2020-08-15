/*
 * @lc app=leetcode.cn id=208 lang=c
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start



typedef struct trie{
    int isEnd;
    struct trie* next[26];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie* root = (Trie*)malloc(sizeof(Trie));
    memset(root, 0, sizeof(Trie));
    root->isEnd = 0;
    return root;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int len = strlen(word);
    if (obj == NULL || len == 0)
        return;
    Trie *node = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        if (node->next[word[i] - 'a'] == NULL) 
            node->next[word[i] - 'a'] = trieCreate();
        node = node->next[word[i] - 'a'];
    }
    node->isEnd = 1;

}

#define WORD_END 1
#define WORD_START_WITH 0
bool trieSearchWord(Trie* obj, char *word, int isWordEnd)
{
    Trie* node = obj;
    int len = strlen(word);
    if (obj == NULL || strlen == 0)
        return false;
    
    for (int i = 0; word[i] != '\0'; i++) {
        if (node->next[word[i]-'a'] == NULL)
            return false;
        node = node->next[word[i] - 'a'];
    }
    if (isWordEnd) 
        return node->isEnd > 0;
    else 
        return true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    return trieSearchWord(obj, word, WORD_END);
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    return trieSearchWord(obj, prefix, WORD_START_WITH);
}

void trieFree(Trie* obj) {
    if (obj == NULL)
        return;
    for (int i = 0; i < 26; i++) {
        if (obj->next[i])
            trieFree(obj->next[i]);
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
// @lc code=end

