#include <iostream>
#include <fcntl.h>
#include <unistd.h>

//4. Написати програму, яка читає всі передані їй в командному рядку файли
// та виводить їх, один за одним, у стандартний вивід (засобами системних викликів POSIX).

#define Buf 10000


using namespace std;


int main(int argc, char *argv[]) {
    int input_file;
    ssize_t rnb_in;
    char buffer[Buf];


    for (int i = 1; i < argc; i++) {
        input_file = open(argv[i], O_RDONLY);
        if (input_file == -1) {
            perror("open file");
            return 2;
        }

        cout <<"Name of file: "<< argv[i] << endl;
        while ((rnb_in = read(input_file, &buffer, Buf)) > 0) {
            buffer[rnb_in] = '\0';
            cout << buffer << endl;
        }
        cout << "!========================================================!" << endl;
        close(input_file);

    }

    return (EXIT_SUCCESS);

}


