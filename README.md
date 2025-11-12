##Get Next Line 1337  

##FileDescriptor  
A dile descriptor is an integer that uniquely identifies an open file, socket or I/O
resources withi a process.

##file descriptors table  
each process in Unix/Linux mainatains a file descriptor table,
which is an array-like structure that stores references to the resources 
(files, sockets, etc...) the process has opened. this is local to a process

##system-wide file table  
The system-wide file table is a kernel data structure tha holds some metadata
about all open files, including information about their location, access mode, offset
and more . Each entry in the file table corresponds to a file descriptor
**File Offset** : Current read/write position in the file
**Access Mode** : Read, Write, or read-write mode
**pointer to inode**: links the file table entry to the inode
**reference Count** : tracks how many file descriptors or processes share this entry

##System-Wide Inode table  
The inode  (index NOde) is a data structure that contains metadata about a file
such as its size, permissions ownership, timestamps and pointers to the data blocks on disk.
An inode does not store the file name but rather points to the actual file's data blocks on the disk. Multiple processes may refermce the same inode allowing them to access the same file data.
the inode table is stored on disk and contain all the inode structure for the files managed by the system
**File Metadata** : size, ownership(UID, GID), permissions, timestamps
**pointers to data block**: direct, indirect, and doubly/triply indirect pointer
to file data blocks.
**link count** : number of hard links to the file
**File Type** : regular file directory, symbolic link, etc...

