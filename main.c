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
        turn_green(&sub_pix[1][1]);
        turn_black(&sub_pix[2][1]);
    } else if (pixel->g <= 179) {
        turn_green(&sub_pix[0][1]);
        turn_black(&sub_pix[1][1]);
        turn_green(&sub_pix[2][1]);
    } else {
        turn_green(&sub_pix[0][1]);
        turn_green(&sub_pix[1][1]);
        turn_green(&sub_pix[2][1]);
    }

    if (pixel->b >= 0 && pixel->b <= 74) {
        turn_black(&sub_pix[0][2]);
        turn_black(&sub_pix[1][2]);
        turn_black(&sub_pix[2][2]);
    } else if (pixel->b <= 134) {
        turn_black(&sub_pix[0][2]);
        turn_blue(&sub_pix[1][2]);
        turn_black(&sub_pix[2][2]);
    } else if (pixel->b <= 179) {
        turn_blue(&sub_pix[0][2]);
        turn_black(&sub_pix[1][2]);
        turn_blue(&sub_pix[2][2]);
    } else {
        turn_blue(&sub_pix[0][2]);
        turn_blue(&sub_pix[1][2]);
        turn_blue(&sub_pix[2][2]);
    }

    return 0;
}

int zoom3x(struct image_s *image) {
        struct image_s zoom1x;

        new_ppm(&zoom1x, image->height*3, image->width*3);

        for(int i = 0; i < image->height; i++) {
            for(int j = 0; j < image->width; j++) {
                struct pixel_s sub_pix[3][3];
                calc_pixel(&image->pix[i * image->width + j], sub_pix);

                for(int x = 0; x < 3; x++) {
                    for(int y = 0; y < 3; y++) {
                        zoom1x.pix[(i * 3 + x) * zoom1x.width + (j * 3 + y)] = sub_pix[x][y];
                    }
                }
            }
        }

        struct image_s zoom2x;

        new_ppm(&zoom2x, zoom1x.height*3, zoom1x.width*3);

        for(int i = 0; i < zoom1x.height; i++) {
            for(int j = 0; j < zoom1x.width; j++) {
                struct pixel_s sub_pix[3][3];
                calc_pixel(&zoom1x.pix[i * zoom1x.width + j], sub_pix);

                for(int x = 0; x < 3; x++) {
                    for(int y = 0; y < 3; y++) {
                        zoom2x.pix[(i * 3 + x) * zoom2x.width + (j * 3 + y)] = sub_pix[x][y];
                    }
                }
            }
        }

        struct image_s zoom3x;

        new_ppm(&zoom3x, zoom2x.height*3, zoom2x.width*3);

        for(int i = 0; i < zoom2x.height; i++) {
            for(int j = 0; j < zoom2x.width; j++) {
                struct pixel_s sub_pix[3][3];
                calc_pixel(&zoom2x.pix[i * zoom2x.width + j], sub_pix);

                for(int x = 0; x < 3; x++) {
                    for(int y = 0; y < 3; y++) {
                        zoom3x.pix[(i * 3 + x) * zoom3x.width + (j * 3 + y)] = sub_pix[x][y];
                    }
                }
            }
        }

        write_ppm("zoom3x", &zoom3x);

        
    return 0;
}

int main() {
    struct image_s image;

    read_ppm("lena.ppm", &image);

    zoom3x(&image);
    
}