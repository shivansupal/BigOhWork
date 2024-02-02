class User {
public:
    string name;
    int receivedBricks;

    User(const string& name) : name(name), receivedBricks(0) {}

    void receiveBrick() {
        receivedBricks++;
    }
};