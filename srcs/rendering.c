#include "cub3D.h"

unsigned int wall(t_img *image, int j, int x)
{
	return (*(unsigned int *)(image->addr + (j * image->line_length + x * \
	image->bits_per_pixel / 8)));
}

unsigned int f_c(int rgb[3])
{
	return(rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	do_color(t_img *image, int x, int y, unsigned int color)
{
	my_mlx_pixel_put(image, x, y, color);
}

void	find_ratio(t_game *game, t_rend *rend)
{
    double difx;
    double dif1;
    double dify;
//
	while (rend->hit == 0 && rend->dist_to_wall < 10)
	{
		rend->x_dir_del = (game->player.posx + rend->x_dir * rend->dist_to_wall);
		rend->y_dir_del = (game->player.posy - rend->y_dir * rend->dist_to_wall);
		if (game->map.size[(int) rend->y_dir_del][(int) rend->x_dir_del] == '1')
			rend->hit = 1;
		else
			rend->dist_to_wall += 0.0005;
	}
    rend->size_wall = game->image.screen_h / rend->dist_to_wall / cos(rend->dif_a);
    if (rend->size_wall > game->image.screen_h)
        rend->size_wall = game->image.screen_h;
    rend->ceil = (game->image.screen_h - rend->size_wall) / 2;
    rend->floor = (rend->ceil + rend->size_wall);
    if (!rend->dif_a)
        rend->straight = rend->dist_to_wall;
//    printf("%f %f %d %d\n", rend->x_dir_del, rend->y_dir_del,
//           (int)(rend->y_dir_del
//    - 0.05), (int)(rend->y_dir_del));
//    printf("before before %f %f\n", rend->x_dir_del, rend->y_dir_del);
    difx = fabs((rend->x_dir_del - (int)rend->x_dir_del));
    dif1 = fabs(rend->x_dir_del - (int)(rend->x_dir_del + 1));
    if (dif1 < difx)
        difx = dif1;
    dify = fabs((rend->y_dir_del - (int)rend->y_dir_del));
    dif1 = fabs(rend->y_dir_del - (int)(rend->y_dir_del + 1));
    if (dif1 < dify)
        dify = dif1;
//    printf("%f %f\n", difx, dify);
//    if (difx < dify || difx + dify < 0.001)
//    {
//    if ((int) (rend->x_dir_del + 0.05) != (int) (rend->x_dir_del) &&
//        (int)(rend->x_dir_del + 0.05) <= game->map.width)
//            rend->x_dir_del = (int) (rend->x_dir_del);
//    else if ((int) (rend->x_dir_del - 0.05) != (int) (rend->x_dir_del) &&
//                 (int) (rend->x_dir_del - 0.05) >= 0)
//            rend->x_dir_del = (int) (rend->x_dir_del);
//    else
//        rend->x_dir_del = (int)rend->x_dir_del;
////    }
////    if (difx > dify || difx + dify < 0.001)
////{
//       if ((int)(rend->y_dir_del + 0.05) != (int)(rend->y_dir_del) &&
//            (int)(rend->y_dir_del + 0.05) <= game->map.height)
//            rend->y_dir_del = (int)(rend->y_dir_del);
//       else if ((int)(rend->y_dir_del - 0.05) != (int)(rend->y_dir_del)
//            && (int)(rend->y_dir_del - 0.05) >= 0)
//            rend->y_dir_del = (int)(rend->y_dir_del);
//       else
//           rend->y_dir_del = (int)rend->y_dir_del;
//    }
//    else
//        rend->y_dir_del = (int) rend->y_dir_del;
}

double	check_rad(double angle)
{
	if (angle > 2 * PI)
		angle -= 2 * PI;
	else if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

void	init_rend(t_game *game, t_rend *rend, int x)
{
	rend->hit = 0;
	rend->dist_to_wall = 0;
	rend->straight = -1;
	rend->ray_a = x * VA / game->image.screen_w;
	rend->ray_a_h = (game->player.da + VA / 2) - rend->ray_a;
	rend->dif_a = game->player.da - rend->ray_a_h;
	rend->dif_a = check_rad(rend->dif_a);
	rend->y_dir = sin(rend->ray_a_h);
	rend->x_dir = cos(rend->ray_a_h);
	rend->x_dir_del = 0;
	rend->y_dir_del = 0;
}

//void    north_path(t_game *game, t_rend *rend)
//{
//    if ((int)(rend.y_dir_del + 1) <= game->map.height &&
//        rend.y_dir_del >= game->player.posy && game->map
//                                                       .size[(int)
//            (rend
//                     .y_dir_del + 1)][
//                                                       (int)
//                                                               (rend
//                                                                       .x_dir_del)] != '1'
//        && (rend.x_dir_del / (int)rend.x_dir_del != 1 || rend.y_dir_del / (int)rend.y_dir_del != 1))
//    {
//        do_color(&game->image, (int) x, (int) y++, \
//                        wall(&game->path[0], (int) j, (int) x));
//        j += (double) game->path[0].screen_h /
//             (double) rend.size_wall;
//        c = 0;
//}

void	make_3d(t_game *game)
{
	t_rend	rend[game->image.screen_w];
//    const char valid[5] = "0NSWE";
	int x;
    double a;
    double b;
    int     c;
    int     cnt;

    a = -1;
    b = -1;
    c = -1;
	x = -1;
    while(++x < game->image.screen_w)
    {
        init_rend(game, &rend[x], x);
        find_ratio(game, &rend[x]);

//        if (x > 0)
//        {
//            if ((int)rend[x].y_dir_del > (int)rend[x - 1].y_dir_del)
//            {
//                double d;
//                double e;
//
//                d = rend[x].y_dir_del - (int)rend[x].y_dir_del;
//                e = (int)rend[x - 1].y_dir_del + 1 - rend[x - 1].y_dir_del;
//                if (d > e)
//                    rend[x - 1].y_dir_del = rend[x - 1].y_dir_del + e;
//                else
//                    rend[x].y_dir_del = rend[x].y_dir_del - d;
//            }
//            else if ((int)rend[x].y_dir_del < (int)rend[x - 1].y_dir_del)
//            {
//                double d;
//                double e;
//
//                d = rend[x - 1].y_dir_del - (int)rend[x - 1].y_dir_del;
//                e = (int)rend[x].y_dir_del + 1 - rend[x].y_dir_del;
//                if (d > e)
//                    rend[x].y_dir_del = rend[x].y_dir_del + e;
//                else
//                    rend[x - 1].y_dir_del = rend[x - 1].y_dir_del - d;
//            }
//            if ((int)rend[x].x_dir_del > (int)rend[x - 1].x_dir_del)
//            {
//                double d;
//                double e;
//
//                d = rend[x].x_dir_del - (int)rend[x].x_dir_del;
//                e = (int)rend[x - 1].x_dir_del + 1 - rend[x - 1].x_dir_del;
//                if (d > e)
//                    rend[x - 1].x_dir_del = rend[x - 1].x_dir_del + e;
//                else
//                    rend[x].x_dir_del = rend[x].x_dir_del - d;
//            }
//            else if ((int)rend[x].x_dir_del < (int)rend[x - 1].x_dir_del)
//            {
//                double d;
//                double e;
//
//                d = rend[x - 1].x_dir_del - (int)rend[x - 1].x_dir_del;
//                e = (int)rend[x].x_dir_del + 1 - rend[x].x_dir_del;
//                if (d > e)
//                    rend[x].x_dir_del = rend[x].x_dir_del + e;
//                else
//                    rend[x - 1].x_dir_del = rend[x - 1].x_dir_del - d;
//            }
//                    printf(" after %f %f\n", rend[x].x_dir_del, rend[x]
//        .y_dir_del);

//        }
    }
    x = -1;
    c = -1;
    while(++x < game->image.screen_w)
    {
        cnt = 0;
        double y = -1;
		while (++y < rend[x].ceil)
			do_color(&game->image, (int)x, (int)y, f_c(game->ident.c_rgb));
		double j;
        int flagx;
        int flagy;
        int maxx;
        int maxy;
        double difx;
        double dify;

        maxx = 4;
        maxy = 4;
        flagx = 0;
        flagy = 0;
        j = 0;
//        printf(" before %f %f\n", rend[x].x_dir_del, rend[x]
//        .y_dir_del);
        if (x + 1 <= game->image.screen_w && rend[x].x_dir_del / (int)rend[x]
        .x_dir_del != 1 && rend[x].y_dir_del / (int)rend[x]
                .y_dir_del != 1)
        {
            int num;

            num = -1;
            if (game->image.screen_w - x  - 2 <= maxx)
                maxx = game->image.screen_w - x - 2;
            while (maxx && num != maxx && x + ++num + 1 < game->image
            .screen_w)
            {
//                printf("%f %f\n", rend[x + num].x_dir_del, rend[x + num + 1]
//                        .x_dir_del);
                difx = fabs(rend[x].x_dir_del - rend[x + num].x_dir_del);
                if (fabs(rend[x + num].x_dir_del - rend[x + num + 1]
                .x_dir_del) > 0.5)
                {
                    maxx = num - 1;
                    if (x - 1 >= 0 && !difx)
                        difx = fabs(rend[x].x_dir_del - rend[x - 1].x_dir_del);
                    printf("%f\n", difx);
                    break ;
                }
                if (rend[x + num].x_dir_del > rend[x + num + 1].x_dir_del)
                    flagx += 1;
                else
                    flagx -= 1;
            }
        }
//            printf("abs x %d %d\n", abs(flagx), maxx + 1);
        if (x + 1 <= game->image.screen_w && rend[x].y_dir_del / (int)rend[x]
                .y_dir_del != 1 && rend[x].x_dir_del / (int)rend[x]
                .x_dir_del != 1) {
            int num;

            num = -1;
            if (game->image.screen_w - x - 2 < maxy)
                maxy = game->image.screen_w - x - 2;
            while (maxy && num != maxy && x + ++num + 1 < game->image
            .screen_w) {
//                printf("%f %f\n", rend[x + num].y_dir_del, rend[x + num + 1]
//                        .y_dir_del);
                dify = fabs(rend[x].y_dir_del - rend[x + num].y_dir_del);
                if (fabs(rend[x + num].y_dir_del - rend[x + num + 1]
                        .y_dir_del) > 0.5)
                {
                    maxy = num - 1;
                    if (x - 1 >= 0 && !difx)
                        difx = fabs(rend[x].y_dir_del - rend[x - 1].y_dir_del);
//                    printf("%f\n", dify);
                    break ;
                }
                if (rend[x + num].y_dir_del > rend[x + num + 1].y_dir_del)
                    flagy += 1;
                else
                    flagy -= 1;
            }
//            printf("abs y %d %d\n", abs(flagy), maxy + 1);
            if ((abs(flagx) != maxx + 1) || difx < dify)
            {
//                num = -1;
//                while(num != 4 && x + ++num <= game->image.screen_w)
                double more;
                double less;
                double mid;

                more = fabs((int)rend[x].x_dir_del + 1 - rend[x].x_dir_del);
                mid = fabs((int)rend[x].x_dir_del - rend[x].x_dir_del);
                less = fabs((int)rend[x].x_dir_del - 1 - rend[x].x_dir_del);
//                printf("absx %f %f %f\n", more, mid, less);
                if (more < mid && more < less)
                    rend[x].x_dir_del = (int)rend[x].x_dir_del + 1;
                else if (mid < more && mid < less)
                    rend[x].x_dir_del = (int)rend[x].x_dir_del;
                else if (less < more && less < mid)
                    rend[x].x_dir_del = (int)rend[x].x_dir_del - 1;
//                rend[x].x_dir_del = (int)rend[x].x_dir_del + 1;
//                    rend[x + 1].x_dir_del = (int)rend[x + 1].x_dir_del;
            }
            else if ((abs(flagy) != maxy + 1) || dify < difx)
            {
//                num = -1;
  //              while(num != 4 && x + ++num <= game->image.screen_w)
                    //rend[x].y_dir_del = (int)rend[x].y_dir_del + 1;
//                rend[x + 1].y_dir_del = (int)rend[x + 1].y_dir_del;
                double more;
                double less;
                double mid;

                more = fabs((int)rend[x].y_dir_del + 1 - rend[x].y_dir_del);
                mid = fabs((int)rend[x].y_dir_del - rend[x].y_dir_del);
                less = fabs((int)rend[x].y_dir_del - 1 - rend[x].y_dir_del);
//                printf("absy %f %f %f\n", more, mid, less);
                if (more < mid && more < less)
                    rend[x].y_dir_del = (int)rend[x].y_dir_del + 1;
                else if (mid < more && mid < less)
                    rend[x].y_dir_del = (int)rend[x].y_dir_del;
                else if (less < more && less < mid)
                    rend[x].y_dir_del = (int)rend[x].y_dir_del - 1;
            }
        }
//        printf(" after %f %f\n", rend[x].x_dir_del, rend[x]
//                .y_dir_del);
        if (rend[x].x_dir_del / (int) rend[x].x_dir_del != 1)
            cnt = 1;
        if (rend[x].y_dir_del / (int) rend[x].y_dir_del != 1)
            cnt = 2;
//        printf(" now %f %f\n", rend[x].x_dir_del, rend[x]
//        .y_dir_del);
		while (y < rend[x].floor)
		{
                if (cnt == 1 && (x == 0 || (x - 1 >= 0 && rend[x].x_dir_del >
                rend[x - 1].x_dir_del)))
                {
                    do_color(&game->image, (int) x, (int) y++, \
                        wall(&game->path[3], (int) j, (int) x));
                    j += (double) game->path[3].screen_h /
                         (double) rend[x].size_wall;
                }
                else if (cnt == 1 && (x == 0 || (x - 1 >= 0 && rend[x].x_dir_del < rend[x - 1].x_dir_del)))
                {
                    do_color(&game->image, (int) x, (int) y++, \
                        wall(&game->path[2], (int) j, (int) x));
                    j += (double) game->path[2].screen_h /
                         (double) rend[x].size_wall;
                }
                if (cnt == 2 && (x == 0 || (x - 1 >= 0 && rend[x].y_dir_del <
                    rend[x - 1].y_dir_del)))
                {
                do_color(&game->image, (int) x, (int) y++, \
                        wall(&game->path[0], (int) j, (int) x));
                j += (double) game->path[0].screen_h /
                     (double) rend[x].size_wall;
                }
                if (cnt == 2 && (x == 0 || (x - 1 >= 0 && rend[x].y_dir_del >
                    rend[x - 1].y_dir_del)))
                {
                    do_color(&game->image, (int) x, (int) y++, \
                            wall(&game->path[1], (int) j, (int) x));
                    j += (double) game->path[1].screen_h /
                         (double) rend[x].size_wall;
                }
        }
        while (y < game->image.screen_h)
			do_color(&game->image, (int)x, (int)y++, f_c(game->ident.f_rgb));
	}
}
