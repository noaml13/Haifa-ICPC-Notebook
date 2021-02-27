#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#include "sqsort.h"
//#include "sqsort.cpp"
#include <bits/stdc++.h>
using namespace std;
static const int HARD_LIMIT = 50000000;

static int n;
static std::vector<int> a;

static bool valid_pos(int i) {
	return 0 <= i && i < n;
}

static int Q;
bool cmp(int a_, int b, int c, int d) {
	if(!valid_pos(a_) || !valid_pos(b) || !valid_pos(c) || !valid_pos(d)) {
		std::cerr << "Invalid query." << std::endl;
		std::cout << -1 << std::endl;
		exit(0);
	}

	Q++;
	if(Q > HARD_LIMIT) {
		std::cerr << "Too many queries." << std::endl;
		std::cout << -1 << std::endl;
		exit(0);
	}

	return a[a_] + a[b] < a[c] + a[d];
}

static bool check_valid(const std::vector<std::pair<int, int>> &a) {
	if(n * (n + 1) / 2 != (int)a.size()) {
		return false;
	}

	std::vector<std::vector<bool>> used(n, std::vector<bool>(n, false));
	for(int i = 0; i < (int)a.size(); i++) {
		if(!valid_pos(a[i].first) || !valid_pos(a[i].second) || used[a[i].first][a[i].second]) {
			return false;
		}

		used[a[i].first][a[i].second] = true;
		used[a[i].second][a[i].first] = true;
	}

	return true;
}

int main() {
	std::cin >> n;
	a.resize(n);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	for(int i = 0; i < n; i++) {
		a[i] = uniform_int_distribution<int>(0,100*n)(rng);
	}

	Q = 0;
	std::vector<std::pair<int, int>> ret = solve(n);	
	std::cout << "Q = " << Q << std::endl;
	
	if(!check_valid(ret)) {
		std::cerr << "Invalid output." << std::endl;
		std::cout << -1 << std::endl;
		return 0;
	}

	for(int i = 1; i < (int) ret.size(); i++) { 
		if(a[ret[i].first] + a[ret[i].second] < a[ret[i - 1].first] + a[ret[i - 1].second]) {
			std::cerr << "Output not sorted." << std::endl;
			std::cout << -1 << std::endl;
			return 0;
		}
	}
	
	std::cerr << "Correct!" << std::endl;
	return 0;
}

