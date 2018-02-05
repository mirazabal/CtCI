namespace mirazabal {

    template<typename T>
class Node{
        public:
            explicit Node(T val) : val_{val}, next {nullptr}, previous{nullptr}
            {
            
            }

            Node* next;
            Node* previous;
            T val_;
};

}
