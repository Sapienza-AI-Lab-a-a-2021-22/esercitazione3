#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "image.h"

#define M_PI 3.14159265358979323846

// HW1 #2.1
// Image& im: image to L1-normalize
void l1_normalize(Image& im)
{

    // TODO: Normalize each channel

    for (int c = 0; c < im.c; c ++) {
        float sum = 0.0;
        for (int y = 0; y < im.h; y ++) {
            for (int x = 0; x < im.w; x ++) {
                sum += im(x,y,c);
            }
        }

        for (int y = 0; y < im.h; y ++) {
            for (int x = 0; x < im.w; x ++) {
                im(x,y,c) = (float) im(x,y,c) / sum;
            }
        }
    }
    return;
}

void l2_normalize(Image& im)
{

    // TODO: Normalize each channel

    //implement your code()

    return;
}

// HW1 #2.1
// int w: size of filter
// returns the filter Image of size WxW
Image make_box_filter(int w)
{
    assert(w%2); // w needs to be odd

    // TODO: Implement the filter

    Image box(w,w,1);
    float val = 1 / (float) (w * w);

    for (int y = 0; y < box.h; y++) {
        for (int x = 0; x < box.w; x ++) {
            box(x,y,0) = val;
        }
    }

    return box;
}

// HW1 #2.2
// const Image&im: input image
// const Image& filter: filter to convolve with
// bool preserve: whether to preserve number of channels
// returns the convolved image
Image convolve_image(const Image& im, const Image& filter, bool preserve)
{
//  Image ret;
//  // This is the case when we need to use the function clamped_pixel(x,y,c).
//  // Otherwise you'll have to manually check whether the filter goes out of bounds
//
//  // TODO: Make sure you set the sizes of ret properly. Use ret=Image(w,h,c) to reset ret
//  // TODO: Do the convolution operator
//  NOT_IMPLEMENTED();
//
//  // Make sure to return ret and not im. This is just a placeholder
//  return im;

    assert(filter.c==1);
    Image conv(im.w, im.h, im.c);

    for (int c = 0; c < im.c; c ++) {
        for (int y = 0; y < im.h; y ++) {
            for (int x = 0; x < im.w; x ++) {

                // The starting coordinates in image
                int sx = x - (filter.w / 2);
                int sy = y - (filter.h / 2);

                float sum = 0.0;

                for (int fy = 0; fy < filter.h; fy ++) {
                    for (int fx = 0; fx < filter.w; fx ++) {
                        sum += filter(fx, fy, 0) * im.clamped_pixel(sx + fx, sy + fy, c);
                    }
                }

                conv(x,y,c) = sum;
            }
        }
    }


    if (!preserve) {
        for (int y = 0; y < conv.h; y ++) {
            for (int x = 0; x < conv.w; x ++) {
                float sum = 0;
                for (int c = 0; c < conv.c; c ++) {
                    sum += conv(x,y,c);
                }
                conv(x,y,0) = sum;
            }
        }
        conv.c = 1;
    }

    //l1_normalize(conv);

    return conv;
}

// HW1 #2.3
// returns basic 3x3 high-pass filter
Image make_highpass_filter()
{
    // TODO: Implement the filter

    Image f (3,3,1);

    f(0,0,0) = 0;
    f(1,0,0) = -1;
    f(2,0,0) = 0;
    f(0,1,0) = -1;
    f(1,1,0) = 4;
    f(2,1,0) = -1;
    f(0,2,0) = 0;
    f(1,2,0) = -1;
    f(2,2,0) = 0;

    return f;
}

// HW1 #2.3
// returns basic 3x3 sharpen filter
Image make_sharpen_filter()
{
    // TODO: Implement the filter

    Image f (3,3,1);

    f(0,0,0) = 0;
    f(1,0,0) = -1;
    f(2,0,0) = 0;
    f(0,1,0) = -1;
    f(1,1,0) = 5;
    f(2,1,0) = -1;
    f(0,2,0) = 0;
    f(1,2,0) = -1;
    f(2,2,0) = 0;

    return f;
}

// HW1 #2.3
// returns basic 3x3 emboss filter
Image make_emboss_filter()
{
    // TODO: Implement the filter

    Image f (3,3,1);

    f(0,0,0) = -2;
    f(1,0,0) = -1;
    f(2,0,0) = 0;
    f(0,1,0) = -1;
    f(1,1,0) = 1;
    f(2,1,0) = 1;
    f(0,2,0) = 0;
    f(1,2,0) = 1;
    f(2,2,0) = 2;

    return f;
}

