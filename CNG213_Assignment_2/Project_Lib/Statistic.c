#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

int Total_cars_washed(List m){
    return m->Store->size;
}
int Total_washing_machines(List m){
    return m->size;
}
int Total_idle_time(List m){
    int total=0;
  
    return m->idle_time;
}
int Total_wait_time(List m){
    int total=0;
    Car temp;
    temp=m->Store->front->next;
    while(temp){
        total+=temp->wait_time;
        temp=temp->next;
    }
    return total;
}
int Total_service_time(List m){
    int total=0;
    Car temp;
    temp=m->Store->front->next;
    while(temp){
        total+=temp->service_time;
        temp=temp->next;
    }
    return total;
}
int Maximum_queue_size(List m){
    int max=0;
    Car temp;
    temp=m->Store->front->next;
     max=temp->queue_size;
    while(temp){
        if((temp->queue_size)>max)
        {
            max=temp->queue_size;
        }
        temp=temp->next;
    }
    return max;
}
double Average_wait_time(List m){
    double average;
    average=Total_wait_time(m)/(Total_cars_washed(m)*1.0);
    return average;
    
}
double Average_service_time(List m){
    double average;
    average=Total_service_time(m)/(Total_cars_washed(m)*1.0);
    return average;
    
}

