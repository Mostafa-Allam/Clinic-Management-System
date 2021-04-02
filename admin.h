
void Add_Patient(){
	u32 id;
	u32 age;
	u8 select;
	u8 name[50];
	u8 gender[20];
	patient *new_Patient,*curnt_Patient;
	new_Patient = (patient *)malloc(sizeof(patient));
	printf("please enter patient id : ");
	scanf("%d",&id);
	if(Patient_isExist(head_Patient,id)){
		printf("this user ID already exist, please select another ID\n");
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
	printf("Do you want to add another patients ? y/n: ");
	scanf("%s",&select);
	switch(select)
	{
		case:'n'
		continue;
		case:'y'
		goto 
	}
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