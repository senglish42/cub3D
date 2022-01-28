/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:29:39 by svirgil           #+#    #+#             */
/*   Updated: 2021/10/16 14:30:11 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# if __linux__
# define KEY_ESC		65307
# define KEY_UP			65362
# define KEY_RIGHT		65363
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_NUM_PLUS	65451
# define KEY_NUM_MINUS	65453
# define KEY_NUM_2		65433
# define KEY_NUM_4		65430
# define KEY_NUM_8		65431
# define KEY_NUM_6		65432

# else

# define KEY_ESC		53
# define KEY_UP			13
# define KEY_RIGHT		2
# define KEY_DOWN		1
# define KEY_LEFT		0

#endif

#endif