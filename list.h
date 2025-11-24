class list {
    class node {
        public:
            int key;
            char data;
            node* next;
    };

    node *head, *cursor, *prev; 

    public: 
        list();
        ~list();
        bool isListEmpty() const;
        bool curIsEmpty() const;
        void toFirst();
        bool atFirst() const;
        void advance();
        void toEnd();
        bool atEnd() const;
        int listSize();
        void updateData(char);
        void updateKey(int);
        char retieveDate();
        void retieveDate(char &);
        void insertFirst(int, char);
        void insertAfter(int, char);
        void insertBefore(int, char);
        void insertEnd(int, char);
        void deleteNode();
        void deleteFirst();
        void deleteEnd();
        void makeListEmplt();
        bool search(int);
        void traverse();
};
