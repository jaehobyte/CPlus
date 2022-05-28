#include <iostream>
#include <vector>
#include <list>

template <typename T>
void print_vector(std::vector<T>& vec) {
	// 전체 벡터를 출력하기
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
		++itr) {
		std::cout << *itr << std::endl;
	}
}

int main() {

	/* vector의 경우 새 데이터를 추가하거나 제거 : O(1)
	   임의의 원소에 접근 : [i], at --> O(1)*/

	std::vector<int> vec;

	vec.push_back(10);  // 맨 뒤에 10 추가
	vec.push_back(20);  // 맨 뒤에 20 추가
	vec.push_back(30);  // 맨 뒤에 30 추가
	vec.push_back(40);  // 맨 뒤에 40 추가

	for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
		std::cout << "vec 의 " << i + 1 << " 번째 원소 :: " << vec[i] << std::endl;
	}

	/* vector 의 경우 현재 가지고 있는 원소의 개수 보다 더 많은 공간을 할당한다.
	예를 들어 현재 vector 에 있는 원소의 개수가 10 개라면 이미 20개를 저장할 수 있는 공간을 미리 할당한다.
	따라서 만약에 뒤에 새로운 원소를 추가하게 된다면 새롭게 메모리를 할당할 필요가 없이,  그냥 이미 할당된 공간에 그 원소를 쓰게된다.
	따라서 대부분의 경우 O(1) 으로 vector 맨 뒤에 새로운 원소를 추가하거나 지울 수 있음.

	문제가 되는 상황은 할당된 공간을 다 채웠을 때는 어쩔 수 없이, 새로운 큰 공간을 다시 할당하고,
	기존의 원소들을 복사한다 따라서 이 경우 n 개의 원소를 모두 복사해야 하기 때문에 O(n) 으로 수행됨.
	하지만 이 O(n)O(n) 으로 수행되는 경우가 매우 드물기 때문에, 전체적으로 평균을 내보았을 때 O(1) 수행됨.
	이렇기에 amortized O(1) 부른다
	*/
}