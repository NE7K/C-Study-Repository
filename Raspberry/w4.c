#include <stdio.h>
#include <pigpio.h> // pigpio 라이브러리 포함

int main(void) {
    if (gpioInitialise() < 0) { // pigpio 초기화
        printf("pigpio 초기화 실패\n");
        return 1;
    }

    // GPIO 21: 항상 켜져 있는 LED
    gpioSetMode(21, PI_OUTPUT);
    gpioWrite(21, 1); // HIGH 상태 유지

    // GPIO 20: 10초마다 깜빡이는 LED
    gpioSetMode(20, PI_OUTPUT);

    while (1) {
        gpioWrite(20, 1); // 켜기
        time_sleep(1);    // 1초간 켜짐 유지
        gpioWrite(20, 0); // 끄기
        time_sleep(9);    // 9초간 꺼짐
        // 결과적으로 10초마다 1초간 깜빡임
    }

    gpioTerminate(); // (실제로는 도달하지 않지만, 구조상 종료 코드 포함)
    return 0;
}
