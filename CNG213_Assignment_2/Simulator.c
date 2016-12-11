#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Project_Lib/Queue.h"
#include "Project_Lib/Statistic.h"
void make_machine(List);
void car_to_wash(List);
int  is_car_arrive();
void start_car_wash(Car,List);
void process_car_wash(List,int);
int complate_wash();
void wash_next_car(List);

int main() {
    srand(time(NULL)); //Random seed
    List m;
    m=create_list();
    m->Store=create_machine();
    int time_limit;
    int max_wash_time;
    int machine_num;
    //Taking variables
    //----------------------------------------------------------
    printf("\nTime Limit in Hours:");
    scanf("%d",&time_limit);
    time_limit*=60;
    
    printf("\nMaximum Wash Time :");
    scanf("%d",&max_wash_time);
    
    printf("\nNumber of Wash Machinies ");
    scanf("%d",&m->size);
    make_machine(m);
    //------------------------------------------------------------
    
    //Main Loop for wash simulation
    //------------------------------------------------------------
    while(m->time < time_limit ){
        car_to_wash(m);
        process_car_wash(m,max_wash_time);
        wash_next_car(m);
        m->time++;
    }
    printf("Total cars washed:      %d \n",Total_cars_washed(m));
    printf("Total washing machines: %d \n",Total_washing_machines(m));
    printf("Total idle time:        %d \n",Total_idle_time(m));
    printf("Total wait time:        %d \n",Total_wait_time(m));
    printf("Total service time:     %d \n",Total_service_time(m));
    printf("Maximum queue size:     %d \n",Maximum_queue_size(m));
    printf("Average wait time:      %lf \n",Average_wait_time(m));
    printf("Average service time:   %lf \n",Average_service_time(m));
	return 0;
}

void make_machine(List m){
    int i;
    Machine temp;
    temp=m->Head;
    for(i=0;i < m->size ;i++){
        temp->next=create_machine();
        temp=temp->next;
        temp->number=i+1;
    }
}

void car_to_wash(List m){
    Machine temp;
    Car car;
    if(is_car_arrive() || m->arrive_counter >= 2){
        m->arrive_counter=0;
        m->car_counter++;
        temp=check_machine(m);//take an empty machine or the shorest queue
        //creating a car wit its information
        //------------------------------------
        car=make_car(m);
        car->washing_machine=temp->number;
        car->queue_size=temp->size;
        if(temp->size==0) start_car_wash(car,m);
        else car->on_washing=-1;
        //------------------------------------
        enqueue(temp,car);//add car to queue
    }
    else{
        m->arrive_counter++;
    }
}

int is_car_arrive(){//this function decides  car is arive or not randomly
    int a;
    a=rand()%10+1;//(1-5) False // (6-10) True)
    if(a>5)return 1;
    else return 0; 
}

void start_car_wash(Car c,List m){//Set car to washing state
    c->on_washing=1;
    c->start_time=m->time;
    c->wait_time = (c->start_time)-(c->arrival_time);
}

void process_car_wash(List m,int limit){
    Machine temp;
    int is_idle=0;
    Car temp1;
    temp=m->Head->next;
    while(temp){
        if(temp->size){
            is_idle++;
            if(temp->front->next->on_washing){
                temp->front->next->service_time++;
                if(temp->front->next->service_time >= limit || complate_wash() ){
                    temp->front->next->on_washing = 0;
                    temp1=temp->front->next;
                    printf("\nTime:%d WasNum:%d ArrTime:%d WaiTim:%d StarTim:%d SerTim:%d WasMach:%d QueSiz:%d\n",m->time,temp1->car_number,temp1->arrival_time,temp1->wait_time,temp1->start_time,temp1->service_time,temp1->washing_machine,temp1->queue_size); 
                }
            }
        }
        temp=temp->next;
    }
    if(!is_idle) m->idle_time++; 
}

int complate_wash(){
    int a;
    a=rand()%10+1;//(1-5) False // (6-10) True)
    if(a>5)return 1;
    else return 0; 
}

void wash_next_car(List m){
    Machine temp;
    Car Complate;
    temp=m->Head->next;
    while(temp){
        if(temp->size){
            if(!temp->front->next->on_washing){
                Complate=dequeue(temp);
                enqueue(m->Store,Complate);
                if(temp->size){
                    start_car_wash(temp->front->next,m);      
                }
            }
        }
        temp=temp->next;
    } 
}
