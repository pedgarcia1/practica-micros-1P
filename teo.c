#include <stdio.h>

int main(void)
{


    printf("Teo hizo esto desde su computadora\n");
    printf("Lu guardo usando github\n");
    printf("Ahora va a pedirle a copilot que haga algo\n");
    // Ask the user its age and inform it
    // if the age is greater than 50 print estas viejo capo
    // if the age is less than 50 print estas joven capo
    // if the age is less than 30 print estas fresco mi pana
    // print smiley face
    int age;
    printf("How old are you?\n");
    scanf("%d", &age);
    if (age > 50)
    {
        printf("Estas viejo capo\n");
    }
    else if (age < 50 && age > 30)
    {
        printf("Estas joven capo\n");
    }
    else
    {
        printf("Estas fresco mi pana\n");
    }
    return 0;
}