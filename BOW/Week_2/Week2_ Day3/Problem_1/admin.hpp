class Admin {
public:
    void editBrick(Brick& brick, const string& newCaption, const string& newMessage) {
        brick.caption = newCaption;
        brick.message = newMessage;
    }
};