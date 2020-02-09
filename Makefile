define MSG
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile for shared_libft                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/14 19:23:44 by arsciand          #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
endef

# Progress bar

ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL	=	make
%:
	  @$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T				:=	$(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
	  -nrRf $(firstword $(MAKEFILE_LIST)) \
	  ECHO="OutputPrintable" | grep -c "OutputPrintable")
N				:=	x
C				=	$(words $N)$(eval N := x $N)
V				=	"`expr "   [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
ECHO			=	printf "\e[1A\r%s %s %s                                      \n" $V
endif

# Color

RESET_C			=	\033[m
B_C				=	\033[0;34m
Y_C				=	\033[0;33m
G_C				=	\033[0;32m
R_C				=	\033[0;31m
M_C				=	\033[0;35m
C_C				=	\033[0;36

# Programms names

NAME			=	shared_libft.a

# Dir/Files Path

S_PATH			=	srcs/
H_PATH			=	includes/
B_PATH			=	build/
O_PATH			=	build/objs/
PRINTF			=	ft_printf/
PATHS			+=	$(B_PATH)
PATHS			+=	$(O_PATH)
PATHS			+=	$(O_PATH)$(PRINTF)

# Files

SRC				+=	$(S_PATH)ft_atoi.c
SRC				+=	$(S_PATH)ft_bzero.c
SRC				+=	$(S_PATH)ft_decade.c
SRC				+=	$(S_PATH)ft_get_options.c
SRC				+=	$(S_PATH)ft_getnextline.c
SRC				+=	$(S_PATH)ft_is_number.c
SRC				+=	$(S_PATH)ft_is_print.c
SRC				+=	$(S_PATH)ft_isalnum.c
SRC				+=	$(S_PATH)ft_isalpha.c
SRC				+=	$(S_PATH)ft_isblank.c
SRC				+=	$(S_PATH)ft_isdigit.c
SRC				+=	$(S_PATH)ft_isnum.c
SRC				+=	$(S_PATH)ft_isstart.c
SRC				+=	$(S_PATH)ft_itoa_base.c
SRC				+=	$(S_PATH)ft_itoa.c
SRC				+=	$(S_PATH)ft_itoabuf.c
SRC				+=	$(S_PATH)ft_lstappend.c
SRC				+=	$(S_PATH)ft_lstlen.c
SRC				+=	$(S_PATH)ft_lstnew.c
SRC				+=	$(S_PATH)ft_memalloc.c
SRC				+=	$(S_PATH)ft_memcpy.c
SRC				+=	$(S_PATH)ft_memdel.c
SRC				+=	$(S_PATH)ft_memset.c
SRC				+=	$(S_PATH)ft_putchar_fd.c
SRC				+=	$(S_PATH)ft_putchar.c
SRC				+=	$(S_PATH)ft_putnbr_fd.c
SRC				+=	$(S_PATH)ft_putnbr.c
SRC				+=	$(S_PATH)ft_putstr_fd.c
SRC				+=	$(S_PATH)ft_putstr.c
SRC				+=	$(S_PATH)ft_strcat.c
SRC				+=	$(S_PATH)ft_strchr.c
SRC				+=	$(S_PATH)ft_strclen.c
SRC				+=	$(S_PATH)ft_strcmp.c
SRC				+=	$(S_PATH)ft_strcpy.c
SRC				+=	$(S_PATH)ft_strdel.c
SRC				+=	$(S_PATH)ft_strdup.c
SRC 			+=	$(S_PATH)ft_strequ.c
SRC				+=	$(S_PATH)ft_strjoin.c
SRC				+=	$(S_PATH)ft_strjoinf.c
SRC				+=	$(S_PATH)ft_strlen_to.c
SRC				+=	$(S_PATH)ft_strlen.c
SRC				+=	$(S_PATH)ft_strlower.c
SRC				+=	$(S_PATH)ft_strncat.c
SRC				+=	$(S_PATH)ft_strncmp.c
SRC				+=	$(S_PATH)ft_strncpy.c
SRC				+=	$(S_PATH)ft_strnew.c
SRC				+=	$(S_PATH)ft_strrchr.c
SRC				+=	$(S_PATH)ft_strsplit.c
SRC				+=	$(S_PATH)ft_strstr.c
SRC				+=	$(S_PATH)ft_strsub_free.c
SRC				+=	$(S_PATH)ft_strsub.c
SRC				+=	$(S_PATH)ft_tabchr.c
SRC				+=	$(S_PATH)ft_tabcopy.c
SRC				+=	$(S_PATH)ft_tabdel.c
SRC				+=	$(S_PATH)ft_tabfree.c
SRC				+=	$(S_PATH)ft_tablen.c
SRC				+=	$(S_PATH)ft_tolower.c
SRC				+=	$(S_PATH)skip_options.c

SRC				+=	$(S_PATH)$(PRINTF)char_conv.c
SRC				+=	$(S_PATH)$(PRINTF)flags_handler.c
SRC				+=	$(S_PATH)$(PRINTF)float_conv.c
SRC				+=	$(S_PATH)$(PRINTF)ft_dprintf.c
SRC				+=	$(S_PATH)$(PRINTF)ft_nputchar.c
SRC				+=	$(S_PATH)$(PRINTF)ft_printf.c
SRC				+=	$(S_PATH)$(PRINTF)ft_wcharlen.c
SRC				+=	$(S_PATH)$(PRINTF)ft_wchartostr.c
SRC				+=	$(S_PATH)$(PRINTF)ft_wstrlen.c
SRC				+=	$(S_PATH)$(PRINTF)ft_wstrsub.c
SRC				+=	$(S_PATH)$(PRINTF)ft_wstrtostr.c
SRC				+=	$(S_PATH)$(PRINTF)memory_handler.c
SRC				+=	$(S_PATH)$(PRINTF)signed_conv.c
SRC				+=	$(S_PATH)$(PRINTF)str_conv.c
SRC				+=	$(S_PATH)$(PRINTF)unsigned_conv.c

# Objects and Headers

HDR				+=	shared_libft.h
HDR				+=	ft_printf.h

OBJ				=	$(patsubst $(S_PATH)%.c, $(O_PATH)%.o, $(SRC))
vpath %.h $(H_PATH)

# Variables

C_GCC			=	clang
COMPL			=	$(C_GCC) -c -I$(H_PATH)
BUILD			=	$(PATHS)
AR_RC			=	ar rc
RANLI			=	ranlib
CFLAG			=	-Wall -Wextra -Werror -g
RM_RF			=	/bin/rm -rf
MKDIR			=	mkdir -p
NORME			=	norminette
SLEEP			=	sleep 0.01
GCFIL			=	"- > Compiling	-"
GCLAR			=	"- } Archiving	-"
RMSHW			=	"- - Removing	-"
MKSHW			=	"- + Creating	-"
GCRUN			=	echo ">\n$(G_C)----->     Compiling$(RESET_C)\n"
CLRUN			=	echo ">\n$(R_C)----->     Cleaning$(RESET_C)\n"
NORMR			=	echo ">\n$(Y_C)----->     Norminette$(RESET_C)\n"

.PHONY: all norme clean fclean re test

# Rules

make:
#	$(MSG)
	@$(MAKE) --no-print-directory all

all: $(BUILD) $(NAME)

$(NAME): $(OBJ)
	@$(SLEEP)
	@$(AR_RC) $(NAME) $^
	@$(ECHO) $(GCLAR) $@
	@$(RANLI) $(NAME)

$(OBJ): $(O_PATH)%.o: $(S_PATH)%.c $(HDR)
	@$(COMPL) $(CFLAG) $< -o $@
	@$(ECHO) $(GCFIL) $<

$(PATHS):
	@$(SLEEP)
	@$(GCRUN)
	@$(MKDIR) $(PATHS)
	@$(foreach var,$(PATHS), $(ECHO) $(MKSHW) $(var);)

norme:
	@$(NORMR)
	@$(NORME) $(SRC) $(H_PATH)$(HNAME)
	@$(NORMD)

clean:
	@$(CLRUN)
	@for i in $(OBJ); do $(RM_RF) $$i; $(ECHO) $(RMSHW) $$i; done

fclean:
	@$(CLRUN)
	@for i in $(OBJ); do $(RM_RF) $$i; $(ECHO) $(RMSHW) $$i; done
	@for i in $(PATHS); do $(RM_RF) $$i; $(ECHO) $(RMSHW) $$i; done
	@$(RM_RF) $(NAME)
	@$(ECHO) $(RMSHW) $(NAME)

re:
	@$(MAKE) --no-print-directory fclean all

endif
