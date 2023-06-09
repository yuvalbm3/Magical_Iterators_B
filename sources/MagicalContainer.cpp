#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

#include <chrono>
#include <thread>

using namespace std;

namespace ariel
{
    MagicalContainer::MagicalContainer()
    {
    }
    MagicalContainer::MagicalContainer(std::vector<int> &vec)
    {
        _container = vec;
    }


    MagicalContainer::MagicalContainer(const MagicalContainer& other){
        _container = other._container;
    }

    MagicalContainer &MagicalContainer::MagicalContainer::operator=(const MagicalContainer& other) {
        if (this != &other) {
            _container = other._container;
        }
        return *this;
    }

    MagicalContainer &MagicalContainer::MagicalContainer::operator=(MagicalContainer&& other) noexcept {
        if (this != &other) {
            _container = std::move(other._container);
        }
        return *this;
    }

    MagicalContainer::MagicalContainer(MagicalContainer&& other) noexcept {
        _container = std::move(other._container);
    }


    MagicalContainer::~MagicalContainer()
    {
    }

    void MagicalContainer::addElement(int num)
    {
        // _container.push_back(num);
        auto it = std::lower_bound(this->_container.begin(), this->_container.end(), num);
        this->_container.insert(it, num);
    }

    void MagicalContainer::removeElement(int num)
    {
        auto it = std::find(_container.begin(), _container.end(), num);
        if (it != _container.end())
        {
            _container.erase(it);
        }
        else
        {
            throw runtime_error("");
        }
    }

    bool MagicalContainer::isPrime(int num)
    {
        if (num < 2)
        {
            // std::cout << "1.False" << std::endl;
            return false;
        }
        else if (num == 2)
        {
            // std::cout << "1.True" << std::endl;
            return true;
        }
        else if (num > 2 && num % 2 == 1)
        {
            for (int i = 2; i <= sqrt(num); i++)
            {
                if (num % i == 0)
                {
                    // std::cout << "2.False" << std::endl;
                    return false;
                }
            }
            // std::cout << "3.True" << std::endl;
            return true;
        }
        // std::cout << "4.True" << std::endl;
        return false;
    }

