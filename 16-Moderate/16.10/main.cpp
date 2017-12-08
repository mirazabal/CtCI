#include <cstdint>
#include <vector>


struct People{
	std::size_t birthYear;
	std::size_t deathYear;
};


std::size_t yearMostLivingPeople(const std::vector<People>& people){

	std::size_t retYear{1900};
	std::size_t livingPeople{0};
	std::vector<std::size_t> birthYearVec;
	birthYearVec.reserve(100);
	std::vector<std::size_t> deathYearVec;
	deathYearVec.reserve(100);
	for(auto& person : people){
		birthYearVec[person.birthYear - 1900] = birthYearVec[person.birthYear - 1900] + 1;
		deathYearVec[person.deathYear - 1900] = deathYearVec[person.deathYear - 1900] + 1;
	}

	for(auto i = 0; i < 100; ++i){
		std::size_t actualLiving = livingPeople + birthYearVec[i] - deathYearVec[i];
		if(actualLiving > livingPeople){
			livingPeople = actualLiving;
			retYear = 1900 + i;
		}
	}

	return retYear;
}



int main()
{



}
