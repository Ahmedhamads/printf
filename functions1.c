#include "main.h"

int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = buff_size - 2;
unsigned long int num = va_arg(types, unsigned long int);
n = convert_size_unsgnd(n, size);
if (n == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (n > 0)
{
buffer[i--] = (n % 10) + '0';
n /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = n;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[buff_size - 1] = '\0';
while (n > 0)
{
buffer[i--] = (n % 8) + '0';
n /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}



int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}


int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}


int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = buff_size - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = n;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (n == 0)
buffer[i--] = '0';
buffer[buff_size - 1] = '\0';
while (n > 0)
{
buffer[i--] = map_to[n % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
