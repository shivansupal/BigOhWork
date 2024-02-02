class Currency {
public:
    vector<Note> notes;

    Currency(initializer_list<Note> initList) : notes(initList) {}

    void addNotes(int count) {
        for (Note& note : notes) {
            note.count += count;
        }
    }
};