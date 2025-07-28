#include <iostream>
using namespace std;

// Function to convert a string number in a given base to an integer
int baseToDecimal(string value, int base) {
    int result = 0;
    for (int i = 0; i < value.length(); ++i) {
        char c = value[i];
        int digit;

        if (c >= '0' && c <= '9') digit = c - '0';
        else if (c >= 'a' && c <= 'f') digit = 10 + (c - 'a');
        else if (c >= 'A' && c <= 'F') digit = 10 + (c - 'A');
        else {
            cout << "Invalid character '" << c << "' in value: " << value << endl;
            return -1;
        }

        if (digit >= base) {
            cout << "Invalid digit '" << c << "' for base " << base << " in value: " << value << endl;
            return -1;
        }

        result = result * base + digit;
    }
    return result;
}

// Function to perform Lagrange interpolation at x = 0
int lagrangeInterpolation(int x[], int y[], int k) {
    int secret = 0;
    for (int i = 0; i < k; i++) {
        long long num = 1;
        long long denom = 1;

        for (int j = 0; j < k; j++) {
            if (i != j) {
                num *= -x[j];
                denom *= (x[i] - x[j]);
            }
        }

        if (denom == 0) continue;  // Avoid division by zero

        long long term = (y[i] * num) / denom;
        secret += term;
    }
    return secret;
}

int main() {
    int k;
    cout << "Enter threshold (k): ";
    cin >> k;

    int x[100], y[100];
    int count = 0;

    cout << "Enter " << k << " points in format: <x_base> <x_value> <y_base> <y_value>\n";
    cout << "(e.g. 10 2 2 111 means x=2 (base 10), y=7 (binary 111))\n";

    while (count < k) {
        int xbase, ybase;
        string xval, yval;

        cout << "Point " << count + 1 << ": ";
        cin >> xbase >> xval >> ybase >> yval;

        int xdec = baseToDecimal(xval, xbase);
        int ydec = baseToDecimal(yval, ybase);

        if (xdec == -1 || ydec == -1) {
            cout << "Invalid input. Try again.\n";
            continue;
        }

        x[count] = xdec;
        y[count] = ydec;
        count++;
    }

    int secret = lagrangeInterpolation(x, y, k);
    cout << "\n=== Reconstructed Secret ===\n";
    cout << "Secret: " << secret << endl;

    return 0;
}
