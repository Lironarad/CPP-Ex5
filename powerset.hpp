
#pragma once
#include <math.h>
#include <set>
#include <functional>

namespace itertools{
	

	template<typename T>
	class powerset{

	//class members
	private:
		T it;
		
		//count the elements in the full set
		uint fullSize() const {
			int size=0;
			for (auto i: it)
				size++;
			return size;
		}		

	public:
		powerset<T>(const T _it): it(_it) {}

		class const_iterator {
			
			//class members
			private:
				const T& fullSet;
				int indSubSet;	

			public:
				const_iterator(const T& _fullSet, int index): fullSet(_fullSet), indSubSet(index) { }


				auto operator*() const {
					//initialize empty set with the iterator type
					std::set<typename std::remove_reference<typename std::remove_const<decltype(*(it.begin()))>::type>::type> subset = {};
					int index=1;
					//fill the set with elements
					for (auto i : fullSet){
						if (index & indSubSet) //bitwise AND
							subset.insert(i);
						index++;
					}
					return subset;
				}

				// ++i;
				const_iterator& operator++() {
					++indSubSet;//increament to the next subset
					return *this;
				}

				// i++;
				const const_iterator operator++(int) {
					const_iterator tmpIt(*this);
					++indSubSet;
					return tmpIt;
				}

				bool operator==(const const_iterator& other) const {
					if(indSubSet == other.indSubSet)
						return true;
					return false;
				}

				bool operator!=(const const_iterator& other) const {
					if(indSubSet == other.indSubSet)
						return false;
					return true;
				}

				template <typename U>
				friend std::ostream& operator <<(std::ostream& os, const typename powerset<U>::const_iterator& it);

		};  // END OF CLASS const_iterator

		const_iterator begin() const {
			return powerset<T>::const_iterator(this->it, 0);//the begin is the first set
		}
			
		const_iterator end() const {
			return powerset<T>::const_iterator(this->it, int(pow(2,fullSize())));//the end is the set in the index of all subsets
		}

	};   // END OF CLASS powerset



	template <typename U>
	std::ostream& operator <<(std::ostream& output, const typename std::set<U> set) {
	
	auto it = set.begin();
	auto itEnd = set.end();
	
	//insert the first element of the subset
    output<< "{";
    if(it != itEnd){
        output << *it; 
        ++it;
    }
	
	//insert all other elements of the subset
    while (it != itEnd){
        output << ',' << *it;
        ++it;
    }
	
    output << "}";
    return output;
}

}
