#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"proj.h"
#include"admin.h"


int main(){
	u8 Module_Choice,i;
	u32 pass,Service_Choice,id;
	printf("==============================================================================================================\n");
	printf("\t\t\t\t\t\t\tWelcom to our Clinic 0_0\nPlease Enter :\nA to Admin Mode\nU to User Mode\nQ to exit\n");
	printf("==============================================================================================================\n");

	scanf("%c",&Module_Choice);
	switch(Module_Choice){
		case 'A' : printf("Admin Mode\nPlease enter Password: ");
			for(i=0;i<3;i++){
				scanf("%d",&pass);
				if(1234 == pass ){
					printf("Accepted Password\n");
					printf("Please Enter:\n1 to Add new patient\n2 to Edit Patient\n3 to Reservation \n4 to Cancel Reservation\n");
					scanf("%d",&Service_Choice);
					switch(Service_Choice){
						case 1 : Add_Patient();break;
						case 2 : printf("Editing...\nplease enter user ID to be edited\n");
						scanf("%d",&id);
						if(Patient_isExist(head_Patient,id)){
							edit_patient(id);
						}else{
							printf("Wrong ID messasge");
						}
						break;
						case 3 : printf("Reserv....");
						break;
						case 4 : printf("Cancel....");
						break;
						default:
						printf("Please enter a valid choice");
					}
					break;
				}else if(i<2){
					printf("Please enter a valid password: ");
				}else{
				printf("you entered wrong password 3 times, so system shutdown");
				}
			}
			break;
		case 'U' : printf("User Mode");
			break;
		case 'Q' : printf("Bye Bye");
			break;
		default :
			printf("Please enter a valid choice");
	}

	print(head_Patient);

	free_Patients(head_Patient);
	return 0;
}

/*
void Add_Patient(){
	u32 id;
	u32 age;
	u8 name[50];
	u8 gender[20];
	patient *new_Patient,*curnt_Patient;
	new_Patient = (patient *)malloc(sizeof(patient));
	printf("please enter patient id : ");
	scanf("%d",&id);
	if(Patient_isExist(head_Patient,id)){
		printf("this user ID already exist\n");
	}else if(No_Of_Patients == 0){
	   head_Patient = new_Patient;
    printf("please enter patient info name age gender: ");
	scanf("%s %d %s",name,&age,gender);
	head_Patient->id = id;
	strcpy(head_Patient->name,name);
	head_Patient->age = age;
	strcpy(head_Patient->gender,gender);
	head_Patient->next = NULL;
	}else{
		curnt_Patient = head_Patient;
		while(curnt_Patient->next != NULL){
			curnt_Patient = curnt_Patient->next;
		}
		curnt_Patient->next = new_Patient;
		printf("please enter patient info name age gender: ");
		scanf("%s %d %s",name,&age,gender);
	    new_Patient->id = id;
	    strcpy(new_Patient->name,name);
	    new_Patient->age = age;
	    strcpy(new_Patient->gender,gender);
	    new_Patient->next = NULL;
	}
	No_Of_Patients++;
}
u32 Patient_isExist(patient *head_Patient, u32 id){

	patient *ptr = head_Patient;
	while(ptr != NULL){
		if(ptr->id == id){
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void free_Patients(patient * head){
       patient * ptr = head;
    while (ptr != NULL) {
        head = ptr;
        ptr = ptr->next;
        free(head);
    }
}

void print(patient *head_Patient){
	patient * ptr = head_Patient;
	u8 i = 1;
	if(ptr == 0){
		printf("\n No patients information are exist !");
	}else{
	while(ptr != NULL){
		printf("listing all patients \n%d- ID = %d \t\t name = %s \t\t age = %d \t\t gender = %s .\n",i,ptr->id,ptr->name,ptr->age,ptr->gender);
		ptr = ptr->next;
		i++;
	}

   }
}
void edit_patient(u32 id){
	patient * ptr = head_Patient;
	while((ptr->id) != id){
		ptr = ptr->next;
	}
	printf("please enter new name for ID number %d \n",id);
	scanf("%s",ptr->name);
	printf("please enter new age for ID number %d \n",id);
	scanf("%d",ptr->age);
	printf("please enter new gender for ID number %d \n",id);
	scanf("%s",ptr->gender);
	printf("%d info edited successfully",id);

}
*/