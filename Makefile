# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 22:14:00 by hbouchet          #+#    #+#              #
#    Updated: 2019/10/16 13:39:56 by hbouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= avm


################################################################################


CC			= g++
CFLAGS		= -Wall -Wextra -Werror -std=c++11
CPPFLAGS	= -Iincludes
OPT			=

COLOR		= \033[31m
FINCOLOR	= \033[0m

SPY			=  


################################################################################


SRC_PATH	=	srcs

INC_PATH	=	includes

OBJ_PATH	=	obj

SRC_NAME	=   main.cpp LexerClass.cpp ExceptionClass.cpp TokenizerClass.cpp \
 				CalculatorClass.cpp Factory.cpp ValueClass.cpp \
 				AnalyzerClass.cpp ParserClass.cpp

INC_NAME	=	LexerClass.hpp ExceptionClass.hpp TokenizerClass.hpp \
				CalculatorClass.hpp Factory.hpp ParserClass.hpp IOperand.hpp \
				AnalyzerClass.hpp Operand.hpp eVerb.hpp eOperandType.hpp \
				ParserClass.hpp

OBJ_NAME	=	$(SRC_NAME:.cpp=.o)


################################################################################


SRC	= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ	= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC	= $(addprefix $(INC_PATH)/,$(INC_NAME))


################################################################################

ifeq ($(DEBUG), dev)
	CFLAGS = -std=c++11
endif
ifeq ($(DEBUG), info)
	CFLAGS += -g
endif

ifeq ($(DEBUG), dev)
	$(SPY)echo "================ Sans -W x3 + -std=c++11 ! ================"
else ifeq ($(ALLOC), info)
	$(SPY)echo "=========== Debug avec -g ! =========="
endif



################################################################################

all: $(NAME)

ifeq ($(DEBUG), yes)
	$(SPY)echo "================ DEBUG avec $(OPT) ! ================"
else ifeq ($(ALLOC), yes)
	$(SPY)echo "=========== ALLOC verification avec $(OPT) ! =========="
endif


$(OBJ_PATH): 
	$(SPY)mkdir $(OBJ_PATH) 2> /dev/null || true 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(INC)
	$(SPY)$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

$(NAME): $(OBJ_PATH) $(OBJ)
	$(SPY)$(CC) -o $(NAME) $(OBJ)


clean:
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)/bin/rm -rf $(NAME)

re: fclean all


.PHONY : all clean fclean re norme exec lib

################################################################################
