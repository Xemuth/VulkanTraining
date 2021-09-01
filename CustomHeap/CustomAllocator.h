#ifndef _CustomHeap_CustomAllocator_h_
#define _CustomHeap_CustomAllocator_h_


class CustomAllocator{
	public:
		
		static CustomAllocator& GetAllocator();
		
		unsigned int GetCurrentHeapSize();
		
		void* _malloc(unsigned int size);
		void* _realloc(void* ptr, unsigned int size);
		
		void* _aligned_malloc(unsigned int size, unsigned int alignement);
		void* _aligned_realloc(void* ptr, unsigned int size, unsigned int alignement);
		
		void  _free(void* ptr);
	private:
		
		CustomAllocator
		
	private:
		unsigned int m_size;
		void* m_begin = nullptr;
		void* m_end = nullptr;
		char* m_heap = nullptr;
		int* m_allocationMatrix = nullptr;
		
		CustomAllocator* m_allocator = nullptr;
};


#endif
