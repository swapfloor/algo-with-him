namespace treetree{
template <class T> std::vector<int> kmp(const std::vector<T>& s) {
    int n = int(s.size());
	vector<int> p(n + 1);
	for (int i = 1, j = 0; i < n; i++) {
		while (j && s[i] != s[j]) j = p[j];
		j += (s[i] == s[j]);
		p[i + 1] = j;
	}
	return p;
}

std::vector<int> kmp(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return kmp(s2);
}
}
