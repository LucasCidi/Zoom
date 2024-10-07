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

int calc_pixel(struct pixel_s *pixel, struct pixel_s *sub_pix[3][3]) {
    
    if (pixel->r >= 0 && pixel->r <= 74) {
        turn_black(&sub_pix[0][0]->r);
        turn_black(&sub_pix[1][0]->g);
        turn_black(&sub_pix[2][0]->b);
    } else if (pixel->r <= 134) {
        turn_black(&sub_pix[0][0]->r);
        turn_red(&sub_pix[1][0]->g);
        turn_black(&sub_pix[2][0]->b);
    } else if (pixel->r <= 179) {
        turn_red(&sub_pix[1][0]->r);
        turn_black(&sub_pix[2][0]->g);
        turn_red(&sub_pix[3][0]->b);
    } else {

    }


    return 0;
}

int zoom3x(struct image_s *image) {
    struct image_s zoom1x;

    new_ppm(&zoom1x, image->height*3, image->width*3);

    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            struct pixel_s sub_pix[3][3];
        }
    }

    return 0;
}

int main() {
    struct image_s image;

    read_ppm("lena.ppm", &image);
    
    // for(int j = 0; j < image.height; j++) {
    //     for(int i = 0; i < image.width; i++) {
    //         image.pix[j * image.width + i].r = 255 - image.pix[j *image.width + i].r;
    //         image.pix[j * image.width + i].g = 255 - image.pix[j *image.width + i].g;
    //         image.pix[j * image.width + i].b = 255 - image.pix[j *image.width + i].b;
    //     }
    // }
    
}