/*Integrantes: 
Nome: Dayani de Jesus - SC3046761
Nome: Laura Valim     - SC3046605
Nome: Weslley Viana   - SC3039757
*/
#ifndef OrderList_h
#define OrderList_h

typedef struct {
    int max;
    int *items;
    int n;
} t_ordered_list;

t_ordered_list* createList(int max);
int insertList(t_ordered_list *list, int elem);
int removeByIndex(t_ordered_list *list, int index);
int removeByElement(t_ordered_list *list, int elem);
int searchList(t_ordered_list *list, int elem);
int indexOf(t_ordered_list *list, int elem);
int getList(t_ordered_list *list, int index);
int countList(t_ordered_list *list, int elem);
int sizeList(t_ordered_list *list);
t_ordered_list* mergeLists(t_ordered_list *list1, t_ordered_list *list2);
int equalsLists(t_ordered_list *list1, t_ordered_list *list2);
int isEmpty(t_ordered_list *list);
int isFull(t_ordered_list *list);
void printList(t_ordered_list *list);
t_ordered_list* reallocateList(t_ordered_list *list);
int clearList(t_ordered_list *list);
t_ordered_list* destroyList(t_ordered_list *list);

#endif