#include <stdarg.h>
#include "libft.h"
#include "stdio.h"

typedef union argumentUnionName
{
    char* argumentChar;
    wchar_t *argumentWide;
    int argumentInt;
    wint_t argumentWideInt;
} argumentUnionName;

typedef struct flagStruct
{
    int integerWidth;
    char charWidth[15];
    int integerPrecision;
    char charPrecision[15];
    int zeroFlag;
    int minusFlag;
    int widthExists;
    int precisionExists;
    int counter;
    int index;
    union argumentUnionName argumentUnion;
} flagStruct;

char checkFinalFlag(char c)
{
    if (c == 's' || c == 'S')
        return c;
    if (c == 'p' || c == 'i' || c == 'd' || c == 'D')
        return c;
    if (c == 'o' || c == 'O' || c == 'u' || c == 'U')
        return c;
    if (c == 'c' || c == 'C' || c == 'x' || c == 'X')
        return c;
    if (c == '%')
        return c;
    return 0;
}

int checkInterFlags(char c)
{
    if (c == '#' || c == 0 || c == '-' || c == '+')
        return 1;
    if (c == ' ' || c == 'l' || c == 'h' || c == 'j')
        return 1;
    if (c == 'z' || c == '.' || (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

void	ft_putstr_wchar(const wchar_t *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
	    write(1, &s[i], 1);
		i++;
	}
}

size_t	ft_strlen_wchar(const wchar_t *s)
{
	size_t i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

flagStruct initializeFlagVars(flagStruct temp)
{
    temp.integerWidth = 0;
    temp.integerPrecision = 0;
    temp.zeroFlag = 0;
    temp.minusFlag = 0;
    temp.widthExists = 0;
    temp.precisionExists = 0;
    temp.counter = 0;
    temp.index = 1;
    return temp;
}

/*
    Checks for zero and minus flags in the given temp flag.
*/
flagStruct zeroAndMinusFlags(char* flags, flagStruct sFlagVars)
{
    if (ft_strchr(flags, '-') != 0)
    {
        if (ft_strchr(flags, '0') == 0)
        {
            while (flags[sFlagVars.index] == '-')
            {
                sFlagVars.index++;
                sFlagVars.minusFlag = 1;
            }
        }
        else
        {
            while (flags[sFlagVars.index] == '-' || flags[sFlagVars.index] == '0')
            {
                if (flags[sFlagVars.index] == '0')
                    sFlagVars.zeroFlag = 1;
                else
                    sFlagVars.minusFlag = 1;
                sFlagVars.index++;
            }
        }
    }
    else if (ft_strchr(flags, '0') != 0)
    {
        while (flags[sFlagVars.index] == '0')
        {
            sFlagVars.zeroFlag = 1;
            sFlagVars.index++;
        }
    }
    return sFlagVars;
}

/*
    If field width exists, takes its value.
*/
flagStruct findFieldWidth(char* flags, flagStruct sFlagVars)
{
    while (flags[sFlagVars.index] >= '0' && flags[sFlagVars.index] <= '9')
    {
        sFlagVars.charWidth[sFlagVars.counter++] = flags[sFlagVars.index++];
        sFlagVars.widthExists = 1;
    }
    if (sFlagVars.widthExists)
    {
        sFlagVars.integerWidth = ft_atoi(sFlagVars.charWidth);
    }
    return sFlagVars;
}

/*
    If precision exists, takes its value.
*/
flagStruct findPrecision(char* flags, flagStruct sFlagVars)
{
    if (flags[sFlagVars.index] == '.')
    {
        sFlagVars.index++;
        sFlagVars.counter = 0;
        while (flags[sFlagVars.index] >= '0' && flags[sFlagVars.index] <= '9')
            sFlagVars.charPrecision[sFlagVars.counter++] = flags[sFlagVars.index++];
        sFlagVars.precisionExists = 1;
        sFlagVars.integerPrecision = ft_atoi(sFlagVars.charPrecision);
    }
    return sFlagVars;
}

void	ft_putchar_wint(wint_t c)
{
	write(1, &c, 1);
}

va_list cFlag(char* flags, va_list ap)
{
    int lFlag;
    char paddingChar;
    flagStruct cFlagVars;
    
    lFlag = 0;
    cFlagVars = initializeFlagVars(cFlagVars);
    cFlagVars = zeroAndMinusFlags(flags, cFlagVars);
    cFlagVars = findFieldWidth(flags, cFlagVars);
    cFlagVars = findPrecision(flags, cFlagVars);
    if (ft_strchr(flags, 'l') != NULL)
        lFlag = 1;
    if (!lFlag)
        cFlagVars.argumentUnion.argumentInt = (unsigned char)va_arg(ap, int);
    else
        cFlagVars.argumentUnion.argumentWideInt = (wint_t)va_arg(ap, int);
    if (cFlagVars.widthExists)
    {
        if (cFlagVars.integerWidth > 1)
        {
            if (cFlagVars.zeroFlag && !cFlagVars.minusFlag)
            {
                while (cFlagVars.integerWidth > 1)
                {
                    ft_putchar('0');
                    cFlagVars.integerWidth--;
                }
                if (lFlag)
                    ft_putchar(cFlagVars.argumentUnion.argumentWideInt);
                else
                    ft_putchar(cFlagVars.argumentUnion.argumentInt);
            }
            else if (!cFlagVars.zeroFlag && !cFlagVars.minusFlag)
            {
                while (cFlagVars.integerWidth > 1)
                {
                    ft_putchar(' ');
                    cFlagVars.integerWidth--;
                }
                if (lFlag)
                    ft_putchar(cFlagVars.argumentUnion.argumentWideInt);
                else
                    ft_putchar(cFlagVars.argumentUnion.argumentInt);
            }
            else if ((!cFlagVars.zeroFlag && cFlagVars.minusFlag) || (cFlagVars.zeroFlag && cFlagVars.minusFlag))
            {
                if (lFlag)
                    ft_putchar(cFlagVars.argumentUnion.argumentWideInt);
                else
                    ft_putchar(cFlagVars.argumentUnion.argumentInt);
                while (cFlagVars.integerWidth > 1)
                {
                    ft_putchar(' ');
                    cFlagVars.integerWidth--;
                }
            }
        }
        else
        {
            if (lFlag)
                ft_putchar(cFlagVars.argumentUnion.argumentWideInt);
            else
                ft_putchar(cFlagVars.argumentUnion.argumentInt);
        }
    }
    else
    {
        if (lFlag)
            ft_putchar(cFlagVars.argumentUnion.argumentWideInt);
        else
            ft_putchar(cFlagVars.argumentUnion.argumentInt);
    }
    return ap;
}

va_list sFlag(char* flags, va_list ap)
{
    int lFlag;
    int argLen;
    char paddingChar;
    flagStruct sFlagVars;
    
    lFlag = 0;
    sFlagVars = initializeFlagVars(sFlagVars);
    sFlagVars = zeroAndMinusFlags(flags, sFlagVars);
    sFlagVars = findFieldWidth(flags, sFlagVars);
    sFlagVars = findPrecision(flags, sFlagVars);
    //checks if l flag exists, and takes argument
    if (ft_strchr(flags, 'l') != NULL)
    {
        lFlag = 1;
        sFlagVars.argumentUnion.argumentWide = va_arg(ap, wchar_t*);
        if (sFlagVars.argumentUnion.argumentChar == 0)
        {
            ft_putstr("(null)");
            return ap;
        }
        argLen = ft_strlen_wchar(sFlagVars.argumentUnion.argumentWide);
    }
    else
    {
        sFlagVars.argumentUnion.argumentChar = va_arg(ap, char*);
        if (sFlagVars.argumentUnion.argumentChar == 0)
        {
            ft_putstr("(null)");
            return ap;
        }
        argLen = ft_strlen(sFlagVars.argumentUnion.argumentChar);
        if (argLen == 0)
            return ap;
        if (sFlagVars.precisionExists && sFlagVars.integerPrecision < argLen)
        {
            char* temp = ft_strdup(sFlagVars.argumentUnion.argumentChar);
            temp[sFlagVars.integerPrecision] = '\0';
            sFlagVars.argumentUnion.argumentChar = temp;
            argLen = sFlagVars.integerPrecision;
        }
    }
    //prints string if field width and precision dont exist
    if (!sFlagVars.widthExists && !sFlagVars.precisionExists)
    {
        if (lFlag)
            ft_putstr_wchar(sFlagVars.argumentUnion.argumentWide);
        else
            ft_putstr(sFlagVars.argumentUnion.argumentChar);
    }
    //prints string otherwise
    if (sFlagVars.widthExists && sFlagVars.integerWidth > argLen)
    {
        if ((sFlagVars.zeroFlag && sFlagVars.minusFlag) || (sFlagVars.minusFlag && !sFlagVars.zeroFlag))
        {
            if (lFlag)
            {
                ft_putstr_wchar(sFlagVars.argumentUnion.argumentWide);
            }
            else
                ft_putstr(sFlagVars.argumentUnion.argumentChar);
            while (sFlagVars.integerWidth > argLen)
            {
                ft_putchar(' ');
                sFlagVars.integerWidth--;
            }
        }
        else
        {
            while (sFlagVars.integerWidth > argLen)
            {
                if (sFlagVars.zeroFlag)
                    ft_putchar('0');
                else
                    ft_putchar(' ');
                sFlagVars.integerWidth--;
            }
            if (lFlag)
                ft_putstr_wchar(sFlagVars.argumentUnion.argumentWide);
            else
                ft_putstr(sFlagVars.argumentUnion.argumentChar);
        }
    }
    else if (sFlagVars.widthExists && sFlagVars.integerWidth <= argLen)
    {
        if (lFlag)
            ft_putstr_wchar(sFlagVars.argumentUnion.argumentWide);
        else
            ft_putstr(sFlagVars.argumentUnion.argumentChar);
    }
    else if (sFlagVars.precisionExists && !sFlagVars.widthExists)
    {
        if (lFlag)
            ft_putstr_wchar(sFlagVars.argumentUnion.argumentWide);
        else
            ft_putstr(sFlagVars.argumentUnion.argumentChar);
    }
    return ap;
}

va_list processTempFlags(char* flags, va_list ap)
{
    int flagsLen;
    char finalFlag;
    char* temp;
    
    flagsLen = ft_strlen(flags);
    finalFlag = flags[flagsLen - 1];
    if (finalFlag == 's')
    {
        return sFlag(flags, ap);
    }
    else if (finalFlag == 'S')
    {
        temp = flags;
        flags = (char*)ft_memalloc(flagsLen + 1);
        flags = ft_strcpy(flags, temp);
        flags[flagsLen - 1] = 'l';
        flags[flagsLen] = 's';
        flags[flagsLen + 1] = '\0';
        flagsLen = ft_strlen(flags);
        return sFlag(flags, ap);
    }
    else if (finalFlag == 'c')
    {
        return cFlag(flags, ap);
    }
    else if (finalFlag == 'C')
    {
        temp = flags;
        flags = (char*)ft_memalloc(flagsLen + 1);
        flags = ft_strcpy(flags, temp);
        flags[flagsLen - 1] = 'l';
        flags[flagsLen] = 'c';
        flags[flagsLen + 1] = '\0';
        flagsLen = ft_strlen(flags);
        return cFlag(flags, ap);
    }
}

int ft_printf(const char* format, ...)
{
    va_list ap;
    int i;
    int j;
    int formatLen;
    
    i = 0;
    formatLen = ft_strlen(format);
    va_start(ap, format);
    while (i < formatLen)
    {
        if (format[i] == '%')
        {
            j = 0;
            char* tempFlags = (char*)malloc(sizeof(char) * 15);
            tempFlags[j++] = format[i++];
            while (checkInterFlags(format[i]) && i < formatLen) 
                tempFlags[j++] = format[i++];
            if (checkFinalFlag(format[i]))
                tempFlags[j++] = format[i++];
            tempFlags[j] = '\0';
            //take tempFlags and process and print in respective function
            ap = processTempFlags(tempFlags, ap);
            i--;
            free(tempFlags);
        }
        else
            ft_putchar(format[i]);
        i++;
    }
    va_end(ap);
    return 0;
}

int main(void)
{    
    printf("%c\n", 200);
    ft_printf("%c\n", 200);
    return 0;
}
