#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> deck(N, -1); // Initialize the deck with -1 (indicating an empty slot)

        int remainingCards = N;
        int position = 0;
        int cardToPlace = 1;

        while (remainingCards > 0) {
            while (deck[position % N] != -1) {
                position++; // Find an empty slot in the deck
            }

            if (cardToPlace <= remainingCards) {
                deck[position % N] = cardToPlace;
                cardToPlace++;
            } else {
                break; // No more cards to place
            }

            position++;
        }

        // Check if the trick was successful
        bool possible = true;
        for (int i = 0; i < N; i++) {
            if (deck[i] == -1) {
                possible = false;
                break;
            }
        }

        if (possible) {
            for (int i = 0; i < N; i++) {
                cout << deck[i] << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
