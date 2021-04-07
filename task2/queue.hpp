#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <vector>
#include <stdexcept>

template <typename T>
class Queue
{
public:
  Queue(const int numberOfAvailableElements);

  void put(const T& object);
  T get() const;
  void removeFirst();
  void clear();

private:
  std::vector<T> queue_;
  size_t headNumber_;
  size_t tailNumber_;
  size_t numberOfElements_;
};

template<typename T>
Queue<T>::Queue(const int numberOfAvailableElements) :
  headNumber_(0),
  numberOfElements_(0)
{
  if (numberOfAvailableElements <= 0)
  {
    throw std::invalid_argument("Invalid number of elements\n");
  }

  queue_ = std::vector<T>(numberOfAvailableElements);
  if (numberOfAvailableElements == 1)
  {
    tailNumber_ = 0;
  }
  else
  {
    tailNumber_ = 1;
  }
}

template<typename T>
void Queue<T>::put(const T& object)
{
  if (numberOfElements_ == queue_.size())
  {
    throw std::runtime_error("The queue is full. You need to remove elements before adding new ones.");
  }

  queue_[tailNumber_] = object;
  numberOfElements_++;
  if (tailNumber_ == queue_.size() - 1)
  {
    tailNumber_ = 0;
  }
  else
  {
    tailNumber_++;
  }
}

template<typename T>
T Queue<T>::get() const
{
  if (!numberOfElements_)
  {
    throw std::runtime_error("You can't get elements from empty queue");
  }

  if (headNumber_ == queue_.size() - 1)
  {
    return queue_[0];
  }

  return queue_[headNumber_ + 1];
}

template<typename T>
void Queue<T>::removeFirst()
{
  if (!numberOfElements_)
  {
    throw std::runtime_error("You can't remove elements from empty queue");
  }

  if (headNumber_ == queue_.size() - 1)
  {
    headNumber_ = 0;
  }
  else
  {
    headNumber_++;
  }

  numberOfElements_--;
}

template<typename T>
void Queue<T>::clear()
{
  numberOfElements_ = 0;

  if (!tailNumber_)
  {
    headNumber_ = queue_.size() - 1;
  }
  else
  {
    headNumber_ = tailNumber_ - 1;
  }
}

#endif
