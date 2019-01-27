#ifndef TASKCHECK_H
#define TASKCHECK_H
#include<string>
#include <utility>
#include <algorithm>
class TaskCheck
{
	public:
		TaskCheck();

		bool operator()();

		void swap(TaskCheck &check) 
		{

			std::swap(task_id_, check.task_id_);
		}
	public:
		void setTaskId(uint64_t task_id);

	private:
		uint64_t task_id_;
	
};

#endif
