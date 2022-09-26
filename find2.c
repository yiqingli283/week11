//路径压缩(第一种初始化)
int Find(int* S, int x){
    if(S[x] < 0){
        return x;
    	}
   	return S[x] = Find(S, S[x]);	//递归的过程中将每个结点直接接到根节点
}

//路径压缩(第二种初始化)
int Find(int* S, int x){
    if(S[x] == x){
        return x;
    	}
    return S[x] = Find(S, S[x]);
}