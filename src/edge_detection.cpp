//
// Created by sabbellasr on 25/03/22.
//

#include <iostream> // cout, cerr
#include <assert.h> // assert
#include <string.h> // memcpy
#include <chrono> // time/clocks
#include <math.h>
#include <stack>
#include "image.h"

using namespace std;

double calculateKernalHalfWidth(double sigma)
{
    return(floor(2.5*sigma) - 0.5);
}

double calculateKernalWidth(double sigma)
{
    return(floor(2 * (calculateKernalHalfWidth(sigma))) + 1);
}

// Calculate gaussians
double* gaussianKernal(double sigma)
{
    double width = calculateKernalWidth(sigma);
    double halfWidth = calculateKernalHalfWidth(sigma);
    double *Gaussian, sum = 0.0;

    //TODO:implement Gaussian Keranl
    NOT_IMPLEMENTED();


    return Gaussian;
    delete[] Gaussian;
}

double* gaussian_derivative(double sigma)
{
    double width = calculateKernalWidth(sigma);
    double halfWidth = calculateKernalHalfWidth(sigma);
    double *Gaussian, sum = 0.0;

    //TODO:implement gaussian derivative logic here
    NOT_IMPLEMENTED();


    return Gaussian;
    delete[] Gaussian;
}

// Convolution

//TODO: use the convolve_image() from the "filter_image.cpp"

Image convolve(Image img_O, double* temp_1, double* temp_2, double sigma)
{
    Image img_1;
    img_1(img_O.w, img_O.h);

    for (int y = 0; y < img_O.h; ++y)
    {
        for (int x = 0; x < img_O.w; ++x)
        {
            img_1(x, y) = img_O(x, y);
        }
    }

    float sum;
    Image img_2, img_3;
    double width = calculateKernalWidth(sigma);
    double halfWidth = calculateKernalHalfWidth(sigma);

    img_2(img_O.w, img_O.h);
    img_3(img_O.w, img_O.h);

    for (int y = 0; y < img_O.h; ++y)
    {
        for (int x = 0; x < img_O.w; ++x)
        {
            img_2(x, y) = 0;
            img_3(x, y) = 0;
        }
    }

    for (int y = 0; y < img_O.h; ++y)
    {
        for (int x = halfWidth; x < img_O.w - halfWidth; ++x)
        {
            sum = 0;
            for (int z = 0; z < width; z++)
            {
                sum += ((temp_1[z] * img_1(x + halfWidth - z, y)));
            }
            img_2(x, y) = sum;
        }
    }

    for (int y = halfWidth; y < img_O.h - halfWidth; ++y)
    {
        for (int x = 0; x < img_O.w; ++x)
        {
            sum = 0;
            for (int z = 0; z < width; z++)
            {
                sum += ((temp_2[z] * img_2(x, y + halfWidth - z)));
            }
            img_3(x, y) = sum;
        }
    }
    return img_3;
}

Image nonMaxSuppression(Image im1, Image im2)
{
    Image im_out;
    double temp;

    //TODO:implement non-max suppression logic in this function
    NOT_IMPLEMENTED();


    return im_out;
}


Image performThreshold(Image im1, int temp)
{
    Image im2;
    im2.h = im1.h;
    im2.w = im1.w;

    //TODO:perform Thresholding
    NOT_IMPLEMENTED();

    return im2;
}




Image performDoubleThreshold(Image imgFile_input, double low, double high)
{
    Image imgFile_output, imgFile_output1, imgFile_tLow;
    /*imgFile_output1 -> (imgFile_input.w, imgFile_input.h);
    imgFile_output.(imgFile_input.w, imgFile_input.h);
    imgFile_tLow.(imgFile_input.w, imgFile_input.h);*/

    imgFile_tLow = performThreshold(imgFile_input, low);

    //TODO:implement the logic for the low and high thresholding to detect the edges();

    NOT_IMPLEMENTED();

    return imgFile_output1;
}

Image performEdgeLink(Image imgFile_img1)
{
    //TODO: perform edge linking for thinning the edges
    NOT_IMPLEMENTED();


    return imgFile_out;

}

void ImgGradient(Image img_O, double sigma, Image *img_1, Image *img_2, Image *img_3, Image *img_4)
{
    (*img_1)(img_O.w, img_O.h);
    (*img_2)(img_O.w, img_O.h);

    for (int y = 0; y < img_O.h; ++y)
    {
        for (int x = 0; x < img_O.w; ++x)
        {
            (*img_1)(x, y) = 0;
            (*img_2)(x, y) = 0;
        }
    }

    double *Gaussian = gaussianKernal(sigma);
    double *DGaussian = gaussian_derivative(sigma);
    double *flip;
    double width = calculateKernalWidth(sigma);

    flip = new double[(int)width];
    int temp = width - 1;
    for (int z = 0; z < width; z++)
    {
        flip[temp] = DGaussian[z];
        temp--;
    }

    (*img_3) = convolve(img_O, flip, Gaussian, sigma);
    (*img_4) = convolve(img_O, Gaussian, flip, sigma);


    for (int y = 0; y < img_O.h; ++y)
    {
        for (int x = 0; x < img_O.w; ++x)
        {
            (*img_1)(x, y) = sqrt(((*img_3)(x, y)*(*img_3)(x, y)) + (((*img_4)(x, y)*(*img_4)(x, y))));
            (*img_2)(x, y) = atan2((*img_4)(x, y), (*img_3)(x, y));
        }
    }
    return;
}


int main(int argc, const char* argv[], const char* envp[])
{

    try
    {
        double sigma;
        sigma = atof(argv[1]);

        Image imgFile_O1;
        Image imgFile_O2;


        double width = calculateKernalWidth(sigma);
        double *Gaussian = gaussianKernal(sigma);
        double *DGaussian = gaussian_derivative(sigma);

        cout << "The Gaussian Kernel is ";
        for (int i = 0; i<width; i++)
        {
            cout << "\t" << Gaussian[i];
        }

        cout << endl << "The Derivative of the Gaussian Kernel is";
        for (int i = 0; i<width; i++)
        {
            cout << "\t" << DGaussian[i];
        }

        Image imgFile_mag, imgFile_phase, imgFile_x, imgFile_y;
        ImgGradient(imgFile_O1, sigma, &imgFile_mag, &imgFile_phase, &imgFile_x, &imgFile_y);



        Image imgFile_nonMaxSup = nonMaxSuppression(imgFile_mag, imgFile_phase);


    }

    catch (exception& e)
    {

    }

    return 0;
}