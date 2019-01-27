#include "sync.h"
#include "checkqueue.h"
#include <boost/thread/thread.hpp>
#include "task_check.h"

int main(int argc,char*argv[])
{

	boost::thread_group threadGroup;
	CCheckQueue<TaskCheck> task_check_queue(128);
	CCheckQueueControl<TaskCheck> control(&task_check_queue);

	for (int i=0; i<5; i++)
		threadGroup.create_thread(boost::bind(&CCheckQueue<TaskCheck>::Thread, boost::ref(task_check_queue)));

	std::vector<TaskCheck> vChecks;
	for(uint32_t i = 0; i < 20; i++) 
	{
//		std::vector<TaskCheck> vChecks;	
		vChecks.push_back(TaskCheck());

		TaskCheck check;
		check.setTaskId(i);
		check.swap(vChecks.back());
//		control.Add(vChecks);
	}
	
	control.Add(vChecks);		
	control.Wait();

	threadGroup.join_all();


	return 0;
}
