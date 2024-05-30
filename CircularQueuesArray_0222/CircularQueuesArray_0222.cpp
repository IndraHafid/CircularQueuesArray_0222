// CircularQueuesArray_0222.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Queues {
private:
    static const int max = 3;
    int FRONT, REAR;
    int queue_array[max];

public:
   
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a number:";
        cin >> num;
        cout << endl;

        //cek apakah antrean penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        //cek apakah antrean kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }

        else {
            //jika REAR berada diposisi terahir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove() {
        //cek apakah antrean kosong 
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        //cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }

        else {
            //jika elemen yang dihapus berada diposisi terahir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;

        }
    }

    void display() {
        int FRONT_Position = FRONT;
        int REAR_Postion = REAR;

        //cek apakah antrian kosong
        if (FRONT_Position == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        //jika FRONT <= REAR, literasi dari FRONT hingga REAR 
        if (FRONT_Position <= REAR_Postion) {
            while (FRONT_Position <= REAR_Postion) {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }
            cout << endl;


        }

        else {
            //jika FRONT > REAR, literasi dari FRONT hingga ahir array
            while (FRONT_Position <= max - 1) {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            FRONT_Position = 0;

            //literasi dari awal array hingga REAR
            while (FRONT_Position <= REAR_Postion) {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queues q;
    char ch;

    while (true) {
        try {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement insert operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch) {
            case '1': {
                q.insert();
                break;
            }
            case '2': {
                q.remove();
                break;
            }
            case '3': {
                q.display();
                break;
            }
            case '4': {
                q.insert();
                return 0;
            }
            default: {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception& e) {
            cout << "Check for the values entered." << endl;
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
