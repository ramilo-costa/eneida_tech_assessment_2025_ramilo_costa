#ifndef MESSAGE_RECEIVER_H
#define MESSAGE_RECEIVER_H

#include <string>
#include <map>

class MessageReceiver {
private:
    std::map<uint8_t, std::string> messages;
    uint8_t nextMessageId;
    const uint8_t max_size_msg;

    void print(); 

public:
    MessageReceiver();

    void receive(uint8_t id, const std::string& text);
};

#endif 