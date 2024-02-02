class Wall {
public:
    int wallNumber;
    vector<Brick> bricks;

    Wall(int wallNumber) : wallNumber(wallNumber) {}

    void addBrick(const string& caption, const string& message, const string& owner) {
        bricks.emplace_back(caption, message, owner);
    }

    void flagBrick(Brick& brick) {
        brick.flagged = true;
    }

    int countInitiatedBricks() const {
        return bricks.size();
    }
};
