#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

struct item {
    string type;
    bool status;
    int price;
};

void read_input(string f_path)
{
    struct item itemArray[100];
    string input_line;
    ifstream f(f_path);
    int count = 0;
    int x = 0;

    if (f.is_open()) {
        cout << "reading lines from: " << f_path << "..." << "\n" << endl;
        while (getline(f, input_line)) {
            stringstream ss(input_line);
            string token;
            int i = 0;

            while (getline(ss, token, ',')) {
                if (i == 0)
                    itemArray[x].type = token;
                if (token == "wanted") {
                    itemArray[x].status = true;
                }
                else if (token == "for sale") {
                    itemArray[x].status = false;
                }
                if (i == 2)
                    itemArray[x].price = stoi(token);
                i++;
            }
            x++;
        }
        f.close();
    }
    
    else
    {
        cout << "File was not opened!" << endl;
        return;
    }

    for (int i = 0; i < x; i++) {
        for (int s = i + 1; s < x; s++) {
            if (itemArray[i].type == itemArray[s].type) {
                if (itemArray[i].status != itemArray[s].status) {
                    if (itemArray[i].status == 0) {
                        if (itemArray[i].price <= itemArray[s].price) {
                            count++;
                            x--;
                            for (int y = s; y < x; y++) {
                                itemArray[y] = itemArray[y + 1];
                            }
                            x--;
                            for (int y = i; y < x; y++) {
                                itemArray[y] = itemArray[y + 1];
                            }
                        }
                    }

                    else {
                        if (itemArray[s].price <= itemArray[i].price) {
                            count++;
                            x--;
                            for (int y = s; y < x; y++) {
                                itemArray[y] = itemArray[y + 1];
                            }
                            x--;
                            for (int y = i; y < x; y++) {
                                itemArray[y] = itemArray[y + 1];
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "# of Items Sold: " << count << endl;
    cout << "# of Items Leftover: " << x << endl;
    cout << "Remaining items in the list: " << "\n" << endl;

    for (int i = 0; i < x; i++) {
        cout << itemArray[i].type << " " << itemArray[i].status << " $" << itemArray[i].price << endl;
    }
}

int main()
{
    void read_input(string f_path);
    read_input("garageSale.txt");
}