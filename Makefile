##
## Makefile for Makefile in /home/ninon_s/
##
## Made by simon ninon
## Login   <ninon_s@epitech.net>
##
## Started on  Mon Oct 22 15:50:18 2012 simon ninon
## Last update Sat Mar 30 17:49:47 2013 simon ninon
##

ASM_FOLDER	=	asm
VM_FOLDER	=	vm
LIB_FOLDER	=	lib

SRC_VM		=	$(VM_FOLDER)/src/main.c					\
			$(VM_FOLDER)/src/init/check_cmd.c			\
			$(VM_FOLDER)/src/init/data_champ.c			\
			$(VM_FOLDER)/src/init/init_structs.c			\
			$(VM_FOLDER)/src/init/insert_champ.c			\
			$(VM_FOLDER)/src/init/linked_list.c			\
			$(VM_FOLDER)/src/battle/convert.c			\
			$(VM_FOLDER)/src/battle/battle.c			\
			$(VM_FOLDER)/src/battle/check.c				\
			$(VM_FOLDER)/src/battle/args.c				\
			$(VM_FOLDER)/src/battle/dump.c				\
			$(VM_FOLDER)/src/battle/functs_1.c			\
			$(VM_FOLDER)/src/battle/functs_2.c			\
			$(VM_FOLDER)/src/battle/functs_3.c			\
			$(VM_FOLDER)/src/battle/functs_4.c			\
			$(VM_FOLDER)/src/battle/gimme_instruction.c		\
			$(VM_FOLDER)/src/battle/gimme_value.c			\
			$(VM_FOLDER)/src/battle/convert_negative.c

SRC_ASM		=	$(ASM_FOLDER)/src/main.c				\
			$(ASM_FOLDER)/src/verif/verif_file.c			\
			$(ASM_FOLDER)/src/verif/verif_label.c			\
			$(ASM_FOLDER)/src/parser/check_line.c			\
			$(ASM_FOLDER)/src/parser/linked_list.c			\
			$(ASM_FOLDER)/src/parser/op.c				\
			$(ASM_FOLDER)/src/parser/stock_header.c			\
			$(ASM_FOLDER)/src/parser/stock_label.c			\
			$(ASM_FOLDER)/src/generate/gen_corfile.c		\
			$(ASM_FOLDER)/src/generate/append_corfile.c		\
			$(ASM_FOLDER)/src/generate/instructions.c

SRC_LIB		=	$(LIB_FOLDER)/my_putstr.c				\
			$(LIB_FOLDER)/my_putchar.c				\
			$(LIB_FOLDER)/my_strlen.c				\
			$(LIB_FOLDER)/my_printf.c				\
			$(LIB_FOLDER)/flags.c					\
			$(LIB_FOLDER)/my_getnbr.c				\
			$(LIB_FOLDER)/my_put_nbr.c				\
			$(LIB_FOLDER)/my_strcmp.c				\
			$(LIB_FOLDER)/get_next_line.c				\
			$(LIB_FOLDER)/buffer.c					\
			$(LIB_FOLDER)/my_strdup.c				\
			$(LIB_FOLDER)/my_strcat.c				\
			$(LIB_FOLDER)/my_strcpy.c				\
			$(LIB_FOLDER)/my_append.c				\
			$(LIB_FOLDER)/my_isalpha.c				\
			$(LIB_FOLDER)/my_isnum.c				\
			$(LIB_FOLDER)/my_memset.c				\
			$(LIB_FOLDER)/my_trim_comment_end.c			\
			$(LIB_FOLDER)/my_epur_str.c				\
			$(LIB_FOLDER)/my_str_to_wordtab.c			\
			$(LIB_FOLDER)/my_detect_sep.c				\
			$(LIB_FOLDER)/my_free_tab.c				\
			$(LIB_FOLDER)/my_size_tab.c				\
			$(LIB_FOLDER)/my_trim.c					\
			$(LIB_FOLDER)/my_aff_error.c				\
			$(LIB_FOLDER)/my_aff_warning.c				\
			$(LIB_FOLDER)/x_functions.c				\
			$(LIB_FOLDER)/my_check.c

SRC_LOADING	=	makefile_deco/loading.c

OBJ_VM		=	$(SRC_VM:.c=.o)
OBJ_ASM		=	$(SRC_ASM:.c=.o)
OBJ_LIB		=	$(SRC_LIB:.c=.o)
OBJ_LOADING	=	$(SRC_LOADING:.c=.o)

NAME_VM		=	$(VM_FOLDER)/corewar
NAME_ASM	=	$(ASM_FOLDER)/asm
NAME_LIB	=	$(LIB_FOLDER)/libmy.a
NAME_LOADING	=	makefile_deco/loading

GREEN		=	\033[1;32m
CYAN		=	\033[1;36m
WHITE		=	\033[0m
RED		=	\033[1;31m

CFLAGS		+=	-Iinclude

all:			$(NAME_LIB) $(NAME_VM) $(NAME_ASM)

$(NAME_VM):		$(OBJ_VM)
			@echo -e "$(RED)\n > COMPILATION .C VM EN COURS\n"
			@echo -e "$(WHITE)"
			@./makefile_deco/loading
			cc -o $(NAME_VM) $(OBJ_VM) -lmy -L $(LIB_FOLDER)
			@echo -e "$(GREEN)\n > COMPILATION .C VM TERMINEE"
			@echo -e "$(WHITE)"

$(NAME_ASM):		$(OBJ_ASM)
			@echo -e "$(RED)\n > COMPILATION .C ASM EN COURS\n"
			@./makefile_deco/loading
			cc -o $(NAME_ASM) $(OBJ_ASM) -lmy -L $(LIB_FOLDER)
			@echo -e "$(GREEN)\n > COMPILATION .C ASM TERMINEE"
			@echo -e "$(CYAN)"
			@cat makefile_deco/header
			@echo -e "$(WHITE)"
			@cat makefile_deco/using
			@echo -e "$(GREEN)"
			@cat makefile_deco/logins
			@echo -e "$(WHITE)"

$(NAME_LIB):		$(OBJ_LIB) $(OBJ_LOADING)
			cc -o $(NAME_LOADING) $(OBJ_LIB) $(OBJ_LOADING)
			@echo -e "$(RED)\n > COMPILATION LIB EN COURS\n"
			@./makefile_deco/loading
			ar rc $(NAME_LIB) $(OBJ_LIB)
			ranlib $(NAME_LIB)
			@echo -e "$(GREEN)\n > COMPILATION LIB TERMINEE$(WHITE)\n"

clean:
			@echo -e "\n$(RED)\t->>> SUPPRESSION DES .o <<<-\n$(WHITE)"
			rm -f $(OBJ_VM)
			rm -f $(OBJ_ASM)
			rm -f $(OBJ_LIB)
			rm -f $(OBJ_LOADING)

fclean:			clean
			@echo -e "\n$(RED)\t->>> SUPPRESSION DU BIN + LIB <<<-\n$(WHITE)"
			rm -f $(NAME_VM)
			rm -f $(NAME_ASM)
			rm -f $(NAME_LIB)
			rm -f $(NAME_LOADING)

re:			fclean all

coffee:
			@echo -e "$(CYAN)"
			@cat makefile_deco/coffee_cup
			@echo -e "$(WHITE)"

.PHONY:			all clean fclean re
