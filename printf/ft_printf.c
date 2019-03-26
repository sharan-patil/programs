#include "stdio.h"
#include "ft_printf.h"

va_list ap;

long long int numberLength(long long int a)
{
	long long int i = 10;
	long long int len = 0;
	
	if ((unsigned long long)a == -9223372036854775808ULL)
	{
		return 20;
	}
	if (a < 0)
	{
		a *= -1;
		len++;
	}
	while (a / i > 0)
	{
		len++;
		i *= 10;
	}
	len++;
	return len;
}

void printNumber(long long int a)
{
	char arr[21];
	int i = 0;
	int len = 0;
	
	len = numberLength(a);
	arr[len] = '\0';
	if ((unsigned long long)a == -9223372036854775808ULL)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (a < 0)
	{
		arr[0] = '-';
		a *= -1;
	}
	while (i != len)
	{
		if (!(arr[0] == '-' && len - i - 1 == 0))
			arr[len - i - 1] = a % 10 + '0';
		a /= 10;
		i++;
	}
	ft_putstr(&arr[0]);
	return ;
}

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
	temp.lFlag = 0;
	temp.argLen = 0;
	temp.llFlag = 0;
	temp.hhFlag = 0;
	temp.hFlag = 0;
	temp.sharpFlag = 0;
	temp.jFlag = 0;
	temp.zFlag = 0;
	temp.plusFlag = 0;
	temp.spaceFlag = 0;
	temp.isNegative = 0;
    return temp;
}

flagStruct	llFlagChecker(char* flags, flagStruct flagVars)
{
	char *subString;
	
	subString = ft_strstr(flags, "ll");
	if (subString == NULL)
		return flagVars;
	else
	{
		flagVars.llFlag = 1;
		return flagVars;
	}
}

flagStruct	hhFlagChecker(char* flags, flagStruct flagVars)
{
	char *subString;
	
	subString = ft_strstr(flags, "hh");
	if (subString == NULL)
		return flagVars;
	else
	{
		flagVars.hhFlag = 1;
		return flagVars;
	}
}

flagStruct	lFlagChecker(char* flags, flagStruct flagVars)
{
	char *subString;
	
	subString = ft_strstr(flags, "l");
	if (subString == NULL)
		return flagVars;
	else
	{
		flagVars.lFlag = 1;
		return flagVars;
	}
}

flagStruct	hFlagChecker(char* flags, flagStruct flagVars)
{
	char *subString;
	
	subString = ft_strstr(flags, "h");
	if (subString == NULL)
		return flagVars;
	else
	{
		flagVars.hFlag = 1;
		return flagVars;
	}
}

flagStruct	jFlagChecker(char* flags, flagStruct flagVars)
{
	char *subString;
	
	subString = ft_strstr(flags, "j");
	if (subString == NULL)
		return flagVars;
	else
	{
		flagVars.jFlag = 1;
		return flagVars;
	}
}

flagStruct	zFlagChecker(char* flags, flagStruct flagVars)
{
	char *subString;
	
	subString = ft_strstr(flags, "z");
	if (subString == NULL)
		return flagVars;
	else
	{
		flagVars.zFlag = 1;
		return flagVars;
	}
}

