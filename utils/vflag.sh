# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vflag.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 13:21:27 by parkjaekw         #+#    #+#              #
#    Updated: 2021/05/08 22:19:16 by parkjaekw        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! bin/bash

ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG

