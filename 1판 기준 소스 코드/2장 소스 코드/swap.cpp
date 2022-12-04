template <typename T>
inline void swap(T& a, T& b) {
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}