// HW1 #2.4
// float sigma: sigma for the gaussian filter
// returns basic gaussian filter
Image make_gaussian_filter(float sigma)
{
    // TODO: Implement the filter

    int w = ceil (sigma * 6);
    if (!(w % 2))
        w ++;

    Image f (w,w,1);

    for (int y = 0; y < f.h; y ++) {
        for (int x = 0; x < f.w; x ++) {

            int rx = x - (w/2);
            int ry = y - (w/2);

            float var = powf(sigma, 2);
            float c = 2 * M_PI * var;
            float p = -(powf(rx,2) + powf(ry,2)) / (2 * var);
            float e = expf(p);
            float val = e / c;
            f(x,y,0) = val;
        }
    }


    return f;
}


// HW1 #3
// const Image& a: input image
// const Image& b: input image
// returns their sum
Image add_image(const Image& a, const Image& b)
{
    assert(a.w==b.w && a.h==b.h && a.c==b.c); // assure images are the same size

    Image res (a.w, a.h, a.c);
    for (int c = 0; c < res.c; c++) {
        for (int y = 0; y < res.h; y ++) {
            for (int x = 0; x < res.w; x ++) {
                res(x,y,c) = a(x,y,c) + b(x,y,c);
            }
        }
    }

    return res;
}

// HW1 #3
// const Image& a: input image
// const Image& b: input image
// returns their difference res=a-b
Image sub_image(const Image& a, const Image& b)
{
    assert(a.w==b.w && a.h==b.h && a.c==b.c); // assure images are the same size

    Image res (a.w, a.h, a.c);
    for (int c = 0; c < res.c; c++) {
        for (int y = 0; y < res.h; y ++) {
            for (int x = 0; x < res.w; x ++) {
                res(x,y,c) = a(x,y,c) - b(x,y,c);
            }
        }
    }

    return res;
}

// HW1 #4.1
// returns basic GX filter
Image make_gx_filter()
{
    // TODO: Implement the filter

    Image f (3,3,1);

    f(0,0,0) = -1;
    f(1,0,0) = 0;
    f(2,0,0) = 1;
    f(0,1,0) = -2;
    f(1,1,0) = 0;
    f(2,1,0) = 2;
    f(0,2,0) = -1;
    f(1,2,0) = 0;
    f(2,2,0) = 1;

    return f;
}

// HW1 #4.1
// returns basic GY filter
Image make_gy_filter()
{
    // TODO: Implement the filter

    Image f (3,3,1);

    f(0,0,0) = -1;
    f(1,0,0) = -2;
    f(2,0,0) = -1;
    f(0,1,0) = 0;
    f(1,1,0) = 0;
    f(2,1,0) = 0;
    f(0,2,0) = 1;
    f(1,2,0) = 2;
    f(2,2,0) = 1;

    return f;
}

// HW1 #4.2
// Image& im: input image
void feature_normalize(Image& im)
{
    assert(im.w*im.h); // assure we have non-empty image

    // TODO: Normalize the features for each channel


    for (int c = 0; c < im.c; c ++) {

        float min_val = im(0,0,c);
        float max_val = im(0,0,c);

        for (int y = 0; y < im.h; y ++) {
            for (int x = 0; x < im.w; x ++) {
                min_val = min (min_val, im(x,y,c));
                max_val = max (max_val, im(x,y,c));
            }
        }

        float range = max_val - min_val;

        for (int y = 0; y < im.h; y ++) {
            for (int x = 0; x < im.w; x++) {
                if (range) {
                    im(x,y,c) = (im(x,y,c) - min_val) / range;
                }
                else
                    im(x,y,c) = 0;
            }
        }
    }

    return;
}


// Normalizes features across all channels
void feature_normalize_total(Image& im)
{
    assert(im.w*im.h*im.c); // assure we have non-empty image

    int nc=im.c;
    im.c=1;im.w*=nc;

    feature_normalize(im);

    im.w/=nc;im.c=nc;

}


