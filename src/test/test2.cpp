#include "../image.h"
#include "../utils.h"

#include <string>

using namespace std;


void test_smooth_image() {

    Image im = load_image("data/iguana.jpg");
    Image smooth = smooth_image(im, 1.4);
    smooth.save_png("output/smooth_iguana");
    Image new_im = rgb_to_grayscale(im);
    new_im.save_png("output/iguana_gray");
    Image check_gt = load_image("data/smooth_iguana.png");
    TEST(same_image(smooth, check_gt));

}


void test_gradient() {

    Image im = load_image("data/iguana.jpg");
    pair<Image,Image> grad = compute_gradient(im, 1.4);
    Image mag = grad.first;
    Image dir = grad.second;
    mag.save_png("output/dx_iguana");
    dir.save_png("output/dy_iguana");
    Image check_gtx = load_image("data/gx_iguana.png");
    TEST(same_image(mag, check_gtx));

}


void test_non_max_supp() {

    Image im = load_image("data/iguana.jpg");
    pair<Image,Image> grad = compute_gradient(im, 1.4);
    Image mag = grad.first;
    Image dir = grad.second;
    Image nms = non_maximum_supp(mag, dir);
    nms.save_png("output/nms_iguana");
    Image check_nms = load_image("data/non_max_supp_iguana.png");
    TEST(same_image(check_nms, nms));

}


void test_double_thresholding() {
    Image im = load_image("data/iguana.jpg");
    pair<Image,Image> grad = compute_gradient(im, 1.4);
    Image mag = grad.first;
    Image dir = grad.second;
    Image nms = non_maximum_supp(mag, dir);
    Image dt = double_thresholding(nms, 0.03, 0.17, 1.0, 0.2);
    dt.save_png("output/double_threshold_iguana");
    Image dt_check = load_image("data/doub_thres_iguana.png");
    TEST(same_image(dt, dt_check));

}

void test_edge_tracking() {
    Image im = load_image("data/iguana.jpg");
    pair<Image,Image> grad = compute_gradient(im, 1.4);
    Image mag = grad.first;
    Image dir = grad.second;
    Image nms = non_maximum_supp(mag, dir);
    float strong = 1.0;
    float weak = 0.2;
    Image dt = double_thresholding(nms, 0.03, 0.17, strong, weak);
    Image edge_track = edge_tracking(dt, weak, strong);
    edge_track.save_png("output/edge_track_iguana");
    Image et_check = load_image("data/edge_iguana.png");
    TEST(same_image(edge_track, et_check));
}


void run_tests() {

    test_smooth_image();
    test_gradient();
    test_non_max_supp();
    test_double_thresholding();
    test_edge_tracking();

    printf("%d tests, %d passed, %d failed\n", tests_total, tests_total - tests_fail, tests_fail);
}

int main(int argc, char **argv) {
    run_tests();
    return 0;
}

