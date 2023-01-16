// File: impl.h
// Created by Diogo R. Roessler ( 2023 )
// Support implementation:
//  Diogo R. Roessler ( 2023 ) - Programmer


#ifndef IMPL_H
#define IMPL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct vec3 {
    double x,y,z;
} vec3 ;

vec3 impl_vec3_add(vec3 a, vec3 b)
{
    vec3 status = {a.x + b.x, a.y + b.y, a.z + b.z};
    return status;
}

vec3 impl_vec3_subtract(vec3 a, vec3 b)
{
    vec3 status = {a.x - b.x, a.y - b.y, a.z - b.z};
    return status;
}

vec3 impl_vec3_multiply(vec3 a, double scalar)
{
    vec3 status = {a.x * scalar, a.y * scalar, a.z * scalar};
    return status;
}

vec3 impl_vec3_divide(vec3 a, double scalar)
{
    vec3 status = {a.x / scalar, a.y /scalar, a.y / scalar};
    return status;
}

double impl_fabs(double a)
{
    if ( a < 0)
        return -a;
    return a;
}

double impl_sqrt(double a)
{
    double g = 1.0;
    double err = 0.0001;
    while (impl_fabs(g*g - a) >= err) {
        g = (g + a/g) /2;
    }
    return g;
}

double impl_vec3_magnitude(vec3 a)
{
    return impl_sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

size_t
impl_strlen(const char *str)
{
    size_t lenght = 0;
    while (str[lenght] != '\0') {
        lenght++;
    }
    return lenght;
}

static int impl_atoi(
        const char* str)
{
    int sign = 1, base = 0, i = 0;
    while ( str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+')
        sign = 1 - 2 * (str[i++] == '-');
    while ( str[i] >= '0' && str[i] <= '9' ) {
        if ( base > INT_MAX /10 || (base == INT_MAX / 10 && str[i] -'0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MAX;
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}

char
impl_toupper_char(char _ch)
{
    if ( _ch >= 'a' && _ch <= 'z' )
        return _ch - ('a' - 'A');
    return _ch;
}

void
impl_printf(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    while ( *format != '\0' ) {
        if (*format == '%') {

            format++;

            switch (*format) {
            case 'd': printf("%d", va_arg(args, int)); break;
            case 'c': printf("%c", (char) va_arg(args, int)); break;
            case 's': printf("%s", va_arg(args, char *)); break;
            default: putchar( *format ); break;
            }
        } else {
            putchar ( *format );
        }

        format++;
    }

    va_end(args);
}

#endif // IMPL_H
