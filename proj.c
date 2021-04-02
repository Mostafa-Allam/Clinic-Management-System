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
