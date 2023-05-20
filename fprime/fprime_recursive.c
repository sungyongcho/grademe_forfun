#include <stdio.h>
#include <stdlib.h>

// 재귀 설명은 따로 안적음
// ref. https://www.google.com/search?q=%EC%86%8C%EC%88%98+%ED%8A%B9%EC%A7%95&rlz=1C5CHFA_enKR938KR938&oq=%EC%86%8C%EC%88%98+%ED%8A%B9%EC%A7%95&aqs=chrome..69i57j0i5i15i30l3.2280j0j4&sourceid=chrome&ie=UTF-8

void display_prime_factors(int num, int factor) {
    if (num <= 1) {
        return;
    }

    if (num % factor == 0) {
        printf("%d", factor);
        if (num / factor != 1) {
            printf("*");
        }
        display_prime_factors(num / factor, factor);
	// !!factor * factor <= num!!
	// num이 아직 다른 factor 로 나눠질 수 있는 가능성이 있다는 말
    } else if (factor * factor <= num) {
        display_prime_factors(num, factor + 1);
    } else {
        printf("%d", num);
    }
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
        printf("\n");
        return 0;
    }

    int num = atoi(argv[1]);
    display_prime_factors(num, 2);
    printf("\n");

    return 0;
}
