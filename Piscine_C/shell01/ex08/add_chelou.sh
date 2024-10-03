# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    add_chelou.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 17:29:55 by rlarbi            #+#    #+#              #
#    Updated: 2024/09/14 17:53:29 by rlarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

FT_NBR1=\'?"\"'\
FT_NBR2=rcrdmddd

cat /etc/passwd | awk -F: 'NR%2==0' | awk -F: '{print $1}' | awk '{print substr($0, length($0), 1) substr($0, 1, length($0)-1)}' | sort -r | awk "NR >= $FT_NBR1 && NR <= $FT_NBR2" | paste -sd', ' - | sed 's/$/./'
