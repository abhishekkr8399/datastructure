#include <stdio.h>
#include <stdlib.h>
void tower(int n, char s, char t, char d);
int main()
{
    int n;
    printf("Enter the number of disks:");
    scanf("%d", &n);
    printf("The disk movements are\n");
    tower(n, 'A', 'B', 'C');
    return 0;
}
void tower(int n, char s, char t, char d)
{
    if (n == 0)
    {
        return;
    }
    tower(n - 1, s, d, t);
    printf("Move disk %d from %c to %c\n", n, s, d);
    tower(n - 1, t, s, d);
}
