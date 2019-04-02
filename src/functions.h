#include "constants.h"
#include <utility>

using namespace std;

// Convert pair of x y coordinates to Position enum member.
// If pr contains values above 7, or below 0 it will fail with an InvalidArgument exception.
Position pair_to_pos(pair<int, int> pr);

// Convert a Position number into a pair of x y coordiinates
pair<int, int> pos_to_pair(Position pn);
