#include<bits/stdc++.h>
using namespace std;

#include"brick.hpp"
#include"wall.hpp"
#include"user.hpp"
#include"city.hpp"
#include"admin.hpp"

int main() {
    City city;
    Admin admin;

    // Input 2 users from the command line
    vector<User> users;
    
    for (int i = 0; i < 2; ++i) {
        string username;
        cout << "Enter username for user " << i + 1 << ": ";
        cin >> username;
        users.emplace_back(username);
    }

    // Example usage:
    city.initiateNewWall();
    city.walls[0].addBrick("Love", "Happy Valentine's Day!", users[0].name);
    city.walls[0].addBrick("Friendship", "Best friends forever!", users[1].name);

    // Admin edits a brick
    admin.editBrick(city.walls[0].bricks[0], "Revised Love", "Wishing a lovely day!");

    // User receives a brick
    users[2].receiveBrick();

    // Check total number of walls and initiated bricks
    cout << "Total walls: " << city.countInitiatedWalls() << endl;
    cout << "Bricks in wall 1: " << city.walls[0].countInitiatedBricks() << endl;

    return 0;
}