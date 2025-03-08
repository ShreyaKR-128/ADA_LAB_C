#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partion(int arr[],int low,int high){
int pivot=arr[low];
int i=low+1;
int j=high;
int temp;
while(1){
while(i<=high&&arr[i]<=pivot)
i++;
while(arr[j]>pivot)
j--;
if(i<j){
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
else
{
temp=arr[low];
arr[low]=arr[j];
arr[j]=temp;
return j;
}
}
}
void quickSort(int arr[],int low,int high){
if(low<high){
int pi=partion(arr,low,high);
quickSort(arr,low,pi-1);
quickSort(arr,pi+1,high);
}
}
int main(){
int n,i;
printf("Enter the number of elements");
scanf("%d",&n);
int arr[n];
srand(time(NULL));
for(i=0;i<n;++i){
arr[i]=rand()%100000;
}
clock_t start=clock();
quickSort(arr,0,n-1);
clock_t end=clock();
printf("Sorted array is:");
for(i=0;i<10;i++){
printf("%d\t",arr[i]);
}