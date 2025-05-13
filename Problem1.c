#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Student
{
  char student_name[50];
  int studentrollno;
  double totalmarks;
}stud;

void init(stud* a,int n,int subjects)
{
  for(int i=0;i<n;i++)
  {
  printf("\n Enter the student %d name: ",i+1);
  //fgets(a[i].student_name,sizeof(a[i].student_name),stdin);
  scanf(" %49[^\n]",a[i].student_name);
  printf("\nEnter the student %d roll number: \n",i+1);
  scanf("%d",&a[i].studentrollno);
  printf("\nEnter the marks of student %d for all subjects \n",i+1);

  a[i].totalmarks=0;
  double total=0;
  for(int j=0;j<subjects;j++)
  {
    printf("\nEnter the marks for subject %d for student %d ",j+1,i+1);
    int mark;
    scanf("%d",&mark);
    total+=mark;
  }
  a[i].totalmarks=total;
  printf("\nThe total marks of the student %d is %.1f ",i+1,a[i].totalmarks);
  
}
}
stud* copyArray(stud* arr,int n)
{
  stud* copy=(stud*)malloc(n*sizeof(stud));
  for(int i=0;i<n;i++)
  {
     copy[i]=arr[i];
  }
  return copy;
}
void printSortedArray(stud* arr,int n)
{
  printf("The sorted students array is:\n");
  for(int i=0;i<n;i++)
  {
    printf("\n Student %d name is:%s",i+1,arr[i].student_name);
    printf("\n Student %d Roll number is:%d",i+1,arr[i].studentrollno);
    printf("\n Student %d total marks is:%.1f",i+1,arr[i].totalmarks);
  }
}
//1.Bubble Sort Algorithm
int BubbleSwap(stud* a,int n)
{
  int noofswaps=0;
    for(int i=0;i<n-1;i++)
    {
      bool Swapped=false;
      for(int j=0;j<n-1-i;j++)
      {
       if(a[j].studentrollno>a[j+1].studentrollno)
       {
        stud temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        Swapped=true;
        noofswaps++;
       }
      }
      if(!Swapped)
      {
        break;
      }
    }
    return noofswaps;
}

