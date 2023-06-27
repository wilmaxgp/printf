#include "main.h"

/**
 * _printf - function that produces output according to a format
 * Description: function that produces output according to a format
 * @format: pointer to character string
 * 
 * Return: the number of characters printed excluding added NULL byte.
 *
 */
int _printf(const char *format, ...)
{
	int count;

	va_list args;
	va_start(args, format);

	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				while (*str != '\0')
					{
						putchar(*str);
						str++;
						count++;
					}
			}	
			else if (*format == '%')
			{
		       		putchar('%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				printf("%d", num);
				count++;
			}

		}
		else
			{
		 		putchar(*format);
		 		count++;
			}

		format++;

	}	


	va_end(args);
	return count;

}
