#include <iostream>
#include <string>
#include "message_receiver.h" // Include your class header

int main() {
    MessageReceiver receiver;

    // Simulate receiving messages out of order
    receiver.receive(1, "Hello");
    receiver.receive(2, "World");
    receiver.receive(4, "Missing␣ID␣3");
    receiver.receive(5, "Another");
    receiver.receive(6, "End␣of␣batch");

    return 0;
}