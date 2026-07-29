#include <stdio.h>

// 1. Define the student structure
struct Student {
    char name[50];       // Name of the student
    int sub1;            // Mark for Subject 1
    int sub2;            // Mark for Subject 2
    int sub3;            // Mark for Subject 3
    int total_marks;     // Calculated total score
};

int main() {
    // 2. Initialize an array of 3 students with fixed data
    // Total marks are initially set to 0 and will be computed later
    struct Student students[3] = {
        {"Alice Smith", 85, 90, 78, 0},
        {"Bob Jones",   92, 88, 95, 0},
        {"Charlie Brown", 70, 65, 80, 0}
    };

    // Initialize accumulator variables for subject-wise totals
    int total_sub1 = 0;
    int total_sub2 = 0;
    int total_sub3 = 0;

    // Calculate individual totals and accumulate subject totals
    for (int i = 0; i < 3; i++) {
        students[i].total_marks = students[i].sub1 + students[i].sub2 + students[i].sub3;
        
        // Summing vertically down each subject column
        total_sub1 += students[i].sub1;
        total_sub2 += students[i].sub2;
        total_sub3 += students[i].sub3;
    }

    // 4. Display the stored data in a clean format
    printf("%-15s | %-5s | %-5s | %-5s | %-5s\n", "Name", "Sub1", "Sub2", "Sub3", "Total");
    printf("---------------------------------------------------\n");
    
    for (int i = 0; i < 3; i++) {
        printf("%-15s | %-5d | %-5d | %-5d | %-5d\n", 
               students[i].name, 
               students[i].sub1, 
               students[i].sub2, 
               students[i].sub3, 
               students[i].total_marks);
    }
    printf("---------------------------------------------------\n");
       
        printf("%-15s | %-5d | %-5d | %-5d | %-5d\n", 
               "Total", 
               total_sub1, 
               total_sub2, 
               total_sub3, 
               total_sub1 + total_sub2 + total_sub3 );
        
    return 0;
}
