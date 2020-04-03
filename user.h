/*
View_Patient
description: used by the user to show information about specific patient
input: patient clinicpatients[]: array of patients in clinic
       s32 pid :id of patient to show information
       s32 patientcount : no of patients already in records
output: void
*/
void View_Patient(patient clinicpatients[],s32 pid,s32 patientcount);
/*
View_Reservation
description: used by the user to show information about reserved clinic slots
input : slot clinicslots[] : array of available slots in clinic
output : void
*/
void View_Reservation(slot clinicslots[]);
