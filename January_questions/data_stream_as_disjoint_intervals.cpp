//Problem: Data stream as Disjoint Intervals
//Path: https://leetcode.com/problems/data-stream-as-disjoint-intervals/

//Code:

class SummaryRanges {
public:
  SummaryRanges() {     
  }
  void addNum(int val) {
    data_given.insert(val);
  }  
  vector<vector<int>> getIntervals() {
      vector<vector<int>> res;
      int start = -1;
      int end = -1;
      for ( auto  &item: data_given) {
          if (start == -1) {
              start = item;
              end = item;
          } else if (item == end + 1) {
              end = item;
          } else {
              res.push_back({start, end});
              start = end = item;
          }
      }
      if (start != -1) res.push_back({start, end});
      return res;
  }
private:
  set<int> data_given;
};

/*Explanationn of the above code:
    1. The class "SummaryRanges" has a default constructor which does not perform any operations.
    2. The "addNum" method takes an integer "val" as input and inserts it into the private member set "data_given".
    3. The "getIntervals" method returns a 2D vector of intervals that represent ranges of consecutive integers stored in "data_given".
    4. The "getIntervals" method uses two variables "start" and "end" to keep track of the current interval being constructed.
    5. The method scans the "data_given" set and adds the current item to the interval if it is consecutive with the previous item.
    6. If the current item is not consecutive, the current interval is added to the result vector and a new interval starts with the current item.
    7. The method returns the result vector of intervals even if "data_given" is empty.
    8. The "data_given" set stores the integers in sorted order due to its properties as a set.
    9. The class uses C++11 range-based for loop to iterate over the items in the "data_given" set.
    10. The "data_given" set is a private member of the class and is not accessible outside the class.
    11. The "data_given" set is used to store the integers in sorted order.
*/

//Time Complexity: O(n)
