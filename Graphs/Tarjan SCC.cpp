struct SCC {
	int N, timer, n_comps;
	vector<vector<int>> adj;
	vector<int> val, low, comp, comp_size;
	vector<bool> onStack;
	vector<int> stk;

	// vertices are 1-indexed!
	SCC(int N_ = 0) {
		N = N_;
		adj.resize(N + 1);
	}

	// vertices are 1-indexed!
	SCC(const vector<vector<int>>& adj_) {
		adj = adj_;
		N = adj.size() - 1;
	}
 
	void add_edge(int a, int b) {
		adj[a].push_back(b);
	}
 
	void tarjan(int v) {
		low[v] = val[v] = timer++;
		onStack[v] = 1;
		stk.push_back(v);
		for (int to : adj[v]) {
			if (val[to] == 0) {
				tarjan(to);
				low[v] = min(low[v], low[to]);
			} else if (onStack[to]) {
				low[v] = min(low[v], val[to]);
			}
		}
		if (low[v] == val[v]) {
			n_comps++;
			while (true) {
				int u = stk.back();
				stk.pop_back();
				onStack[u] = 0;
				comp[u] = n_comps;
				++comp_size[n_comps];
				if (u == v) {
					break;
				}
			}
		}
	}
 
	void build() {
		timer = 1;
		n_comps = 0;
		val = low = comp = comp_size = vector<int>(N + 1);
		onStack = vector<bool>(N + 1);
		stk.clear();
 
		for (int i = 1; i <= N; i++) {
			if (!val[i]) {
				tarjan(i);
			}
		}
	}
};