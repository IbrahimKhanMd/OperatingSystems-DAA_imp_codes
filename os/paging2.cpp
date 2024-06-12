#include <iostream>
using namespace std;
#define MAX 50
int main() {
    int page[MAX], i, n, f, ps, off, pno;
    int choice = 0;
    cout << "\nEnter the number of pages in memory: ";
    cin >> n;
    cout << "\nEnter page size: ";
    cin >> ps;
    cout << "\nEnter the number of frames: ";
    cin >> f;
    for (i = 0; i < n; i++)
        page[i] = -1;
    cout << "\nEnter the page table" << endl;
    cout << "(Enter frame no as -1 if that page is not present in any frame)" << endl;
    cout << "\nPageNo\tFrameNo\n-------\t-------" << endl;
    for (i = 0; i < n; i++) {
        cout << "\n\n" << i << "\t\t";
        cin >> page[i];
    }
    do {
        cout << "\n\nEnter the logical address (i.e., page no & offset): ";
        cin >> pno >> off;
        if (page[pno] == -1)
            cout << "\n\nThe required page is not available in any of the frames";
        else
            cout << "\n\nPhysical address (i.e., frame no & offset): " << page[pno] << "," << off;
        cout << "\nDo you want to continue (1/0)?: ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
