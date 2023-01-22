template<typename T, bool mode_max = false>
struct SparseTable {
	int N, K;
	vector<int> lg;
	vector<T> arr;
	vector<vector<int>> st;

	int compare(int a, int b) {
		return (mode_max ? (arr[a] > arr[b]) : (arr[a] < arr[b])) ? a : b;
	}

	void build_logs() {
		lg = vector<int>(N + 1);
		lg[1] = 0;
		for (int i = 2; i <= N; i++) {
			lg[i] = lg[i / 2] + 1;
		}
		K = lg[N];
	}

	SparseTable(const vector<T>& arr_) {
		// arr_ should be 1-indexed!
		arr = arr_;
		N = arr.size() - 1;
		build_logs();
		st = vector<vector<int>> (K + 1, vector<int>(N + 1));
		iota(st[0].begin(), st[0].end(), 0);

		for (int i = 1; i <= K; i++) {
			for (int j = 1; j + (1 << i) <= N + 1; j++) {
				st[i][j] = compare(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	int query_index(int l, int r) {
		int i = lg[r - l + 1];
		return compare(st[i][l], st[i][r - (1 << i) + 1]);
	}

	T query_value(int l, int r) {
		return arr[query_index(l, r)];
	}
};