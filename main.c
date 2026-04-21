/*
Name: Namuganza Maria Gorret
Registration Number: 25/U/BIO/027/GV
*/

#include <stdio.h>

int main(void) {
    float s1[8], s2[8];
    int gp1[8], gp2[8];
    char grade1[8], grade2[8];
    
    int units_1[] = {4, 3, 3, 3, 3, 3, 2, 3};
    int units_2[] = {4, 3, 3, 3, 3, 3, 3, 3};
    
    char *codes_1[] = {"TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104", "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"};
    char *codes_2[] = {"TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204", "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"};
    
    float s1_total_weighted = 0, s2_total_weighted = 0;
    float gpa_1, gpa_2, cgpa;


    printf("Enter Semester I Marks:\n");
    for(int i = 0; i < 8; i++) {
        printf("%d. %s: ", i + 1, codes_1[i]);
        scanf("%f", &s1[i]);
    }

    
    printf("\nEnter Semester II Marks:\n");
    for(int i = 0; i < 8; i++) {
        printf("%d. %s: ", i + 9, codes_2[i]);
        scanf("%f", &s2[i]);
    }

    for(int i = 0; i < 8; i++) {
        if(s1[i] < 0 || s1[i] > 100 || s2[i] < 0 || s2[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    for(int i = 0; i < 8; i++){
        if (s1[i] >= 80) { gp1[i] = 5; grade1[i] = 'A'; }
        else if (s1[i] >= 70) { gp1[i] = 4; grade1[i] = 'B'; }
        else if (s1[i] >= 60) { gp1[i] = 3; grade1[i] = 'C'; }
        else if (s1[i] >= 50) { gp1[i] = 2; grade1[i] = 'D'; }
        else { gp1[i] = 0; grade1[i] = 'F'; }
        s1_total_weighted += (float)gp1[i] * units_1[i];
    }

    for(int i = 0; i < 8; i++){
        if (s2[i] >= 80) { gp2[i] = 5; grade2[i] = 'A'; }
        else if (s2[i] >= 70) { gp2[i] = 4; grade2[i] = 'B'; }
        else if (s2[i] >= 60) { gp2[i] = 3; grade2[i] = 'C'; }
        else if (s2[i] >= 50) { gp2[i] = 2; grade2[i] = 'D'; }
        else { gp2[i] = 0; grade2[i] = 'F'; }
        s2_total_weighted += (float)gp2[i] * units_2[i]; // Fixed: used gp2
    }

    gpa_1 = s1_total_weighted / 24.0;
    gpa_2 = s2_total_weighted / 25.0;
    cgpa = (s1_total_weighted + s2_total_weighted) / 49.0;

    
    char *final_class;
    if (cgpa >= 4.40) final_class = "First Class";
    else if (cgpa >= 3.60) final_class = "Second Class Upper";
    else if (cgpa >= 2.80) final_class = "Second Class Lower";
    else if (cgpa >= 2.00) final_class = "Pass";
    else final_class = "Fail";

    
    printf("\n%-10s | %-6s | %-5s | %-5s | %-5s | %-s\n", "Code", "Score", "Grade", "GP", "CU", "Weighted");
    printf("-----------------------------------------------------------------\n");
    for(int i = 0; i < 8; i++) {
        printf("%-10s | %6.1f | %-5c | %-5d | %-5d | %.1f\n", codes_1[i], s1[i], grade1[i], gp1[i], units_1[i], (float)gp1[i]*units_1[i]);
    }
    for(int i = 0; i < 8; i++) {
        printf("%-10s | %6.1f | %-5c | %-5d | %-5d | %.1f\n", codes_2[i], s2[i], grade2[i], gp2[i], units_2[i], (float)gp2[i]*units_2[i]);
    }


    printf("\nSemester I GPA: %.2f\n", gpa_1);
    printf("Semester II GPA: %.2f\n", gpa_2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", final_class);


    return 0;
}
