# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    count_files.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 16:29:24 by rlarbi            #+#    #+#              #
#    Updated: 2024/09/14 16:30:14 by rlarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/sh

find . -type f -or -type d | wc -l | tr -d " "
