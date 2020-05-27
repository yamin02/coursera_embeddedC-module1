/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file <stats.h>
 * @brief <This is a C header file which contains some statistical functions>
 *
 * <Add Extended Description Here>
 *
 * @author <Yaminul Hoque>
 * @date <26/05/2020>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stdio.h>

unsigned int roundof(double num){
    int intpart = (int)num;
    double decpart = num - intpart;
    unsigned int ans = (decpart>= 0.5)? intpart+1 : intpart;
    return ans;
}
/* Add Your Declarations and Function Comments here */
void print_array(unsigned char arr[], unsigned int size ){
    for (int i = 0; i<size ; i++)
    {printf("%d ", arr[i]);
        if ((i+1)%8 == 0 && i>0)
            printf("\n");}
}
void swap(unsigned char *a1 , unsigned char *a2){
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
unsigned int find_median(unsigned char arr[], unsigned int size){
    double median;
    if (size % 2 == 1){
        int num = (int)(size + 1)/2;
        median = arr[num];}
    else
    {int x1 = (int)size/2;
        median = (double)(arr[x1]+arr[x1+1])/2;}
    return roundof(median);
}

unsigned int  find_mean(unsigned char arr[], unsigned int size){
    double mean;
    double sum = 0;
    for (int i = 0 ; i<size ; i++){
        sum+=arr[i];
    }
    mean = sum/size;
    return roundof(mean);

}
unsigned int find_maximum(unsigned char arr[], unsigned int size){
    unsigned int max=0;
    for (int i= 0 ; i<size; i++){
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}
unsigned int find_minimum(unsigned char arr[], unsigned int size){
    unsigned int min=arr[0];
    for (int i= 0 ; i<size; i++){
        if(arr[i]<min)
            min = arr[i];}
    return min;
}
void sort_array(unsigned char arr[], unsigned int size){
    for (int i = 0; i<size-1; i++){
        for(int a = 0; a<(size-1-i); a++)
        { if (arr[a]<arr[a+1])
                swap(&arr[a+0],&arr[a+1]);}
    }
}

void print_statistics(unsigned char arr[], unsigned int size){
    printf("Mean of the given data = %d\n", find_mean(arr,size));
    printf("Median of the given data = %d\n", find_median(arr,size));
    printf("Maximum value of the given data = %d\n", find_maximum(arr,size));
    printf("Minimum of the given data = %d", find_minimum(arr,size));

}



#endif /* __STATS_H__ */
