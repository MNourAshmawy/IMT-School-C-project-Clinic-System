#include"types.h"
#include"user.h"
#include<string.h>
#include<string.h>
#include<stdio.h>
#include <stdlib.h>

void View_Patient(patient clinicpatients[],s32 pid,s32 patientcount)
{
    for(u8 i=0;i<patientcount;i++)
    {
        if(clinicpatients[i].id == pid)
        {
            printf("Patient's Name : %s \n",clinicpatients[i].name);
            printf("Patient's Gender : %s \n",clinicpatients[i].gender);
            printf("Patient's Age : %d \n",clinicpatients[i].age);
        }
    }
}


void View_Reservation(slot clinicslots[])
{
    for(u8 i=0;i<5;i++)
    {
        if(clinicslots[i].reserved == 1)
        {
            printf("Slot Number : %d \n",i);
            printf("From : %s \n",clinicslots[i].from);
            printf("To : %s \n",clinicslots[i].to);
            printf("Patient's ID : %d \n",clinicslots[i].pid);
        }

    }

}
