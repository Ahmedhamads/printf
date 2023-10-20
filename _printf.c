#include "main.h"
void print_bufer(char bufer[], int *buff_size)
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char bufer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
bufer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_bufer(bffer, &buff_ind);
/* write(1, &format[i], 1);*/
printed_chars++;
}
else
{
print_bufer(bufer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, bufer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_bufer(bufer, &buff_ind);
va_end(list);
return (printed_chars);
}


void print_bufer(char bufer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &bufer[0], *buff_ind);
*buff_ind = 0;
}
