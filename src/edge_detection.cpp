#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "image.h"

#define M_PI 3.14159265358979323846


Image smooth_image(const Image& im, float sigma)
{

    //TODO: Implement the smoothing
    NOT_IMPLEMENTED();


    return im;
}


pair<Image,Image> compute_gradient(const Image& im, float sigma)
{

    //TODO: Implement the gradient computation
    NOT_IMPLEMENTED();

    return{im, im};
}



Image non_maximum_supp(const Image& G, const Image& theta)
{

    //TODO: Implement the non maximum suppression
    NOT_IMPLEMENTED();

    return G;

}


Image double_thresholding(const Image& im, float lowThresholdRatio, float highThresholdRatio, float strong, float weak)
{

    //TODO: Implement the Double thresholding
    NOT_IMPLEMENTED();

    return im;
}


Image edge_tracking(const Image& im, float weak, float strong)
{

    //TODO: Implement the Edge tracking
    NOT_IMPLEMENTED();

    return im;

}

