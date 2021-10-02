/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 21:13:33 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 13:49:25 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_locate
{
	size_t	i;
	size_t	j;
}				t_index;

typedef struct s_flags
{
	t_bool	left;
	t_bool	zeroes;
	t_bool	dot_num;
	t_index	i_dot_num;
	t_bool	dot_star;
	t_bool	dot;
	t_bool	star;
	t_bool	star_dot;
	t_bool	star_dot_num;
	t_index	i_star_dot_num;
	t_bool	star_dot_star;
	t_bool	num_dot_star;
	t_index	i_num_dot_star;
	t_bool	num_dot;
	t_index	i_num_dot;
	t_bool	num_dot_num;
	t_index	i_num_dot_num;
	t_bool	check_combo;
	t_bool	check_all;
	t_bool	mwidth;
	t_index	i_mwidth;
	int		type_id;
	int		result;
	size_t	i;
	int		fd;
	t_bool	format_detected;
}				t_data;

typedef struct s_vars
{
	char			*str;
	char			*spaces;
	char			*zeroes;
	char			*ptr;
	int				str_width;
	int				min_width;
	int				precision;
	int				i;
	int				number;
	unsigned int	unumber;
	unsigned long	ulnumber;
	int				ptr_trigger;
	char			c;
	int				cap;
	t_bool			have_zero;
	t_bool			int_exception;
	t_bool			hex_exception;
	t_bool			negative_min_width;
	t_bool			negative_prec;
	t_bool			negative_max;
	t_bool			is_negative;
	t_bool			print_fail;
}				t_vars;

