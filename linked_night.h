struct mob_node {
    char name[20];
    char species[20];
    int level;

    struct mob_node *next;
};

struct mob_node *new_mob_node(char *nm, char *sp, int lvl);
void print_list(struct mob_node *node);
void change_mob(struct mob_node *mb, char *nm, char *sp, int lvl);
struct mob_node *insert_front(struct mob_node *node, char *nm, char *sp, int lvl);
struct mob_node *free_list(struct mob_node *node);
struct mob_node *remove_node(struct mob_node *front, char *nm);