//2.Selection Sort
int SelectionSort(stud*a,int n)
{
  int swaps=0;
  for(int i=0;i<n-1;i++)
  {
    int minindex=i;
    for(int j=i+1;j<n;j++)
    {
      if(a[j].studentrollno<a[minindex].studentrollno)
      {
        minindex=j;
      }
    }
    if(minindex!=i)
    {
    stud temp=a[i];
    a[i]=a[minindex];
    a[minindex]=temp;
    swaps++;
    }
  }
  return swaps;
}
//3.Insertion Sort
int InsertionSort(stud* arr,int n)
{
  for(int i=1;i<n;i++)
  {
    stud temp=arr[i];
    int j=i-1;
    for(;j>=0;j--)
    {
      if(arr[j].studentrollno>arr[j+1].studentrollno)
      {
      arr[j+1]=arr[j];
    }
    else
    {
      break;
    }
  }
    arr[j+1]=temp;
  }
}
//4.Merge Sort
void Merge(stud*arr,int s,int mid,int e)
{
  //Step 1:get sizes of two subarrays arr[s..mid],arr[mid+1...e]
   int n1=mid-s+1;
   int n2=e-mid;

//Step 2:create two arrays
   stud* first=(stud*)malloc(n1*sizeof(stud));
   stud* second=(stud*)malloc(n2*sizeof(stud));

//Step 3:copy data in subarrays from original array
   for(int i=0;i<n1;i++)
   {
    first[i]=arr[s+i];//first subarray is from 0 to mid
   }

   for(int i=0;i<n2;i++)
   {
    second[i]=arr[mid+i+1];//second subarray from mid+1 to e
   }

//Step 4:put elements in sorted array from two subarrays into main array
   int i=0,j=0;
   int k=s;//mainArrayIndex
   while(i<n1 && j<n2)
   {
    if(first[i].studentrollno<=second[j].studentrollno)
    {
       arr[k]=first[i];//if smaller bring first one into original
       i++;
    }
    else
    {
      arr[k]=second[j];//if larger bring second one into original
      j++;
    }
    k++;
   }
//step 5:put remaining lements of subarrays into original array
   while(i<n1)
   {
       arr[k]=first[i];
       i++;
       k++;
    }
  while(j<n2)
   {
      arr[k]=second[j];
      j++;
      k++;
    }
//Step 6:free the subarrays
   free(first);
   free(second);
}
int MergeSort(stud* arr,int s,int e,int n)
{
    int passes1=0;
    int passes2=0;
    if(s<e)
    {
//Step 1:Find Mid
    int mid=s+(e-s)/2;
//step 2:count no.of passes for sorting arr[s...mid] and arr[mid+1...e]
    passes1=MergeSort(arr,s,mid,n);
    passes2=MergeSort(arr,mid+1,e,n);
//Step 3:Merge the two sorted halves
    Merge(arr,s,mid,e);
    }
//Step 4:return number of passes +1 is for merge because we are merge for n elements n-1 operations in merge sort
    return passes1+passes2+1;
}
//5.Quick Sort
int partition(stud* arr,int s,int e)
{
   stud pivot=arr[s];

   int i=s+1;
   int j=e;

   while(i<j)
   {
   while(arr[i].studentrollno<=pivot.studentrollno && i<=e)
   {
    i++;
   }
   while(arr[j].studentrollno>pivot.studentrollno && j>=s)
   {
    j--;
   }
   if(i<j)
   {
    stud temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
   }
   }
   stud temp=arr[j];
   arr[j]=arr[s];
   arr[s]=temp;
   return j;
}
int QuickSort(stud* arr,int s,int e)
{
  int passes1=0;
  int passes2=0;
   if(s<e)
   {
    int partitionindex=partition(arr,s,e);
     passes1=QuickSort(arr,s,partitionindex-1);
    passes2=QuickSort(arr,partitionindex+1,e);
   }
   return passes1+passes2+1;
}
//6.Heap Sort
void heapify(stud* arr,int n,int i,int* swaps)
{
  int maximum=i;
  int left_index=2*i+1;
  int rightindex=2*i+2;

  if(left_index<n && arr[left_index].studentrollno>arr[maximum].studentrollno)
  {
    maximum=left_index;
  }

  if(rightindex<n && arr[rightindex].studentrollno>arr[maximum].studentrollno)
  {
    maximum=rightindex;
  }

  if(maximum!=i)
  {
    stud temp=arr[i];
    arr[i]=arr[maximum];
    arr[maximum]=temp;
    (*swaps)++;
    heapify(arr,n,maximum,swaps);
  }
}
int HeapSort(stud* arr,int n)
{
  int swaps=0;
  for(int i=n/2-1;i>=0;i--)
  {
    heapify(arr,n,i,&swaps);
  }
  for(int i=n-1;i>0;i--)
  {
    stud temp=arr[0];
    arr[0]=arr[i];
    arr[i]=temp;
    swaps++;
    heapify(arr,i,0,&swaps);
  }
  return swaps;
}
int main()
{
  printf("\n Enter the number of students you want :");
  int n;
  scanf("%d",&n);
  stud* arr=(stud*)malloc(n*sizeof(stud));

  printf("\n Enter the number of subjects you want :");
  int subjects;
  scanf("%d",&subjects);

  init(arr,n,subjects);
  int choice;
  do
  {
    printf("\n Sorting Menu:");
    printf("\n 1.Bubble Sort");
    printf("\n 2.Insertion Sort");
    printf("\n 3.Selection Sort");
    printf("\n 4.Merge Sort");
    printf("\n 5.Quick Sort");
    printf("\n 6.Heap Sort");
    printf("\n 7.Exit");
    printf("\n Hey User!Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
      {
           stud* temp=copyArray(arr,n);
           int noofswapsinBubble=BubbleSwap(temp,n);
           printf("\n The number of swaps performed in Bubble sort is:%d\n",noofswapsinBubble);
           printSortedArray(temp,n);
           break;    
      }
      case 2:
      {
           stud* temp=copyArray(arr,n);
           int noofswapsinInsertion=InsertionSort(temp,n);
           printf("\n The number of swaps performed in Insertion sort is:%d\n",noofswapsinInsertion);
           printSortedArray(temp,n);
           free(temp);
           break;  
      }  
      case 3:
      {
           stud* temp=copyArray(arr,n);
           int noofswapsinSelection=SelectionSort(temp,n);
           printf("\n The number of swaps performed in  Selection sort is:%d\n",noofswapsinSelection);
           printSortedArray(temp,n);
           free(temp);
           break;
      }
      case 4:
      {
           stud* temp=copyArray(arr,n);
           int s=0;
           int e=n-1;
           int MergePasses=MergeSort(temp,s,n-1,n);
           printf("\n The number of swaps performed in Merge sort is:%d\n",MergePasses);
           printSortedArray(temp,n);
           free(temp);
           break;
      }
      case 5:
      {
           stud* temp=copyArray(arr,n);
             int s=0;
           int e=n-1;
           int noofswapsinQuick=QuickSort(temp,s,e);
           printf("\n The number of swaps performed in Quick sort is:%d\n",noofswapsinQuick);
           printSortedArray(temp,n);
           free(temp);
           break;
      }
      case 6:
      {
           stud* temp=copyArray(arr,n);
           int noofswapsinHeap=HeapSort(temp,n);
           printf("\n The number of swaps performed in Heap sort is:%d\n",noofswapsinHeap);
           printSortedArray(temp,n);
           free(temp);
           break;
      }
      case 7:
           printf("\n Exiting the program.");
           break; 
      default:
           printf("\n Invalid choice.Please enter valid choice");
           break;            
    }
  } while (choice!=7);
  
  free(arr);
  return 0;
}