#Indice
## [Using const](#using-const)

# Using const
int var = 21;
int& alias = var; // Only to remember that's possible

const int* ptr1 = &var;
*ptr1 = 21 // ERROR, we cannot change the value of a pointed variable
ptr1 = &alias; // This is allowed

int* const ptr2 = &var; 
*ptr2 = 21; // This is allowed
ptr2 = &alias // ERROR 