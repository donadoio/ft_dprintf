# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: idonado <idonado@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 12:23:24 by idonado       #+#    #+#                  #
#    Updated: 2020/07/07 01:23:56 by idonado       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftdprintf.a

SRC = 	ft_atoi.c\
		ft_chrjoin.c\
		ft_chrrjoin.c\
		ft_hexgen.c\
		ft_hexgen_long.c\
		ft_itoa.c\
		ft_itoa_unsigned.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_isdigit.c\
		check_all.c\
		check_dot_num.c\
		check_dot_star.c\
		check_dot.c\
		check_left.c\
		check_mwidth.c\
		check_num_dot_num.c\
		check_num_dot_star.c\
		check_star_dot.c\
		check_star.c\
		check_num_dot.c\
		check_star_dot_num.c\
		check_star_dot_star.c\
		check_zeroes.c\
		ft_printf_utils_a.c\
		ft_printf_utils_b.c\
		ft_printf_utils_c.c\
		ft_dprintf.c\
		p_char.c\
		p_char_utils_a.c\
		p_char_utils_b.c\
		p_hex.c\
		p_hex_utils_a.c\
		p_hex_utils_b.c\
		p_hex_utils_c.c\
		p_hex_utils_d.c\
		p_int.c\
		p_int_utils_a.c\
		p_int_utils_b.c\
		p_int_utils_c.c\
		p_int_utils_d.c\
		p_int_utils_e.c\
		p_int_utils_f.c\
		p_pct.c\
		p_ptr.c\
		p_ptr_utils_a.c\
		p_ptr_utils_b.c\
		p_ptr_utils_c.c\
		p_ptr_utils_d.c\
		p_ptr_utils_e.c\
		p_str.c\
		p_str_utils_a.c\
		p_str_utils_b.c\
		p_str_utils_c.c\
		p_uint.c\
		p_uint_utils_a.c\
		p_uint_utils_b.c\
		p_uint_utils_c.c

OBJ := $(SRC:.c=.o)
HDR = ft_dprintf.h
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rcs $@ $^
	@echo "\033[1m\033[32mft_dprintf library successfully built\033[39m"

%.o: %.c $(HDR)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@$(RM) $(OBJ)
	@echo "\033[1m\033[33mDeleted  Object Files\033[39m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1m\033[31mDeleted Objects and Executables\033[39m"

re: fclean all

.PHONY: all clean fclean re ft_printf
