/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/01 08:26:34 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		handle_format(const char **format, int *bytes, va_list *p_vl);
int		check_format_sequence(const char *format);
char	get_arg_type(const char *format);
int		is_conv_specifier(char c);
int		ft_strlen(const char *s);
int		ft_isdigit(int c);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void *s1, const void *s2, unsigned int n);
void	get_flag(const char *format, char *flag);
int		get_width(const char *format);
int		ft_isdigit(int c);
void	ft_bzero(void *s, int n);
int		get_precision(const char *format);
char	*handle_hex1(char *flag, int width, int precision, unsigned int val);
char	*handle_hex2(char *flag, int width, int precision, unsigned int val);
char	*handle_int(char *flag, int width, int precision, int val);
char	*handle_char(char minus, int width, int val);
char	*handle_uint(char *flag, int width, int precision, unsigned int val);
void	put_precision(char *str, int precision);
void	put_width(char *str, int width, char hash, char minus);
void	put_zero(char *str);
int		get_u_int_len(unsigned int val);
int		get_hex_len(char hash, int width, int precision, unsigned int val);
void	put_hex(char *str, unsigned int val);
void	put_hash(char *str, char minus);
char	*handle_ptr(char minus, int width, unsigned long long val);
char	*handle_str(char minus, int width, int precision, char *val);
char	*handle_percent(int width, char zero, char minus);
int		check_char_null(const char *format, va_list *p_vl);
int		handle_char_null(const char **format, int *bytes);
int		get_char_len(int width);
void	print_space(int len);
int		handle_num_precision_zero(const char **format, int *bytes);
int		check_num_precision_zero(const char *format, va_list *p_vl);

#endif
