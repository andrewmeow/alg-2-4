#include "..//gtest/gtest-all.cc"
#include "d_heaps.h"
#include "skip_list.h"
#include "priority_queue.h"

//DHeap
TEST(DHeapTest, ConstructorInvalidD) {
    EXPECT_THROW(DHeap<int> heap(1), const char*);
}

TEST(DHeapTest, ConstructorValidD) {
    EXPECT_NO_THROW(DHeap<int> heap(3));
}

TEST(DHeapTest, InsertSingleElement) {
    DHeap<int> heap(3);
    heap.Insert(10);
    ASSERT_EQ(heap.size(), 1);
    EXPECT_EQ(heap.isEmpty(), false);
}

TEST(DHeapTest, InsertMultipleElements) {
    DHeap<int> heap(3);
    heap.Insert(10);
    heap.Insert(20);
    heap.Insert(5);
    ASSERT_EQ(heap.size(), 3);
}

TEST(DHeapTest, RemoveExistingElement) {
    DHeap<int> heap(3);
    heap.Insert(10);
    heap.Insert(20);
    heap.Insert(5);
    heap.Remove(10);
    ASSERT_EQ(heap.size(), 2);
    EXPECT_NO_THROW(heap.Remove(20));
    EXPECT_NO_THROW(heap.Remove(5));
    EXPECT_TRUE(heap.isEmpty());
}

TEST(DHeapTest, RemoveNonExistingElement) {
    DHeap<int> heap(3);
    heap.Insert(10);
    heap.Insert(20);
    EXPECT_THROW(heap.Remove(15), const char*);
}

TEST(DHeapTest, IsEmpty) {
    DHeap<int> heap(3);
    EXPECT_TRUE(heap.isEmpty());
    heap.Insert(10);
    EXPECT_FALSE(heap.isEmpty());
}

TEST(DHeapTest, Size) {
    DHeap<int> heap(3);
    EXPECT_EQ(heap.size(), 0);
    heap.Insert(10);
    EXPECT_EQ(heap.size(), 1);
    heap.Insert(20);
    EXPECT_EQ(heap.size(), 2);
}

TEST(DHeapTest, Print) {
    DHeap<int> heap(3);
    heap.Insert(10);
    heap.Insert(20);
    heap.Insert(5);
    testing::internal::CaptureStdout();
    heap.Print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "20 10 5 \n");
}
//SkipList
TEST(SkipListTest, InsertSingleElement) {
    SkipList<int> list;
    list.Insert(10);
    EXPECT_TRUE(list.Find(10));
}

TEST(SkipListTest, InsertMultipleElements) {
    SkipList<int> list;
    list.Insert(10);
    list.Insert(20);
    list.Insert(5);
    EXPECT_TRUE(list.Find(10));
    EXPECT_TRUE(list.Find(20));
    EXPECT_TRUE(list.Find(5));
}

TEST(SkipListTest, FindExistingElement) {
    SkipList<int> list;
    list.Insert(10);
    EXPECT_TRUE(list.Find(10));
}

TEST(SkipListTest, FindNonExistingElement) {
    SkipList<int> list;
    list.Insert(10);
    EXPECT_FALSE(list.Find(20));
}


TEST(SkipListTest, RemoveExistingElement) {
    SkipList<int> list;
    list.Insert(10);
    list.Insert(20);
    list.Insert(5);
    list.Remove(10);
    EXPECT_FALSE(list.Find(10));
    EXPECT_TRUE(list.Find(20));
    EXPECT_TRUE(list.Find(5));
}

TEST(SkipListTest, RemoveNonExistingElement) {
    SkipList<int> list;
    list.Insert(10);
    EXPECT_NO_THROW(list.Remove(20));
    EXPECT_TRUE(list.Find(10));
}

TEST(SkipListTest, Print) {
    SkipList<int> list;
    list.Insert(10);
    list.Insert(20);
    list.Insert(5);
    testing::internal::CaptureStdout();
    list.Print();
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output; 
    EXPECT_FALSE(output.empty());
}
//PriorityQueue
TEST(PriorityQueueTest, PushSingleElement) {
    PriorityQueue<int> pq(5);
    EXPECT_NO_THROW(pq.Push(10, 3));
}

TEST(PriorityQueueTest, PushElementWithInvalidPriority) {
    PriorityQueue<int> pq(5);
    EXPECT_THROW(pq.Push(10, 6), const char*);
}

// Тесты для функции Pop
TEST(PriorityQueueTest, PopSingleElement) {
    PriorityQueue<int> pq(5);
    pq.Push(10, 3);
    EXPECT_EQ(pq.Pop(), 10);
}

TEST(PriorityQueueTest, PopMultipleElements) {
    PriorityQueue<int> pq(5);
    pq.Push(10, 3);
    pq.Push(20, 2);
    pq.Push(5, 4);
    EXPECT_EQ(pq.Pop(), 20);
    EXPECT_EQ(pq.Pop(), 10);
    EXPECT_EQ(pq.Pop(), 5);
}

TEST(PriorityQueueTest, PopFromEmptyQueue) {
    PriorityQueue<int> pq(5);
    EXPECT_THROW(pq.Pop(), const char*);
}

// Тесты для функции IsEmpty
TEST(PriorityQueueTest, IsEmptyInitially) {
    PriorityQueue<int> pq(5);
    EXPECT_TRUE(pq.IsEmpty());
}

TEST(PriorityQueueTest, IsEmptyAfterPush) {
    PriorityQueue<int> pq(5);
    pq.Push(10, 3);
    EXPECT_FALSE(pq.IsEmpty());
}

TEST(PriorityQueueTest, IsEmptyAfterPop) {
    PriorityQueue<int> pq(5);
    pq.Push(10, 3);
    pq.Pop();
    EXPECT_TRUE(pq.IsEmpty());
}