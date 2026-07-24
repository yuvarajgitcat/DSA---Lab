#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    char word[100];

    printf("Enter the legal document text");
    if(fgets(sentence, sizeof(sentence), stdin) == NULL) return 0;
    printf("Enter the clause to search");
    if(fgets(word, sizeof(word), stdin) == NULL) return 0;

    sentence[strcspn(sentence, "\n")] = '\0';   // This block Removes newline characters
    word[strcspn(word, "\n")] = '\0';

    printf("The legal document text is: %s\n", sentence);

    if (strstr(sentence, word) != NULL) {
        printf("The word '%s' is present in the given sentence.", word);
    } else {
        printf("The word '%s' is not present in the given sentence.", word);
    }

    return 0;
}