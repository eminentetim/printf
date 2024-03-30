#include "main.h"
#include <stdio.h>
/**
 * _rec_number - recursive number
 * @num: variable
 * @count: pointer
 * Return: int
 */
int _rec_number(int num, int *count)
{
	if (num == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		*count += 2;
		_rec_number(147483648, count);
		return (0);
	}
	else if (num < 0)
	{
		_putchar('-');
		*count += 1;
		num *= (-1);
	}
	if (num >= 10)
	{
		_rec_number(num / 10, count);
		_putchar((num % 10) + '0');
		*count += 1;
	}
	else if (num < 10)
	{
		_putchar(num + '0');
		*count += 1;
	}
	return (0);
}
/**
 * _printf_string - print string
 * @tmp: pointer
 * Return: int
 */
int _printf_string(char *tmp)
{
	int res = 0, i;
	char *null = "(null)";

	if (tmp == NULL)
	{
		for (i = 0; *(null + i) != '\0'; i++)
		{
			_putchar(*(null + i));
			res++;
		}
	}
	else
	{
		for (i = 0; tmp[i] != '\0'; i++)
		{
			_putchar(tmp[i]);
			res++;
		}
	}
	return (res);
}
/**
 * _printf_binary - print stri
 * @num: variable
 * @count: pointer
 * Return: int
 */
int _printf_binary(unsigned int num, int *count)
{
	int binary[64] = {0};
	int j, i = 0;

	if (num == 0)
	{
		_putchar('0');
		(*count)++;
		return (0);
	}
	while (num > 0)
	{
		binary[i] = num & 1;
		num = num >> 1;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_printf("%d", binary[j]);
		(*count)++;
	}
	return (0);
}
/**
 * _printf_helper - function that produces output according to a format
 * @format: character string - composed of zero or more directives.
 * @arg: character string - composed of zero or more directives.
 * @i: character string - composed of zero or more directives.
 * Return:  the number of characters printed without null
 */
int _printf_helper(const char *format, va_list arg, int *i)
{
	int res = 0, num;
	char *tmp;

	switch (*(format + *i + 1))
	{
	case 's':
		tmp = va_arg(arg, char *);
		res += _printf_string(tmp);
		break;
	case 'c':
		_putchar(va_arg(arg, int));
		res++;
		break;
	case '%':
		_putchar(format[*i]);
		res++;
		break;
	case 'i':
	case 'd':
		num = va_arg(arg, int);
		_rec_number(num, &res);
		break;
	case 'b':
		num = va_arg(arg, int);
		_printf_binary(num, &res);
		break;
	default:
		_putchar(format[*i]);
		res++;
		*i -= 1;
		break;
	}
	*i += 1;
	return (res);
}
/**
 * _printf - function that produces output according to a format
 * @format: character string - composed of zero or more directives.
 * Return:  the number of characters printed without null
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);
	for (i = 0; *(format + i) != '\0'; i++)
	{
		if (*(format + i) == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			count += _printf_helper(format, arg, &i);
		}
		else
		{
			_putchar(*(format + i));
			count++;
		}
	}
	va_end(arg);
	return (count);
}
