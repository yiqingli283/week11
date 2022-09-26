typedef struct trie
{
    struct trie *child[26];
    bool isEnd;
} Trie;
 
 
Trie* trieCreate() 
{
    Trie *newNode = (Trie*)malloc(sizeof(Trie));
    memset(newNode->child,0,sizeof(newNode->child));
    newNode -> isEnd = false;
 
    return newNode;
}
 
void trieInsert(Trie* obj, char * word) 
{
    for(int i=0; i<strlen(word); i++)
    {
        int index = word[i] - 'a';
        if(obj->child[index] == NULL)
        {
            obj->child[index] = trieCreate();
        }
        obj = obj->child[index];
    }
    obj->isEnd = true;
}
 
bool trieSearch(Trie* obj, char * word) 
{
    for(int i=0; i<strlen(word); i++)
    {
        int index = word[i] - 'a';
        if(obj->child[index] == NULL)
            return false;
        obj = obj->child[index];
    }
    return obj->isEnd;
}
 
bool trieStartsWith(Trie* obj, char * prefix) 
{
    for(int i=0; i<strlen(prefix); i++)
    {
        int index = prefix[i] - 'a';
        if(obj->child[index] == NULL)
            return false;
        obj = obj->child[index];
    }
    return true;
}
 
void trieFree(Trie* obj) 
{
    for(int i=0; i<26; i++)
    {
        if(obj->child[i] != NULL)
            trieFree(obj->child[i]);
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