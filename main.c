#include "powermenu.h"

int main(void) {
    App app;

    init(&app);

    while(app.is_running) {
        render(&app);
    }

    return 0;
}
