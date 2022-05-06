#include <iostream>
#include <vector>

struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

stats inserts_sort(std::vector<int>& data) {
	stats tmp;
	for (size_t i = 1; i < data.size(); i++) {
		for (size_t j = i; j > 0; j--) {
			tmp.comparison_count++;
			if (data[j - 1] > data[j]) {
				int temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;
				tmp.copy_count++;
			}
		}
	}
	return tmp;
}

stats shell_sort(std::vector<int>& data) {
	stats tmp;
	size_t j;
	size_t size = data.size();
	for (size_t step = size / 2; step > 0; step /= 2) {
		for (size_t i = step; i < size; i++) {
			int temp = data[i];
			for (j = i; j >= step; j-=step) {
				tmp.comparison_count++;
				if (temp < data[j - step]) {
					data[j] = data[j - step];
					tmp.copy_count++;
				}
				else break;
			}
			data[j] = temp;
		}
	}
	return tmp;
}

int main() {
	std::vector<int> test = { 5, 4, 12, 6, 2, 7, 18};
	stats result = shell_sort(test);
	std::cout << result.comparison_count << std::endl;
	std::cout << result.copy_count << std::endl;
	for (auto i = test.begin(); i != test.end(); ++i) {
		std::cout << *i << std::endl;
	}
}