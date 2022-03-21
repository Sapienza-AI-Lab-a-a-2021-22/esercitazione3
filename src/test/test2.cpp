#include "../image.h"
#include "../utils.h"

#include <string>

using namespace std;

void test_dummy() {
    return;
}

void run_tests() {
    test_dummy();
    printf("%d tests, %d passed, %d failed\n", tests_total, tests_total - tests_fail, tests_fail);
}

int main(int argc, char **argv) {
    run_tests();
    return 0;
}
