#include <iostream>
#include <cstddef>
#include <array>
#include <type_traits>
#include <cstdint>

template<typename container>
auto
operator *(container&& left,
           container&& right) {

  std::remove_reference_t<container> result {
    /* [0][0] */ left[0][0]*right[0][0] + left[0][1]*right[1][0],
    /* [0][1] */ left[0][0]*right[0][1] + left[0][1]*right[1][1],

    /* [1][0] */ left[1][0]*right[0][0] + left[1][1]*right[1][0],
    /* [1][1] */ left[1][0]*right[0][1] + left[1][1]*right[1][1],
  };

  return result;
}

template<typename container, typename stream_out>
stream_out&
operator <<(stream_out& out,
            container&& cr) {

  for (auto&& line : cr) {
    for (auto&& element : line) {
      out << element << ' ';
    }

    out << '\n';
  }

  return out;
}

int
main(void) {
  int number;
  std::cin >> number;

  std::array<std::array<std::uint32_t, 2u>, 2u> base {
    0u, 1u,
    1u, 1u
  }, state = base;

  for (int n{}; n < number-1; ++n) {
    state = state * base;
  }

  std::cout << state;
}
