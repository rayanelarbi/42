/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:01:08 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/12 17:02:16 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(void)
// {
// 	int	fd;
// 	int	x;

// 	printf("Opening...\n");
// 	fd = open("myfifo", O_RDWR);
// 	if (fd == -1)
// 		return (2);
// 	printf("Opened\n");
// 	x = 97;
// 	if (write(fd, &x, sizeof(x)) == -1)
// 		return (1);
// 	printf("Writtend\n");
// 	close(fd);
// 	printf("closed\n");
// }

// int	main(void)
// {
// 	int	arr[] = {1, 2, 3, 1, 2, 4};
// 	int	sizeArr;
// 	int	fd[2];
// 	int	id;
// 	int	start;
// 	int	end;
// 	int	sum;
// 	int	i;

// 	sizeArr = sizeof(arr) / sizeof(int);

// 	if (pipe(fd) == -1)
// 		return (1);
// 	id = fork();
// 	if (id == -1)
// 		return (2);
// 	if (id == 0)
// 	{
// 		start = 0;
// 		end = sizeArr / 2;
// 	}
// 	else
// 	{
// 		start = sizeArr / 2;
// 		end = sizeArr;
// 	}
// 	sum = 0;
// 	for (i = start; i < end; i++)
// 	{
// 		sum += arr[i];
// 	}
// 	printf("Calcul is %d\n", sum);
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		if (write(fd[1], &sum, sizeof(sum)) == -1)
// 			return (3);
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		int sumChild;
// 		close(fd[1]);
// 		if (read(fd[0], &sumChild, sizeof(sumChild)) == -1)
// 			return (4);
// 		close(fd[0]);

// 		int	totalSum = sum + sumChild;
// 		printf("Total is : %d\n", totalSum);
// 		wait(NULL);
// 	}
// 	return (0);
// }
