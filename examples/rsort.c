#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_WORD_LEN 100

int cmp_rev(const void *a, const void *b) {
    const char * const *sa = a;
    const char * const *sb = b;
    /* Reverse alphabetical: compare b to a */
    return strcmp(*sb, *sa);
}

int main(void) {
    char buffer[MAX_WORD_LEN + 2]; /* +1 for '\n', +1 for '\0' */
    char **words = NULL;
    size_t count = 0;
    size_t capacity = 0;

    char string[256];

    printf("Enter something: " );
    fgets(string, 256, stdin);

    printf("%s", string);

    return EXIT_SUCCESS;

    /* Read lines from stdin */
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        size_t len = strlen(buffer);
        /* Remove trailing '\n', if present */
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[--len] = '\0';
        }
        /* Ignore empty lines */
        if (len == 0) {
            continue;
        }
        /* Check length limit */
        if (len > MAX_WORD_LEN) {
            fprintf(stderr, "Error: word exceeds maximum length of %d characters: %s...\n", MAX_WORD_LEN, buffer);
            continue;
        }
        /* Store word */
        if (count >= capacity) {
            size_t newcap = capacity == 0 ? 16 : capacity * 2;
            char **tmp = realloc(words, newcap * sizeof(char *));
            if (!tmp) {
                perror("realloc");
                return EXIT_FAILURE;
            }
            words = tmp;
            capacity = newcap;
        }
        words[count] = malloc(len + 1);
        if (!words[count]) {
            perror("malloc");
            return EXIT_FAILURE;
        }
        strcpy(words[count], buffer);
        count++;
    }
    if (ferror(stdin)) {
        perror("fgets");
        return EXIT_FAILURE;
    }

    /* Sort in reverse alphabetical order */
    qsort(words, count, sizeof(char *), cmp_rev);

    /* Output sorted words to stdout */
    for (size_t i = 0; i < count; i++) {
        if (fputs(words[i], stdout) == EOF || fputc('\n', stdout) == EOF) {
            perror("fputs/fputc");
            return EXIT_FAILURE;
        }
    }

    /* Free allocated memory */
    for (size_t i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);

    return EXIT_SUCCESS;
}
