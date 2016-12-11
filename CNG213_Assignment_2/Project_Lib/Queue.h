struct Node{//struct  for a car
	int on_washing;//washing status ; 1:on washing, 0:finished, -1:on queue
	int car_number;
	int arrival_time;
	int wait_time;
	int start_time;
	int service_time;
	int washing_machine;
	int queue_size;
	struct Node *next;
};

struct Machine_Queue{//struct for a machine
	struct Node *front;
	struct Node *rear;
	struct Machine_Queue *next;
	int number;//Machine number
	int size;             
};

struct Machine_List{
    struct Machine_Queue *Head;
    struct Machine_Queue *Store;
    int time;
    int idle_time;//count time that machine spend idling
    int arrive_counter;//count times that a car doesnt appear
    int car_counter;//total amount of car
    int size;
};

typedef struct Node *Car;
typedef struct Machine_Queue *Machine;
typedef struct Machine_List *List;

List    create_list();
void    empty_list(List);
Machine create_machine();
void    new_machine(Machine);
Machine check_machine(List);
Car     make_car(List);
void    enqueue(Machine,Car);
Car     dequeue(Machine); 
