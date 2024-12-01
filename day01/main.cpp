#include "test_data.hpp"
#include "live_data.hpp"

#include <__ranges/chunk_by_view.h>
#include <numeric>
#include <ranges>
#include <algorithm>
#include <array>
#include <print>

constexpr int abs(int l, int r)
{
	return l >= r ? l - r : r - l;
}

template<std::size_t N>
constexpr int part1(std::array<int, N> const& data)
{
	auto l = std::array<int, N / 2>{};
	auto r = std::array<int, N / 2>{};
	for(std::size_t i = 0; i < N / 2; ++i)
	{
		l.at(i) = data.at(i * 2);
		r.at(i) = data.at(i * 2 + 1);
	}
	std::ranges::sort(l);
	std::ranges::sort(r);
	auto zipped = std::views::zip(l, r);
	return std::accumulate(zipped.begin(), zipped.end(), 0, [](int acc, auto left_and_right) {
		auto [l, r] = left_and_right;
		return acc + abs(l, r);
	});
}

template<std::size_t N>
constexpr int part2(std::array<int, N> const& data)
{
	auto l = std::array<int, N / 2>{};
	auto r = std::array<int, N / 2>{};
	for(std::size_t i = 0; i < N / 2; ++i)
	{
		l.at(i) = data.at(i * 2);
		r.at(i) = data.at(i * 2 + 1);
	}
	return std::accumulate(l.begin(), l.end(), 0, [&r](int acc, int l) {
		int occurences = std::ranges::count(r, l);
		return acc + l * occurences;
	});
}

int main()
{
	constexpr int testAnswer1 = part1(testData);
	static_assert(testAnswer1 == 11);

	constexpr int liveAnswer1 = part1(liveData);
	static_assert(liveAnswer1 == 765748);

	constexpr int testAnswer2 = part2(testData);
	static_assert(testAnswer2 == 31);

	constexpr int liveAnswer2 = part2(liveData);
	static_assert(liveAnswer2 == 27732508);
}