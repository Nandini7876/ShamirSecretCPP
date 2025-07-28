# Shamir Secret Sharing in C++

This project implements **Shamir's Secret Sharing Scheme** using pure C++ without using any inbuilt libraries. The program supports:

- User-defined number of points and thresholds
- Custom base input (e.g., binary, decimal, hexadecimal)
- Manual base-to-decimal conversion
- Polynomial interpolation to reconstruct the secret

---

## 🔧 How It Works

1. **Input**: User enters the number of threshold points and provides each `(x, y)` point in a custom base.
2. **Conversion**: The program manually converts all base values to decimal.
3. **Interpolation**: Performs Lagrange interpolation to recover the original secret (value at `x = 0`).

---

## 💻 Example Input

Enter threshold (k): 3
Enter 3 points in format: <x_base> <x_value> <y_base> <y_value>
Point 1: 10 1 10 4
Point 2: 10 2 2 111
Point 3: 10 3 10 12


---

## 📦 Files

- `main.cpp`: Contains the full source code.
- `README.md`: This file.

---

## 🚀 How to Run

```bash
g++ main.cpp -o main
./main
📌 Notes
The program avoids using standard libraries like <cmath>, <bitset>, <std::stoi>, etc.

It manually handles base conversion and interpolation logic for full transparency.

Ideal for learning number systems, modular arithmetic, and polynomial math.

👩‍💻 Author
Nandini Raj
GitHub: @Nandini7876
