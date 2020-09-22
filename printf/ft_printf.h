#ifndef _FT_PRINTF_H
#define _FT_PRINTF_H

#include <stdarg.h>
#include "libft.h"

// typedef union argumentUnionName
// {
//     char* argumentChar;
//     wchar_t *argumentWide;
//     int argumentInt;
//     wchar_t argumentWideInt;
// 	size_t argumentSizeT;
// 	long int argumentLong;
// 	long long int argumentLLong;
// 	short int argumentShort;
// 	char argumentCharacter;
// } argumentUnionName;

typedef struct argStruct
{
	char* argumentChar;
    wchar_t *argumentWide;
    int argumentInt;
    wchar_t argumentWideInt;
	size_t argumentSizeT;
	ssize_t argumentSSizeT;
	long int argumentLong;
	long long int argumentLLong;
	short int argumentShort;
	char argumentCharacter;
	unsigned long long int argumentULL;
} argStruct;

typedef struct flagStruct
{
    int integerWidth;
    char charWidth[15];
    int integerPrecision;
    char charPrecision[15];
    int widthExists;
    int precisionExists;
    int zeroFlag;
    int minusFlag;
	int plusFlag;
	int spaceFlag;
	int sharpFlag;
	int llFlag;
	int lFlag;
	int hhFlag;
	int hFlag;
	int jFlag;
	int zFlag;
    int index;
	int argLen;
    int counter;
	int isNegative;
	argStruct arguments;
} flagStruct;

long long int numberLength(long long int a);
void printNumber(long long int a);
void dFlag(char* flags);
flagStruct makeIntegerArgsNegative(flagStruct tempFlagStruct);
flagStruct	getdFlagArgs(flagStruct flagVars);
flagStruct getArg(flagStruct tempFlagStruct, char finalFlag);
flagStruct getSFlagArg(flagStruct tempFlagStruct);
void printArg(flagStruct tempFlagStruct, char finalFlag);
flagStruct printPadding(flagStruct tempFlagStruct, char padding);
char checkFinalFlag(char c);
int checkInterFlags(char c);
void	ft_putstr_wchar(const wchar_t *s);
size_t	ft_strlen_wchar(const wchar_t *s);
flagStruct initializeFlagVars(flagStruct temp);
flagStruct zeroAndMinusFlags(char* flags, flagStruct sFlagVars);
flagStruct findFieldWidth(char* flags, flagStruct sFlagVars);
flagStruct findPrecision(char* flags, flagStruct sFlagVars);
flagStruct	llFlagChecker(char* flags, flagStruct flagVars);
flagStruct	hhFlagChecker(char* flags, flagStruct flagVars);
flagStruct	lFlagChecker(char* flags, flagStruct flagVars);
flagStruct	hFlagChecker(char* flags, flagStruct flagVars);
flagStruct	zFlagChecker(char* flags, flagStruct flagVars);
flagStruct	jFlagChecker(char* flags, flagStruct flagVars);
flagStruct	sharpFlagChecker(char* flags, flagStruct flagVars);
void	ft_putchar_wchar_t(wchar_t c);
void cFlag(char* flags);
void sFlag(char* flags);
void processTempFlags(char* flags);
int ft_printf(const char* format, ...);

#endif
