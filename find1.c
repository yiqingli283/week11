//第一种初始化方式的Find操作
int Find(int* S, int x){
    if(S[x] < 0){
        return x;
    	}
    return Find(S, S[x]);
}

//第二种初始化方式的Find操作
int Find(int* S, int x){
    if(S[x] == x){
        return x;
    	}
    return Find(S, S[x]);
}