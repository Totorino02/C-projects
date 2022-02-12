#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char firstName[50];
    char middleName[50];
    char lastName[50];
}Name;

typedef struct{
    int day;
    int month;
    int year;
}Date;

typedef struct{
    int english;
    int mathematics;
    int informatic;
}Marks;

typedef struct {
    int rolName;
    Name name;
    char sexe[50];
    Date dob;
    Marks marks;
}Student;

int main()
{
    printf("****** EASY SCHOOL GESTION ******\n");
    Student std1;
    printf("\n votre identifiant: ");
    scanf("%d", &std1.rolName);

    printf("\nNoms(firstN middleN lastN): ");
    scanf("%s %s %s", std1.name.firstName, std1.name.middleName, std1.name.lastName);
    fflush(stdin);

    printf("\nVotre sexe(F ou M): ");
    scanf("%s",std1.sexe);
    fflush(stdin);

    printf("\nDate de naissance: ");
    scanf("%d/%d/%d", &std1.dob.day, &std1.dob.month, &std1.dob.year);
    fflush(stdin);

    printf("\nVos notes(Eng-Mth-Inf): ");
    scanf("%d %d %d", &std1.marks.english, &std1.marks.mathematics, &std1.marks.informatic);
    fflush(stdin);

    // Affichage
    printf("Donneé de l'elève N°%d\n\n", std1.rolName);
    printf("\tNoms: %s %s %s \n",std1.name.firstName, std1.name.middleName, std1.name.lastName);
    printf("\tSexe: %s \n", std1.sexe);
    printf("\tDate de naissance: %d/%d/%d \n", std1.dob.day, std1.dob.month, std1.dob.year);
    printf("\tNotes:\n");
    printf("\t\tmathematics: %d \n", std1.marks.mathematics);
    printf("\t\tinformatic: %d \n", std1.marks.informatic);
    printf("\t\tenglish: %d \n", std1.marks.english);
}
