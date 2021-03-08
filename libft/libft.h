/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:47:32 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/23 06:57:34 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *str, size_t size);
size_t			ft_strlcpy(char *dst, const char *str, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_atoi(char *str, int *va);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcat(char *s1, const char *s2);
void			ft_putnbr(int number);
void			ft_putstr(char *str);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *s1, const char *s2);
int				ft_tolower(int n);
int				ft_toupper(int n);
char			*ft_strchr(const char *s, int n);
char			*ft_strrchr(const char *s, int n);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
int				ft_isalpha(int n);
int				ft_isdigit(int n);
int				ft_isalnum(int n);
int				ft_isprint(int n);
int				ft_isascii(int n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *mem, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t len);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t count);
void			*ft_memccpy(void *dest, const void *src, int c, size_t len);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(const char *s, int fd);
char			**ft_split(char *s, char s2);
char			*ft_strjoin(const char *s, const char *s2);
char			*ft_itoa(int n);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s, const char *delset);
char			*ft_itoa_hex(long long n);
char			*ft_itoa_x(long long n);
char			*ft_itoa_u(unsigned int n);
char			*ft_replace_star(char *src, char *match);
void			free_buffer(char **sbuffer);

#endif
