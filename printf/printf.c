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
  if (n == -2147483648)
		return (11);
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
int ft_print_unsigned(unsigned int num)
{
  int count;

  count = 0;
  if (num >= 10)
    count += ft_print_interger(num / 10);
  count += ft_print_char(num % 10 + '0');
  return (count);
  
}
int ft_print_pointer()
{
}
int ft_print_hex(unsigned int num, char specifier)
{
  int count;
  char *hex_dig;

  count = 0;
  if (num == 0)
    count += write(1, "0", 1);//////////////////////////
  
  if (specifier == 'x')
    hex_dig = "0123456789abcdef";
  else
    hex_dig = "0123456789ABCDEF";
  if (num >= 16)
    count += ft_print_hex(num / 16, specifier);
  count += ft_print_char(hex_dig[num % 16]);
  return (count);
}
int handle_format(char format, va_list args)
{
  if (format == 's')
    return ft_print_string(va_arg(args, char *));
  else if (format == 'c')
    return ft_print_char(va_arg(args, int));
  else if (format == 'd' || format[i] == 'i')
    return ft_print_integer(va_arg(args, int));
  else if (format == 'p')
    return ft_print_pointer(va_arg(args, void *));
  else if (format == 'x' || format[i] == 'X')
    return ft_print_hex(va_arg(args, unsigned int), format[i]);
  else if (format == 'u')
    return ft_print_unsigned(va_arg(args, unsigned int));
  else if (format == '%')
    return write (1, '%', 1);
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
      count += handle_format(format[++i], args);
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
