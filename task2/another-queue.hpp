#ifndef ANOTHER_QUEUE_HPP
#define ANOTHER_QUEUE_HPP

#include <vector>
#include <stdexcept>

template <typename T>
class AnotherQueue
{
  public:
  AnotherQueue(const int numberOfAvailableElements);

  void put(const T& object);
  T getAndRemoveFirst();
  void clear();

  private:
    std::vector<T> queue_;
    size_t headNumber_;
    size_t tailNumber_;
    size_t numberOfElements_;
};

template<typename T>
AnotherQueue<T>::AnotherQueue(const int numberOfAvailableElements):
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
void AnotherQueue<T>::put(const T& object)
{
  queue_[tailNumber_] = object;

  if (numberOfElements_ == queue_.size())
  {
    if (headNumber_ == queue_.size() - 1)
    {
      headNumber_ = 0;
    }
    else
    {
      headNumber_++;
    }
  }
  else
  {
    numberOfElements_++;
  }

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
T AnotherQueue<T>::getAndRemoveFirst()
{
  if (!numberOfElements_)
  {
    throw std::runtime_error("You can't get elements from empty queue");
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
  return queue_[headNumber_];
}

template<typename T>
void AnotherQueue<T>::clear()
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
