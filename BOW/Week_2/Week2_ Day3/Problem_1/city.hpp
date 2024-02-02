class City {
public:
    vector<Wall> walls;

    void initiateNewWall() {
        walls.emplace_back(walls.size() + 1);
    }

    int countInitiatedWalls() const {
        return walls.size();
    }
};