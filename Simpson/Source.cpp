#include "Twin.h"
#include <cmath>

typedef std::vector<double> vec;

vec gvec(Twin&);
void dvec(Twin&, const vec&);
double simp(const int&, const double&, const vec&);

int main() {

	Twin t("Simpsons Rule");

	double a, b, h;
	int n;
	vec y;

	while (true) {

		t.println("Enter lower bound 'a'.");
		t.display();

		std::cin >> a;
		std::cin.ignore(1000, '\n');
		std::cin.clear();

		t.println("Enter upper bound 'b'.");
		t.display();

		std::cin >> b;
		std::cin.ignore(1000, '\n');
		std::cin.clear();

		t.println("Enter subintervals 'n'.");
		t.display();

		std::cin >> n;
		std::cin.ignore(1000, '\n');
		std::cin.clear();

		h = (b - a) / n;

		t.println("Confirm input:");
		t.println();
		t.println("Lower bound a = ");
		t.print(a);
		t.println("Upper bound b = ");
		t.print(b);
		t.println("Subintervals n = ");
		t.print(n);
		t.println("Subintervals size h = ");
		t.print(h);
		t.println();
		t.println("Enter 'x' to save and continue.");
		t.display();

		char input;
		std::cin >> input;
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		if (input == 'x' || input == 'X') break;
	}

	t.println("Choose an option:");
	t.println();
	t.println("[1] Use built in function f(x).");
	t.println("[2] Enter vector y of n+1 elements.");
	t.display();

	int input;
	std::cin >> input;
	std::cin.ignore(1000, '\n');
	std::cin.clear();

	if (input == 1)
		for (double i = a; i <= b; i += h)
			y.push_back(1 - i - 4 * pow(i, 3) + 2 * pow(i, 5));

	if (input == 2) {

		while (true) {

			t.println("Enter the first element of Vector y.");
			t.println("Example: 2.3");
			t.display();

			double el;
			std::cin >> el;
			std::cin.ignore(1000, '\n');
			std::cin.clear();
			y.push_back(el);

			for (int i = 0; i < n; i++) {
				t.println("Vector y:");
				t.println();
				dvec(t, y);
				t.println("Enter the next element.");
				t.display();

				std::cin >> el;
				std::cin.ignore(1000, '\n');
				std::cin.clear();
				y.push_back(el);
			}

			t.println("Vector y:");
			t.println();
			dvec(t, y);
			t.println("Enter 'x' to save and continue.");
			t.display();

			char save;
			std::cin >> save;
			std::cin.ignore(1000, '\n');
			std::cin.clear();

			if (save == 'x' || save == 'X') break;

			else y.clear();

		}

	}

	double answer = simp(n, h, y);

	t.println("Integral = ");
	t.print(answer);
	t.println();
	t.println("Press enter to exit. . .");
	t.display();

	std::cin.ignore(1000, '\n');
	std::cin.clear();

	return EXIT_SUCCESS;
}

double simp(const int& n, const double& h, const vec& y) {

	bool odd = n % 2;
	double sum = 0;

	if (n == 1)
		return .5 * h * (y.front() + y.back());

	else {

		int m = n;
		if (odd) {
			sum = 3.0 / 8.0 * h * (y[n - 3] + 3.0 * (y[n - 2] + y[n - 1]) + y[n]);
			m = n - 3;
		}

		if (m > 1) {
			double sub = y.front();
			for (int i = 1; i < m - 2; i += 2)
				sub += 4.0 * y[i] + 2.0 * y[i + 1];
			sub += 4.0 * y[m - 1] + y[m];
			sum += h * sub / 3.0;
		}

		return sum;
	}
}

vec gvec(Twin& t) {

	vec b;
	double in;
	std::string input;

	std::getline(std::cin, input);
	std::stringstream iss(input);
	iss >> in;
	b.push_back(in);

	while (true) {

		t.println("Vector:");
		t.println();
		dvec(t, b);
		t.println("Enter the next element.");
		t.println("Enter 'x' to save and continue.");
		t.display();

		std::getline(std::cin, input);
		std::stringstream iss(input);
		iss >> in;

		if (input == "x" || input == "X") return b;
		else b.push_back(in);

	}
}

void dvec(Twin& t, const vec& vec) {

	for (auto&& i : vec) {
		t.println("[ ");
		t.print(i);
		t.print(" ]");
	}

	t.println();
}