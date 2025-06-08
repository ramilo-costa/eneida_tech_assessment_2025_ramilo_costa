#include <iostream>
#include "message_receiver.h"


MessageReceiver::MessageReceiver()
    : nextMessageId(0), max_size_msg(5) {
}

void MessageReceiver::receive(uint8_t id, const std::string& text) {
    messages[id] = text;
    // Only try to print if we have at least 'max_size_msg' messages stored
    if (messages.size() >= max_size_msg) {
        print();
    }
}

void MessageReceiver::print() {
    // Continue iterating as long as there are enough messages to form a batch of 5
    while (messages.size() >= max_size_msg) {
        // Start ID for the current batch. Assumes first valid ID is 1.
        // nextMessageId tracks the last printed ID, so we start from next one.
        uint8_t startId = nextMessageId + 1;

        // Print 5 consecutive messages starting from startId
        for (uint8_t i = 0; i < max_size_msg; ++i) {
            uint8_t currentId = startId + i;
            if (messages.count(currentId)) {
                std::cout << messages[currentId] << std::endl;
                messages.erase(currentId);
            } else {
                std::cout << "[faulty message for ID " << currentId << "]" << std::endl;
            }
        }
        // Update nextMessageId to the last ID that was just printed. Because I went through the whole batch of message (5). now, as my startId is 1 I have to deduct 1 from to reach max otherwise i'll be reaching max(5) + startid(1)
        nextMessageId = startId + (max_size_msg - 1);
    } 
    
}