#include <iostream>
#include <set>

/* 셋에 원소를 추가하거나 지우는 작업은 O(log N)
결과적으로 셋은 원소의 삽입과 삭제를 O(log N) 원소의 탐색도 O(log N) 에 수행하는 자료 구조*/

template <typename T>
void print_set(std::set<T>& s) {
    // 셋의 모든 원소들을 출력하기
    std::cout << "[ ";
    for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << " ] " << std::endl;
}
int main() {
    std::set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    std::cout << "순서대로 정렬되서 나온다" << std::endl;
    print_set(s);

    std::cout << "20 이 s 의 원소인가요? :: ";
    auto itr = s.find(20);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    std::cout << "25 가 s 의 원소인가요? :: ";
    itr = s.find(25);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    // 멀티셋은 중복값 허용
    std::multiset<std::string> ms;

    ms.insert("a");
    ms.insert("b");
    ms.insert("a");
    ms.insert("c");
    ms.insert("d");
    ms.insert("c");

}