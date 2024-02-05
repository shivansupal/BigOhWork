class ImageStatus : public Status {
public:
    string imagePath;
    ImageStatus(string _content, string _imagePath) : Status(_content), imagePath(_imagePath) {}
};