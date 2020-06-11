/* 

		   LAB Session 5 Data Structure
By : 
  
  Nama : I Putu Krisna Dharma Saputra
  NIM  : 2301924353
  
*/

//Header File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Deklarasi Struct
struct drink_node{
	char name[30];
	int  qty;
	char denom[30];
	struct drink_node *next;
};
struct drink_node *front;
struct drink_node *rear;
int choice;

//Deklarasi Fungsi
int main_menu();
void view_order();
void add_order();
void take_order();

//fungsi main
int main(){
	
	do{ 
		system("cls");
		
		main_menu();	
			
		switch (choice){
			case 1 :{
				view_order();
				break;
			}
			case 2 :{
				add_order();
				break;
			}
			case 3 :{
				take_order();
				break;
			}
	
    	}
    
    }while(choice !=4);
    
	system("cls");
 
	printf("Thanks for using this program");

  	getch();
  	
  	return 0;
}

//Fungsi memunculkan main menu
int main_menu(){
	printf("BLUE DRINKS SHOP\n");
	printf(".........................\n\n");
	printf("1. View Order List\n");
	printf("2. Add New Order\n");
	printf("3. Take Order\n");
	printf("4. Exit\n\n");
	printf(">> Input your choice : ");
    fflush(stdin);
	scanf("%d",&choice);
}

//Fungsi Menu 1 View Order List	
void view_order(){
	struct drink_node *temp = (struct drink_node*) malloc(sizeof(struct drink_node));
	int i =1;
	
	system("cls");
	
	printf("\t\t\t --- ORDER LIST ---\n");
    printf("\n+----+---------------------+-----------------+----------------------+");
	printf("\n| No.| Name of Drink       | Quantity        | Damaged              |");
	printf("\n+----+---------------------+-----------------+----------------------+\n");
	if(rear == NULL){
		printf("+----+---------------------+-----------------+----------------------+");
	}else{
		temp = front;
		do{
		printf("| %-2d | %-19s | %-15d | %-20s |\n",i,temp->name,temp->qty,temp->denom);
		temp = temp->next;
		i++;
		}while(temp != front);
		printf("+----+---------------------+-----------------+----------------------+");
	}
	
	getch();
}


//Fungsi menu ke 2 yaitu Add New Order (Engueue)
int counter = 0;

int push(char *name, int qty, char *denom){
	struct drink_node *temp = (struct drink_node*) malloc(sizeof(struct drink_node));
	strcpy(temp->name,name);
	temp->qty = qty;
	strcpy(temp->denom,denom);
	
	if(rear == NULL){
		temp->next = temp;
		rear = temp;
		front = temp;
	}else{
		temp->next = rear->next;
		rear->next = temp;
		rear = temp;
	}
	++counter;
	return 0;
}

void add_order(){
	char name[30];
	int qty;
	char denom[30];
	char choice;
	
	system("cls");
	fflush(stdin);
	//input name of drink
    do{
		system("cls");
		printf("Input Name of Drink [3..30]: ");
		fflush(stdin);
		gets(name);
		if(strlen(name) < 3 || strlen(name) > 30){
			printf("The length of Name must be between 3 and 30 characters");
			getch();
		}
    }while(strlen(name) < 3 || strlen(name) > 30);
    
	//Input Quantity of Drink
	do{
		system("cls");
		printf("Input Name of Drink [3..30]: %s ",name); 
		
		printf("\n\nInput Quatity of Drink [1..100] : ");
		fflush(stdin);
	    scanf("%d",&qty);
		
		if(qty < 1 || qty > 100){
			printf("\nThe quantity must be between 1 and 100");
			getch();
		}
		
	}while(qty < 1 || qty > 100);
	
	//input Denomination of Drink
	do{
		
		system("cls");
		printf("Input Name of Drink [3..30]: %s ",name); 
		printf("\n\nInput Quatity of Drink [1..100] : %d",qty);
		
		printf("\n\nInput Denomination [pieces/dozen/box]: ");
		fflush(stdin);
		gets(denom);
		
		if(strcmp(denom, "pieces") !=0 && strcmp(denom, "dozen") !=0 && strcmp(denom, "box") !=0){
			printf("\n      		Please choose appropriate type !\n ");
			getch();
		}
			
	}while(strcmp(denom, "pieces") !=0 && strcmp(denom, "dozen") !=0 && strcmp(denom, "box") !=0);
		
	push(name,qty,denom);
	
	printf("\n--- Add New Order Success ---");
	getch();

}
		
//Fungsi-Fungsi menu ke 3, Take Order 

void Delete(int index){
	int i = 1;
	struct drink_node *temp = (struct drink_node*)malloc(sizeof(struct drink_node));
	struct drink_node *pretemp = (struct drink_node*) malloc(sizeof(struct drink_node));
	temp = rear->next;
	while(index != i){
		pretemp = temp;
		temp = temp->next;
		i++;
	}
	if(temp->next == temp){
		front = NULL;
		rear = NULL;
		free(temp);
	}
	else if(temp == front){
		pretemp = rear;
		front = temp->next;
		pretemp->next = front;
		free(temp);
	}else if(temp == rear){
		pretemp->next = front;
		rear = pretemp;
		free(temp);
	}else{
		pretemp->next = temp->next;
		temp = NULL;
		free(temp);
	}
	--counter;
}

void take_order(){
	struct drink_node *temp = NULL;
	temp = (struct drink_node *)malloc(sizeof(struct drink_node));
	temp = front;
	int i = 0;
	i = counter;
	int number;
	
	if(front == NULL){
		printf("\n --- There is No Order in The List ---\n");
		getch();
		return;
	}else{
		system("cls");
		view_order();
		
		do{
			printf("\n\n Input Number of The Order [1...%d] : ",i);
			scanf("%d",&number);
			if(number > i || number < 1){
				printf("\n Number of order must be between 1...%d! \n",i);
				getch();
			}
		}while(number > i || number < 1);
		Delete(number);
		printf("\n\n\n --- Take Order Success ---");
		getch();
	}

}



