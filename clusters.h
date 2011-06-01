#ifndef __CLUSTERS_H__
#define __CLUSTERS_H__

#include <linux/fs.h>
#include <vector>
#include <deque>
#include <string>

inline __u64 minu64(__u64 a, __u64 b) {
	if (a < b) return a; else return b;	
}

inline __u64 maxu64(__u64 a, __u64 b) {
	if (a > b) return a; else return b;	
}

typedef struct {
	__u64 start, length;
} tuple;

typedef std::deque<tuple> tuple_list;

typedef struct {
	tuple_list extents;
	std::string name;
} f_info;

typedef std::deque<f_info> file_list;
typedef std::vector<f_info *> file_p_list;
//typedef std::deque<f_info> file_p_list;

typedef struct {
	file_p_list files;
	int free;
	int fragmented;
} cluster_info;

typedef std::deque<cluster_info> cluster_list;

extern file_list files2;
extern cluster_list clusters2;
extern pthread_mutex_t clusters2_mutex;
extern pthread_mutex_t files2_mutex;

void collect_fragments(const char *initial_dir, file_list *files, pthread_mutex_t *files_mutex);
__u64 get_device_size_in_blocks(const char *initial_dir);
void __fill_clusters(file_list *files, __u64 device_size_in_blocks, 
					cluster_list *clusters, __u64 cluster_count,
					int frag_limit);

#endif // __CLUSTERS_H__
