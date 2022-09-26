//按大小求并，即根据集合元素的数量大小合

//方法一的初始化(此时-1，表示集合元素数为1)
void Union(int* S, int x1, int x2){
    int root1 = Find(S, x1);
    int root2 = Find(S, x2);
    if(root1 == root2){
        return;
    	}
    if(S[root1] < S[root2]){
        S[root2] = root1;
        S[root1]--;
    	}
    else if(S[root1] > S[root2]){
        S[root1] = root2;
        S[root2]--;
    	}
    else{
        S[root1] = root2;
        S[root2]--;
    	}
}


//方法二的初始化
int TreeSize[Size];	//初始化为1
void Union(int* S, int x1, int x2){
    int root1 = Find(S, x1);
    int root2 = Find(S, x2);
    if(root1 == root2){
        return;
    	}
    if(TreeSize[root1] > TreeSize[root2]){
        S[root2] = root1;
        TreeSize[root1]++;
    	}
    else if(TreeSize[root1] < TreeSize[root2]){
        S[root1] = root2;
        TreeSize[root2]++;
    	}
    else{
        S[root1] = root2;
        TreeSize[root2]++;
    	}
}
