//线段树
void Update(int* arr, int* Tree, int start, int end, int idx, int val, int node){
    if(start == end){
        arr[idx] = val;
        Tree[node] = val;
    	}
    else{
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        if(start <= idx && idx <= mid){	//根据idx所属的区间选择路径
            Update(arr, Tree, start, mid, idx, val, left_node);
        	}
        else{
            Update(arr, Tree, mid + 1, end, idx, val, right_node);
        	}
        Tree[node] = Tree[left_node] + Tree[right_node];	//更新结点
    	}
}
