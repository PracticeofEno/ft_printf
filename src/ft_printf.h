/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 04:39:04 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/23 07:38:54 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_fm
{
	char		*str;
	int			minus;
	int			zero;
	int			dot;
	int			mul;
	int			width;
	int			precision;
	int			type;
	char		*converted;
	struct s_fm	*next;
}				t_fm;

int				ft_printf(const char *str, ...);
bool			is_minus_option(char c);
bool			is_zero_option(char c);
bool			is_dot_option(char c);
bool			is_mul_option(char c);
char			*ft_itoa(int n);
bool			is_type(char c);
int				ft_toupper(int n);
int				ft_tolower(int n);
void			ft_lst_clear(t_fm *lst);
int				ft_lstsize(t_fm *lst);
t_fm			*ft_lstlast(t_fm *lst);
void			ft_lstadd_back(t_fm **list, t_fm *nw);
void			setting_option(t_fm *format, char c, va_list *ap);
char			*converting(t_fm *format, va_list *ap);
t_fm			*make_format(const char *str, int *count);
t_fm			*get_format(const char *str);
void			va_setting(t_fm *format, va_list ap);
void			flag_setting(t_fm *format, va_list *ap);
char			*make_string_c(t_fm *format, va_list *ap);
char			*make_string_d(t_fm *format, va_list *ap);
char			*make_string_s(t_fm *format, va_list *ap);
char			*make_string_p(t_fm *format, va_list *ap);
char			*make_string_u(t_fm *format, va_list *ap);
char			*make_string_x(t_fm *format, va_list *ap);
char			*make_string_x2(t_fm *format, va_list *ap);
char			*make_string_i(t_fm *format, va_list *ap);
char			*make_string_per(t_fm *format, va_list *ap);
int				fill_width(char *arr, int start_index, int size, char c);
int				fill_precision(char *arr, int start_index, int precision_size);
int				get_precision_size(t_fm *format, char *number);
void			fill_left_normal(char *arr, char *number, t_fm *format);
void			fill_left_width(char *arr, char *number, t_fm *format);
void			fill_left_width_precision(char *arr, char *number, t_fm *d);
void			fill_left_precision(char *arr, char *number, t_fm *format);
void			fill_right_normal(char *arr, char *number, t_fm *format);
void			fill_right_width(char *arr, char *number, t_fm *format);
void			fill_right_width_precision(char *arr, char *number, t_fm *d);
void			fill_right_precision(char *arr, char *number, t_fm *format);
void			p_left_normal(char *arr, char *number, t_fm *format);
void			p_left_width(char *arr, char *number, t_fm *format);
void			p_left_width_precision(char *arr, char *number, t_fm *d);
void			p_left_precision(char *arr, char *number, t_fm *format);
void			p_right_normal(char *arr, char *number, t_fm *format);
void			p_right_width(char *arr, char *number, t_fm *format);
void			p_right_width_precision(char *arr, char *number, t_fm *d);
void			p_right_precision(char *arr, char *number, t_fm *format);
int				gp_size(char *number, int precision, t_fm *format);
int				fill_content(char *arr, int b, char *c);
int				fill_content2(char *arr, int si, char *content, t_fm *format);
bool			check_minus(char *arr, char **number, int *i, bool *minus);
void			set_width(t_fm *format, char *number);
int				get_presize(t_fm *format, char *number);
char			*gm_c(t_fm *format);
char			*gm_i(t_fm *format, char *number);
char			*gm_p(t_fm *format, char *number);
int				result_size(char *str, t_fm *lst);
int				all_converted_size(t_fm *lst);
#endif
