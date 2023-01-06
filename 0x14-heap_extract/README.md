# 0x14-heap_extract

# Files

### 0. Heap - Extract
### [0-heap_extract.c](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x14-heap_extract/0-heap_extract.c)

```C
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

```