/*
    Checks for zero and minus flags in the given temp flag.
*/
flagStruct zeroAndMinusFlags(char* flags, flagStruct sFlagVars)
{
	while (flags[sFlagVars.index] == '-' || flags[sFlagVars.index] == '0' || flags[sFlagVars.index] == '+' || flags[sFlagVars.index] == ' ')
	{
		if (flags[sFlagVars.index] == '0')
			sFlagVars.zeroFlag = 1;
		if (flags[sFlagVars.index] == '-')
			sFlagVars.minusFlag = 1;
		if (flags[sFlagVars.index] == '+')
			sFlagVars.plusFlag = 1;
		if (flags[sFlagVars.index] == ' ')
			sFlagVars.spaceFlag = 1;
		sFlagVars.index++;
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

void	ft_putchar_wchar_t(wchar_t c)
{
	write(1, &c, 1);
}

flagStruct printPadding(flagStruct tempFlagStruct, char padding)
{
	while (tempFlagStruct.integerWidth > tempFlagStruct.argLen)
	{
		ft_putchar(padding);
		tempFlagStruct.integerWidth--;
	}
	return tempFlagStruct;
}

void printArg(flagStruct tempFlagStruct, char finalFlag)
{
	if (finalFlag == 'c')
	{
		if (tempFlagStruct.lFlag)
			ft_putchar(tempFlagStruct.argumentWideInt);
		else
			ft_putchar(tempFlagStruct.argumentInt);
	}
	else if (finalFlag == 's')
	{
		if (tempFlagStruct.lFlag)
            ft_putstr_wchar(tempFlagStruct.argumentWide);
        else
            ft_putstr(tempFlagStruct.argumentChar);
	}
	else if (finalFlag == 'd' || finalFlag == 'i')
	{
		if (tempFlagStruct.zFlag)
		{
			printNumber(tempFlagStruct.argumentSizeT);
		}
		else if (tempFlagStruct.llFlag || tempFlagStruct.jFlag)
		{
			printNumber(tempFlagStruct.argumentLLong);
		}
		else if (tempFlagStruct.lFlag)
		{
			printNumber(tempFlagStruct.argumentLong);
		}
		else if (tempFlagStruct.hhFlag)
		{
			printNumber((int)tempFlagStruct.argumentCharacter);
		}
		else if (tempFlagStruct.hFlag)
		{
			printNumber(tempFlagStruct.argumentShort);
		}
		else
		{
			printNumber(tempFlagStruct.argumentInt);
		}
	}
}

flagStruct getSFlagArg(flagStruct tempFlagStruct)
{
	char *temp;
	
	if (tempFlagStruct.lFlag)
	{
		tempFlagStruct.argumentWide = va_arg(ap, wchar_t*);
		if (tempFlagStruct.argumentChar == 0)
		{
			ft_putstr("(null)");
		}
		else
			tempFlagStruct.argLen = ft_strlen_wchar(tempFlagStruct.argumentWide);
	}
	else
	{
		tempFlagStruct.argumentChar = va_arg(ap, char*);
		if (tempFlagStruct.argumentChar == 0)
		{
			ft_putstr("(null)");
		}
		else
		{
			tempFlagStruct.argLen = ft_strlen(tempFlagStruct.argumentChar);
			if (tempFlagStruct.precisionExists && tempFlagStruct.integerPrecision < tempFlagStruct.argLen)
			{
				temp = ft_strdup(tempFlagStruct.argumentChar);
				temp[tempFlagStruct.integerPrecision] = '\0';
				tempFlagStruct.argumentChar = temp;
				tempFlagStruct.argLen = tempFlagStruct.integerPrecision;
			}
		}
	}
	return tempFlagStruct;
}

flagStruct getArg(flagStruct tempFlagStruct, char finalFlag)
{
	if (finalFlag == 'c')
	{
    	if (!tempFlagStruct.lFlag)
        	tempFlagStruct.argumentInt = (unsigned char)va_arg(ap, int);
	    else
        	tempFlagStruct.argumentWideInt = (wchar_t)va_arg(ap, int);
	}
	else if (finalFlag == 's')
	{
		tempFlagStruct = getSFlagArg(tempFlagStruct);
	}
	return tempFlagStruct;
}

void cFlag(char* flags)
{
    flagStruct cFlagVars;
    
	cFlagVars.argLen = 1;
    cFlagVars = initializeFlagVars(cFlagVars);
    cFlagVars = zeroAndMinusFlags(flags, cFlagVars);
    cFlagVars = findFieldWidth(flags, cFlagVars);
    cFlagVars = findPrecision(flags, cFlagVars);
	cFlagVars = lFlagChecker(flags, cFlagVars);
	cFlagVars = getArg(cFlagVars, 'c');
    if (cFlagVars.widthExists)
    {
        if (cFlagVars.integerWidth > 1)
        {
            if (cFlagVars.zeroFlag && !cFlagVars.minusFlag)
            {
				cFlagVars = printPadding(cFlagVars, '0');
				printArg(cFlagVars, 'c');
            }
            else if (!cFlagVars.zeroFlag && !cFlagVars.minusFlag)
            {
				cFlagVars = printPadding(cFlagVars, ' ');
				printArg(cFlagVars, 'c');
            }
            else if ((!cFlagVars.zeroFlag && cFlagVars.minusFlag) || (cFlagVars.zeroFlag && cFlagVars.minusFlag))
            {
				printArg(cFlagVars, 'c');
				cFlagVars = printPadding(cFlagVars, ' ');
            }
        }
        else
        {
			printArg(cFlagVars, 'c');
        }
    }
    else
    {
		printArg(cFlagVars, 'c');
    }
    return ;
}

void sFlag(char* flags)
{
    flagStruct sFlagVars;

    sFlagVars = initializeFlagVars(sFlagVars);
    sFlagVars = zeroAndMinusFlags(flags, sFlagVars);
    sFlagVars = findFieldWidth(flags, sFlagVars);
    sFlagVars = findPrecision(flags, sFlagVars);
	sFlagVars = lFlagChecker(flags, sFlagVars);
	sFlagVars = getArg(sFlagVars, 's');
	if (sFlagVars.argumentChar == 0)
	{
		return ;
	}
	//prints string with required padding
    if (!sFlagVars.widthExists && !sFlagVars.precisionExists)
    {
		printArg(sFlagVars, 's');
    }
    if (sFlagVars.widthExists && sFlagVars.integerWidth > sFlagVars.argLen)
    {
        if ((sFlagVars.zeroFlag && sFlagVars.minusFlag) || (sFlagVars.minusFlag && !sFlagVars.zeroFlag))
        {
			printArg(sFlagVars, 's');
			printPadding(sFlagVars, ' ');
        }
        else
        {
            if (sFlagVars.zeroFlag)
            	printPadding(sFlagVars, '0');
			else
				printPadding(sFlagVars, ' ');
			printArg(sFlagVars, 's');
        }
    }
    else if ((sFlagVars.widthExists && sFlagVars.integerWidth <= sFlagVars.argLen) || (sFlagVars.precisionExists && !sFlagVars.widthExists))
    {
		printArg(sFlagVars, 's');
    }
    return ;
}

flagStruct	getdFlagArgs(flagStruct flagVars)
{
	if (flagVars.zFlag)
	{
		flagVars.argumentSizeT = va_arg(ap, size_t);
		flagVars.argLen = numberLength(flagVars.argumentSizeT);
	}
	else if (flagVars.llFlag || flagVars.jFlag)
	{
		flagVars.argumentLLong = va_arg(ap, long long int);
		flagVars.argLen = numberLength(flagVars.argumentLLong);
		if (flagVars.argumentLLong < 0)
			flagVars.isNegative = 1;
	}
	else if (flagVars.lFlag)
	{
		flagVars.argumentLong = va_arg(ap, long int);
		flagVars.argLen = numberLength(flagVars.argumentLong);
		if (flagVars.argumentLong < 0)
			flagVars.isNegative = 1;
	}
	else if (flagVars.hhFlag)
	{
		flagVars.argumentCharacter = va_arg(ap, int);
		flagVars.argLen = numberLength(flagVars.argumentCharacter);
		if (flagVars.argumentCharacter < 0)
			flagVars.isNegative = 1;
	}
	else if (flagVars.hFlag)
	{
		flagVars.argumentShort = va_arg(ap, int);
		flagVars.argLen = numberLength(flagVars.argumentShort);
		if (flagVars.argumentShort < 0)
			flagVars.isNegative = 1;
	}
	else
	{
		flagVars.argumentInt = va_arg(ap, int);
		flagVars.argLen = numberLength(flagVars.argumentInt);
		if (flagVars.argumentInt < 0)
			flagVars.isNegative = 1;
	}
	return flagVars;
}

flagStruct makeIntegerArgsNegative(flagStruct tempFlagStruct)
{
	tempFlagStruct.argumentInt *= -1;
	tempFlagStruct.argumentLong *= -1;
	tempFlagStruct.argumentLLong *= -1;
	tempFlagStruct.argumentShort *= -1;
	return tempFlagStruct;
}

void dFlag(char* flags)
{
	flagStruct dFlagVars;
	
	dFlagVars = initializeFlagVars(dFlagVars);
	dFlagVars = zeroAndMinusFlags(flags, dFlagVars);
	dFlagVars = findFieldWidth(flags, dFlagVars);
	dFlagVars = findPrecision(flags, dFlagVars);
	dFlagVars = lFlagChecker(flags, dFlagVars);
	dFlagVars = llFlagChecker(flags, dFlagVars);
	dFlagVars = hFlagChecker(flags, dFlagVars);
	dFlagVars = hhFlagChecker(flags, dFlagVars);
	dFlagVars = jFlagChecker(flags, dFlagVars);
	dFlagVars = zFlagChecker(flags, dFlagVars);
	if (dFlagVars.zeroFlag)
		if (dFlagVars.precisionExists || dFlagVars.minusFlag)
			dFlagVars.zeroFlag = 0;
	if (dFlagVars.plusFlag)
		if (dFlagVars.spaceFlag)
			dFlagVars.spaceFlag = 0;
	dFlagVars = getdFlagArgs(dFlagVars);
	if (dFlagVars.widthExists && dFlagVars.integerWidth > dFlagVars.argLen)
	{
		if (dFlagVars.precisionExists && dFlagVars.integerPrecision > dFlagVars.argLen)
		{
			if (dFlagVars.minusFlag)
			{
				if (dFlagVars.plusFlag)
				{
					if (!dFlagVars.isNegative)
					{
						dFlagVars.integerWidth--;
						ft_putchar('+');
					}
				}
				if (dFlagVars.spaceFlag)
				{
					if (!dFlagVars.isNegative)
					{
						dFlagVars.integerWidth--;
						ft_putchar(' ');
					}
				}
				while (dFlagVars.integerPrecision > dFlagVars.argLen)
				{
					ft_putchar('0');
					dFlagVars.argLen++;
				}
				printArg(dFlagVars, 'd');
				printPadding(dFlagVars, ' ');
			}
			else
			{
				if ((dFlagVars.plusFlag || dFlagVars.spaceFlag) && !dFlagVars.isNegative)
				{
					dFlagVars.argLen++;
					dFlagVars.integerPrecision++;
				}
				dFlagVars.counter = dFlagVars.argLen;
				dFlagVars.argLen = dFlagVars.integerPrecision;
				printPadding(dFlagVars, ' ');
				if (!dFlagVars.isNegative)
				{
					if (dFlagVars.plusFlag)
						ft_putchar('+');
					if (dFlagVars.spaceFlag)
						ft_putchar(' ');
				}
				while (dFlagVars.integerPrecision > dFlagVars.counter)
				{
					ft_putchar('0');
					dFlagVars.counter++;
				}
				printArg(dFlagVars, 'd');
			}
		}
		else if (dFlagVars.precisionExists && dFlagVars.integerPrecision == 0)
		{
			if (dFlagVars.minusFlag)
			{
				if (dFlagVars.plusFlag)
				{
					ft_putchar('+');
					printPadding(dFlagVars, ' ');
				}
			}
			else if (dFlagVars.plusFlag)
			{
				printPadding(dFlagVars, ' ');
				ft_putchar('+');
			}
			else
			{
				dFlagVars.integerWidth++;
				printPadding(dFlagVars, ' ');
			}
		}
		else
		{
			if (dFlagVars.zeroFlag)
			{
				if (dFlagVars.plusFlag && !dFlagVars.isNegative)
				{
					ft_putchar('+');
					dFlagVars.integerWidth--;
				}
				else if (dFlagVars.spaceFlag && !dFlagVars.isNegative)
				{
					ft_putchar(' ');
					dFlagVars.integerWidth--;
				}
				if (dFlagVars.isNegative)
				{
					ft_putchar('-');
					printPadding(dFlagVars, '0');
					dFlagVars = makeIntegerArgsNegative(dFlagVars);
					printArg(dFlagVars, 'd');
				}
				else
				{
					printPadding(dFlagVars, '0');
					printArg(dFlagVars, 'd');
				}
			}
			else if (dFlagVars.minusFlag)
			{
				if (dFlagVars.plusFlag && !dFlagVars.isNegative)
				{
					ft_putchar('+');
					dFlagVars.integerWidth--;
				}
				else if (dFlagVars.spaceFlag && !dFlagVars.isNegative)
				{
					ft_putchar(' ');
					dFlagVars.integerWidth--;
				}
				printArg(dFlagVars, 'd');
				printPadding(dFlagVars, ' ');
			}
			else if (dFlagVars.plusFlag && !dFlagVars.isNegative)
			{
				dFlagVars.integerWidth--;
				printPadding(dFlagVars, ' ');
				ft_putchar('+');
				printArg(dFlagVars, 'd');
			}
			else
			{
				printPadding(dFlagVars, ' ');
				printArg(dFlagVars, 'd');
			}
		}
	}
	else
	{
		printArg(dFlagVars, 'd');
	}
}

void processTempFlags(char* flags)
{
    int flagsLen;
    char finalFlag;
    char* temp;
    
    flagsLen = ft_strlen(flags);
    finalFlag = flags[flagsLen - 1];
    if (finalFlag == 's')
    {
        sFlag(flags);
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
        sFlag(flags);
    }
    else if (finalFlag == 'c')
    {
        cFlag(flags);
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
        cFlag(flags);
    }
	else if (finalFlag == 'd' || finalFlag == 'i')
	{
		dFlag(flags);
	}
}

int ft_printf(const char* format, ...)
{
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
            processTempFlags(tempFlags);
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
