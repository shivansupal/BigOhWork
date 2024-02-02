class Brick {
public:
    string caption;
    string message;
    string owner;
    bool flagged;

    Brick(const string& caption, const string& message, const string& owner)
        : caption(caption), message(message), owner(owner), flagged(false) {}

    void animate() {
        // Animate brick when owner visits the city wall
        cout << "Animating brick for owner: " << owner << endl;
    }
};