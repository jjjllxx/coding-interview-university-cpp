#include "LinkedList.h"
#include <gtest/gtest.h>
#include <stdexcept>

namespace dsa_test
{
namespace LinkedList
{
    const dsa::LinkedList<int> EMPTY_LIST;
    const dsa::LinkedList<int> LINKED_LIST = { 1, 2, 3, 4, 5 };
} // namespace LinkedList
} // namespace dsa_test

GTEST_TEST(DS_LinkedList, initialise_with_list)
{
    EXPECT_EQ(dsa_test::LinkedList::LINKED_LIST.at(0), 1);
    EXPECT_EQ(dsa_test::LinkedList::LINKED_LIST.at(1), 2);
    EXPECT_EQ(dsa_test::LinkedList::LINKED_LIST.at(2), 3);
    EXPECT_EQ(dsa_test::LinkedList::LINKED_LIST.at(3), 4);
    EXPECT_EQ(dsa_test::LinkedList::LINKED_LIST.at(4), 5);
}

GTEST_TEST(DS_LinkedList, size)
{
    EXPECT_EQ(dsa_test::LinkedList::LINKED_LIST.size(), 5);
}

GTEST_TEST(DS_LinkedList, empty_true)
{
    EXPECT_TRUE(dsa_test::LinkedList::EMPTY_LIST.empty());
}

GTEST_TEST(DS_LinkedList, empty_false)
{
    EXPECT_FALSE(dsa_test::LinkedList::LINKED_LIST.empty());
}

GTEST_TEST(DS_LinkedList, subscript_operation_access)
{
    EXPECT_EQ(dsa_test::LinkedList::LINKED_LIST.at(2), 3);
}

GTEST_TEST(DS_LinkedList, subscript_operation_modify)
{
    dsa::LinkedList<int> ll = { 1, 2, 3 };
    ll.at(0)                = 3;
    EXPECT_EQ(ll.at(0), 3);
}

GTEST_TEST(DS_LinkedList, value_n_from_end)
{
    EXPECT_EQ(dsa_test::LinkedList::LINKED_LIST.value_n_from_end(1), 4);
}

GTEST_TEST(DS_LinkedList, value_n_from_end_out_of_range)
{
    EXPECT_THROW(dsa_test::LinkedList::LINKED_LIST.value_n_from_end(6), std::out_of_range);
}

GTEST_TEST(DS_LinkedList, push_front)
{
    dsa::LinkedList<int> ll          = { 1, 2, 3 };
    const int            val_to_push = 5;
    ll.push_front(val_to_push);
    EXPECT_EQ(ll.front(), val_to_push);
    EXPECT_EQ(ll.size(), 4);
}

GTEST_TEST(DS_LinkedList, push_front_empty)
{
    dsa::LinkedList<int> ll;
    const int            val_to_push = 5;
    ll.push_front(val_to_push);
    EXPECT_EQ(ll.front(), val_to_push);
    EXPECT_EQ(ll.back(), val_to_push);
    EXPECT_EQ(ll.size(), 1);
}

GTEST_TEST(DS_LinkedList, pop_front)
{
    dsa::LinkedList<int> ll = { 1, 2, 3 };
    EXPECT_EQ(ll.pop_front(), 1);
    EXPECT_EQ(ll.front(), 2);
    EXPECT_EQ(ll.size(), 2);
}

GTEST_TEST(DS_LinkedList, pop_front_empty)
{
    dsa::LinkedList<int> ll;
    EXPECT_THROW(ll.pop_front(), std::out_of_range);
}

GTEST_TEST(DS_LinkedList, push_back)
{
    dsa::LinkedList<int> ll          = { 1, 2, 3 };
    const int            val_to_push = 5;
    ll.push_back(val_to_push);
    EXPECT_EQ(ll.back(), val_to_push);
    EXPECT_EQ(ll.size(), 4);
}

GTEST_TEST(DS_LinkedList, push_back_empty)
{
    dsa::LinkedList<int> ll;
    const int            val_to_push = 5;
    ll.push_back(val_to_push);
    EXPECT_EQ(ll.front(), val_to_push);
    EXPECT_EQ(ll.back(), val_to_push);
    EXPECT_EQ(ll.size(), 1);
}

GTEST_TEST(DS_LinkedList, pop_back)
{
    dsa::LinkedList<int> ll = { 1, 2, 3 };
    EXPECT_EQ(ll.pop_back(), 1);
    EXPECT_EQ(ll.back(), 2);
    EXPECT_EQ(ll.size(), 2);
}

