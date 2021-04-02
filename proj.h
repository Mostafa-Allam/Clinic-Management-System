#include"types.h"

#ifndef PROJ_H

#define PROJ_H


typedef struct User patient;

typedef struct User{
	u32 id;
	u8 age;
	u8 name[60];
	u8 gender[10];
	patient *next;
}patient;

patient *head_Patient = NULL;
u32 No_Of_Patients = 0;

void Add_Patient();
u32 Patient_isExist(patient *, u32);
void free_Patients(patient *);
void print(patient *);
void edit_patient(u32);


#endif