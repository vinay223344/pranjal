/*
 * a.C
 *
 *  Created on: 02-Jul-2026
 *      Author: engineer
 */


/*
 ============================================================================
 Name        : c.c
 Author      : Rabindra
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define PI 3.14159

void amicable_numbers(void);
void function_pointer_arithmetic(void);
void volume_of_shapes(void);
//void string_permutations(void);
//void largest_element_dma(void);
//void string_length_pointer(void);
//void vowels_consonants_pointer(void);
//void print_alphabets_pointer(void);
//void palindrome_pointer(void);
//void dynamic_2d_array(void);
//void plural_strings(void);
//void void_pointer_arithmetic(void);
//void reverse_lines_malloc(void);
//void stack_using_pointers(void);
//void matrix_double_pointer(void);


//=============================Q-1====================================

/*
 * 1. Write a C program to check whether a pair of numbers is amicable or not, using
pointers.
Example: 220 & 284 are amicable numbers then the factors of 220:1, 2, 4, 5, 10, 11,
20, 22, 44, 55, 110 then 1+ 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 = 284 and
Now, 284: 1, 2, 4, 71, 142 1 + 2 + 4 + 71 + 142 = 220.
 */
int sum_factors(int *num)
{
	int sum=1;
	if (*num<1)
	{
		return 0;
	}
	for(int i=2;i<=(*num)/2;i++){
		if ((*num)%i==0)
		{
			sum=sum+i;
		}
	}
	return sum;
}
void check_amicable(int *a,int *b)
{
	int x=sum_factors(a);
	int y=sum_factors(b);

	if(x==*b && y==*a)
	{
		printf("Both numbers are amicable\n");
	}
	else
	{
		printf("Both numbers are not amicable\n");
	}
}
void amicable_numbers(void)
{
	int a,b;
	printf("Enter two numbers :");
	scanf("%d %d",&a,&b);

	check_amicable(&a,&b);
}




/*
 * Enter two numbers :220
284
Both numbers are amicable
 */



//==============================Q-2===================================
/*
Write a C program to perform basic arithmetic operations (addition, subtraction,
multiplication, division) using an array of function pointers.
*/


int add(int a,int b)
{
    return a+b;
}

int sub(int a,int b)
{
    return a-b;
}

int mul(int a,int b)
{
    return a*b;
}

int divide(int a,int b)
{
    return a/b;
}

void function_pointer_arithmetic()
{
    int a,b;

    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);

    int (*arr[4])(int,int);

    arr[0]=add;
    arr[1]=sub;
    arr[2]=mul;
    arr[3]=divide;

    printf("Addition       : %d\n",arr[0](a,b));
    printf("Subtraction    : %d\n",arr[1](a,b));
    printf("Multiplication : %d\n",arr[2](a,b));
    printf("Division       : %d\n",arr[3](a,b));
}
/*
 * Enter two numbers: 4
2
Addition       : 6
Subtraction    : 2
Multiplication : 8
Division       : 2
 */

//=====================================Q-3=======================================
/*
 * 3. Write a C program to calculate the volume of the following shapes:
• Cube
• Cuboid
• Sphere
• Cylinder
• Cone.
Let the user select a shape, input dimensions in main(), and call shape-specific
functions (using appropriate parameters) to compute the volume by using pointers.
 */

/* Cube */
float cube(float *side)
{
    return (*side) * (*side) * (*side);
}

/* Cuboid */
float cuboid(float *l, float *b, float *h)
{
    return (*l) * (*b) * (*h);
}

/* Sphere */
float sphere(float *r)
{
    return (4.0 / 3.0) * PI * (*r) * (*r) * (*r);
}

/* Cylinder */
float cylinder(float *r, float *h)
{
    return PI * (*r) * (*r) * (*h);
}

/* Cone */
float cone(float *r, float *h)
{
    return (1.0 / 3.0) * PI * (*r) * (*r) * (*h);
}

void volume_of_shapes()
{
    int choice;
    float side, length, breadth, height, radius, volume;

    printf("\n===== Volume Calculator =====\n");
    printf("1. Cube\n");
    printf("2. Cuboid\n");
    printf("3. Sphere\n");
    printf("4. Cylinder\n");
    printf("5. Cone\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter side: ");
            scanf("%f", &side);

            volume = cube(&side);
            printf("Volume of Cube = %.2f\n", volume);
            break;

        case 2:
            printf("Enter Length Breadth Height: ");
            scanf("%f %f %f", &length, &breadth, &height);

            volume = cuboid(&length, &breadth, &height);
            printf("Volume of Cuboid = %.2f\n", volume);
            break;

        case 3:
            printf("Enter Radius: ");
            scanf("%f", &radius);

            volume = sphere(&radius);
            printf("Volume of Sphere = %.2f\n", volume);
            break;

        case 4:
            printf("Enter Radius and Height: ");
            scanf("%f %f", &radius, &height);

            volume = cylinder(&radius, &height);
            printf("Volume of Cylinder = %.2f\n", volume);
            break;

        case 5:
            printf("Enter Radius and Height: ");
            scanf("%f %f", &radius, &height);

            volume = cone(&radius, &height);
            printf("Volume of Cone = %.2f\n", volume);
            break;

        default:
            printf("Invalid Choice\n");
    }
}

