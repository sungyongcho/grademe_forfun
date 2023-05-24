#include <stdio.h>
#include <stdlib.h>

void display_prime_factors(int num, int factor) {
	// 함수 종료조건
	// 1번부터 읽고

	// 2. 만약에 들어온 num이 1보다 작다 (= 소수의 조건에 포함 안됨)
	//    소수의 조건: 0 제외, 1과 자기 자신을 곱했을때 나누는 숫자
	//    숫자를 계속 나눠가면서 재귀 호출을 하면 num은 계속 줄어들 수 밖에 없다.
    if (num <= 1) {
        return;
    }

	// ** 함수 분기문 (conditional statements) **
	// - 함수가 계속 진행 하기 위한 조건들
	// - 이 문제에서는 받아오는 num 을 계속 나누어서 곱셈 수를 봐야되기 때문에 각각의 분기들이 존재함
	// 1-1. 몫(num) 을 factor 로 나누었을때 나머지가 0이면?
	//    = num 은 소수가 아니다 (= 왜냐하면 나누어질 수 없기 때문에)
    if (num % factor == 0) {
		// 출력
        printf("%d", factor);
		// 1로 나누어지는게 아니면 계속 출력해야되기 때문에
        if (num / factor != 1) {
            printf("*");
        }
		// 일단 여기로 들어왔으면 위의 if 조건문 때문에 num은 factor로 나눠질 수 있음
		// num을 factor로 나눌 수 있기 때문에 num / factor 로 나눠 준 다음에 '재귀호출'
		// 2번으로 ㄱㄱ
        display_prime_factors(num / factor, factor);
	// 1-2. !!factor * factor <= num!!
	//       num이 아직 다른 factor 로 나눠질 수 있는 가능성이 있다는 말
    } else if (factor * factor <= num) {
		// 이번 분기는 우선 현재 factor 로 안나눠 지기 때문에 factor 에 1을 더해서 다시 재귀호출 해봄
		// 2번으로 ㄱㄱ
        display_prime_factors(num, factor + 1);
	// 아니면??
	// 들어오자 마자 소수다?
    } else {
		// 바로 숫자출력
        printf("%d", num);


		//재귀 호출도 없어서 위에 2번 조건문도 못들어감.
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
