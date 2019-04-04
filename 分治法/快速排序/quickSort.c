void quickSort(int left, int right){
	int i,j,t,temp;
	if(left > right) return;
	temp = a[left];
	i = left;
	j = right;
	while( i != j){
		while(a[j] >= temp && i<j) j--;
		//从右往左
		while(a[i] <= temp && i<j) i++;
		//从左往右
		if(i<j){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		a[left] = a[i];
		a[i] = temp;
		quickSort(left, i-1);//处理左边
		quickSort(i+1, right);//处理右边
	}
}