/*
 * ===== Volume Calculator =====
1. Cube
2. Cuboid
3. Sphere
4. Cylinder
5. Cone
Enter your choice: 4
Enter Radius and Height: 5
3
Volume of Cylinder = 235.62
 */



//=============================Q-4====================================
/*Write a program in C to print all permutations of a given string using pointers.
Expected Output :
The permutations of the string are :
abcd abdc acbd acdb adcb adbc bacd badc bcad bcda bdca bdac cbad cbda
cabd cadb cdab cdba dbca dbac dcba dcab dacb dabc*/





















//=========================================Q-5======================================
/*
Write a C program to input n numbers using dynamic memory allocation and find the
largest element using a pointer.
 */

void largest_element_dma() {
	int *p, n;
	printf("Enter the number of element : ");
	scanf("%d", &n);

	p = (int*) malloc(n * sizeof(int));

	if (p == NULL) {
		printf("Memory Allocation Failed\n");
		return;
	}
	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
	int largest = *p;

	for (int i = 1; i < n; i++) {
		if (*(p + i) > largest) {
			largest = *(p + i);
		}
	}

	printf("Largest Element = %d\n", largest);

	free(p);
}


//===================================Q-6==================================

//Write a C program to calculate the length of a string using a pointer?

void string_length_pointer()
{
	char s[100];
	printf("Enter the string:");
	scanf("%s",s);

	int count=0;
	char *ptr=s;
	while(*ptr != '\0'){
		count++;
		ptr++;
	}
	printf("The length of the string is %d ",count);

}


//=========================Q-7============================
/*Write a C program to count and print the number of vowels and consonants in a string
using a pointer?
*/

void vowels_consonants_pointer() {
	char s[100];
	char *p;
	int vowels = 0, consonants = 0;

	printf("Enter the string: ");
	scanf("%s", s);

	p = s;

	while (*p != '\0') {
		char ch = tolower(*p);

		if (ch >= 'a' && ch <= 'z') {
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
				vowels++;
			else
				consonants++;
		}

		p++;
	}

	printf("Vowels = %d\n", vowels);
	printf("Consonants = %d\n", consonants);
}

//=========================Q-8==================================
/*Write a C program to print all the alphabets (both upper and lower case) using a
pointer?
*/
void print_alphabets_pointer()
{
	char s[100];
	char *p;

	printf("Enter the word : ");
	scanf("%s",s);

	p=s;

	while(*p != '\0')
	{
		if((*p >='a' && *p <='z')||(*p >='A' && *p <='Z'))
		{
			printf("%c\n",*p);
		}
		p++;
	}

}


//=============================Q-9===============================++

/*
 * . Write a C program to accept a string and check whether it is a palindrome or not using
pointers.
 */


void palindrome_pointer()
{
	char s[100];

	printf("Enter the String : ");
	scanf("%s",s);

	char *start=s;
	char *end=s+strlen(s)-1;


	while(start<end)
	{
		if(*start != *end){
			printf("This string is not palindrome\n");
			return ;

		}
		start++;
		end--;

	}
	printf("This string is palindrome\n");
}


//=========================Q-16===============================

