# include <namespace>
# include <string>
usingn namespace std;

long int n, result;

long int factorial(f) {
	if (f == 0 or f == 1)
		return 1;
	else
		result = f * factorial(f - 1)
		return result;
}

int main() {
	cin >> n;
	cout << factorial(n) << endl; '
}