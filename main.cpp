#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using qis = queue<pair<int, string>>;

int opD(int n) {
	auto ret = 2 * n;
	ret %= 10000;

	return ret;
}

int opS(int n) {
	if (0 == n) {
		return 9999;
	}

	const auto& ret = n - 1;

	return ret;
}

int opL(int n) {
	auto ret = n % 1000;
	ret *= 10;
	ret += n / 1000;

	return ret;
}

int opR(int n) {
	auto ret = n % 10;
	ret *= 1000;
	ret += n / 10;

	return ret;
}

string solve(int a, int b) {
	auto isVisited = vb(10000, false);
	isVisited[a] = true;

	auto q = qis{};
	q.push({ a, "" });

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		if (f.first == b) {
			return f.second;
		}

		const auto& vd = opD(f.first);
		if (!isVisited[vd]) {
			isVisited[vd] = true;
			q.push({ vd, f.second + "D" });
		}

		const auto& vs = opS(f.first);
		if (!isVisited[vs]) {
			isVisited[vs] = true;
			q.push({ vs, f.second + "S" });
		}

		const auto& vl = opL(f.first);
		if (!isVisited[vl]) {
			isVisited[vl] = true;
			q.push({ vl, f.second + "L" });
		}

		const auto& vr = opR(f.first);
		if (!isVisited[vr]) {
			isVisited[vr] = true;
			q.push({ vr, f.second + "R" });
		}
	}

	return "";
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		int a, b;
		cin >> a >> b;

		const auto& ans = solve(a, b);
		cout << ans << '\n';
	}

	return 0;
}