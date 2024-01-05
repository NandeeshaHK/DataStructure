#include <stdio.h>
#include <string.h>

// Define a Union named MyUnion
union MyUnion {
    int intValue;
    float floatValue;
    char stringValue[20];
};

int main() {
    // Declare a variable of type MyUnion
    union MyUnion myVariable;

    // Assign values to different members of the union
    myVariable.intValue = 42;
    printf("Float Value: %f\n", myVariable.floatValue);
    printf("Integer Value: %d\n", myVariable.intValue);
    printf("String Value: %s\n", myVariable.stringValue);

    myVariable.floatValue = 3.14;
    printf("Float Value: %f\n", myVariable.floatValue);
    printf("Integer Value: %d\n", myVariable.intValue);
    printf("String Value: %s\n", myVariable.stringValue);

    // The value of intValue is overridden by the following assignment
    strcpy(myVariable.stringValue, "Hello, Union!");
    printf("Float Value: %f\n", myVariable.floatValue);
    printf("Integer Value: %d\n", myVariable.intValue);
    printf("String Value: %s\n", myVariable.stringValue);

    return 0;
}
