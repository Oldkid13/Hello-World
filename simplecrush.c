#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<math.h>
int checkclock(clock_t start)
{//timer
    clock_t end = clock();
    if (trunc((double)(end - start)) / CLOCKS_PER_SEC >= 180.00)
    return 0;
    else return 1;
}
char randomCandy()
{//generate random candy
    char candies[]="ABCDE";
    char candy;
    candy=candies[rand() % 5];
    return candy;
}
int calculatePoints(int*);
void display_board(char**);
int crushCandies(int*,int*,int*,int*,char**);
int checkCandies(int*,int*,int*,int*,char**,int*);
int getCandiesCoordinates(int*,int*,int*,int*);
int initializeBoard(char**);
int main()
{
    srand(time(NULL));
    clock_t start = clock();
    int x1,y1,x2,y2,counter=0;
    int i,record=0;
    char tryagain='y';//for restart menu
    char **board;//for create a board
    board=(char **)malloc(7*sizeof(char*));
    for(i=0;i<7;i++) board[i]=(char*)malloc(7*sizeof(char*));
    
    while(tryagain=='y')
    {
        int total_point=0;
        initializeBoard(board);
        while(checkclock(start))
        {
            while(getCandiesCoordinates(&x1,&y1,&x2,&y2));
            if(checkCandies(&x1,&y1,&x2,&y2,board,&counter))
            {
                crushCandies(&x1,&y1,&x2,&y2,board);
                total_point=total_point+calculatePoints(&counter);
                printf("Your total points is %d!\n",total_point);
                display_board(board);  
            }
        }
        fflush(stdin);
        printf("\ntime is up\n");
        if(total_point>record)record=total_point;
        printf("Record is %d\n",record);
        printf("Do you want to play again (y/n) :");
        scanf("%c",&tryagain);
        start = clock();
    }
    printf("\nGood Bye\n");
    system("pause");
    return 0;
}
int initializeBoard(char **board)//for generate a random board
{
    int i,x;//control gruop
    for(i=0;i<7;i++)
    {
        for(x=0;x<7;x++)
        board[i][x]=randomCandy();//take random candys from function
    }
    printf("  ");//for making a better looking board
	for(int i=0;i<7;i++)
	{
		printf("%d  ",i);
	}
		printf("\n\n");
	for(int i=0;i<7;i++)
	{
		printf("%d ",i);
		for(int a=0;a<7;a++)
		{
			printf("%c  ",board[i][a]);
		}
		printf("\n");
		for(int d=0;d<7;d++)printf(" ");
		printf("\n");
	}
}
int getCandiesCoordinates(int* x1,int* y1,int* x2,int* y2)
{//this part take coordiantes if they are in the accapteble range)
    printf("For crushing those litle candies please enter");
    printf("\nStart Coordinates\n");
    printf("as x y : ");
    scanf("%d %d",x1,y1);
    fflush(stdin);
    if((*x1>6||*y1>6))
    {
        printf("Those are not valid coordinates try again\n");
        return 1;
    }
    printf("\nEnd Coordinates\n");
    printf("as x y : ");
    scanf("%d %d",x2,y2);
    fflush(stdin);
    if((*x2>6||*y2>6))
    {
        printf("Those are not valid coordinates try again\n");
        return 1;
    }
    return 0;  
}
int checkCandies(int* x1,int* y1,int* x2,int* y2,char** board,int* counter)
{
    *counter=0;
    char control;
    int var1,var2;
    //Vertical control part 
        if(*x1==*x2&&*y1<*y2)
        {
            *counter=0;
            var1=*y1;
            control=board[*y1][*x1];
            while(var1<=*y2)
            {
                if(board[var1][*x1]==control)
                {
                    *counter=*counter+1;;
                    var1=var1+1;
                }
                else
                {
                    printf("those candys not same try again\n");
                    return 0;
                }
            }
            if(*counter>=3)
            {
                return 1;
            }
            else
            {
                printf("You need 3 or more candies from same kind\n");
                return 0;
            }
        }
        else if(*x1==*x2&&*y1>*y2)
        {
            *counter=0;
            var1=*y2;
            control=board[*y2][*x2];
            while(var1<=*y1)
            {
                if(board[var1][*x2]==control)
                {
                    *counter=*counter+1;;
                    var1=var1+1;
                }
                else
                {
                    printf("those candys not same try again\n");
                    return 0;
                }
            }
            if(*counter>=3)
            {
                return 1;
            }
            else
            {
                printf("You need 3 or more candies from same kind\n");
                return 0;
            }
        }
    //horizontal control part
        else if(*y1==*y2&&*x1<*x2)
        {
            *counter=0;
            var1=*x1;
            control=board[*y1][*x1];
            while(var1<=*x2)
            {
                if(board[*y1][var1]==control)
                {
                    *counter=*counter+1;;
                    var1=var1+1;
                }
                else
                {
                    printf("those candys not same try again\n");
                    return 0;
                }
            }
            if(*counter>=3)
            {
                return 1;
            }
            else
            {
                printf("You need 3 or more candies from same kind\n");
                return 0;
            }
        }
        else if(*y1==*y2&&*x1>*x2)
        {
            *counter=0;
            var1=*x2;
            control=board[*y2][*x2];
            while(var1<=*x1)
            {
                if(board[*y2][var1]==control)
                {
                    *counter=*counter+1;
                    var1=var1+1;
                }
                else
                {
                    printf("those candys not same try again\n");
                    return 0;
                }
            }
            if(*counter>=3)
            {
                return 1;
            }
            else
            {
                printf("You need 3 or more candies from same kind\n");
                return 0;
            }
        }
    //diagonal control part
        else if(*x1<*x2&&*y1<*y2)
        {
            *counter=0;
            if(*x2-*x1!=*y2-*y1)//this part control the move if its diagonal or not
            {
                printf("Wrong move you have to chose same row, column or diagonal\n");
                return 0;
            }
            var1=*x1;
            var2=*y1;
            control=board[*y1][*x1];
            while(var1<=*x2&&var2<=*y2)
            {
                if(board[var2][var1]==control)
                {
                    *counter=*counter+1;;
                    var1++;
                    var2++;
                }
                else
                {
                    printf("those candys not same try again\n");
                    return 0;
                }
            }
            if(*counter>=3)
            {
                return 1;
            }
            else
            {
                printf("You need 3 or more candies from same kind\n");
                return 0;
            }
        }
        else if(*x2<*x1&&*y2<*y1)
        {
            *counter=0;
            if(*x1-*x2!=*y1-*y2)//this part control the move if its diagonal or not
            {
                printf("Wrong move you have to chose same row, column or diagonal\n");
                return 0;
            }
            var1=*x2;
            var2=*y2;
            control=board[*y2][*x2];
            while(var1<=*x1&&var2<=*y1)
            {
                if(board[var2][var1]==control)
                {
                    *counter=*counter+1;;
                    var1++;
                    var2++;
                }
                else
                {
                    printf("those candys not same try again\n");
                    return 0;
                }
            }
            if(*counter>=3)
            {
                return 1;
            }
            else
            {
                printf("You need 3 or more candies from same kind\n");
                return 0;
            }
        }
        else if(*x2<*x1&&*y1<*y2)
        {
            *counter=0;
            if(*x1-*x2!=*y2-*y1)//this part control the move if its diagonal or not
            {
                printf("Wrong move you have to chose same row, column or diagonal\n");
                return 0;
            }
            var1=*x1;
            var2=*y1;
            control=board[*y1][*x1];
            while(var1>=*x2&&var2<=*y2)
            {
                if(board[var2][var1]==control)
                {
                    *counter=*counter+1;;
                    var1--;
                    var2++;
                }
                else
                {
                    printf("those candys not same try again\n");
                    return 0;
                }
            }
            if(*counter>=3)
            {
                return 1;
            }
            else
            {
                printf("You need 3 or more candies from same kind\n");
                return 0;
            }
        }
        else if(*x1<*x2&&*y2<*y1)
        {
            *counter=0;
            if(*x2-*x1!=*y1-*y2)//this part control the move if its diagonal or not
            {
                printf("Wrong move you have to chose same row, column or diagonal\n");
                return 0;
            }
            var1=*x2;
            var2=*y2;
            control=board[*y2][*x2];
            while(var1>=*x1&&var2<=*y1)
            {
                if(board[var2][var1]==control)
                {
                    *counter=*counter+1;;
                    var1--;
                    var2++;
                }
                else
                {
                    printf("those candys not same try again\n");
                    return 0;
                }
            }
            if(*counter>=3)
            {
                return 1;
            }
            else
            {
                printf("You need 3 or more candies from same kind\n");
                return 0;
            }
        }        
}
int crushCandies(int* x1,int* y1,int* x2,int* y2,char** board)
{
    int counter=0;
    char control,var1,var2,var3;
    //Vertical control part 
        if(*x1==*x2&&*y1<*y2)
        {
            var1=*y1-1;
            var2=*y2;
            while(var2>=0)
            {
                if(var1>=0)
                {
                    board[var2][*x2]=board[var1][*x1];
                    var1--;
                }
                else
                {
                    board[var2][*x2]=randomCandy();
                }
                var2--;
                
            }
            
        }
        else if(*x1==*x2&&*y1>*y2)
        {
            var1=*y2-1;
            var2=*y1;
            while(var2>=0)
            {
                if(var1>=0)
                {
                    board[var2][*x1]=board[var1][*x2];
                    var1--;
                }
                else
                {
                    board[var2][*x1]=randomCandy();
                }
                var2--;
                
            }
        }
    //horizontal control part
        else if(*y1==*y2&&*x1<*x2)
        {
            var1=*x1;
            while(var1<=*x2)
            {
                var2=*y1;
                while(var2>0)
                {
                    board[var2][var1]=board[var2-1][var1];
                    var2--;
                }
                if(var2==0)
                {
                    board[var2][var1]=randomCandy();
                }
                var1++;
            }
        }
        else if(*y1==*y2&&*x1>*x2)
        {
           var1=*x2;
            while(var1<=*x1)
            {
                var2=*y2;
                while(var2>0)
                {
                    board[var2][var1]=board[var2-1][var1];
                    var2--;
                }
                if(var2==0)
                {
                    board[var2][var1]=randomCandy();
                }
                var1++;
            } 
        }
    //diagonal control part
        else if(*x1<*x2&&*y1<*y2)
        {
            var1=*x1;
            var2=*y1;
            var3=*y1;
            while(var1<=*x2&&var2<=*y2)
            {
                while(var2!=0)
                {
                    board[var2][var1]=board[var2-1][var1];
                    var2--;
                }
                if(var2==0)
                {
                    board[var2][var1]=randomCandy();
                }
                var1++;
                var3++;
                var2=var3;
            }
        }
        else if(*x2<*x1&&*y2<*y1)
        {
            var1=*x2;
            var2=*y2;
            var3=*y2;
            while(var1<=*x1&&var2<=*y1)
            {
                while(var2!=0)
                {
                    board[var2][var1]=board[var2-1][var1];
                    var2--;
                }
                if(var2==0)
                {
                    board[var2][var1]=randomCandy();
                }
                var1++;
                var3++;
                var2=var3;
            }
        }
        else if(*x2<*x1&&*y1<*y2)
        {
            var1=*x1;
            var2=*y1;
            var3=*y1;
            while(var1>=*x2&&var2<=*y2)
            {
                while(var2!=0)
                {
                    board[var2][var1]=board[var2-1][var1];
                    var2--;
                }
                if(var2==0)
                {
                    board[var2][var1]=randomCandy();
                }
                var1--;
                var3++;
                var2=var3;
            }
        }
        else if(*x1<*x2&&*y2<*y1)
        {
            var1=*x2;
            var2=*y2;
            var3=*y2;
            while(var1>=*x1&&var2<=*y1)
            {
                while(var2!=0)
                {
                    board[var2][var1]=board[var2-1][var1];
                    var2--;
                }
                if(var2==0)
                {
                    board[var2][var1]=randomCandy();
                }
                var1--;
                var3++;
                var2=var3;
            } 
        }
}
void display_board(char** board)
{
    system("pause");
    system("cls");//clear screen
    printf("  ");//for making a better looking board
	for(int i=0;i<7;i++)
	{
		printf("%d  ",i);
	}
		printf("\n\n");
	for(int i=0;i<7;i++)
	{
		printf("%d ",i);
		for(int a=0;a<7;a++)
		{
			printf("%c  ",board[i][a]);
		}
		printf("\n");
		for(int d=0;d<7;d++)printf(" ");
		printf("\n");
	}
}
int calculatePoints(int* counter)
{//calculate points you gained in a round
    int gained_point;
    gained_point=(*counter)*100;
    printf("You got %d points!\n",gained_point);
    return gained_point;
}
