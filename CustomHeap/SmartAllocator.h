#ifndef _CustomHeap_SmartAllocator_h_
#define _CustomHeap_SmartAllocator_h_

namespace Upp{

class SmartAllocator{
	public:
		static SmartAllocator& GetAllocator(unsigned int heapSize, unsigned int blockSize);
		static void DestroyAllocator();
		
		unsigned int GetCurrentHeapSize()const;
		
		void* _malloc(unsigned int size);
	//	void* _realloc(void* ptr, unsigned int size);
		
	//	void* _aligned_malloc(unsigned int size, unsigned int alignement);
	//	void* _aligned_realloc(void* ptr, unsigned int size, unsigned int alignement);
		void  _free(void* ptr);
		
	private:
		
		SmartAllocator(unsigned int heapSize, unsigned int alignement);
		~SmartAllocator();
		
	private:
		typedef struct{
			char* pNext; //Next usable memory block
			char* pPrevious; //Previous usable memory block
			char* pMem; //Ptr to the current usable memory block
			short size; //Size of the current allocation used by this block (in number of block)
			short allocId; //Unique allocation ID, used to retrieve information if necessary
		}MBlock __attribute__((packed));
		
		unsigned int m_heapSize;
		unsigned int m_blockSize;
		char* m_begin = nullptr;
		char* m_end = nullptr;
		char* m_heap = nullptr;
		
		static SmartAllocator* m_allocator;
		
		MBlock* FindFreeBlock(int size); //Size in bytes
};

}
#endif
