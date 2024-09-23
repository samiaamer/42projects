#include <unistd.h>
#include <stdarg.h>

int ft_print_string(const char *str)
{
  int count;

  count = 0;
  if (!str)
    return (0);
  while (str[count])
  {
    write (1, &str[count], 1);
    count++;
  }
  return (count);
}
int ft_print_char(char c)
{
  write (1, &c, 1);
  return (1);
}
int ft_print_interger(int num)
{
  int count;

  count = 0;
  if (num < 0)
  {
    write (1, "-", 1);
    num = -num;
    return (1 + ft_print_interger(num));
  }
  if (num >= 10)
    count += ft_print_interger(num / 10);
  count += ft_print_char(num % 10 + '0');
  return (count);
}
int ft_print_pointer()
{
}
int	ft_printf(const char *format, ...)
{
  int i;
  int count;
  va_list  args;

  i = 0;
  count = 0;
  va_start(args, format);
  while (format[i] != '\0')
  {
    if (format[i] == '%')
    {
      i++;
      if (format[i] == 's')
        count += ft_print_string(va_arg(args, char *));
      else if (format[i] == 'c')
        count += ft_print_char(va_arg(args, int));
      else if (format[i] == 'd' || format[i] == 'i')
        count += ft_print_integer(va_arg(args, int));
      else if (format[i] == 'p')
        count += ft_print_pointer(va_arg(args, void *));
      else if (format[i] == 'x' || 'X')
        print hexadecimal number
    }
    else
    {
      write(1, &format[i], 1);
      count++;
    }
    i++;
  }
  va_end(args);
  return (count);
}