void q16()
{
	int arr[6]={11,22,33,44,55,66};
	int *ptr=arr;
	printf("%d\n",*ptr++);  // *(ptr++) 11, then ptr -> 22
	printf("%d\n",++*ptr);  // ++(*ptr) 23, now ptr -> 22
	printf("%d\n",*++ptr);  // *(++ptr) 33, now ptr -> 33
	ptr[1]++; // ptr[i] = *(ptr+i) => *(ptr+1) = 44 => 44+1 = 45
	ptr++; // now ptr->44
	ptr[-1]++; // *(ptr-1)++ = 33 => 33+1 = 34
	ptr[0]++; // *(ptr+0) = 45 => 45+1 = 46
	printf("%d %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5]);
}
/* Output: 11
		   23
		   33
		   11 23 34 46 55 66
*/

/* ============================17=========================== */
void q17()
{
	int arr[6]={11,22,33,44,55,66};
	printf("%d\n",++*arr); // ++(*arr) = 11+1 = 12
	//printf("%d\n",*arr++); // *(arr++) -> array name incrementing - error
}
/* Output: 12
           Error
*/

/* ================================18. =========================*/
void q18()
{
	char arr[10]={'0','1', '2', '3', '4', '5', '6','7', '8', '9'};
	char *cp;
	int *ip;
	cp=ip=arr;
	printf("%x %x\n", *cp,*ip);
	cp++;
	ip++;
	printf("%x %x\n",*cp,*ip);
}
/* Output: 30 33323130
		   31 37363534
*/
/* Explanation: 0 -> 48 -> 30
 				char = 30
 				int = 4 Bytes = 33323130
*/

/*============================ 19.========================= */
void print(char *ptr, int n)
{
	if(n)
	print(ptr+1, n-1); // print(b,4) -> print(c,3) -> print(d,2) -> print(e,1)
	printf("%c",*ptr);
}
void q19()
{
	char arr[]={'a', 'b', 'c', 'd', 'e'};
	print(arr,sizeof(arr)-1); // print(a,5)
}
/* Output: edcba */

/*================================= 20.============================== */
void q20()
{
	int a[]={2,3,4,5,6};
	int i=0;
	printf("%d",a[i++]+i[a+1]); // *(i+(a+1)) = *(a+2) = 4; a[i] = 2  ; 4+2 = 6
}
/* Output: 6 */

/* =================================21.================================ */
void q21()
{
	int a[3],i;
	for(i=0;i<3;i++)
	a[i]=i++; // a = [0,...,2]
	for(i=0;i<3;i++)
	printf("%d",a[i]);
}
/* Output: *** stack smashing detected ***: terminated */

/* ==============================22.======================== */
void q22()
{
	int a[ 5]={11,22,33,44,55};
	int b[5];
	//b=a;
	printf("%d %d\n",*a,*b);
}
/* Output: Error: Array assigning not possible */

/* =====================================23.==================== */
void fun(int *ptr, int n)
{
	if(n)
	{
		fun(ptr+1,n-1);
		++*ptr;
	}
}
void q23()
{
	int arr[ ]={11,22,33,44,55},i;
	fun(arr,sizeof(arr)/sizeof(*arr));
	for(i=0;i<5;i++)
	printf("%d,",arr[i]);
}
/* Output: 12,23,34,45,56, */
		//========================Main Function=================================
int main() {
	int choice;

	while (1) {
		printf("\n========== POINTER ASSIGNMENT MENU ==========\n");
		printf("1. Check Amicable Numbers\n");
		printf("2. Arithmetic Using Function Pointer Array\n");
		printf("3. Volume of Different Shapes\n");
		printf("4. String Permutations Using Pointers\n");
		printf("5. Largest Element Using Dynamic Memory\n");
		printf("6. String Length Using Pointer\n");
		printf("7. Count Vowels and Consonants Using Pointer\n");
		printf("8. Print Alphabets Using Pointer\n");
		printf("9. Palindrome Check Using Pointer\n");
		printf("10. Dynamic 2D Array Using Array of Pointers\n");
		printf("11. Animal and Bird Names in Plural\n");
		printf("12. Void Pointer Arithmetic Demo\n");
		printf("13. Read Lines Until EOF and Print Reverse\n");
		printf("14. Stack Using Pointers\n");
		printf("15. Allocate and Free 2D Matrix\n");
		printf("0. Exit\n");

		printf("Enter Choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			amicable_numbers();
			break;

		case 2:
			function_pointer_arithmetic();
			break;
			//
		case 3:
			volume_of_shapes();
			break;
			//
			//            case 4:
			//                string_permutations();
			//                break;
			//
		case 5:
			largest_element_dma();
			break;
			//
		case 6:
			string_length_pointer();
			break;
			//
		case 7:
			vowels_consonants_pointer();
			break;

		case 8:
			print_alphabets_pointer();
			break;
			//
		case 9:
			palindrome_pointer();
			break;
			//
			//            case 10:
			//                dynamic_2d_array();
			//                break;
			//
			//            case 11:
			//                plural_strings();
			//                break;
			//
			//            case 12:
			//                void_pointer_arithmetic();
			//                break;
			//
			//            case 13:
			//                reverse_lines_malloc();
			//                break;
			//
			//            case 14:
			//                stack_using_pointers();
			//                break;
			//
			//            case 15:
			//                matrix_double_pointer();
			//                break;
		case 16:
			q16();
			break;
		case 17:
			q17();
			break;
		case 18:
			q18();
			break;
		case 19:
			q19();
			break;
		case 20:
			q20();
			break;
		case 21:
			q21();
			break;
		case 22:
			q22();
			break;
		case 23:
			q23();
			break;

		case 0:
			return 0;

		default:
			printf("Invalid Choice\n");
		}
	}
}
