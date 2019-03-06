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

TEST(GMockTests, CanInstantiateDataHolder) {
	MockQueue myMockObject;
	DataHolder dh(&myMockObject);
}
TEST(GMockTests, CanAddData) {
	MockQueue myMockObject;
	DataHolder dh(&myMockObject);

	dh.addData(1);
}
