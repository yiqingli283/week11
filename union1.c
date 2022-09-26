void Union(int* S, int x1, int x2){
    int root1 = Find(S, x1);
    int root2 = Find(S, x2);
    if(root1 == root2){	//如果已经属于同一集合了，不必再合并了
        return;
    	}
    S[root1] = root2;	//或者S[root2] = root1;
}
