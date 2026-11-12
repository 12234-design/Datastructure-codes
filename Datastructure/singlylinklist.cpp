    #include <iostream>
    using namespace std;

    class Node
    {
        public:
        int data;
        Node *next;
        Node(int val): data(val), next(NULL) {}

    };
    class List
    {
        Node *head;
        Node *tail;
        public:
        List()
        {
            head=tail=NULL;
        }
        void push_front(int val)
        {
            Node *newnode = new Node(val);
            if (head == NULL)
            {
                head=tail=newnode; 
                return;
            }
            else
            {
                newnode-> next= head;
                head=newnode;
            }
        }
        void push_back( int val)
        {
            Node *newnode = new Node(val);
            if(head == NULL)
            {
                head=tail=newnode;
                return;
            }
            else{
                tail->next=newnode;
                tail=newnode;
            }
        }
        void pop_front()
        {
            if (head == NULL)
                return;
            Node *temp = head;
            head = head->next;
            if (head == NULL)
                tail = NULL;
            delete temp;
        }
        void pop_back()
        {
            if (head == NULL)
                return;
            if (head->next == NULL)
            {
                delete head;
                head = tail = NULL;
                return;
            }
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
        void insert(int val,int pos)
        {
            if(pos<0) return;
            if(pos==0)
            {
                push_front(val);
                return;
            }
            Node *temp = head;
            for (int i=0; i<pos-1 && temp != NULL; i++)
            {
                temp = temp->next;
            }
            if (temp == NULL)
                return;
            Node *newnode = new Node(val);
            newnode->next = temp->next;
            temp->next = newnode;
            if (newnode->next == NULL)
                tail = newnode;
        }
            void counter()
            {
            int count=0;
            Node*temp= head;
            while(temp!=NULL)
            {
                temp=temp->next;
                count++;
            }
            cout<<"count of nodes: "<<count<<endl;
            }
            void PrintLL()
        {
            Node *temp=head;
            while(temp!= NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
        void search(int key)
        {
            Node *temp=head;
            int idx=0;

            while(temp!=NULL)
            {
                if(temp->data==key)
                {
                    cout<<"idx= "<<idx<<endl;
                }
                temp=temp->next;
                idx++;
            }
        }
    }; 
    int main()
    {
        List ll;
        ll.push_front(1);
        ll.push_front(2);
        ll.push_front(3);
        ll.insert(4,1);
        //ll.search(3);
        ll.counter();
        
        ll.PrintLL();
    }