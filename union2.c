//第一种初始化
void Union(int* S, int x1, int x2){
    int root1 = Find(S, x1);
    int root2 = Find(S, x2);
    if(root1 == root2){
        return;
    	}	
    if(S[root1] < S[root2]){	//说明树1更高
        S[root2] = root1;
    	}
    else if(S[root1] > S[root2]){	//树2更高
        S[root1] = root2;
    	}
    else{	//如果两树一样高，选择一个接到另一个下面，然后更新高度
        S[root1] = root2;
        S[root2]--;
    	}
}


//第二种初始化
int TreeHight[Size];	//需要一个额外的数组表示高度，且初始化为1
void Union(int* S, int x1, int x2){
    int root1 = Find(S, x1);
    int root2 = Find(S, x2);
    if(root1 == root2){
        return;
    	}
    if(TreeHight[root1] > TreeHight[root2]){
        S[root2] = root1;
    	}
    else if(TreeHight[root1] < TreeHight[root2]){
        S[root1] = root2;
    	}
    else{
        S[root1] = root2;
        TreeHight[root2]++;
    	}
}