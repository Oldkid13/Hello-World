#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int menu()
{
	int opt;
	printf("Choose one from the followings:\n");
	printf("1. Start the game by selecting who will start first\n");
	printf("2. Exit\n");
	printf("Option :");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			return 1;
			break;	
		case 2:
			printf("Goodbye\n");
			return 0;
			break;
		default:
			printf("Invalid option please try again\n");
			menu();
	}
}
int start_roll()
{
	srand(time(NULL));
	int d1,d2;
	printf("Dice are rolled by each player in order to select who will start first:\n");
	do
	printf("Dice 1 (rolled by player 1): %d Dice 2 (rolled by player 2): %d \n",d1=roll_a_dice(),d2=roll_a_dice());
	while(d1==d2);
	if(d1>d2)
	{
		printf("Player 1 is starting!\n");
		return 1;
	}
	else 
	{
		printf("Player 2 is starting!\n");
		return 2;
	}
}
int select_rule_number(int point, int remdice, int count)
{
	int rule;
	if(count!=3 && remdice!=0)
	{
		printf("Select rule number: ");
		scanf("%d",&rule);
		point+=compute_points(rule,remdice,count,point);		
	}
	
}			
int compute_points(int rule, int remdice,int count,int point)
{
	int numdice,remain,dice,rollpoint=0;
	int c1=0,c2=0,c3=0,check=0,check2=0,check3=0;
	switch(rule)
	{
		case 1:
			remain=remdice;
			for(numdice=1;numdice<=remain;numdice++)
			{
				dice=roll_a_dice();
				printf("Dice %d: %d\t",numdice,dice);
				if(dice==5)
				{
					rollpoint+=50;
					remdice--;
				}
			}
			point+=rollpoint;
			printf("\nPoints: %d",rollpoint);
			printf("\nTotal Points: %d",point);
			printf("\n%d dice left... \n",remdice);
			count++;
			select_rule_number(point,remdice,count);
			break;
		case 2:
			remain=remdice;
			for(numdice=1;numdice<=remain;numdice++)
			{
				dice=roll_a_dice();
				printf("Dice %d: %d\t",numdice,dice);
				if(dice==1)
				{
					rollpoint+=100;
					remdice--;
				}	
			}
			point+=rollpoint;
			printf("\nPoints: %d",rollpoint);
			printf("\nTotal Points: %d",point);
			printf("\n%d dice left... \n",remdice);		
			count++;
			select_rule_number(point,remdice,count);
			break;		
		case 3:
			if(remdice>=3)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(dice==1) check++;
					if(check==3)
					{
						rollpoint+=300;
						remdice-=3;
						check=0;
					}
				}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);
			}
			else
			{
				printf("Not valid, there is no 3 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		case 4:
			if(remdice>=3)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(dice==2) check++;
					if(check==3)
					{
						rollpoint+=200;
						remdice-=3;
						check=0;
					}
				}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);
			}
			else
			{
				printf("Not valid, there is no 3 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		case 5:
			if(remdice>=3)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(dice==3) check++;
					if(check==3)
					{
						rollpoint+=300;
						remdice-=3;
						check=0;
					}
				}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);
			}
			else
			{
				printf("Not valid, there is no 3 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;	
		case 6:
			if(remdice>=3)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(dice==4) check++;
					if(check==3)
					{
						rollpoint+=400;
						remdice-=3;
						check=0;
					}
				}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);
			}
			else
			{
				printf("Not valid, there is no 3 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;		
		case 7:
			if(remdice>=3)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(dice==5) check++;
					if(check==3)
					{
						rollpoint+=500;
						remdice-=3;
						check=0;
					}
				}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);
			}
			else
			{
				printf("Not valid, there is no 3 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		case 8:
			if(remdice>=3)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(dice==6) check++;
					if(check==3)
					{
						rollpoint+=600;
						remdice-=3;
						check=0;
					}
				}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);
			}
			else
			{
				printf("Not valid, there is no 3 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		case 9:
			if(remdice>=4)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(c1==0)c1=dice;
					else if(c2==0)
					{
						if(dice==c1)check++;
						else c2=dice;
					}
					else if(c3==0)
					{
						if(dice==c1)check++;
						else if (dice==c2)check2++;
						else c3=dice;
					}
					else
					{
						if(dice==c1)check++;
						else if (dice==c2)check2++;
						else if (dice==c3)check3++;
					}
				}
				if(check==3 || check2==3 || check3==3)
				{
					rollpoint+=1000;
					remdice-=4;
				}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);	
			}
			else
			{
				printf("Not valid, there is no 4 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		case 10:
			if(remdice>=5)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(c1==0)c1=dice;
					else if(c2==0)
					{
						if(dice==c1)check++;
						else c2=dice;
					}
					else
					{
						if(dice==c1)check++;
						else if (dice==c2)check2++;
					}
				}
				if(check==4 || check2==4)
					{
						rollpoint+=2000;
						remdice-=5;
					}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);	
			}
			else
			{
				printf("Not valid, there is no 5 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		case 11:
			if(remdice>=6)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(c1==0)c1=dice;
					else if(dice==c1)check++;
				}
				if(check==5)
					{
						rollpoint+=3000;
						remdice-=6;
					}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);	
			}
			else
			{
				printf("Not valid, there is no 6 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		case 12:
			if(remdice>=6)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					check+=pow(10,dice);
				}
				if(check==1111110)
				{
					rollpoint+=1500;
					remdice-=6;
				}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);	
			}
			else
			{
				printf("Not valid, there is no 6 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		case 13:
			if(remdice>=6)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(c1==0)c1=dice;
					else if(c2==0)
					{
						if(dice==c1)check++;
						else c2=dice;
					}
					else if(c3==0)
					{
						if(dice==c1)check++;
						else if (dice==c2)check2++;
						else c3=dice;
					}
					else
					{
						if(dice==c1)check++;
						else if (dice==c2)check2++;
						else if (dice==c3)check3++;
					}	
				}
				if(check==1 && check2==1 && check3==1)
					{
						rollpoint+=1500;
						remdice-=6;
					}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);	
			}
			else
			{
				printf("Not valid, there is no 6 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		case 14:
			if(remdice>=6)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(c1==0)c1=dice;
					else if(c2==0)
					{
						if(dice==c1)check++;
						else c2=dice;
					}
					else
					{
						if(dice==c1)check++;
						else if (dice==c2)check2++;
					}
				}
				if(check==3 && check2==1 || check==1 && check2==3)
					{
						rollpoint+=2000;
						remdice-=6;
					}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);	
			}
			else
			{
				printf("Not valid, there is no 6 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		case 15:
			if(remdice>=6)
			{
				remain=remdice;
				for(numdice=1;numdice<=remain;numdice++)
				{
					dice=roll_a_dice();
					printf("Dice %d: %d\t",numdice,dice);
					if(c1==0)c1=dice;
					else if(c2==0)
					{
						if(dice==c1)check++;
						else c2=dice;
					}
					else
					{
						if(dice==c1)check++;
						else if (dice==c2)check2++;
					}
				}
				if(check==2 && check2==2 )
					{
						rollpoint+=2500;
						remdice-=6;
					}
				point+=rollpoint;
				printf("\nPoints: %d",rollpoint);
				printf("\nTotal Points: %d",point);
				printf("\n%d dice left... \n",remdice);		
				count++;
				select_rule_number(point,remdice,count);	
			}
			else
			{
				printf("Not valid, there is no 6 dice left!");
				select_rule_number(point,remdice,count);
			}
			break;
		default:
			printf("Invalid rule number please try again\n");
			select_rule_number(point,remdice,count);
			break;
	}
}
int display_points(int player,int raound)
{
	int totalpoint;
	int dispoint=select_rule_number(0,6,0);
	if(dispoint<350)
	{
		printf("PLAYER %d'S TURN IS OVER!\n",player);
		printf("PLAYER %d FARKLED!\n",player);
		printf("ROUND %d POINTS: = %d \n",raound,dispoint);
		printf("ACCUMULATED POINTS: 0 \n\n");
		return 0;
	}
	else
	{
		printf("PLAYER %d'S TURN IS OVER!\n",player);
		printf("ROUND %d POINTS: = %d \n",raound,dispoint);
		printf("ACCUMULATED POINTS: %d \n\n",dispoint);
		return dispoint;
	}
}
void display_final_points(int player1,int player2)
{
	printf("PLAYER 1: %d POINTS\n",player1);
	printf("PLAYER 2: %d POINTS\n\n",player2);
	if(player1>player2) printf("PLAYER 1 ﾝS WINNER! CONGRATULATIONS...\n\n");
	else if(player1<player2) printf("PLAYER 2 ﾝS WINNER! CONGRATULATIONS...\n\n");
	else printf("It's a tie :)\n\n");
}
int roll_a_dice()
{
	int dice ;
	dice=(1+rand() % 6);
	return dice;	
}
int main()
{
	while(menu())
	{
	int turn,player1,player2,raound,counter;
	turn=start_roll();
	for(raound=1;raound<=5;raound++)
	{
		for(counter=0;counter<2;counter++)
		{
			if(turn==1)
			{
				printf("ROUND %d\n",raound);
				printf("-------------------------\n");
				printf("PLAYER %d TURN\n\n",turn);
				player1+=display_points(turn,raound);
				turn=2;
			}
			else if(turn==2)
			{
				printf("ROUND %d\n",raound);
				printf("-------------------------\n");
				printf("PLAYER %d TURN\n\n",turn);
				player2+=display_points(turn,raound);
				turn=1;
			}
		}
	}
	display_final_points(player1,player2);
	}
	system("pause");
	return 0;
}