// HW1 #4.3
// Image& im: input image
// return a pair of images of the same size
pair<Image,Image> sobel_image(const Image& im)
{

    Image fx = make_gx_filter();
    Image fy = make_gy_filter();

    Image Gx = convolve_image (im, fx, false);
    Image Gy = convolve_image (im, fy, false);


    Image G(im.w, im.h, 1);
    Image T(im.w, im.h, 1);


    for (int y = 0; y < im.h; y ++) {
        for (int x = 0; x < im.w; x ++) {
            G(x,y,0) = sqrtf ( pow(Gx(x,y,0), 2) + pow(Gy(x,y,0), 2));
            T(x,y,0) = atan2f( Gy(x,y,0) , Gx(x,y,0));
        }
    }


    return {G,T};
}


// HW1 #4.4
// const Image& im: input image
// returns the colorized Sobel image of the same size
Image colorize_sobel(const Image& im)
{

    Image f = make_gaussian_filter(4);
    Image blur = convolve_image(im, f, true);
    blur.clamp();

    pair<Image, Image> sobel = sobel_image(blur);

    Image mag = sobel.first;
    Image theta = sobel.second;


    feature_normalize(mag);

    for (int y = 0; y < im.h; y ++) {
        for (int x = 0; x < im.w; x ++) {
            theta(x,y,0) = theta(x,y,0) / (2 * M_PI) + 0.5;
        }
    }


    Image hsv (im.w, im.h, 3);

    for (int y = 0; y < im.h; y ++) {
        for (int x = 0; x < im.w; x ++) {
            hsv(x,y,0) = theta(x,y,0);
            hsv(x,y,1) = mag(x,y,0);
            hsv(x,y,2) = mag(x,y,0);
        }
    }

    hsv_to_rgb(hsv);

    return hsv;
}



Image make_bilateral_filter (const Image &im, const Image &sgf, int cx, int cy, int cc, float sigma) {


    // Color gaussian filter
    Image cgf (sgf.w, sgf.h, 1);

    for (int y = 0; y < sgf.w; y ++) {
        for (int x = 0; x < sgf.w; x ++) {
            int ax = cx - sgf.w/2 + x;
            int ay = cy - sgf.w/2 + y;

            float diff = im.clamped_pixel(ax ,ay ,cc) - im.clamped_pixel(cx, cy, cc);

            float var = powf(sigma, 2);
            float c = 2 * M_PI * var;
            float p = - powf(diff,2) / (2 * var);
            float e = expf(p);
            float val = e / c;

            cgf(x,y,0) = val;

        }
    }


    Image bf (sgf.w, sgf.h, 1);

    // Multiply space gaussian by color gaussian
    for (int y = 0; y < bf.h; y ++) {
        for (int x = 0; x < bf.w; x ++) {
            bf (x,y,0) = sgf(x,y,0) * cgf(x,y,0);
        }
    }


    l1_normalize(bf);


    return bf;
}





// HW1 #4.5
// const Image& im: input image
// float sigma1,sigma2: the two sigmas for bilateral filter
// returns the result of applying bilateral filtering to im
Image bilateral_filter(const Image& im, float sigma1, float sigma2)
{

    Image gf = make_gaussian_filter(sigma1);

    Image res(im.w, im.h, im.c);


    for (int c = 0; c < res.c; c ++) {
        for (int y = 0; y < im.h; y ++) {
            for (int x = 0; x < im.w; x ++) {

                // Get bilateral filter
                Image bf = make_bilateral_filter(im, gf, x, y, c, sigma2);

                float sum = 0.0;
                // Convolve for pixel x,y,c
                for (int fy = 0; fy < gf.w; fy ++) {
                    for (int fx = 0; fx < gf.w; fx ++) {

                        int ax = x - bf.w/2 + fx;
                        int ay = y - bf.w/2 + fy;

                        sum += bf(fx,fy,0) * im.clamped_pixel( ax, ay, c);
                    }
                }

                res (x,y,c) = sum;

            }
        }
    }

    return res;
}



// HELPER MEMBER FXNS

void Image::feature_normalize(void) { ::feature_normalize(*this); }
void Image::feature_normalize_total(void) { ::feature_normalize_total(*this); }
void Image::l1_normalize(void) { ::l1_normalize(*this); }
void Image::l2_normalize(void) { ::l2_normalize(*this); }

Image operator-(const Image& a, const Image& b) { return sub_image(a,b); }
Image operator+(const Image& a, const Image& b) { return add_image(a,b); }
