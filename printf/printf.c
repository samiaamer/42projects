#include <unistd.h>

int ft_print_string()
{

}


int	ft_printf(const char *format, ...)
{
  int i;
  int count;

  i = 0;
  count = 0;
  while (format[i] != '\0')
  {
    if (format[i] == '%')
    {
      i++;
      if (format[i] == 's')
      {
        count += ft_print_string()
      }
      if (format[i] == 'c')
      {
        write(1, &c, 1);
        count++;
      }
      if (format[i] == 'd' || 'i')
      {
        print integer
      }
      
      if (format[i] == 'p')
      {
        print pointer address
      }
      if (format[i] == 'x' || 'X')
      {
        print hexadecimal number
      }
    }
    else
    {
      write(1, &format[i], 1);
      count++;
    }
    i++;
  }
  return (count);
}