GTEST_TEST(DS_LinkedList, pop_back_empty)
{
    dsa::LinkedList<int> ll;
    EXPECT_THROW(ll.pop_back(), std::out_of_range);
}

GTEST_TEST(DS_LinkedList, front)
{
    EXPECT_EQ(dsa_test::LinkedList::LINKED_LIST.front(), 1);
}

GTEST_TEST(DS_LinkedList, front_empty)
{
    EXPECT_THROW(dsa_test::LinkedList::EMPTY_LIST.front(), std::out_of_range);
}

GTEST_TEST(DS_LinkedList, back)
{
    EXPECT_EQ(dsa_test::LinkedList::LINKED_LIST.back(), 5);
}

GTEST_TEST(DS_LinkedList, back_empty)
{
    EXPECT_THROW(dsa_test::LinkedList::EMPTY_LIST.back(), std::out_of_range);
}

GTEST_TEST(DS_LinkedList, insert_out_of_range)
{
    dsa::LinkedList<int> ll = { 1, 2, 3 };
    EXPECT_THROW(ll.insert(ll.size() + 2, 5), std::out_of_range);
}

GTEST_TEST(DS_LinkedList, insert_back)
{
    dsa::LinkedList<int> ll = { 1, 2, 3 };
    ll.insert(ll.size(), 5);
    EXPECT_EQ(ll.back(), 5);
}

GTEST_TEST(DS_LinkedList, insert_front)
{
    dsa::LinkedList<int> ll = { 1, 2, 3 };
    ll.insert(0, 5);
    EXPECT_EQ(ll.front(), 5);
}

GTEST_TEST(DS_LinkedList, insert)
{
    dsa::LinkedList<int> ll = { 1, 2, 3 };
    ll.insert(2, 5);
    EXPECT_EQ(ll.at(2), 5);
}

GTEST_TEST(DS_LinkedList, erase_out_of_range)
{
    dsa::LinkedList<int> ll = { 1, 2, 3, 4 };
    EXPECT_THROW(ll.erase(ll.size()), std::out_of_range);
}

GTEST_TEST(DS_LinkedList, erase_back)
{
    dsa::LinkedList<int> ll = { 1, 2, 3, 4 };
    ll.erase(ll.size() - 1);
    EXPECT_EQ(ll.back(), 3);
}

GTEST_TEST(DS_LinkedList, erase_front)
{
    dsa::LinkedList<int> ll = { 1, 2, 3, 4 };
    ll.erase(0);
    EXPECT_EQ(ll.front(), 2);
}

GTEST_TEST(DS_LinkedList, erase)
{
    dsa::LinkedList<int> ll = { 1, 2, 3, 4 };
    ll.erase(2);
    EXPECT_EQ(ll.at(0), 1);
    EXPECT_EQ(ll.at(1), 2);
    EXPECT_EQ(ll.at(2), 4);
}

GTEST_TEST(DS_LinkedList, remove)
{
    dsa::LinkedList<int> ll = { 2, 1, 2, 3, 4, 2 };
    ll.remove(2);
    EXPECT_EQ(ll.front(), 1);
    EXPECT_EQ(ll.at(1), 3);
    EXPECT_EQ(ll.back(), 4);
    EXPECT_EQ(ll.size(), 3);
}

GTEST_TEST(DS_LinkedList, remove_all_same)
{
    dsa::LinkedList<int> ll = { 2, 2, 2, 2, 2, 2 };
    ll.remove(2);
    EXPECT_TRUE(ll.empty());
    EXPECT_THROW(dsa_test::LinkedList::EMPTY_LIST.front(), std::out_of_range);
    EXPECT_THROW(dsa_test::LinkedList::EMPTY_LIST.back(), std::out_of_range);
}

GTEST_TEST(DS_LinkedList, reverse)
{
    dsa::LinkedList<int> ll = { 2, 1, 2, 3, 4, 5 };
    ll.reverse();
    EXPECT_EQ(ll.at(0), 5);
    EXPECT_EQ(ll.at(1), 4);
    EXPECT_EQ(ll.at(2), 3);
    EXPECT_EQ(ll.at(3), 2);
    EXPECT_EQ(ll.at(4), 1);
    EXPECT_EQ(ll.at(5), 2);
}

GTEST_TEST(DS_LinkedList, reverse_empty)
{
    dsa::LinkedList<int> ll;
    ll.reverse();
    EXPECT_TRUE(ll.empty());
}

GTEST_TEST(DS_LinkedList, reverse_one)
{
    dsa::LinkedList<int> ll = { 2 };
    ll.reverse();
    EXPECT_EQ(ll.back(), 2);
    EXPECT_EQ(ll.front(), 2);
}