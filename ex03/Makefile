# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 00:19:22 by ayarmaya          #+#    #+#              #
#    Updated: 2025/05/18 21:02:30 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= bureaucrat
CC				:= c++
CFLAGS			:= -Wall -Wextra -Werror -std=c++98 -MMD -MP
LDFLAGS			:= -std=c++98 -MMD -MP
RM				:= rm -f
RMDIR 			:= rm -rf
INCDIR 			:= include
HEADERS 		:= -I./$(INCDIR)
SRCDIR			:= src
SRCS			:= $(SRCDIR)/main.cpp \
        		   $(SRCDIR)/Bureaucrat.cpp \
				   $(SRCDIR)/AForm.cpp \
				   $(SRCDIR)/PresidentialPardonForm.cpp \
				   $(SRCDIR)/RobotomyRequestForm.cpp \
				   $(SRCDIR)/ShrubberyCreationForm.cpp \
				   $(SRCDIR)/Intern.cpp

OBJDIR 			:= obj
OBJS 			:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))
DEPS 			:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.d, $(SRCS))

all 			: $(NAME)

$(NAME) 		: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o 	: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(RMDIR) $(OBJDIR)

fclean 			: clean
	$(RM) $(NAME)

re 				: fclean all

-include $(DEPS)

.PHONY 			: all clean fclean re