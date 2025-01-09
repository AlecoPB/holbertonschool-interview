#include <stdio.h>
#include <math.h>

/**
 * menger - Draws a 2D Menger Sponge of a given level
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level) {
    if (level < 0)
        return;

    int size = pow(3, level);

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            int x = row, y = col;
            int is_space = 0;

            // Check if the position should be a space
            while (x > 0 || y > 0) {
                if (x % 3 == 1 && y % 3 == 1) {
                    is_space = 1;
                    break;
                }
                x /= 3;
                y /= 3;
            }

            if (is_space)
                putchar(' ');
            else
                putchar('#');
        }
        putchar('\n');
    }
}
