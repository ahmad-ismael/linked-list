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
        bool atFirst() const;
        bool atEnd() const;

        void advance();
        void toFirst();
        void toEnd();

        int listSize() const;
        void updateData(const char &);
        void updateKey(const int &);
        void retrieveData(char &) const;
        void retrieveKey(int &) const;

        void insertFirst(const int &, const char &);
        void insertAfter(const int &, const char &);
        void insertBefore(const int &, const char &);
        void insertEnd(const int &, const char &);

        void deleteNode();
        void deleteFirst();
        void deleteEnd();
        void makeListEmpty();
        
        bool search(int);
	    void orderInsert(const char &, const int & );
        void traverse();
};
