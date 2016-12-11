#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

List create_list(){//This part crate a list for storing machine
    List m;
    m=(struct Machine_List*)malloc(sizeof(struct Machine_List));
    if(m==NULL) printf("Out of Memory");
    empty_list(m);
    return m;
}

void empty_list(List m){//set empty the list
    m->Head=(struct Machine_Queue*)malloc(sizeof(struct Machine_Queue));
    if(m->Head==NULL) printf("Out of Memory");
    m->Head->next=NULL;
    m->Store=NULL;
    m->time=0;
    m->idle_time=0;
    m->arrive_counter=0;
    m->car_counter=0;
    m->size=0;
}

Machine create_machine(){//make washing machinies acording tho users input
    Machine temp;
    temp = (struct Machine_Queue*)malloc(sizeof(struct Machine_Queue));
    if(temp==NULL)printf("Out of Memory");
    new_machine(temp);
}

void new_machine(Machine m){//create a new machine and set it to empty
    m->front=(struct Node*)malloc(sizeof(struct Node));
    if(m->front==NULL) printf("Out of Memory");
    m->front->next=NULL;
    m->rear=m->front;
    m->size=0;
    m->next=NULL;
}

Machine check_machine(List m){//return an empty machine or the shorestes queue
    Machine temp;
    Machine min;//store the shortest machine queue
    int i;
    temp=m->Head->next; 
    min=temp;
    for(i=0;i < m->size;i++){//check every machine
        if(temp->size==0) return temp;
        else {       
            if(min->size > temp->size){
                min=temp;
            }
            else if(min->size==temp->size){
                if(rand()%2){
                    min=temp;
                }
                else continue;
            }
        }
        temp=temp->next;
    }
    return min;
}

Car make_car(List m){//make and return an empty car
    Car c;
    c=(struct Node*)malloc(sizeof(struct Node));
    if(c==NULL)printf("out of memory");
    c->next=NULL;
    c->arrival_time=m->time;
    c->car_number=m->car_counter;
    c->service_time=0;
    c->wait_time=0;
    return c;
}

void enqueue(Machine m,Car c){//add car to queue
    if(m->size==0){
        m->front->next=c;
        m->rear=m->front->next;
        m->size++;
    }
    else{
        m->rear->next=c;
        m->rear=m->rear->next;
        m->size++;
    }
}

Car dequeue(Machine m){
    Car temp;
    temp = m->front->next;
    m->front->next = temp->next;
    m->size--;
    return temp;
}
