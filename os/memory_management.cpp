#include <iostream>
#include <vector>
using namespace std;
class MemorySegment {
private:
int startAddress;
int endAddress;
int segmentSize;
public:
MemorySegment(int start, int size) : startAddress(start), segmentSize(size) {
endAddress = startAddress + segmentSize;
}
bool allocate(int requestedSize) {
if (requestedSize <= segmentSize) {
segmentSize -= requestedSize;
endAddress -= requestedSize;
return true;
} else {
return false;
}
}
void deallocate(int deallocatedSize) {
segmentSize += deallocatedSize;
endAddress += deallocatedSize;
}
void display() {
cout << "Start Address: " << startAddress << ", End Address: " << endAddress <<
", Size: " << segmentSize << endl;
}
};
int main() {
vector<MemorySegment> memory;
memory.push_back(MemorySegment(0, 100));
memory.push_back(MemorySegment(100, 50));
memory.push_back(MemorySegment(150, 200));
memory[0].allocate(20);
memory[1].allocate(30);
for (size_t i = 0; i< memory.size(); ++i) {
memory[i].display();
}
memory[0].deallocate(10);
memory[1].deallocate(20);
for (size_t i = 0; i< memory.size(); ++i) {
memory[i].display();
}
return 0;
}
