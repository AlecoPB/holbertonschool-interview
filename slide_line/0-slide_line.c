#include "slide_line.h"
#include <stddef.h> // For size_t

/**
 * slide_line - Slides and merges an array of integers in a given direction
 * @line: Pointer to the array of integers
 * @size: The number of elements in the array
 * @direction: The direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction) {
    size_t i, pos;
    int merged = 0;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    if (direction == SLIDE_LEFT) {
        pos = 0;
        for (i = 0; i < size; i++) {
            if (line[i] != 0) {
                if (pos > 0 && line[pos - 1] == line[i] && !merged) {
                    line[pos - 1] *= 2;
                    line[i] = 0;
                    merged = 1;
                } else {
                    if (pos != i) {
                        line[pos] = line[i];
                        line[i] = 0;
                    }
                    pos++;
                    merged = 0;
                }
            }
        }
    } else { // SLIDE_RIGHT
        pos = size - 1;
        for (i = size; i > 0; i--) {
            if (line[i - 1] != 0) {
                if (pos < size - 1 && line[pos + 1] == line[i - 1] && !merged) {
                    line[pos + 1] *= 2;
                    line[i - 1] = 0;
                    merged = 1;
                } else {
                    if (pos != i - 1) {
                        line[pos] = line[i - 1];
                        line[i - 1] = 0;
                    }
                    pos--;
                    merged = 0;
                }
            }
        }
    }

    return (1);
}
