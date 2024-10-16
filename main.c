
// just to test the placement of variables in memory
char var1;
char var2 = 0;
char var3 = 3;
const char const1;
const char const2 = 0;
const char const3 = 5;

int main(void) {
    // classic FizzBuzz test
    for (int i = 1; i <= 100; i++) {
        if (i % var3 == var2 && i % const3 == var2) {
            // FizzBuzz
        } else if (i % var3 == var2) {
            // Fizz
        } else if (i % const3 == var2) {
            // Buzz
        } else {
            // i
        }
    }

    for (;;);
}
