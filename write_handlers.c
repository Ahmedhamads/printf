#include "main.h"

int handle_write_char(char c, char bufer[],
int flags, int width, int precision, int size)
{ 
int i = 0;
char padd = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
padd = '0';
bufer[i++] = c;
bufer[i] = '\0';
if (width > 1)
{
bufer[BUFF_SIZE - 1] = '\0';
for (i = 0; i < width - 1; i++)
bufer[BUFF_SIZE - i - 2] = padd;
if (flags & F_MINUS)
return (write(1, &bufer[0], 1) +
write(1, &bufer[BUFF_SIZE - i - 1], width - 1));
else
return (write(1, &bufer[BUFF_SIZE - i - 1], width - 1) +
write(1, &bufer[0], 1));
}
return (write(1, &bufer[0], 1));
}
	
int write_number(int is_negative, int ind, char bufer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';
return (write_num(ind, bufer, flags, width, precision,
length, padd, extra_ch);
}
int write_num(int ind, char bufer[],
int flags, int width, int prec,
int length, char padd, char extra_c)
{
int i, padd_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && bufer[ind] == '0' && width == 0)
return (0); 
if (prec == 0 && ind == BUFF_SIZE - 2 && bufer[ind] == '0')
bufer[ind] = padd = ' '; 
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
bufer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (i = 1; i < width - length + 1; i++)
bufer[i] = padd;
bufer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
{
if (extra_c)
bufer[--ind] = extra_c;
return (write(1, &bufer[ind], length) + write(1, &bufer[1], i - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &bufer[1], i - 1) + write(1, &bufer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
bufer[--padd_start] = extra_c;
return (write(1, &bufer[padd_start], i - padd_start) +
write(1, &bufer[ind], length - (1 - padd_start)));
}
}
if (extra_c)
bufer[--ind] = extra_c;
return (write(1, &bufer[ind], length));
}


int write_unsgnd(int is_negative, int ind,
char bufer[],
int flags, int width, int precision, int size)
{


int length = BUFF_SIZE - ind - 1, i = 0;
char padd = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && bufer[ind] == '0')
return (0); 
if (precision > 0 && precision < length)
padd = ' ';
while (precision > length)
{
bufer[--ind] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (width > length)
{
for (i = 0; i < width - length; i++)
bufer[i] = padd;
bufer[i] = '\0';
if (flags & F_MINUS) 
{
return (write(1, &bufer[ind], length) + write(1, &bufer[0], i));
}
else 
{
return (write(1, &bufer[0], i) + write(1, &bufer[ind], length));
}
}
return (write(1, &bufer[ind], length));
}

 

int write_pointer(char bufer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start)
{
int i;
if (width > length)
{
for (i = 3; i < width - length + 3; i++)
bufer[i] = padd;
bufer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
{
bufer[--ind] = 'x';
bufer[--ind] = '0';
if (extra_c)
bufer[--ind] = extra_c;
return (write(1, &bufer[ind], length) + write(1, &bufer[3], i - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
bufer[--ind] = 'x';
bufer[--ind] = '0';
if (extra_c)
bufer[--ind] = extra_c;
return (write(1, &bufer[3], i - 3) + write(1, &bufer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
bufer[--padd_start] = extra_c;
bufer[1] = '0';
bufer[2] = 'x';
return (write(1, &bufer[padd_start], i - padd_start) +
write(1, &bufer[ind], length - (1 - padd_start) - 2));
}
}
bufer[--ind] = 'x';
bufer[--ind] = '0';
if (extra_c)
bufer[--ind] = extra_c;
return (write(1, &bufer[ind], BUFF_SIZE - ind - 1));
}

