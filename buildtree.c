//线段树
void BuildTree(int* arr, int* Tree, int start, int end, int node){
    if(start == end){	//递归终点，到达叶子结点
        Tree[node] = arr[start];
    	}
    else{
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        BuildTree(arr, Tree, start, mid, left_node);	//左半区间
        BuildTree(arr, Tree, mid + 1, end, right_node);	//右半区间
        Tree[node] = Tree[left_node] + Tree[right_node];	//自底向上返回
    	}
}

BuildTree(arr, Tree, 0, arrSize - 1, 0);