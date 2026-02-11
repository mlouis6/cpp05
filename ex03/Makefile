# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 13:03:16 by mlouis            #+#    #+#              #
#    Updated: 2026/02/11 10:21:15 by mlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean cleanshr re

NAME := except.out

CL_DIR := class/
SRCS_DIR := src/
OBJS_DIR := .build/

BUREAUCRAT_DIR := $(addprefix $(CL_DIR), bureaucrat/)
BUREAUCRAT_CL := Bureaucrat.cpp Intern.cpp

FORM_DIR := $(addprefix $(CL_DIR), form/)
FORM_CL := AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

P_BUREAUCRAT := $(addprefix $(BUREAUCRAT_DIR), $(BUREAUCRAT_CL))
P_FORM := $(addprefix $(FORM_DIR), $(FORM_CL))

P_MAIN := $(addprefix $(SRCS_DIR), main.cpp)

SRCS := $(P_BUREAUCRAT) $(P_FORM) $(P_MAIN)
INCS := $(BUREAUCRAT_DIR) $(FORM_DIR)
OBJS := $(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.o))
DEPS := $(addprefix $(OBJS_DIR), $(OBJS:.o=.d))

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := $(addprefix -I,$(INCS)) -MMD -MP
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJS_DIR)

fclean:
	rm -rf $(OBJS_DIR)
	rm -f $(NAME)

cleanshr:
	rm -f *_shrubbery

re: fclean
	$(MAKE) all
	