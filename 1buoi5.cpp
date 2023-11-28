#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ExpressionFinder {
public:
    ExpressionFinder(int n, long long target_sum, const vector<long long>& sequence)
        : n(n), target_sum(target_sum), sequence(sequence) {}

    // Function to find the expression
    string findExpression() {
        for (int i = 0; i < (1 << (n - 1)); ++i) {
            long long current_sum = sequence[0];
            string expression = to_string(sequence[0]);

            for (int j = 0; j < n - 1; ++j) {
                if (i & (1 << j)) {
                    current_sum += 2 * sequence[j + 1];
                    expression += '.';
                } else {
                    current_sum += sequence[j + 1];
                    expression += '+';
                }
                expression += to_string(sequence[j + 1]);
            }

            if (current_sum == target_sum) {
                return expression;
            }
        }

        return "Impossible";
    }

private:
    int n;
    long long target_sum;
    vector<long long> sequence;
};

int main() {
    int N;
    long long S;
    cin >> N >> S;

    vector<long long> sequence(N);
    for (int i = 0; i < N; ++i) {
        cin >> sequence[i];
    }

    ExpressionFinder expressionFinder(N, S, sequence);
    string result = expressionFinder.findExpression();
    cout << result << endl;

    return 0;
}
