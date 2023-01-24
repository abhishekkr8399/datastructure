#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[100], usn[20];
    int sem, marks1, marks2, marks3, total;
};
void display(struct student *s);
int main()
{
    struct student s[100];
    int i, n;
    printf("enter the no. of students\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the of student %d details\n", i + 1);
        printf("enter the name of students\n");
        scanf("%s", s[i].name);
        printf("enter the usn of student\n");
        scanf("%s", s[i].usn);
        printf("enter the sem of student2");
        scanf("%d", &s[i].sem);
        printf("enter the marks1 of students\n");
        scanf("%d", &s[i].marks1);
        printf("enter the marks2 of students\n");
        scanf("%d", &s[i].marks2);
        printf("enter the marks3 of students\n");
        scanf("%d", &s[i].marks3);
    }
    for (i = 0; i < n; i++)
    {
        s[i].total = s[i].marks1 + s[i].marks2 + s[i].marks3;
    }
    printf("\ndisplaying details of students\n");
    for (i = 0; i < n; i++)
    {
        printf("student %d\n", i + 1);
        display(&s[i]);
        printf("\n");
    }
    return 0;
}
void display(struct student *s)
{
    printf("name of student:%s\n", s->name);
    printf("usn of student:%s\n", s->usn);
    printf("sem of student:%d\n", s->sem);
    printf("marks1 of student:%d\n", s->marks1);
    printf("marks2 of student:%d\n", s->marks2);
    printf("marks3 of student:%d\n", s->marks3);
    printf("total marks of student:%d\n", s->total);
}