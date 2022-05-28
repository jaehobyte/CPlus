#include <iostream>
#include <map>
#include <string>

/*  
셋의 경우 키만 보관했지만, 맵의 경우 키에 대응되는 값(value) 까지도 같이 보관한다 
맵의 경우 operator[] 를 이용해서 새로운 원소를 추가 가능 (만일 해당하는 키가 맵에 없다면). 
만일 키가 이미 존재하고 있다면 값이 대체됨
default값이 0 이므로 따라서 되도록이면 find 함수로 원소가 키가 존재하는지 먼저 확인 후에, 값을 참조하는 것이 좋음
원소에 대응되는 값을 바꾸고 싶다면 insert 를 하지 말고, [] 연산자로 대응되는 값을 바꿔주면 된다.

multimap에서는 한 개의 키에 여러개의 값이 대응될 수 있다는 것은 알 수 있다. 이 때문에 [] 연산자를 멀티맵의 경우 사용불가.
equal_range 함수의 경우 인자로 멀티맵의 키를 받은 뒤에, 이 키에 대응되는 원소들의 반복자들 중에서시작과 끝 바로 다음을 가리키는 반복자를 std::pair 객체로 만들어서 리턴.*/

template <typename K, typename V>
void print_map(std::map<K, V>& m) {
    // 맵의 모든 원소들을 출력하기
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        std::cout << itr->first << " " << itr->second << std::endl;
    }
}

int main() {
    std::map<std::string, double> pitcher_list;

    // 참고로 2017년 7월 4일 현재 투수 방어율 순위입니다.

    // 맵의 insert 함수는 pair 객체를 인자로 받습니다.
    pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
    pitcher_list.insert(std::pair<std::string, double>("해커 ", 2.93));

    pitcher_list.insert(std::pair<std::string, double>("피어밴드 ", 2.95));

    // 타입을 지정하지 않아도 간단히 std::make_pair 함수로
    // std::pair 객체를 만들 수 도 있습니다.
    pitcher_list.insert(std::make_pair("차우찬", 3.04));
    pitcher_list.insert(std::make_pair("장원준 ", 3.05));
    pitcher_list.insert(std::make_pair("헥터 ", 3.09));

    // 혹은 insert 를 안쓰더라도 [] 로 바로
    // 원소를 추가할 수 있습니다.
    pitcher_list["니퍼트"] = 3.56;
    pitcher_list["박종훈"] = 3.76;
    pitcher_list["켈리"] = 3.90;

    print_map(pitcher_list);

    std::cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << std::endl;

    std::multimap<int, std::string> m;
    m.insert(std::make_pair(1, "hello"));
    m.insert(std::make_pair(1, "hi"));
    m.insert(std::make_pair(1, "ahihi"));
    m.insert(std::make_pair(2, "bye"));
    m.insert(std::make_pair(2, "baba"));

    std::cout << "--------------------" << std::endl;

    // 1 을 키로 가지는 반복자들의 시작과 끝을
    // std::pair 로 만들어서 리턴한다.
    auto range = m.equal_range(1);
    for (auto itr = range.first; itr != range.second; ++itr) {
        std::cout << itr->first << " : " << itr->second << " " << std::endl;
    }
}