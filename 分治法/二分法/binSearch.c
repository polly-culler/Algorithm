int binSearch(int array[], int x,int n){
	int low = 0;
	int high = n-1;
	int mid = 0;
	while(low < high){
		mid = (low + high)/2;
		if(x == array[mid]){
			printf("%d,%d\n",n,mid);
			return 1;
		}
		else if (x > array[mid])
		
			/* code */
			low = mid + 1;
			else 
				high = mid - 1;
	}
	return 0;
	
}