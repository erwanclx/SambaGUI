#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define CONFIG_FILE "/etc/samba/smb.conf"

void get_input(WINDOW *win, int starty, int startx, char *label, char *input, int len) {
    mvwprintw(win, starty, startx, "%s: ", label);
    wgetnstr(win, input, len);
}

void append_to_config(const char *share, const char *comment, const char *path) {
    FILE *file = fopen(CONFIG_FILE, "a");
    if (file == NULL) {
        perror("Error opening configuration file");
        return;
    }

    fprintf(file, "\n[%s]\n", share);
    fprintf(file, "    comment = %s\n", comment);
    fprintf(file, "    path = %s\n", path);
    fprintf(file, "    browsable = yes\n");
    fprintf(file, "    guest ok = yes\n");
    fprintf(file, "    read only = no\n");

    fclose(file);
}

int main() {
    char share[50], comment[100], path[100];

    initscr();
    cbreak();
    noecho();
    WINDOW *win = newwin(10, 50, 1, 1);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    get_input(win, 1, 1, "Name of shared folder", share, 50);
    get_input(win, 3, 1, "Comments (optional)", comment, 100);
    get_input(win, 5, 1, "Absolute path", path, 100);

    endwin();

    append_to_config(share, comment, path);

    printf("Configuration successfully added %s\n", CONFIG_FILE);

    return 0;
}

