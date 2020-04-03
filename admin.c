#include"types.h"
#include"admin.h"
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
u8 AddPatient(patient clinicpatients[],s8 name[],s8 gender[],s32 age,s32 id ,s32 patientcount)
{
    for(u8 i=0;i<patientcount;i++)
    {
        if(clinicpatients[i].id == id)
        {
            return 0;
        }

    }
    strcpy(clinicpatients[patientcount].name,name);
    strcpy(clinicpatients[patientcount].gender,gender);
    clinicpatients[patientcount].age = age;
    clinicpatients[patientcount].id = id;
    return 1;
}
void Editpatient(patient clinicpatients[],s8 name[],s8 gender[],s32 age,s32 id ,s32 patientcount)
{
    for(u8 i=0;i<patientcount;i++)
    {
        if(clinicpatients[i].id == id)
        {
            strcpy(clinicpatients[i].name,name);
            strcpy(clinicpatients[i].gender,gender);
            clinicpatients[i].age = age;
        }

    }
}
void Init_Clinicslots(slot clinicslots[])
{
    for(u8 i=0;i<5;i++)
    {
        switch(i)
        {
        case 0:
            strcpy(clinicslots[i].from,"2:00pm");
            strcpy(clinicslots[i].to,"2:30pm");
            clinicslots[i].reserved = 0;
            clinicslots[i].pid = 0;
            break;
        case 1:
            strcpy(clinicslots[i].from,"2:30pm");
            strcpy(clinicslots[i].to,"3:00pm");
            clinicslots[i].reserved = 0;
            clinicslots[i].pid = 0;
            break;
        case 2:
            strcpy(clinicslots[i].from,"3:00pm");
            strcpy(clinicslots[i].to,"3:30pm");
            clinicslots[i].reserved = 0;
            clinicslots[i].pid = 0;
            break;
        case 3:
            strcpy(clinicslots[i].from,"4:00pm");
            strcpy(clinicslots[i].to,"4:30pm");
            clinicslots[i].reserved = 0;
            clinicslots[i].pid = 0;
            break;
        case 4:
            strcpy(clinicslots[i].from,"4:30pm");
            strcpy(clinicslots[i].to,"5:00pm");
            clinicslots[i].reserved = 0;
            clinicslots[i].pid = 0;
            break;
        default:
            break;
        }
    }
}

void View_Availableslots(slot clinicslots[])
{
    for(u8 i=0;i<5;i++)
    {
        if(clinicslots[i].reserved == 0)
        {
            printf("Slot Number : %d \n",i);
            printf("From : %s \n",clinicslots[i].from);
            printf("To: %s \n",clinicslots[i].to);
        }
    }
}

u8 checkid(patient clinicpatients[],s32 id ,s32 patientcount)
{
   for(u8 i=0;i<patientcount;i++)
    {
        if(clinicpatients[i].id == id)
        {
            return 1;
        }
    }
    return 0;
}
u8 ReserveSlot(slot clinicslots[],s32 slot,s32 pid)
{
    if(clinicslots[slot].reserved == 0)
    {
        clinicslots[slot].reserved = 1;
        clinicslots[slot].pid = pid;
        return 1;
    }
    else
    {
        return 0;
    }
}
u8 CancelSlot(slot clinicslots[],s32 pid)
{
    for(u8 i=0;i<5;i++)
    {
        if(clinicslots[i].pid==pid&&clinicslots[i].reserved==1)
        {
            clinicslots[i].reserved = 0;
            return 1;
        }
    }
    return 0;
}
