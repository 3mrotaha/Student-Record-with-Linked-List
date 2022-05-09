/************************************************************************** 
 * TEAM NAMES : 	(1)Amr Mohamed Taha Ibrahem                           *
 *                  (2)Mohamed Bedir                                      *
 * Version : V1                                                           *
 * DATE : 20 AUG                                                          *
 * Description :                  Standard Data Types                     *
 **************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#define DAYS  5
#define NAME_CHARS  8
#define WEEKS 2
#define STUDENTS  16

typedef char char_8; // %c
typedef unsigned char u8;        // %cu  --> 
typedef unsigned short int u16; // %hu --> %ho -->  %hx
typedef unsigned long int u32; //%lu --> %lo -->  %lx

typedef unsigned int Uint32; // %du
typedef int int_32;          // %d

typedef signed char s8;
typedef signed long int s32;
typedef signed short int s16;

typedef float f32;          //%f 
typedef double f64;        // %lf
typedef long double f128; // %Lf

typedef long long ll64; // %ll


 typedef struct { 
	char_8 frstname[NAME_CHARS]; 								 
	char_8 lstname[NAME_CHARS]; 
	int_32 id; 
	f32 grades[WEEKS][DAYS]; 
}Student;

#endif


