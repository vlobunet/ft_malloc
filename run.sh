#!/bin/sh
clear  
printf "\n"
printf "\e[93m/* ************************************************************************** */\e[0m\n"
printf "\e[93m/*                                                                            */\e[0m\n"
printf "\e[93m/*\e[0m                                                        \e[97m:::      ::::::::\e[0m\e[25m   \e[93m*/\e[0m\n"
printf "\e[93m/*   \e[34mmalloc.c                                           \e[97m:+:      :+:    :+:\e[92m\e[25m \e[93m  */\e[0m\n"
printf "\e[93m/*\e[0m                                                    \e[97m+:+ +:+         +:+\e[92m\e[25m     \e[93m*/\e[0m\n"
printf "\e[93m/*\e[0m   \e[97mBy: vlobunet <marvin@42.fr>\e[39m                     \e[97m+#+  +:+       +#+\e[92m\e[25m       \e[93m*/\e[0m\n"
printf "\e[93m/*\e[0m                                                \e[97m+#+#+#+#+#+    +#+\e[92m\e[25m          \e[93m*/\e[0m\n"
printf "\e[93m/*\e[0m   \e[97mCreated: 2019/11/02 14:10:13 by \e[34mvlobunet\e[39m          \e[97m#+#    #+#\e[92m\e[25m             \e[93m*/\e[0m\n"
printf "\e[93m/*\e[0m   \e[97mUpdated: 2019/11/02 14:10:17 by \e[34mvlobunet\e[39m         \e[97m###   ########.fr\e[92m\e[25m       \e[93m*/\e[0m\n"
printf "\e[93m/*                                                                            */\e[0m\n"
printf "\e[93m/* ************************************************************************** */\e[0m\n"
printf "\n"
make -C . re
export DYLD_LIBRARY_PATH=.
export DYLD_INSERT_LIBRARIES="libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1

#gcc "$1" -L. -lft_malloc -o "ft_malloc"
