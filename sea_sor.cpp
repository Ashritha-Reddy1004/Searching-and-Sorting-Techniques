//searching and sorting techniques
#include<iostream>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;
int linear()
{
	int arr[100], tot, i, num, arrTemp[50], j=0, chk=0;
    cout<<"Enter the Size for Array Size: ";
    cin>>tot;
    cout<<"Enter "<<tot<<" Array Elements: ";
    for(i=0; i<tot; i++)
        cin>>arr[i];
    cout<<"\nEnter the Number to Search: ";
    cin>>num;
    for(i=0; i<tot; i++)
    {
        if(arr[i]==num)
        {
            arrTemp[j] = i;
            j++;
            chk++;
        }
    }
    if(chk>0)
    {
        cout<<"\nNumber Found at Index No. ";
        tot = chk;
        for(i=0; i<tot; i++)
            cout<<arrTemp[i]<<" ";
    }
    else
        cout<<"\nNumber doesn't Found!";
    cout<<endl;
    return 0;
}
int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;
    if (array[mid] == x)
      return mid;
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}
int jumpSearch(int array[], int size, int key) {
   int start = 0;
   int end = sqrt(size); 

   while(array[end] <= key && end < size) {
      start = end; 
      end += sqrt(size);
      if(end > size - 1)
         end = size; 
   }
    for(int i = start; i<end; i++) {
      if(array[i] == key)
         return i; 
   }
   return -1;
}
int interpolationSearch(int array[], int start, int end, int key) {
   int dist, valRange, indexRange, estimate;
   float fraction;
   while(start <= end && key >= array[start] && key <= array[end]) {
      dist = key - array[start];
      valRange = array[end] - array[start];     
      fraction = dist / valRange;
      indexRange = end - start;
      estimate = start + (fraction * indexRange);      
      if(array[estimate] == key)
         return estimate;
      if(array[estimate] < key)
         start = estimate +1;
      else
         end = estimate - 1;
   }
   return -1;
}
int binarySear(int arr[], int, int, int); 
int exponentialSearch(int arr[], int n, int x) 
{
    if (arr[0] == x) 
        return 0;  
    int i = 1; 
    while (i < n && arr[i] <= x) 
        i = i*2;
    return binarySear(arr, i/2, min(i, n), x); 
} 
int binarySear(int arr[], int l, int r, int x) 
{ 
    if (r >= l) 
    { 
        int mid = l + (r - l)/2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySear(arr, l, mid-1, x); 
         return binarySear(arr, mid+1, r, x); 
    }  
    return -1; 
} 
struct Node 
{ 
    int data; 
    Node* next; 
};  
bool findList(Node* first, Node* second) 
{ 
    Node* ptr1 = first, *ptr2 = second;  
    if (first == NULL && second == NULL) 
        return true;
    if ( first == NULL || 
        (first != NULL && second == NULL)) 
        return false;  
    while (second != NULL) 
    { 
        ptr2 = second; 
        while (ptr1 != NULL) 
        { 
            if (ptr2 == NULL);
            else if (ptr1->data == ptr2->data) 
            { 
                ptr1 = ptr1->next; 
                ptr2 = ptr2->next; 
            }  
            else break; 
        }  
        if (ptr1 == NULL) 
            return true; 
        ptr1 = first;  
        second = second->next; 
    } 
  
    return false; 
} 
void printList(Node* node) 
{ 
    while (node != NULL) 
    { 
        cout<<node->data; 
        node = node->next; 
    } 
} 
Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp-> data= key; 
    temp->next = NULL; 
    return temp; 
}
int min(int x, int y)
{
    return (x<=y)? x : y;
}
int fibonaccianSearch(int arr[], int x, int n)
{
    int fbM2 = 0;   
    int fbM1 = 1;   
    int fbM = fbM2 + fbM1; 
    int offset = -1;
    while (fbM < n)
    {
        fbM2 = fbM1;
        fbM1 = fbM;
        fbM  = fbM2 + fbM1;
    }
    while (fbM > 1)
    {
    int i = min(offset+fbM2, n-1);
    if (arr[i] < x)
    {
        fbM  = fbM1;
        fbM1 = fbM2;
        fbM2 = fbM - fbM1;
        offset = i;
    }
    else if (arr[i] > x)
    {
        fbM  = fbM2;
        fbM1 = fbM1 - fbM2;
        fbM2 = fbM - fbM1;
    }
    else return i;
    }
    if(fbM1 && arr[offset+1]==x)
    return offset+1;
    return -1;
}
int UbiSearch(int array[], int x, int low, int high) {
if (high >= low) {
    int mid = low + (high - low) / 2;
    if (array[mid] == x)
      return mid;
    if (array[mid] > x)
      return UbiSearch(array, x, low, mid - 1);
    return UbiSearch(array, x, mid + 1, high);
  }

  return -1;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void insertionSort(int *array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key;   
   }
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
 int bubble_sort()
{
int i, j,temp,pass=0;
                int a[20],n;
                cout<<"Enter the number of elements\n";
                cin>>n;
                cout<<"Enter the elements to be sorted\n";
                for(i=0;i<n;i++)
                cin>>a[i];
                cout <<"Input list ...\n";
                for(i = 0; i<10; i++) {
                  cout <<a[i]<<"\t";
                 }
                cout<<endl;
                for(i = 0; i<10; i++) {
                   for(j = i+1; j<10; j++)
                     {
                          if(a[j] < a[i]) {
                             temp = a[i];
                             a[i] = a[j];
                             a[j] = temp;
                          }
                      }
                    pass++;
                }
                    cout <<"Sorted Element List ...\n";
                    for(i = 0; i<10; i++) {
                    cout <<a[i]<<"\t";
                }
                     cout<<"\nNumber of passes taken to sort the list:"<<pass<<endl;
					 return 0;
					 }
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++; 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}   
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);   
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
void printarray(int arrayb[30], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arrayb[i] << " ";  
    cout << endl;  
}  
void swapping(int &a, int &b) {         
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display1(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void selectionSort(int *array, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i; 
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
         swap(array[i], array[imin]);
   }
}
int partition1(int arr[], int l, int h) 
{ 
    int x = arr[h]; 
    int i = (l - 1); 
  
    for (int j = l; j <= h - 1; j++) { 
        if (arr[j] <= x) { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 
void quickSort1(int A[], int l, int h) 
{ 
    if (l < h) { 
        int p = partition1(A, l, h); 
        quickSort1(A, l, p - 1); 
        quickSort1(A, p + 1, h); 
    } 
} 
void recBubble(int arr[], int n){
   if (n == 1)
      return;
   for (int i=0; i<n-1; i++) 
      if (arr[i] > arr[i+1]) 
   swap(arr[i], arr[i+1]); 
   recBubble(arr, n-1);
}  
void insertionSortRecursive(int arr[], int n) 
{  
    if (n <= 1) 
        return; 
    insertionSortRecursive( arr, n-1 );  
    int last = arr[n-1]; 
    int j = n-2;
    while (j >= 0 && arr[j] > last) 
    { 
        arr[j+1] = arr[j]; 
        j--; 
    } 
    arr[j+1] = last; 
} 
void prinArray(int arr[], int n) 
{ 
    for (int i=0; i < n; i++) 
        cout << arr[i] <<" "; 
} 
int main()
{
	 int choice,no,item;
		cout<<"1.Searching Techniques\n";
		cout<<"2.Sorting Techniques\n";
		cout<<"Enter your Choice\n";
		cin>>choice;
	if(choice==1){
		
	
	while(no!=9)
	    {
	  	cout<<"1.Linear Search\n";
	  	cout<<"2.Binary Search\n";
	  	cout<<"3.Jump Search\n";
	  	cout<<"4.Interpolation Search\n";
	  	cout<<"5.Exponential Search\n";
	  	cout<<"6.Sublist Search\n";
	  	cout<<"7.Fibonacci Search\n";
	  	cout<<"8.Ubiquitous Search\n";
	  	cout<<"9.Exit\n";
	    cin>>no;
	    switch(no)
	    {
	    	case 1:
	    		while(item!=4)
	    		{
	    			cout<<"1.Information\n";
	    			cout<<"2.Algorithm\n";
	    			cout<<"3.Implementation\n";
	    			cout<<"4.Exit\n";
	    			cin>>item;
	    			switch(item)
	    			{
	    				case 1:
	    					cout<<"Time Complexity of Linear Search O(n)\n Space Complexity of Linear Search O(1)\n";
	    					break;
	    				case 2:
	    					cout<<"Step 1: Set i to 1 \nStep 2: if i > n then go to step 7 \nStep 3: if A[i] = x then go to step 6 \n";
                            cout<<"Step 4: Set i to i + 1\nStep 5: Go to Step 2\nStep 6: Print Element x Found at index i and go to step 8\n";
                            cout<<"Step 7: Print element not found\nStep 8: Exit";
                            break;
                        case 3:
                        	linear();
                            break;
                        case 4:
                        	exit(1);
                        	break;
	    					
					}
	    			
				}
				case 2:
				while(item!=4)
	    		{
	    			cout<<"1.Information\n";
	    			cout<<"2.Algorithm\n";
	    			cout<<"3.Implementation\n";
	    			cout<<"4.Exit\n";
	    			cin>>item;
	    			switch(item)
	    			{
	    				case 1:
	    					cout<<"Time Complexity of Binary Search log(n)\n Space Complexity of Binary Search O(1)\n";
	    					break;
	    				case 2:
	    					cout<<"Compare x with the middle element.\n If x matches with middle element, we return the mid index.\n";
                            cout<<"Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element.\n";
							cout<<" So we recur for right half.\nElse (x is smaller) recur for the left half.\n";
                            break;
                        case 3:
                            int array[20],x,n,result;
                            cout<<"Enter no. of elements to be entered in to the array\n";
                            cin>>n;
                            cout<<"Enter the elements\n";
                            for(int i=0;i<x;i++)
                               cin>>array[i];
                            cout<<"Enter the element to be searched\n";
                            cin>>x;
                            result = binarySearch(array, x, 0, n - 1);
                            if (result == -1)
                                cout<<"Not found";
                            else
                                cout<<"Element is found at index"<<result<<"\n";
                            break;
                        case 4:
                        	exit(1);
                        	break;
	    					
					}
				
		     	}
		     	case 3:
		     		while(item!=4)
	    		{
	    			cout<<"1.Information\n";
	    			cout<<"2.Algorithm\n";
	    			cout<<"3.Implementation\n";
	    			cout<<"4.Exit\n";
	    			cin>>item;
	    			switch(item)
	    			{
	    				case 1:
	    					cout<<"Time Complexity of Jump Search O(1)\n Space Complexity of Jump Search is between O(1)\n";
	    					break;
	    				case 2:
	    					cout<<"Step 1: Start from index 1\nStep 2: Jump head by B elements. Current position = Current position + B. If position is out of element list, set current position to last position.\n";
                            cout<<"If element at current position target element, then do Linear Search on element from position current position -B to current position";
							cout<<"else go to step 2. If current position is last position, go to step 4.\n";
                            cout<<"Exit. Element not found.\n";
						    break;
                        case 3:
                        	int n, searchKey, loc,arr[20];;
                            cout << "Enter number of items: ";
                            cin >> n;
                            cout << "Enter items: " << endl;
                            for(int i = 0; i< n; i++) 
                                cin >> arr[i];
							cout << "Enter search key to search in the list: ";
                                cin >> searchKey;
                            if((loc = jumpSearch(arr, n, searchKey)) >= 0)
                                cout << "Item found at location: " << loc << endl;
                            else
                                cout << "Item is not found in the list." << endl;
                            break;
                        case 4:
                        	exit(1);
                        	break;
	    		
	    		}
	    	}
	    	case 4:
	    		while(item!=4)
	    		{
	    			cout<<"1.Information\n";
	    			cout<<"2.Algorithm\n";
	    			cout<<"3.Implementation\n";
	    			cout<<"4.Exit\n";
	    			cin>>item;
	    			switch(item)
	    			{
	    				case 1:
	    					cout<<"Time Complexity of Interpolation Search O(log2(log2 n))\n Space Complexity of Interpolation Search O(1)\n";
	    					break;
	    				case 2:
	    					cout<<"Step 1 - Start searching data from middle of the list.\nStep 2 - If it is a match, return the index of the item, and exit.\n";
                            cout<<"Step 3 - If it is not a match, probe position.\nStep 4 - Divide the list using probing formula and find the new midle.\n";
                            cout<<"Step 5 - If data is greater than middle, search in higher sub-list.\nStep 6 - If data is smaller than middle, search in lower sub-list.\n";
                            cout<<"Step 7 - Repeat until match.\n";
                            break;
                        case 3:
                        	int n, searchKey, loc,arr[20];
                            cout << "Enter number of items: ";
                            cin >> n;   
                            cout << "Enter items: " << endl;
                            for(int i = 0; i< n; i++) 
                              cin >> arr[i];
                            cout << "Enter search key to search in the list: ";
                              cin >> searchKey;
                            if((loc = interpolationSearch(arr, 0, n-1, searchKey)) >= 0)
                              cout << "Item found at location: " << loc << endl;
                            else
                              cout << "Item is not found in the list." << endl;
                            break;
                        case 4:
                        	exit(1);
                        	break;
	    					
					}
	    			
				}
				case 5:
					while(item!=4)
	    		{
	    			cout<<"1.Information\n";
	    			cout<<"2.Algorithm\n";
	    			cout<<"3.Implementation\n";
	    			cout<<"4.Exit\n";
	    			cin>>item;
	    			switch(item)
	    			{
	    				case 1:
	    					cout<<"Time Complexity of Exponential Search O(1)\n Space Complexity of Exponential Search O(1)\n";
	    					break;
	    				case 2:
	    					cout<<"Step 1: Find range where element is present\nStep 2: Execute Binary Search algorithm in above found range. \n";
                            cout<<"Step 3: The idea is to start with sub-list of size 1. Ccompare the last element of the list with the target element, then try size 2, then 4 and so on until last element of the list is not greater.\n";
                            cout<<"Step 4: Once we find a location loc (after repeated doubling of list size), we know that the element must be present between loc/2 and loc. \nStep 5: Exit\n";
                            break;
                        case 3:
                        	int arr[20],n,x,result;
							cout<<"Enter the number of elements\n";
							cin>>n;
							cout<<"Enter the elements into the arrar\n";
							for(int i=0;i<n;i++)
							cin>>arr[i];
							cout<<"Enter the element to be searched\n";
							cin>>x;
							result = exponentialSearch(arr, n, x); 
                            (result == -1)? printf("Element is not present in array") : printf("Element is present at index %d",result);
                            break;
                        case 4:
                        	exit(1);
                        	break;
	    			}
	    		}
			case 6:
					while(item!=4)
	    		{
	    			cout<<"1.Information\n";
	    			cout<<"2.Algorithm\n";
	    			cout<<"3.Implementation\n";
	    			cout<<"4.Exit\n";
	    			cin>>item;
	    			switch(item)
	    			{
	    				case 1:
	    					cout<<"Time Complexity of sub list Search O(m*n)\n Space Complexity of Sublist Search O(n)\n";
	    					break;
	    				case 2:
	    					cout<<"1- Take first node of second list.\n2- Start matching the first list from this first node.\n 3- If whole lists match return true\n";
                            cout<<"4- Else break and take first list to the first node again.\n 5- And take second list to its second node. \n";
                            cout<<"6- Repeat these steps until any of linked lists becomes empty. \n7- If first list becomes empty then list found else not.\n";
                            break;
                        case 3:
                        	linear(); 
                            break;
                        case 4:
                        	exit(1);
                        	break;
	    					
					}
	    		}
	    		case 7:
	    		while(item!=4)
	    		{
	    			cout<<"1.Information\n";
	    			cout<<"2.Algorithm\n";
	    			cout<<"3.Implementation\n";
	    			cout<<"4.Exit\n";
	    			cin>>item;
	    			switch(item)
	    			{
	    				case 1:
	    					cout<<"Time Complexity of Fibonacci Search O(log(n))\n Space Complexity of Fibonacci Search O(n)\n";
	    					break;
	    				case 2:
	    					cout<<"Find the smallest Fibonacci number greater than or equal to n. Let this number be fb(M) [m’th Fibonacci number].\n";
                            cout<<"While the array has elements to be checked:\nCompare x with the last element of the range covered by fb(M-2)\nIf x matches, return index value \nElse if x is less than the element, move the third Fibonacci variable two Fibonacci down, indicating removal of approximately two-third of the unsearched array.\n";
                            cout<<"Since there might be a single element remaining for comparison, check if fbMm1 is '1'. If Yes, compare x with that remaining element. If match, return index value.\n";
                            break;
                        case 3:
                          int l,arr[10],n;
                          cout<<"Enter the size of the array\n";
                          cin>>n;
                          cout<<"Enter elements in array";
                          for(int i=0;i<n;i++)
                            cin>>arr[i];
						   int x;
						   cout<<"\nEnter element to be searched :" ;
                           cin>>x;
                           cout<<"Found at index:"<<fibonaccianSearch(arr, x, n);
                           break;
                        case 4:
                        	exit(1);
                        	break;
	    			}	
				}
	            case 8:
	    		while(item!=4)
	    		{
	    			cout<<"1.Information\n";
	    			cout<<"2.Algorithm\n";
	    			cout<<"3.Implementation\n";
	    			cout<<"4.Exit\n";
	    			cin>>item;
	    			switch(item)
	    			{
	    				case 1:
	    					cout<<"Time Complexity of Ubiquitous Search O(n)\n Space Complexity of Ubiquitous Search O(1)\n";
	    					break;
	    				case 2:
	    					cout<<"Step 1: Set i to 1 \nStep 2: if i > n then go to step 7 \nStep 3: if A[i] = x then go to step 6 \n";
                            cout<<"Step 4: Set i to i + 1\nStep 5: Go to Step 2\nStep 6: Print Element x Found at index i and go to step 8\n";
                            cout<<"Step 7: Print element not found\nStep 8: Exit";
                            break;
                        case 3:
                        	int array[20],x,n,result;
                            cout<<"Enter no. of elements to be entered in to the array\n";
                            cin>>n;
                            cout<<"Enter the elements\n";
                            for(int i=0;i<x;i++)
                               cin>>array[i];
                            cout<<"Enter the element to be searched\n";
                            cin>>x;
                            result = UbiSearch(array, x, 0, n - 1);
                            if (result == -1)
                                cout<<"Not found";
                            else
                                cout<<"Element is found at index"<<result<<"\n";
                            break;
                        	
                            break;
                        case 4:
                        	exit(1);
                        	break;
	    					
					}
	    			
				}
			}
	        
	  }
	    }
     
   else
      while(no!=9)
	    {
	  	    cout<<"1.Bubble Sort \n";
	  	    cout<<"2.Insertion Sort\n";
	     	cout<<"3.Merge Sort\n";
	      	cout<<"4.Quick Sort\n";
	     	cout<<"5.Selection Sort\n";
	     	cout<<"6.Iterative Quick Sort\n";
	    	cout<<"7.Recursive Bubble Sort\n";
	    	cout<<"8.Recursive Insertion Sort\n";
	    	cout<<"9.Exit\n";
	        cin>>no;
	    switch(no)
	    {
	    	case 1:
	    		bubble_sort();
	    	     break;
	    	case 2:
	    	   int n;
               cout << "Enter the number of elements: ";
               cin >> n;
               int arr[30]; 
               cout << "Enter elements:" << endl;
               for(int i = 0; i<n; i++) {
                   cin >> arr[i];
                }
                cout << "Array before Sorting: ";
                display(arr, n);
                insertionSort(arr, n);
                cout << "Array after Sorting: ";
                display(arr, n);
                break;
	    	case 3:
	    		int array[20],arr_size;
                cout<<"Enter the size of the array\n";
                cin>>arr_size;
                cout<<"Enter the values\n";
                for(int i=0;i<arr_size;i++)
                   cin>>array[i];
                cout << "Given array is \n";
                printArray(array, arr_size);
                mergeSort(array, 0, arr_size - 1);
                cout << "\nSorted array is \n";
                printArray(array, arr_size);
	    		break;
		    case 4:
		    	 int arrayb[20],i,n1;  
                 cout<<"Enter the size of the array\n";
				 cin>>n;
				 cout<<"Enter the elements\n";
				 for(i=0;i<n1;i++)
				 cin>> arrayb[i];
                 quickSort(arrayb, 0, n1 - 1);  
                 cout << "Sorted array: \n";  
                 printarray(arrayb, n1);  
                 break;
            case 5:
            	int n2;
                cout << "Enter the number of elements: ";
                cin >> n2;
                int ar[30];         //create an array with given number of elements
                cout << "Enter elements:" << endl;
                for(int i = 0; i<n2; i++) {
                   cin >> ar[i];
                }
                cout << "Array before Sorting: ";
                display1(ar, n2);
                selectionSort(ar, n2);
                cout << "Array after Sorting: ";
                display(ar, n2);
            	break;
            case 6:
                int N,A[30];
				cout<<"Enter the size of the array\n";
				cin>>N;
				cout<<"Enter the elements into the array\n";
				 for(int i=0;i<N;i++ )
				  cin>>A[i];
                quickSort1(A, 0, n - 1); 
                for (i = 0; i < N; i++) { 
                 cout << A[i] << " "; 
				 } 
            	break;
            case 7:
              int data[30],n3;
              cout<<"Enter the size of the array\n";
              cin>>n3;
              cout<<"Enter the elements into the array\n";
              for(int i=0;i<n;i++)
              cin>>data[i];
			  cout << "Sorted Sequence ";
              recBubble(data, n3);
              for(i = 0; i <n;i++)
                cout << data[i] << " ";
                break;
   	        case 8:
   	            int element[20],z;
			    cout<<"Enter the size of the array\n";
                cin>>z;
                cout<<"Enter the elements into the array\n";
                for(int i=0;i<z;i++)
                  cin>>element[i];
                insertionSortRecursive(element, z); 
                prinArray(element, z);
				break;
            case 9:
            	exit(1);
            	break;
            	
		
}

}
}


