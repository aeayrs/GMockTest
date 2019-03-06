//============================================================================
// Name        : GMockTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;
using ::testing::_;
using ::testing::Return;

class QueueInterface {
public:
	virtual ~QueueInterface(){};
	virtual void enqueue(int data) = 0;
	virtual int dequeue() = 0;
};

class DataHolder {
public:
	DataHolder(QueueInterface *queue):queue(queue){};
	void addData(int data) {
		queue->enqueue(data);
	}
	int getData() {
		return queue->dequeue();
	}

protected:
	QueueInterface *queue;
};

class MockQueue: public QueueInterface {
public:
	MOCK_METHOD0(dequeue, int());
	MOCK_METHOD1(enqueue, void(int data));
};

//-----------------------------------------------------------------------------
//              UNIT TESTS
//-----------------------------------------------------------------------------

class GMockTests : public ::testing::Test {
protected:
	MockQueue myMockObject;
	DataHolder dh = DataHolder(&myMockObject);
};

TEST_F(GMockTests, CanAddData) {
//	MockQueue myMockObject;
//	DataHolder dh(&myMockObject);
	EXPECT_CALL(myMockObject, enqueue(_));
	dh.addData(1);
}
TEST_F(GMockTests, CanAddAndGetData) {
//	MockQueue myMockObject;
//	DataHolder dh(&myMockObject);

	EXPECT_CALL(myMockObject, enqueue(1));
	EXPECT_CALL(myMockObject, dequeue()).WillOnce(Return(1));
	dh.addData(1);
	int data = dh.getData();
	ASSERT_EQ(1, data);
}
