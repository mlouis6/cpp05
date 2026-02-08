# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 13:03:16 by mlouis            #+#    #+#              #
#    Updated: 2026/02/08 13:11:16 by mlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := except.out

SRCS := Bureaucrat.cpp main.cpp
INCS := .
OBJS := $(SRCS:%.cpp=%.o)
DEPS := $(OBJS:.o=.d)

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := $(addprefix -I,$(INCS)) -MMD -MP
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean:
	rm -rf $(OBJS) $(DEPS)
	rm -f $(NAME)

re: fclean
	$(MAKE) all
	