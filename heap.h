#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : num_children(m), comp(c)
  {}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() { arr.clear(); }

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void print() const;


private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> arr;
  void trickle_up(int index);
  int return_best_index(std::vector<int> indices) const;

  int num_children;
  PComparator comp;

};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Error: Attempting to get top of empty heap");

  }
  return arr[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Error: Attempting to pop empty heap");
  }
  std::swap(arr[0], arr[size() - 1]);
  arr.pop_back();

  int index = 0;
  int best_child_index;
  std::vector<int> child_indices;
  for (int i = 1; i <= num_children; i++) {
    if (index * num_children + i < size()) {
      child_indices.push_back(index * num_children + i);
    }
  }

  if (child_indices.empty()) { // at leaf
    return; 
  }
  else {  // need to potentially swap with only the best of the m children
    best_child_index = return_best_index(child_indices);
  }
  while (comp(arr[best_child_index], arr[index])) { // compare with best child
    std::swap(arr[index], arr[best_child_index]);
    index = best_child_index;
    
    child_indices.clear();
    for (int i = 1; i <= num_children; i++) {
      if (index * num_children + i < size()) {
        child_indices.push_back(index * num_children + i);
      }
    }
    if (child_indices.empty()) { // at leaf
      return;
    }
    else {  // need to potentially swap with only the better of the two children
      best_child_index = return_best_index(child_indices);
    }
  }

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return arr.size();
}
// 0 a1 b2 *a3 *a4 **b5 **b8
// 0  1  2   3   4   5    6
// if even: i / 2 - 1
// if odd: i / 2

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  arr.push_back(item);
  trickle_up(size() - 1);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickle_up(int index) {
  int parent_index = (index - 1) / num_children;

  while (index != 0 && comp(arr[index], arr[parent_index])) {
    std::swap(arr[index], arr[parent_index]);
    index = parent_index;
    parent_index = (index - 1) / num_children;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::print() const {
    int layer_capacity = 1;
    int layer = 1;
    int total_above = 0;
    for (int i = 0; i < size(); ++i) {
      if (i == layer_capacity + total_above) {
        layer += 1;
        total_above += layer_capacity;
        layer_capacity *= num_children;
    }
      std::cout << i << " " << layer << ": " << arr[i] << std::endl;
    }
    // 0; [ 1: a]
    // 1: [2: b]
    // 2 [2: c]
    // 3 [3: d]
    // 4 [3: e]
    // 5 [3: f]
    // 6 [3: g]
    // 7 [4: h]
}

template <typename T, typename PComparator>
int Heap<T,PComparator>::return_best_index(std::vector<int> children_indices) const {
  int best_i = children_indices[0];
  for (const int& index : children_indices) {
    if (comp(arr[index], arr[best_i])) {
      best_i = index;
    }
  }
  return best_i;
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return size() == 0;
}


#endif

