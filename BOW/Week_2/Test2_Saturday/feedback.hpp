class Feedback {
public:
    string comment;
    int rating; // Assuming rating is an integer between 1 and 5

    Feedback(const string& c, int r) : comment(c), rating(r) {}

};