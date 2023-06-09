#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H

#include <vector>
#include <string>
#include <math.h>
#include <iterator>
#include <cstddef>
#include <algorithm> // Added for std::sort

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> _container;

    public:
        MagicalContainer();
        MagicalContainer(std::vector<int> &);
        ~MagicalContainer();
        void addElement(int);
        void removeElement(int);
        bool isPrime(int);
        size_t size() const
        {
            return this->_container.size();
        }

        class AscendingIterator
        {
        private:
            MagicalContainer *_ascIt;
            std::vector<int>::size_type _index;

        public:
            AscendingIterator(MagicalContainer &container) : _ascIt(&container), _index(0)
            {
                std::sort(_ascIt->_container.begin(), _ascIt->_container.end());
            }
            AscendingIterator(const AscendingIterator &other) : _ascIt(other._ascIt), _index(other._index){};
            AscendingIterator() : _ascIt(nullptr), _index(0){};
            ~AscendingIterator() {}
            // int size();
            AscendingIterator begin() const;
            AscendingIterator end() const;

            // move assignment operator
            // AscendingIterator &operator=(AscendingIterator &&other) noexcept;

            // move constructor
            AscendingIterator(AscendingIterator &&other) noexcept : _ascIt(other._ascIt), _index(0) {}

            // AscendingIterator &operator=(const AscendingIterator &other);

            int operator*();
            friend bool operator==(const AscendingIterator &rhs, const AscendingIterator &lhs);
            friend bool operator!=(const AscendingIterator &rhs, const AscendingIterator &lhs);
            friend bool operator>(const AscendingIterator &rhs, const AscendingIterator &lhs);
            friend bool operator<(const AscendingIterator &rhs, const AscendingIterator &lhs);
            AscendingIterator& operator=(const AscendingIterator &other);
            AscendingIterator& operator++();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer *_siCoIt;
            std::vector<int>::size_type _index;
            std::vector<int>::size_type _end_i;
            int start_i = 0;
            int end_i = _siCoIt->_container.size() - 1;

        public:
            SideCrossIterator(MagicalContainer &other_cont) : _siCoIt(&other_cont), _index(0), _end_i(other_cont._container.size() - 1)
            {
                std::sort(_siCoIt->_container.begin(), _siCoIt->_container.end());
            }
            SideCrossIterator() : _siCoIt(nullptr), _index(0), _end_i(0){};
            ~SideCrossIterator() {}
            SideCrossIterator begin() const;
            SideCrossIterator end() const;

            int operator*();
            friend bool operator==(const SideCrossIterator &rhs, const SideCrossIterator &lhs);
            friend bool operator!=(const SideCrossIterator &rhs, const SideCrossIterator &lhs);
            friend bool operator>(const SideCrossIterator &rhs, const SideCrossIterator &lhs);
            friend bool operator<(const SideCrossIterator &rhs, const SideCrossIterator &lhs);
            SideCrossIterator& operator=(const SideCrossIterator &other);
            SideCrossIterator& operator++();
        };

        class PrimeIterator
        {
        private:
            MagicalContainer *_primIt;
            std::vector<int>::size_type _index;
            std::vector<int>::size_type _np; //not prime

        public:
            PrimeIterator(MagicalContainer &other_cont);
            PrimeIterator(const PrimeIterator &other) : _primIt(other._primIt), _index(other._index){};
            ~PrimeIterator();

            PrimeIterator begin() const;
            PrimeIterator end() const;

            int operator*();
            friend bool operator==(const PrimeIterator &rhs, const PrimeIterator &lhs);
            friend bool operator!=(const PrimeIterator &rhs, const PrimeIterator &lhs);
            friend bool operator>(const PrimeIterator &rhs, const PrimeIterator &lhs);
            friend bool operator<(const PrimeIterator &rhs, const PrimeIterator &lhs);
            PrimeIterator& operator=(const PrimeIterator &other);
            PrimeIterator& operator++();
        };
    };

}

#endif
