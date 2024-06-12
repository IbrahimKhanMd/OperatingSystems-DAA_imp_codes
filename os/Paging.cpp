#include <iostream>
using namespace std;
int main() {
  int page_size, num_pages;
  int job_count, job_size, pages_needed;
  cout << "Enter the physical address space (total memory size): ";
  cin >> page_size; // Assuming page size represents total memory here
  cout << "Enter the size of each page (page size): ";
  cin >> page_size;
  num_pages = page_size / page_size; // All memory acts as pages
  int page_table[num_pages];
  for (int i = 0; i < num_pages; i++) {
    page_table[i] = -1; // -1 represents free page
  }
  cout << "Enter the number of jobs: ";
  cin >> job_count;
  for (int job_num = 1; job_num <= job_count; job_num++) {
    cout << "Enter the size of job " << job_num << ": ";
    cin >> job_size;
    pages_needed = job_size / page_size;
    if (job_size % page_size != 0) {
      pages_needed++;
    }
if (pages_needed <= num_pages) {
      // Allocate pages for the job
      bool allocated_all = false;
      for (int i = 0; i < num_pages && !allocated_all; i++) {
        if (page_table[i] == -1) {
          page_table[i] = job_num;
          pages_needed--;
          if (pages_needed == 0) {
            allocated_all = true;
          }
        }
      }
      if (allocated_all) {
        cout << "Memory allocated for job " << job_num << endl;
        cout << "Page table: " << endl;
        for (int i = 0; i < num_pages; i++) {
          cout << "page[" << i << "] = " << page_table[i] << endl;
        }
      }
	  else {
        cout << "Not enough memory for job " << job_num << endl;
      }
    }
	else {
      cout << "Not enough memory for job " << job_num << endl;
    }
  }
  return 0;
}
