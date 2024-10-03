# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    r_dwssap.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 17:07:12 by rlarbi            #+#    #+#              #
#    Updated: 2024/09/14 17:47:33 by rlarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

cat /etc/passwd | grep -v '\#' | sed '1!n;d' | cut -d':' -f1 | rev | sort -r | awk 'NR>= ENVIRON["FT_LINE1"] && NR<= ENVIRON["FT_LINE2"]' | paste -s -d"," - | sed 's/,/, /g' | sed 's/$/./' | tr -d '\n'


