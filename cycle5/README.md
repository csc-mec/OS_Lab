### Flags used
- `IPC_CREAT` : Create a new shared memory segment
- `IPC_RMID` : Remove the shared memory segment
- `0666` : Read and write permission

### Functions used and format
- `shmget(key_t key, size_t size, int shmflg)`
        we used shmflag as `IPC_CREAT | 0666` to create a new shared memory segment
- `shmat(int shmid, void *shmaddr, int shmflg)`
        we used `shmaddr` as `NULL` and `shmflag` as `0` to attach the shared memory segment
        (why?) because we are not interested in the address where the shared memory segment is attached
- `shmdt()`
        to detach the shared memory segment
- `shmctl(int shmid, int cmd, struct shmid_ds *buf)`
        to control the shared memory segment . we used `cmd` as `IPC_RMID` to remove the shared memory segment

         