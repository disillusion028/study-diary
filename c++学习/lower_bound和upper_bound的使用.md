> std::lower_bound   
> std::upper_bound

这两个模板函数在map/set/multimap/multiset这几个有序容器中都有实现，lower_bound其原型为:
```
default (1)	
template <class ForwardIterator, class T>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                               const T& val);
custom (2)	
template <class ForwardIterator, class T, class Compare>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                               const T& val, Compare comp);
```
lower_bound/upper_bound的实现一般是binary search。
lower_bound 返回的是一个指向在[first,last)范围中第一个不小于val的迭代器，upper_bound返回的是一个指向在[first,last)范围中第一个大于val 的迭代器，由于该函数通过比较排序范围的非连续元素来优化比较次数，对于随机访问迭代器这种优化更加有效。
平均时间复杂度：在随机访问迭代器上大约是log2(N)次比较（N是first到last的距离），在非随机访问迭代器上平均大约附加一个N的线性时间复杂度。
```
//其binary search代码类似于：
template <class ForwardIterator, class T>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator it;
  iterator_traits<ForwardIterator>::difference_type count, step;
  count = distance(first,last);
  while (count>0)
  {
    it = first; step=count/2; advance (it,step);
    if (*it<val) {                 // or: if (comp(*it,val)), for version (2)
      first=++it;
      count-=step+1;
    }
    else count=step;
  }
  return first;
}
```
