/*
Given an unsorted array arr[] of size N having both negative and positive integers. 
The task is place all negative element at the end of array without changing the order of 
positive element and negative element.
Input : 
N = 8
arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
Output : 
1  3  2  11  6  -1  -7  -5
*/
#include <iostream>

int main()
{
    int arr[] = {1 ,-1 ,3 ,2 ,-7, -5 ,11, 6} ; 
    int size = sizeof(arr)/sizeof(int) ; 
    
//Solution 1
//Time Complexity: O(n) , Space Complexity: O(n)
    int brr[size] , k=0, l=size-1 ;
    for ( int i=0, j=size-1 ; i<size ; i++,j-- )
    {
        if ( arr[i] > 0) 
            brr[k++] = arr[i];
        if (arr[j] < 0 )
            brr[l--] = arr[j] ; 
    }

    for( int i=0 ; i<size ; i++ )
        std::cout << brr[i] << " ";  

std::cout << std::endl ; 

//Solution 2
//Time Complexity: O( n^(no. of swaps) ) , Space Complexity: O(1)
    
    int temp ;
    for ( int i=0 ; i<size ; i++ )
    {
        if ( arr[i]<0 && arr[i+1]>0 )
        {
            temp = arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp; 
            i=-1;
        }
    }

    for( int i=0 ; i<size ; i++ )
        std::cout << arr[i] << " "; 

std::cout << std::endl ; 

//Solution 3 
//Time Complexity: O(n) , Space Complexity: O(1)

    int left = 0 , right = size - 1 ; 

    while( left <= right )
    {
        if( arr[left] > 0 && arr[right] > 0 )
            left ++ ;
    
        else if( arr[left] < 0 && arr[right] > 0 )
        {
            temp = arr[left];
            arr[left]=arr[right];
            arr[right]=temp; 
            left ++;
            right --;
        }

        else if( arr[left] < 0 && arr[right] < 0)
            right -- ;

        else
        {
        right -- ;
        left ++;
        } 
    }

    for( int i=0 ; i<size ; i++ )
        std::cout << arr[i] << " "; 



}