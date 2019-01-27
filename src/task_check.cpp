#include "task_check.h"
#include <iostream>
TaskCheck::TaskCheck()
{
}

bool TaskCheck::operator() ()
{
	std::cout << "taskcheck: "  << task_id_ << " run !" << std::endl;
	return true;
}

void TaskCheck::setTaskId(uint64_t task_id)
{
	task_id_ = task_id;
}
