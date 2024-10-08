#include "lib_ppm.h"

int turn_blue(struct pixel_s *pixel) {
    pixel->r = 0;
    pixel->g = 0;
    pixel->b = 255;

    return 0;
}

int turn_red(struct pixel_s *pixel) {
    pixel->r = 255;
    pixel->g = 0;
    pixel->b = 0;

    return 0;
}

int turn_green(struct pixel_s *pixel) {
    pixel->r = 0;
    pixel->g = 255;
    pixel->b = 0;

    return 0;
}

int turn_black(struct pixel_s *pixel) {
    pixel->r = 0;
    pixel->g = 0;
    pixel->b = 0;

    return 0;
}

int calc_pixel(struct pixel_s *pixel, struct pixel_s sub_pix[3][3]) {
    
    if (pixel->r >= 0 && pixel->r <= 74) {
        turn_black(&sub_pix[0][0]);
        turn_black(&sub_pix[1][0]);
        turn_black(&sub_pix[2][0]);
    } else if (pixel->r <= 134) {
        turn_black(&sub_pix[0][0]);
        turn_red(&sub_pix[1][0]);
        turn_black(&sub_pix[2][0]);
    } else if (pixel->r <= 179) {
        turn_red(&sub_pix[0][0]);
        turn_black(&sub_pix[1][0]);
        turn_red(&sub_pix[2][0]);
    } else {
        turn_red(&sub_pix[0][0]);
        turn_red(&sub_pix[1][0]);
        turn_red(&sub_pix[2][0]);
    }

    if (pixel->g >= 0 && pixel->g <= 74) {
        turn_black(&sub_pix[0][1]);
        turn_black(&sub_pix[1][1]);
        turn_black(&sub_pix[2][1]);
    } else if (pixel->g <= 134) {
        turn_black(&sub_pix[0][1]);
        turn_red(&sub_pix[1][1]);
        turn_black(&sub_pix[2][1]);
    } else if (pixel->g <= 179) {
        turn_red(&sub_pix[0][1]);
        turn_black(&sub_pix[1][1]);
        turn_red(&sub_pix[2][1]);
    } else {
        turn_red(&sub_pix[0][1]);
        turn_red(&sub_pix[1][1]);
        turn_red(&sub_pix[2][1]);
    }

    if (pixel->b >= 0 && pixel->b <= 74) {
        turn_black(&sub_pix[0][2]);
        turn_black(&sub_pix[1][2]);
        turn_black(&sub_pix[2][2]);
    } else if (pixel->b <= 134) {
        turn_black(&sub_pix[0][2]);
        turn_red(&sub_pix[1][2]);
        turn_black(&sub_pix[2][2]);
    } else if (pixel->b <= 179) {
        turn_red(&sub_pix[0][2]);
        turn_black(&sub_pix[1][2]);
        turn_red(&sub_pix[2][2]);
    } else {
        turn_red(&sub_pix[0][2]);
        turn_red(&sub_pix[1][2]);
        turn_red(&sub_pix[2][2]);
    }

    return 0;
}

int zoom3x(struct image_s *image) {
    struct image_s zoom1x;

    new_ppm(&zoom1x, image->height*3, image->width*3);


        struct pixel_s sub_pix[3][3];
        calc_pixel(&image->pix[0 * image->width + 0], sub_pix);

        zoom1x.pix[0 * zoom1x.width + 0] = sub_pix[0][0];
        zoom1x.pix[1 * zoom1x.width + 0] = sub_pix[1][0];
        zoom1x.pix[2 * zoom1x.width + 0] = sub_pix[2][0];

        zoom1x.pix[0 * zoom1x.width + 1] = sub_pix[0][1];
        zoom1x.pix[1 * zoom1x.width + 1] = sub_pix[1][1];
        zoom1x.pix[2 * zoom1x.width + 1] = sub_pix[2][1];

        zoom1x.pix[0 * zoom1x.width + 2] = sub_pix[0][2];
        zoom1x.pix[1 * zoom1x.width + 2] = sub_pix[1][2];
        zoom1x.pix[2 * zoom1x.width + 2] = sub_pix[2][2];

        write_ppm("zoom1x", &zoom1x);
    

    return 0;
}

int main() {
    struct image_s image;

    read_ppm("lena.ppm", &image);

    zoom3x(&image);
    
}