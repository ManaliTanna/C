#include<stdio.h>
#define MAX 50
int main()
{
	int a[MAX];
	int i,c,p,n,elt;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);

	//Heapify---------------------------> top down
	for(i=1;i<n;i++)
	{
		elt=a[i]; //elt is key
		c=i;
		p=(c-1)/2;//find parent
		while(c>0 && a[p]<elt)
		{
			a[c]=a[p];
			c=p;
			p=(c-1)/2;
		}
		a[c]=elt;
	}


	//display heapified elements
	printf("\nElements of heap:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	
	//Heap sort
	for(i=n-1;i>0;i--)
	{
		elt=a[i];
		a[i]=a[0];
		p=0;
		if(i==1)
			c=-1;
		else
			c=1;
		if(i>2 && a[2]>a[1])
			c=2;
		while(c>=0 && elt<a[c])
		{
			a[p]=a[c];
			p=c;
			c=2*p+1;
			if(c+1<=i-1 && a[c]<a[c+1])
				c=c+1;
			if(c>i-1)
				c=-1;
		}
		a[p]=elt;
	}
	printf("\nSorted elements(Heap sort):\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
	return 0;
}




void bottom_heap(int *h,int n)//h is heap and n is elements (0 to n-1)
{
	int child,parent,k;
	//start from last parental node
	for(k=(n-2)/2;k>=0;k--)
	{
		parent = k;
		key = h[parent] //key is to avoid swaps
		//find left child position as defaut
		child = 2*parent + 1;
		while(child < n)//while left child exists, its possible its leaf node...
		{
			if(child+1 < n && h[child+1] > h[child])//if right child also exists and is greater than left child
			{
					child = child +1; //change focus of child to the larger one
			}
			if(h[child] > key) //key is value at parent
			{
				h[parent] = h[child]; //move value at child to parent 
				parent = child; //the new parent is the child
				child = 2*parent +1;//the new child is the child of the new parent
			}
			else
				break;	
		}//while ends
		h[parent]=key; 
	}//end for -> do it for every parent position
}