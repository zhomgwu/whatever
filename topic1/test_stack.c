
struct list_node {
    char c;
    list_node *next;
};

struct stack {
    list_node *head;
};

void stack_push(struct stack *stack, char c) {
    list_node * data = (list_node*)malloc(sizeof(list_node));
    data->next = NULL;
    data->c = c;
    data->next = stack->head;
    stack->head = data;
}

char stack_pop(struct stack *stack) {
    list_node * data = stack->head;
    if (!data) {
        return '';
    }
    char c = data->c;
    stack->head = data->next;
    free(data);
    return c;
}

bool is_empty(struct stack *stack) {
    return stack->head == NULL;
}


void valid_parentheses(char * str);


void valid_parentheses(char * str) {

}


