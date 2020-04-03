/*
Add Patient
description: This function is used by the admin to add a new patient to the record of the clinic
input: patient clinicpatients[] : array of patients in clinic
       s8 name[] : name of patient to be added
       s8 gender[] : gender of patient to be added
       s32 age : age of patient to be added
       s32 id : id of patient to be added
       s32 patientcount : no of patients already in records
output: 1: if patient was successfully added
        0: if patient was not added (because ID was repeated or patientcount excedded array size)
*/
u8 AddPatient(patient clinicpatients[],s8 name[],s8 gender[],s32 age,s32 id ,s32 patientcount);
/*
Edit Patient
description: This function is used by the admin to edit information of a specific patient
input: patient clinicpatients[] : array of patients in clinic
       s8 name[] : name of patient to be edited
       s8 gender[] : gender of patient to be edited
       s32 age : age of patient to be edited
       s32 id : id of patient will remain same
       s32 patientcount : no of patients already in records
output: void

*/
void Editpatient(patient clinicpatients[],s8 name[],s8 gender[],s32 age,s32 id ,s32 patientcount);
/*
checkid
description: This function is used by the admin to check if ID is present in clinic or not
input: patient clinicpatients[] : array of patients in clinic
       s32 id : id of patient to search for
       s32 patientcount : no of patients already in records
output: 1: if ID is available
        0: if ID is not available
*/
u8 checkid(patient clinicpatients[],s32 id ,s32 patientcount);
/*
Init_Clinicslots
description: used to initialize slots assign time to them (from,to) according to the clinic
input : slot clinicslots[] : array of available slots in clinic
output : void
*/
void Init_Clinicslots(slot clinicslots[]);
/*
View_Availableslots
description: used to show free slots in clinic (slots which are not reserved)
input : slot clinicslots[] : array of available slots in clinic
output : void

*/
void View_Availableslots(slot clinicslots[]);
/*
ReserveSlot
description: used to reserve a free slot to a specific patient
input : slot clinicslots[]: array of slots in clinic
        s32 slot: slot number to be reserved
        s32 pid: patient id to reserve this slot for
output : 1: Successful reservation
         0: failure of reservation
*/
u8 ReserveSlot(slot clinicslots[],s32 slot,s32 pid);
/*
CancelSlot
description: used to cancel slot to a specific patient
input : slot clinicslots[]: array of slots in clinic
        s32 pid: patient id to cancel this slot for
output : 1: Successful cancellation
         0: failure of cancellation

*/
u8 CancelSlot(slot clinicslots[],s32 pid);
