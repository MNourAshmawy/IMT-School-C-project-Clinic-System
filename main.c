#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"types.h"
#include"admin.h"
#include"user.h"
patient clinicpatients[20];
slot clinicslots[5];
s8 name[20];
s8 gender[20];
s32 id ;
s32 age;
s32 patientcount = 0;
int main()
{
    u8 contine = 'y' ;
    Init_Clinicslots(clinicslots);
    while(contine == 'y')
    {
        s32 mode;
        printf("\t\t\t Welcome to M.Nour Ashmawy Clinic system\n");
        printf("Choose desired mode (1-Admin  2-User)\n");
        scanf("%d",&mode);
        if(mode==1)
        {
            printf("\t\t Welcome to Admin Mode \n");
            s32 pass = 1234;
            s32 enterpass;
            u8 passtrial = 3;
            do
            {
                passtrial--;
                printf("Enter Password for admin mode: \n");
                scanf("%d",&enterpass);
            }
            while(passtrial>0&&enterpass!=pass);
            if(passtrial == 0)
            {
                return 0;
            }
            u8 contadmin = 'y';
            while (contadmin == 'y')
            {
                    s32 adminmode;
                    printf("Enter Selected feature: \n");
                    printf("1: Add New patient record \n");
                    printf("2: Edit patient record \n");
                    printf("3: Reserve a slot with the doctor \n");
                    printf("4: Cancel Reservation \n");
                    scanf("%d",&adminmode);
                    if(adminmode == 1)
                    {
                        u8 contadmin1 = 'y';
                        while (contadmin1 == 'y')
                        {
                            printf("Enter patient's name \n");
                            scanf("%s",&name);
                            printf("Enter patient's gender \n");
                            scanf("%s",&gender);
                            printf("Enter patient's age \n");
                            scanf("%d",&age);
                            printf("Enter patient's ID \n");
                            scanf("%d",&id);
                            u8 patienadd = AddPatient(clinicpatients,name,gender,age,id,patientcount);
                            if(patienadd == 1)
                            {
                                patientcount++;
                                printf("Patient added successfully to the records \n");

                            }
                            else
                            {
                                printf("Patient wasn't added to the records try another ID \n");
                            }
                            printf("Do you Want to continue adding new patients (y: yes n:no)\n");
                            scanf("%s",&contadmin1);

                            }

                    }
                    else if(adminmode == 2)
                    {
                        u8 contadmin2 = 'y';
                        while(contadmin2 == 'y')
                        {
                            printf("Enter ID of patient to edit \n");
                            scanf("%d",&id);
                            u8 check= checkid(clinicpatients,id,patientcount);
                            if(check == 1)
                            {
                                printf("Enter patient's name \n");
                                scanf("%s",&name);
                                printf("Enter patient's gender \n");
                                scanf("%s",&gender);
                                printf("Enter patient's age \n");
                                scanf("%d",&age);
                                Editpatient(clinicpatients,name,gender,age,id,patientcount);
                                printf("Patient with ID: %d  was successfully edited\n",id);

                            }
                            else
                            {
                                printf("Incorrect ID \n");
                            }

                            printf("Do you Want to continue Editing patients records (y: yes n:no)\n");
                            scanf("%s",&contadmin2);
                        }

                    }
                    else if(adminmode == 3)
                    {
                        u8 contadmin3 = 'y';
                        while (contadmin3 == 'y')
                        {
                            View_Availableslots(clinicslots);
                            printf("Enter number of slot to be reserved: \n");
                            s32 slot;
                            scanf("%d",&slot);
                            printf("Enter patient ID to assign to slot to be reserved: \n");
                            scanf("%d",&id);
                            u8 check = checkid(clinicpatients,id,patientcount);
                            if(check == 1)
                            {
                                u8 reserve = ReserveSlot(clinicslots,slot,id);
                                if(reserve == 1)
                                {
                                    printf("Slot number %d is reserved for patient with id %d \n",slot,id);
                                }
                                else
                                {
                                    printf("Slot was not reserved check again available slots \n");
                                }

                            }
                            else
                            {
                                printf("You entered a non-existing id.  \n");
                            }
                        printf("Do you Want to continue Reserving another slot (y: yes n:no)\n");
                        scanf("%s",&contadmin3);
                        }
                    }
                    else if(adminmode == 4)
                    {
                        u8 contadmin4 = 'y';
                        while(contadmin4 == 'y')
                        {
                            printf("Enter Patient ID to cancel reservation\n");
                            scanf("%d",&id);
                            u8 cancel = CancelSlot(clinicslots,id);
                            if(cancel == 1)
                            {
                              printf("Reservation was successfully canceled\n");
                            }
                            else
                            {
                                printf("Reservation was not canceled check again\n");
                            }
                        printf("Do you Want to Cancel another slot (y: yes n:no)\n");
                        scanf("%s",&contadmin4);
                        }

                    }
                    else
                    {
                        printf("Invalid Admin mode selection\n");
                    }
                    printf("Do you Want to continue in admin mode (y: yes n:no)\n");
                    scanf("%s",&contadmin);
                }
            }

        else if(mode==2)
        {
            printf("\t\t Welcome to User Mode \n");
            u8 contuser = 'y';
            while(contuser == 'y')
            {
                s32 usermode ;
                printf("Enter Selected feature: \n");
                printf("1: View patient record \n");
                printf("2: View today's reservations\n");
                scanf("%d",&usermode);
                if(usermode == 1)
                {
                    u8 contuser1 ='y';
                    while (contuser1 =='y')
                    {
                        printf("Enter ID of patient to view:\n");
                        scanf("%d",&id);
                        u8 checkview = checkid(clinicpatients,id,patientcount);
                        if(checkview == 1)
                        {
                            View_Patient(clinicpatients,id,patientcount);

                        }
                        else
                        {
                            printf("Incorrect ID Entered\n");
                        }
                        printf("Do you Want to continue viewing patients records (y: yes n:no)\n");
                        scanf("%s",&contuser1);
                    }
                }
                else if(usermode == 2)
                {
                    u8 contuser2 = 'y';
                    while(contuser2 == 'y')
                    {
                        View_Reservation(clinicslots);
                        printf("Do you Want to continue viewing reservations (y: yes n:no)\n");
                        scanf("%s",&contuser2);
                    }

                }
                else
                {
                    printf("Invalid user mode selection\n");
                }
                printf("Do you Want to continue in user mode (y: yes n:no)\n");
                scanf("%s",&contuser);
            }

        }
        else
        {
           printf("Invalid Mode Selection\n");
        }
        printf("Do you Want to remain in system (y: yes n:no)\n");
        scanf("%s",&contine);
    }
    return 0;
}
