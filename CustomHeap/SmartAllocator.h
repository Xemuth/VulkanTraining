#ifndef _CustomHeap_SmartAllocator_h_
#define _CustomHeap_SmartAllocator_h_

#include <Core/Core.h>

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
		
		short GenerateUniqueID();
	private:
		
		#ifdef _MSC_VER
			#pragma( pack(push, 1) )
		#endif
		typedef struct{
			short size; //Size of the current allocation used by this block (in number of block)
			short allocId; //Unique allocation ID, used to retrieve information if necessary
			byte used; //flag to know if the block is allocated
		}MBlock
		#ifdef  __GNUC__
			__attribute__((packed))
		#endif
		;
		#ifdef _MSC_VER
			#pragma( pack(pop))
		#endif
	
	
		typedef struct{
			MBlock* previous;
			MBlock* current;
		}BlockFound;
	
		unsigned int m_heapSize;
		unsigned int m_blockSize;
		char* m_begin = nullptr;
		char* m_end = nullptr;
		char* m_heap = nullptr;
		
		static SmartAllocator* m_allocator;
		
		BlockFound FindFreeBlock(int size); //Size in bytes
};

}
#endif
