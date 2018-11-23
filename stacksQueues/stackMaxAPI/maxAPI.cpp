// implements a max function in the stack class 
// efficiently with a cached struct
// version one that keeps max int stored 

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std; 

class Stack {
	public:
	 
		bool Empty() const {
			if (element_with_cached_max_.size() == 0) {
				return true;
			}
			return false;
		}
		
		int Max() const {
			if (Empty()) {
				throw length_error("Max(): empty stack"); 
			}
			//cout << "Max: " << element_with_cached_max_.top().max << endl;
			return element_with_cached_max_.top().max; 
		}
		
		int Pop() {
			if (Empty()) {
				throw length_error("Pop(): empty stack"); 
			}
			int pop_element = element_with_cached_max_.top().element; 
			cout << "Pop: " << pop_element << endl;
			element_with_cached_max_.pop(); // stack function 
			return pop_element; 
		}
		
		void Push(int x) {
			element_with_cached_max_.emplace(ElementWithMaxCache{x, max(x, Empty() ? x : Max())});
			cout << "Push: " << x << endl; 
		}
		
			
	private: 
		struct ElementWithMaxCache {
			int element; 
			int max; 
		};
		
		stack<ElementWithMaxCache> element_with_cached_max_; 

}; 

int main() {
	
	Stack new_stack; 
	new_stack.Push(1); 
	new_stack.Push(10);
	new_stack.Push(2);
	new_stack.Push(0);
	 
	
	return 0; 
}
