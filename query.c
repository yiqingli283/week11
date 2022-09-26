//线段树
int Query(int* arr, int* Tree, int start, int end, int left, int right, int node){
    if(start == left && end == right){	//当前结点表示区间和所求区间完全重合时返回
        return Tree[node];
    	}
    else{
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        int left_sum, right_sum;
        left_sum = right_sum = 0;
        //分别找交集
        if(left <= mid && right >= start){	//如果与[start, mid]有交集
            int l = fmax(left, start);
            int r = fmin(right, mid);
            left_sum = Query(arr, Tree, start, mid, l, r, left_node);
        	}
        if(left <= end && right >= mid + 1){
            int l = fmax(left, mid + 1);
            int r = fmin(right, end);
            right_sum = Query(arr, Tree, mid + 1, end, l, r, right_node);
        	}
        return left_sum + right_sum;	//返回两边的和
    	}
}