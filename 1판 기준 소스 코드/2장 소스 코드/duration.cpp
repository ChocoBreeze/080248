#include <chrono>
#include <iostream>
#include <ratio>

int main() {

	std::cout << std::fixed << std::endl;

	typedef std::chrono::duration<long long, std::ratio<1>> MySecondTick;
	MySecondTick aSecond(1);

	std::chrono::nanoseconds nano(aSecond);
	std::cout << nano.count() << "나노초";

	std::chrono::milliseconds milli(aSecond); // 이거는 왜 cast필요없지
	std::cout << milli.count() << "밀리초";

	std::chrono::seconds sec(aSecond);
	std::cout << sec.count() << "초";

	std::chrono::minutes min(duration_cast<std::chrono::minutes>(aSecond)); // 이거는 왜 cast 필요하지
	std::cout << min.count() << "분";

	typedef std::chrono::duration<double, std::ratio<2700>> MyLessonTick;
	MyLessonTick myLesson(aSecond);
	std::cout << myLesson.count() << "수업";

	return 0;
}


