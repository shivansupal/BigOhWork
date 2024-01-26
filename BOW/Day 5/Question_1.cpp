#include <iostream>
#include <unordered_set>
using namespace std;
 
// Function to find all interleaving of string `X` and `Y`
void findInterleavings(string result, string X, string Y, auto &interleavings)
{
    // insert `result` into the set if the end of both strings is reached
    if (!X.length() && !Y.length())
    {
        interleavings.insert(result);
        return;
    }
 
    // if the string `X` is not empty, append its first character in the
    // result and recur for the remaining substring
 
    if (X.length()) {
        findInterleavings(result + X[0], X.substr(1), Y, interleavings);
    }
 
    // if the string `Y` is not empty, append its first character in the
    // result and recur for the remaining substring
 
    if (Y.length()) {
        findInterleavings(result + Y[0], X, Y.substr(1), interleavings);
    }
}
 
unordered_set<string> findInterleavings(string X, string Y)
{
    // use set to handle duplicates
    unordered_set<string> interleavings;
 
    if (!X.length() && !Y.length()) {
        return interleavings;
    }
 
    findInterleavings("", X, Y, interleavings);
    return interleavings;
}
 
int main()
{
    string X = "AB";
    string Y = "C";
 
    unordered_set<string> interleavings = findInterleavings(X, Y);
    for (string s: interleavings) {
        cout << s << endl;
    }
 
    return 0;
}

//This code is contributed by Shivansu Pal