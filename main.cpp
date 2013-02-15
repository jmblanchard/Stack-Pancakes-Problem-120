// Flip on the highest number, then flip on the position it needs to
// end up in.

#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>

void flip(std::vector<int> &v, int posToFlip) {
    int printThePos = v.size() - posToFlip;

    for (int i = 0; i <= posToFlip/2; ++i) {
        int temp = v[posToFlip-i];
        v[posToFlip-i] = v[i];
        v[i] = temp;
    }

    std::cout << printThePos << " ";
}

int main() {
    std::vector<int> stack;
    std::vector<int> sortedStack;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty())
            break;

        std::istringstream stream(line);
        std::istream_iterator<int> begin(stream), eof;
        stack = std::vector<int>(begin, eof);

        sortedStack = stack;
        std::sort(sortedStack.begin(), sortedStack.end());

        int currMaxPos = stack.size()-1;
        int currMax = sortedStack[currMaxPos];
        int currPos;
        int goalPos = stack.size()-1;

        for (int i = 0; i < stack.size(); ++i) {
            std::cout << stack[i];
            if (i != stack.size()-1)
                std::cout << " ";
        }
        std::cout << "\n";

        while (stack != sortedStack) {
            // find position of currMax in stack
            for (int i = 0; i < stack.size(); ++i) {
                if (stack[i] == currMax) {
                    currPos = i;
                    break;
                }
            }

            // we have position, now we need to see if its on the
            // "top" of the stack. if not, we flip on our currPos
            if (currPos != 0 && currPos != goalPos) {
                flip(stack, currPos);
                currPos = 0;
            }

            if (currPos != goalPos) {
                flip(stack, goalPos);
                currPos = goalPos;
            }

            currMaxPos--;
            goalPos = currMaxPos;
            if (currMaxPos > 0)
                currMax = sortedStack[currMaxPos];
        }

        std::cout << "0\n";

        stack.clear();
        sortedStack.clear();
    }

    return 0;
}
