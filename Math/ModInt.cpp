template<int MOD_> 
struct Mint {
	int MOD = MOD_;
	int value;

	Mint() {
		value = 0;
	}
	Mint(ll value_) {
		value = value_ % MOD;
		if (value < 0) {
			value += MOD;
		}
	}

	void operator=(ll value_) {
		value = value_;
	}
	Mint operator-() const {
		return Mint(-value);
	}
	bool operator==(const Mint& other) {
		return value == other.value;
	}
	bool operator!=(const Mint& other) {
		return value != other.value;
	}
	Mint& operator++() {
		value++;
		if (value == MOD) {
			value = 0;
		}
		return *this;
	}
	Mint& operator--() {
		if (value == 0) {
			value = MOD;
		}
		value--;
		return *this;
	}
	Mint& operator+=(const Mint& other) {
		value += other.value;
		if (value >= MOD) {
			value -= MOD;
		}
		return *this;
	}
	Mint& operator-=(const Mint& other) {
		value -= other.value;
		if (value < 0) {
			value += MOD;
		}
		return *this;
	}
	Mint& operator*=(const Mint& other) {
		value = 1ll * value * other.value % MOD;
		return *this;
	}
	Mint& operator/=(const Mint& other) {
		return *this *= other.modinv();
	}
	Mint pwr(ll pw) const {
		Mint ret = 1, a = value;
		while (pw > 0) {
			if (pw & 1) {
				ret *= a;
			}
			a *= a;
			pw >>= 1;
		}
		return Mint(ret);
	}
	Mint modinv() const {
		return Mint(value).pwr(MOD - 2);
	}
	friend Mint operator+(const Mint& a, const Mint& b) {
		return Mint(a) += b;
	}
	friend Mint operator-(const Mint& a, const Mint& b) {
		return Mint(a) -= b;
	}
	friend Mint operator*(const Mint& a, const Mint& b) {
		return Mint(a) *= b;
	}
	friend Mint operator/(const Mint& a, const Mint& b) {
		return Mint(a) /= b;
	}
	friend std::istream& operator>>(std::istream& in, Mint& a) {
		ll value_;
		in >> value_;
		a = Mint(value_);
		return in; 
	}
	friend std::ostream& operator<<(std::ostream& out, const Mint& a) {
		return out << a.value;
	}
};