int				ft_dprintf(int fd, const char *format, ...);
char			*ft_chrrjoin(int c, char *str);
char			*ft_chrjoin(char *str, int c);
char			*ft_hexgen(unsigned int number, int capital);
char			*ft_hexgen_long(unsigned long number);
size_t			ft_strlen(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
int				ft_atoi(const char *num);
char			*ft_strdup(const char *s1);
int				ft_isdigit(int c);
int				print_and_free(char *str, int result, int fd);
void			wipe_struct(t_data *data);
void			print_fail(t_data *data, t_vars vars);
t_vars			vars_init(t_vars vars);
int				type_check(const char *format, size_t end);
int				check_all(t_data *data);
void			print_data(const char *format, t_data *data, va_list args);
void			check_zeroes(const char *format, t_data *data);
void			check_left(const char *format, t_data *data);
void			check_mwidth(const char *format, t_data *data);
void			check_dot(const char *format, t_data *data);
void			check_dot_num(const char *format, t_data *data);
void			check_dot_star(const char *format, t_data *data);
void			check_star(const char *format, t_data *data);
void			check_star_dot(const char *format, t_data *data);
void			check_star_dot_star(const char *format, t_data *data);
void			check_star_dot_num(const char *format, t_data *data);
void			check_num_dot(const char *format, t_data *data);
void			check_num_dot_num(const char *format, t_data *data);
void			check_num_dot_star(const char *format, t_data *data);
void			str_mwidth(t_vars vars, t_data *data);
t_vars			str_double_precision(t_data *data, t_vars vars);
t_vars			str_double_mwidth(t_data *data, t_vars vars);
void			p_str(const char *format, t_data *data, va_list args);
void			p_str_star_dot(t_data *data, va_list args);
void			p_str_star_dot_num(const char *format, \
t_data *data, va_list args);
void			p_str_num_dot_num(const char *format, \
t_data *data, va_list args);
void			p_str_num_dot_star(const char *format, \
t_data *data, va_list args);
void			p_str_star_dot_star(t_data *data, va_list args);
void			p_str_num_dot(const char *format, t_data *data, va_list args);
void			p_str_dot_num(const char *format, t_data *data, va_list args);
void			p_str_dot(t_data *data, va_list args);
void			p_c_dot_star(t_data *data, va_list args);
int				p_c_if_none(int result, va_list args, int fd);
void			p_char(const char *format, t_data *data, va_list args);
void			p_c_star(t_data *data, va_list args);
void			p_c_mwidth(const char *format, t_data *data, va_list args);
void			p_char_util_a(t_vars *vars, t_data *data);
t_vars			int_mwidth(t_data *data, t_vars vars);
t_vars			int_dot_num(t_vars vars);
t_vars			int_num_dot(t_data *data, t_vars vars);
t_vars			int_num_dot_num_b(t_vars vars);
t_vars			int_num_dot_num_c(t_data *data, t_vars vars);
t_vars			int_num_dot_num_a(t_vars vars);
t_vars			is_int_negative(t_vars vars);
char			*seek_last_number(t_vars vars);
t_vars			check_precision(t_vars vars);
t_vars			int_star_vars(t_vars vars, va_list args);
t_vars			int_ds_vars(t_vars vars, va_list args);
t_vars			int_sds_vars(t_vars vars, t_data *data, va_list args);
t_vars			int_sdn_vars(const char *format, t_vars vars, \
t_data *data, va_list args);
t_vars			int_nds_vars(t_vars vars, t_data *data, va_list args);
t_vars			int_mw_vars(const char *format, t_data *data, \
t_vars vars, va_list args);
t_vars			int_sd_vars(t_vars vars, va_list args);
t_vars			int_ndn_a_vars(t_vars vars);
void			p_int(const char *format, t_data *data, va_list args);
void			p_int_util_a(t_vars *vars, t_data *data);
void			p_int_util_b(t_vars *vars);
void			p_int_num_dot_num(const char *format, \
t_data *data, va_list args);
void			p_int_num_dot_star(const char *format, \
t_data *data, va_list args);
void			p_int_star_dot_num(const char *format, \
t_data *data, va_list args);
void			p_int_star_dot_star(t_data *data, va_list args);
void			p_int_dot_num(const char *format, t_data *data, va_list args);
void			p_int_dot_star(t_data *data, va_list args);
void			p_int_star(t_data *data, va_list args);
void			p_int_mwidth(const char *format, t_data *data, va_list args);
t_vars			uint_num_dot_num_a(t_vars vars);
t_vars			uint_mwidth(t_data *data, t_vars vars);
t_vars			uint_dot_num(t_vars vars);
t_vars			uint_num_dot(t_data *data, t_vars vars);
t_vars			uint_num_dot_num(t_vars vars);
void			p_uint(const char *format, t_data *data, va_list args);
void			p_uint_num_dot_num(const char *format, \
t_data *data, va_list args);
void			p_uint_num_dot_star(const char *format, \
t_data *data, va_list args);
void			p_uint_star_dot_num(const char *format, \
t_data *data, va_list args);
void			p_uint_star_dot_star(t_data *data, va_list args);
void			p_uint_mwidth(const char *format, t_data *data, va_list args);
void			p_uint_star(t_data *data, va_list args);
void			p_uint_dot_star(t_data *data, va_list args);
void			p_uint_dot_num(const char *format, t_data *data, va_list args);
void			switch_unegative(int *mwidth, t_data *data);
t_vars			uint_sd_vars(t_vars vars, t_bool *left, va_list args);
t_vars			hex_capital_check(t_vars vars, int capital);
t_vars			hex_sds_var(t_vars vars, t_bool *left, \
t_bool zeroes, va_list args);
t_vars			hex_sdn_var(const char *format, \
t_vars vars, va_list args, t_data *data);
t_vars			hex_nds_var(const char *format, \
t_vars vars, va_list args, t_data *data);
t_vars			hex_ndn_var(const char *format, \
t_vars vars, va_list args, t_data *data);
t_vars			hex_double_precision(t_vars vars);
t_vars			hex_double_mwidth(t_data *data, t_vars vars);
t_vars			hex_mwidth(t_data *data, t_vars vars);
t_vars			hex_dn(t_vars vars);
t_vars			hex_nd(t_data *data, t_vars vars);
void			p_hex(const char *format, t_data *data, va_list args, int cap);
void			p_hex_ndn(const char *format, \
t_data *data, va_list args, int cap);
void			p_hex_nds(const char *format, \
t_data *data, va_list args, int cap);
void			p_hex_sdn(const char *format, \
t_data *data, va_list args, int cap);
void			p_hex_sds(t_data *data, va_list args, int cap);
void			p_hex_nd(const char *format, \
t_data *data, va_list args, int cap);
void			p_hex_ds(t_data *data, va_list args, int cap);
void			p_hex_mwidth(const char *format, \
t_data *data, va_list args, int cap);
void			p_hex_star(t_data *data, va_list args, int cap);
void			p_hex_dn(const char *format, \
t_data *data, va_list args, int cap);
t_vars			ptr_double_check(t_data *data, t_vars vars);
t_vars			ptr_double_mwidth(t_data *data, t_vars vars);
t_vars			ptr_double_precision(t_vars vars);
t_vars			ptr_dot_num(t_vars vars);
t_vars			ptr_mwidth(t_data *data, t_vars vars);
t_vars			ptr_mwidth_if(t_vars vars, t_data *data);
void			p_ptr(const char *format, t_data *data, va_list args);
void			p_ptr_util_a(t_vars *vars);
void			p_ptr_mwidth(const char *format, t_data *data, va_list args);
void			p_ptr_star(t_data *data, va_list args);
void			p_ptr_num_dot(const char *format, t_data *data, va_list args);
void			p_ptr_star_dot(t_data *data, va_list args);
void			p_ptr_ndn(const char *format, t_data *data, va_list args);
t_vars			ptr_ndn_vars(char *str, t_vars vars, t_data *data, \
va_list args);
t_vars			ptr_nds_vars(char *str, t_vars vars, t_data *data, \
va_list args);
t_vars			ptr_sdn_vars(char *str, t_vars vars, t_data *data, \
va_list args);
t_vars			ptr_sds_vars(t_vars vars, t_data *data, va_list args);
t_vars			ptr_ds_vars(t_vars vars, va_list args);
void			p_ptr_dot_star(t_data *data, va_list args);
void			p_ptr_dot_num(const char *format, t_data *data, va_list args);
void			p_ptr_dot(t_data *data, va_list args);
void			p_pct(const char *format, t_data *data, va_list args);
int				print_char(char c, int fd);
int				print_str(char *s, int fd);
char			*smart_join(char *s1, char *s2);
void			switch_negative(int *mwidth, t_data *data);

#endif