    // _____________AscendingIterator_____________

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
    {
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
    {
        AscendingIterator it(*_ascIt);
        it._index = _ascIt->_container.size();
        return it;
    }

    // MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    // {
    //     if (this->_ascIt != other._ascIt)
    //     {
    //         throw std::runtime_error("operator = ");
    //     }
    //     if (this != &other)
    //     {
    //         _ascIt = other._ascIt;
    //         _index = other._index;
    //     }
    //     return *this;
    // }

    int MagicalContainer::AscendingIterator::operator*()
    {
        return _ascIt->_container[_index];
    }

    bool operator==(const MagicalContainer::AscendingIterator &rhs, const MagicalContainer::AscendingIterator &lhs)
    {
        if (rhs._ascIt->size() == lhs._ascIt->size() && lhs._ascIt->size() == 0)
        {
            return true;
        }
        return rhs._index == lhs._index;
    }

    bool operator!=(const MagicalContainer::AscendingIterator &rhs, const MagicalContainer::AscendingIterator &lhs)
    {
        return rhs._index != lhs._index;
    }

    bool operator>(const MagicalContainer::AscendingIterator &rhs, const MagicalContainer::AscendingIterator &lhs)
    {
        return rhs._index > lhs._index;
    }

    bool operator<(const MagicalContainer::AscendingIterator &rhs, const MagicalContainer::AscendingIterator &lhs)
    {
        return rhs._index < lhs._index;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other)
    {
        if (this->_ascIt->_container != other._ascIt->_container)
        {
            throw runtime_error("");
        }
        return *this;
    }


    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept
    {
        if (this != &other)
        {
            this->_ascIt = other._ascIt;
            this->_index = other._index;
            other._ascIt = nullptr;
            other._index = 0;
        }
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (this->_index == this->end()._index)
        {
            throw runtime_error("");
        }
        this->_index++;
        return *this;
    }

    // _____________SideCrossIterator_____________

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
    {
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
    {
        SideCrossIterator iter(*_siCoIt);
        iter._index = _siCoIt->_container.size() + 1;
        return iter;
    }

    int MagicalContainer::SideCrossIterator::operator*()
    {
        return this->_siCoIt->_container[_index];
    }

    bool operator==(const MagicalContainer::SideCrossIterator &rhs, const MagicalContainer::SideCrossIterator &lhs)
    {
        if (rhs._siCoIt->size() == lhs._siCoIt->size() && lhs._siCoIt->size() == 0)
        {
            return true;
        }
        return rhs._index == lhs._index;
    }
    bool operator!=(const MagicalContainer::SideCrossIterator &rhs, const MagicalContainer::SideCrossIterator &lhs)
    {
        return rhs._index != lhs._index;
    }
    bool operator>(const MagicalContainer::SideCrossIterator &rhs, const MagicalContainer::SideCrossIterator &lhs)
    {
        return rhs._index > lhs._index;
    }
    bool operator<(const MagicalContainer::SideCrossIterator &rhs, const MagicalContainer::SideCrossIterator &lhs)
    {
        return rhs._index < lhs._index;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other)
    {
        if (this->_siCoIt->_container != other._siCoIt->_container)
        {
            throw runtime_error("");
        }
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept
    {
        if (this != &other)
        {
            this->_siCoIt = other._siCoIt;
            this->_index = other._index;
            other._siCoIt = nullptr;
            other._index = 0;
        }
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        size_t midle = (this->_siCoIt->size() / 2);
        if (this->_index == this->end()._index)
        {
            throw runtime_error("");
        }
        else if (this->_index == midle)
        {
            this->_index = this->_siCoIt->size() + 1;
        }
        else if (this->_index < midle)
        {
            this->_index = (size_t)end_i;
            end_i--;
        }
        else if (this->_index > midle)
        {
            this->_index = (size_t)start_i + 1;
            start_i++;
        }

        return *this;
    }

    // _____________PrimeIterator_____________

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &other_cont) : _primIt(&other_cont), _index(0), _np(0)
    {
        while (_index < _primIt->_container.size() && !_primIt->isPrime(_primIt->_container[_index]))
            ++_index;
    }
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
    {
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
    {
        PrimeIterator iter(*_primIt);
        if (_np == _primIt->_container.size())
        {
            iter._index = 0;
            return iter;
        }
        iter._index = _primIt->_container.size();
        return iter;
    }

    int MagicalContainer::PrimeIterator::operator*()
    {
        return _primIt->_container[_index];
    }

    bool operator==(const MagicalContainer::PrimeIterator &rhs, const MagicalContainer::PrimeIterator &lhs)
    {
        if (rhs._primIt->size() == lhs._primIt->size() && lhs._primIt->size() == 0)
        {
            return true;
        }
        return rhs._index == lhs._index;
    }

    bool operator!=(const MagicalContainer::PrimeIterator &rhs, const MagicalContainer::PrimeIterator &lhs)
    {
        return rhs._index != lhs._index;
    }

    bool operator>(const MagicalContainer::PrimeIterator &rhs, const MagicalContainer::PrimeIterator &lhs)
    {
        return rhs._index > lhs._index;
    }

    bool operator<(const MagicalContainer::PrimeIterator &rhs, const MagicalContainer::PrimeIterator &lhs)
    {
        return rhs._index < lhs._index;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other)
    {
        if (this->_primIt->_container != other._primIt->_container)
        {
            throw runtime_error("");
        }
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept
    {
        if (this != &other)
        {
            this->_primIt = other._primIt;
            this->_index = other._index;
            this->_np = other._np;
            other._primIt = nullptr;
            other._index = 0;
            other._np = 0;
        }
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (this->_index == this->end()._index)
        {
            throw runtime_error("");
        }
        ++_index;
        while (_index < _primIt->_container.size() && !_primIt->isPrime(_primIt->_container[_index]))
            ++_index;
        return *this;
    }

}
