// This program performs data analysis on a heart disease dataset (heart.csv) using pure C, without any external libraries.
// It reads and parses the CSV file line by line, extracts key health attributes for each patient, and generates analytical insights.
//AUTHOR: MOHAMAD MUSADIQ
//GITHUB: ARQORYN



#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp;
    fp = fopen("heart.csv", "r");
    if (fp == NULL){
        printf("File not found!");
        return 1;
    }

    int Age, RestingBP, FastingBS, Cholesterol, MaxHR, HeartDisease;
    float Oldpeak;
    char Sex, ExerciseAngina;
    char ChestPainType[10], RestingECG[10], ST_Slope[10];



    int ageGroup1to10 = 0;
    int ageGroup11to20 = 0;
    int ageGroup21to30 = 0;
    int ageGroup31to40 = 0;
    int ageGroup41to50 = 0;
    int ageGroup51to60 = 0;
    int ageGroup61to70 = 0;
    int ageGroup71to80 = 0;
    int ageGroup81to90 = 0;
    int ageGroup91above = 0;

    //skip header in csv
    char dummy[200];
    fgets(dummy, sizeof(dummy), fp);


    int malecount = 0;
    int femalecount = 0;



    int maleGroup[10] = {0,0,0,0,0,0,0,0,0,0};
    int femaleGroup[10] = {0,0,0,0,0,0,0,0,0,0};

    int TA = 0, ATA = 0, NAP = 0, ASY = 0;

    int grp_TA[10] = {0,0,0,0,0,0,0,0,0,0};
    int grp_ATA[10] = {0,0,0,0,0,0,0,0,0,0};
    int grp_NAP[10] = {0,0,0,0,0,0,0,0,0,0};
    int grp_ASY[10] = {0,0,0,0,0,0,0,0,0,0};


    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%d,%c,%9[^,],%d,%d,%d,%9[^,],%d,%c,%f,%9[^,],%d",&Age, &Sex, ChestPainType, &RestingBP, &Cholesterol, &FastingBS,RestingECG, &MaxHR, &ExerciseAngina, &Oldpeak, ST_Slope, &HeartDisease) == 12) {
        
            if (Age >=1 && Age <= 10 && HeartDisease==1){
                ageGroup1to10++;
                if (Sex == 'M') {
                    malecount++;
                    maleGroup[0]++;
                }
                else if (Sex == 'F') {
                    femalecount++;
                    femaleGroup[0]++;
                }

                // chest pain type total & individual
                if (strcmp(ChestPainType,"TA") == 0){
                    TA++;
                    grp_TA[0]++;
                }
                else if (strcmp(ChestPainType,"ATA") == 0){
                    ATA++;
                    grp_ATA[0]++;
                }
                else if (strcmp(ChestPainType,"NAP") == 0){
                    NAP++;
                    grp_NAP[0]++;
                }
                else if (strcmp(ChestPainType,"ASY") == 0){
                    ASY++;
                    grp_ASY[0]++;
                }


                

            }
            else if (Age >=11 && Age <= 20 && HeartDisease==1){
                ageGroup11to20++;
                if (Sex == 'M') {
                    malecount++;
                    maleGroup[1]++;
                }
                else if (Sex == 'F') {
                    femalecount++;
                    femaleGroup[1]++;
                }
                if (strcmp(ChestPainType,"TA") == 0){
                    TA++;
                    grp_TA[1]++;
                }
                else if (strcmp(ChestPainType,"ATA") == 0){
                    ATA++;
                    grp_ATA[1]++;
                }
                else if (strcmp(ChestPainType,"NAP") == 0){
                    NAP++;
                    grp_NAP[1]++;
                }
                else if (strcmp(ChestPainType,"ASY") == 0){
                    ASY++;
                    grp_ASY[1]++;
                }
            }
            else if (Age >=21 && Age <= 30 && HeartDisease==1){
                ageGroup21to30++;
                if (Sex == 'M') {
                    malecount++;
                    maleGroup[2]++;
                }
                else if (Sex == 'F') {
                    femalecount++;
                    femaleGroup[2]++;
                }
                if (strcmp(ChestPainType,"TA") == 0){
                    TA++;
                    grp_TA[2]++;
                }
                else if (strcmp(ChestPainType,"ATA") == 0){
                    ATA++;
                    grp_ATA[2]++;
                }
                else if (strcmp(ChestPainType,"NAP") == 0){
                    NAP++;
                    grp_NAP[2]++;
                }
                else if (strcmp(ChestPainType,"ASY") == 0){
                    ASY++;
                    grp_ASY[2]++;
                }
            }
            else if (Age >=31 && Age <= 40 && HeartDisease==1){
                ageGroup31to40++;
                if (Sex == 'M') {
                    malecount++;
                    maleGroup[3]++;
                }
                else if (Sex == 'F') {
                    femalecount++;
                    femaleGroup[3]++;
                }
                if (strcmp(ChestPainType,"TA") == 0){
                    TA++;
                    grp_TA[3]++;
                }
                else if (strcmp(ChestPainType,"ATA") == 0){
                    ATA++;
                    grp_ATA[3]++;
                }
                else if (strcmp(ChestPainType,"NAP") == 0){
                    NAP++;
                    grp_NAP[3]++;
                }
                else if (strcmp(ChestPainType,"ASY") == 0){
                    ASY++;
                    grp_ASY[3]++;
                }
            }
            else if (Age >=41 && Age <= 50 && HeartDisease==1){
                ageGroup41to50++;
                if (Sex == 'M') {
                    malecount++;
                    maleGroup[4]++;
                }
                else if (Sex == 'F') {
                    femalecount++;
                    femaleGroup[4]++;
                }
                if (strcmp(ChestPainType,"TA") == 0){
                    TA++;
                    grp_TA[4]++;
                }
                else if (strcmp(ChestPainType,"ATA") == 0){
                    ATA++;
                    grp_ATA[4]++;
                }
                else if (strcmp(ChestPainType,"NAP") == 0){
                    NAP++;
                    grp_NAP[4]++;
                }
                else if (strcmp(ChestPainType,"ASY") == 0){
                    ASY++;
                    grp_ASY[4]++;
                }
            }
            else if (Age >=51 && Age <= 60 && HeartDisease==1){
                ageGroup51to60++;
                if (Sex == 'M') {
                    malecount++;
                    maleGroup[5]++;
                }
                else if (Sex == 'F') {
                    femalecount++;
                    femaleGroup[5]++;
                }


                if (strcmp(ChestPainType,"TA") == 0){
                    TA++;
                    grp_TA[5]++;
                }
                else if (strcmp(ChestPainType,"ATA") == 0){
                    ATA++;
                    grp_ATA[5]++;
                }
                else if (strcmp(ChestPainType,"NAP") == 0){
                    NAP++;
                    grp_NAP[5]++;
                }
                else if (strcmp(ChestPainType,"ASY") == 0){
                    ASY++;
                    grp_ASY[5]++;
                }
            }
            else if (Age >=61 && Age <= 70 && HeartDisease==1){
                ageGroup61to70++;
                if (Sex == 'M') {
                    malecount++;
                    maleGroup[6]++;
                }
                else if (Sex == 'F') {
                    femalecount++;
                    femaleGroup[6]++;
                }
                if (strcmp(ChestPainType,"TA") == 0){
                    TA++;
                    grp_TA[6]++;
                }
                else if (strcmp(ChestPainType,"ATA") == 0){
                    ATA++;
                    grp_ATA[6]++;
                }
                else if (strcmp(ChestPainType,"NAP") == 0){
                    NAP++;
                    grp_NAP[6]++;
                }
                else if (strcmp(ChestPainType,"ASY") == 0){
                    ASY++;
                    grp_ASY[6]++;
                }
            }
            else if (Age >=71 && Age <= 80 && HeartDisease==1){
                ageGroup71to80++;
                if (Sex == 'M') {
                    malecount++;
                    maleGroup[7]++;
                }
                else if (Sex == 'F') {
                    femalecount++;
                    femaleGroup[7]++;
                }
                if (strcmp(ChestPainType,"TA") == 0){
                    TA++;
                    grp_TA[7]++;
                }
                else if (strcmp(ChestPainType,"ATA") == 0){
                    ATA++;
                    grp_ATA[7]++;
                }
                else if (strcmp(ChestPainType,"NAP") == 0){
                    NAP++;
                    grp_NAP[7]++;
                }
                else if (strcmp(ChestPainType,"ASY") == 0){
                    ASY++;
                    grp_ASY[7]++;
                }
            }
            else if (Age >=81 && Age <= 90 && HeartDisease==1){
                ageGroup81to90++;
                if (Sex == 'M') {
                    malecount++;
                    maleGroup[8]++;
                }
                else if (Sex == 'F') {
                    femalecount++;
                    femaleGroup[8]++;
                }
                if (strcmp(ChestPainType,"TA") == 0){
                    TA++;
                    grp_TA[8]++;
                }
                else if (strcmp(ChestPainType,"ATA") == 0){
                    ATA++;
                    grp_ATA[8]++;
                }
                else if (strcmp(ChestPainType,"NAP") == 0){
                    NAP++;
                    grp_NAP[8]++;
                }
                else if (strcmp(ChestPainType,"ASY") == 0){
                    ASY++;
                    grp_ASY[8]++;
                }
            }
            else if (Age >= 91 && HeartDisease == 1){
                ageGroup91above++;
                if (Sex == 'M') {
                    malecount++;
                    maleGroup[9]++;
                }
                else if (Sex == 'F') {
                    femalecount++;
                    femaleGroup[9]++;
                }
                if (strcmp(ChestPainType,"TA") == 0){
                    TA++;
                    grp_TA[9]++;
                }
                else if (strcmp(ChestPainType,"ATA") == 0){
                    ATA++;
                    grp_ATA[9]++;
                }
                else if (strcmp(ChestPainType,"NAP") == 0){
                    NAP++;
                    grp_NAP[9]++;
                }
                else if (strcmp(ChestPainType,"ASY") == 0){
                    ASY++;
                    grp_ASY[9]++;
                }
            }
        }
    }
    fclose(fp);

    int totalcount = malecount + femalecount;
    float malepercent = (float)malecount / totalcount * 100;
    float femalepercent = (float)femalecount / totalcount * 100;

    

    printf("HEART DISEASE DATA ANALYSIS\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Number of Males with heart disease = %d\n", malecount);
    printf("Number of Females with heart disease = %d\n", femalecount);
    printf("Percentage of Heart Disease Patients being Male = %.2f%%\n", malepercent);
    printf("Percentage of Heart Disease Patients being Female = %.2f%%\n", femalepercent);

    printf("------------------------------------------------------------------------------------------------\n");

    printf("Total Number of people having Chest pain type - Typical Angina (TA): %d\n", TA);
    printf("Total Number of people having Chest pain type - Atypical Angina (ATA): %d\n", ATA);
    printf("Total Number of people having Chest pain type - Non-Anginal Pain (NAP): %d\n", NAP);
    printf("Total Number of people having Chest pain type - Asymptomatic (ASY): %d\n", ASY);

    printf("------------------------------------------------------------------------------------------------\n");

    printf("\nGroup 1 analysis (Age 1 to 10)\n");
    printf("People of Group 1 having heart attack: %d, \nMales = %d, Females = %d \n| TA: %d | ATA: %d | NAP: %d | ASY: %d\n",ageGroup1to10, maleGroup[0], femaleGroup[0], grp_TA[0], grp_ATA[0], grp_NAP[0], grp_ASY[0]);
    printf("\nGroup 2 analysis (Age 11 to 20)\n");
    printf("People of Group 2 having heart attack: %d, \nMales = %d, Females = %d \n| TA: %d | ATA: %d | NAP: %d | ASY: %d\n",ageGroup11to20, maleGroup[1], femaleGroup[1], grp_TA[1], grp_ATA[1], grp_NAP[1], grp_ASY[1]);
    printf("\nGroup 3 analysis (Age 21 to 30)\n");
    printf("People of Group 3 having heart attack: %d, \nMales = %d, Females = %d \n| TA: %d | ATA: %d | NAP: %d | ASY: %d\n",ageGroup21to30, maleGroup[2], femaleGroup[2], grp_TA[2], grp_ATA[2], grp_NAP[2], grp_ASY[2]);
    printf("\nGroup 4 analysis (Age 31 to 40)\n");
    printf("People of Group 4 having heart attack: %d, \nMales = %d, Females = %d \n| TA: %d | ATA: %d | NAP: %d | ASY: %d\n",ageGroup31to40, maleGroup[3], femaleGroup[3], grp_TA[3], grp_ATA[3], grp_NAP[3], grp_ASY[3]);
    printf("\nGroup 5 analysis (Age 41 to 50)\n");
    printf("People of Group 5 having heart attack: %d, \nMales = %d, Females = %d \n| TA: %d | ATA: %d | NAP: %d | ASY: %d\n",ageGroup41to50, maleGroup[4], femaleGroup[4], grp_TA[4], grp_ATA[4], grp_NAP[4], grp_ASY[4]);
    printf("\nGroup 6 analysis (Age 51 to 60)\n");
    printf("People of Group 6 having heart attack: %d, \nMales = %d, Females = %d \n| TA: %d | ATA: %d | NAP: %d | ASY: %d\n",ageGroup51to60, maleGroup[5], femaleGroup[5], grp_TA[5], grp_ATA[5], grp_NAP[5], grp_ASY[5]);
    printf("\nGroup 7 analysis (Age 61 to 70)\n");
    printf("People of Group 7 having heart attack: %d, \nMales = %d, Females = %d \n| TA: %d | ATA: %d | NAP: %d | ASY: %d\n",ageGroup61to70, maleGroup[6], femaleGroup[6], grp_TA[6], grp_ATA[6], grp_NAP[6], grp_ASY[6]);
    printf("\nGroup 8 analysis (Age 71 to 80)\n");
    printf("People of Group 8 having heart attack: %d, \nMales = %d, Females = %d \n| TA: %d | ATA: %d | NAP: %d | ASY: %d\n",ageGroup71to80, maleGroup[7], femaleGroup[7], grp_TA[7], grp_ATA[7], grp_NAP[7], grp_ASY[7]);
    printf("\nGroup 9 analysis (Age 81 to 90)\n");
    printf("People of Group 9 having heart attack: %d, \nMales = %d, Females = %d \n| TA: %d | ATA: %d | NAP: %d | ASY: %d\n",ageGroup81to90, maleGroup[8], femaleGroup[8], grp_TA[8], grp_ATA[8], grp_NAP[8], grp_ASY[8]);
    printf("\nGroup 10 analysis (Age 91 above)\n");
    printf("People of Group 10 having heart attack: %d, \nMales = %d, Females = %d \n| TA: %d | ATA: %d | NAP: %d | ASY: %d\n",ageGroup91above, maleGroup[9], femaleGroup[9], grp_TA[9], grp_ATA[9], grp_NAP[9], grp_ASY[9]);




    return 0;
}
