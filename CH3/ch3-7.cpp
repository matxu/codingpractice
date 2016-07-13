//Animal shelter: adopt the oldest dog, or cat, or either anmial

struct AnimalNode{
    int val;
    string name;
    AnimalNode *next;
    AnimalNode(int x, string givenname){
        val = x;
        name = givenname;
        next = NULL;
    }

};


class AnimalShelter {
public:
    AnimalShelter() {
        // do initialization if necessary
        dogs = new AnimalNode(-1,"");
        cats = new AnimalNode(-1,"");
        age = 0;
    }
    int age;
    AnimalNode *dogs, *cats;
    void enqueue(string &name, int type) {
        // Write your code here
        if ( type == 0 ){// cat
            AnimalNode *newcomer = new AnimalNode(age++,name);
            AnimalNode *p=cats;
            while ( p->next != NULL) p = p->next;
            p->next = newcomer;
        }else { // dog
            AnimalNode *newcomer = new AnimalNode(age++,name);
            AnimalNode *p=dogs;
            while ( p->next != NULL) p = p->next;
            p->next = newcomer;
        }
    }
    
    string dequeueAny() {
        // Write your code here
        if ( dogs->next == NULL ) return dequeueCat();
        if ( cats->next == NULL ) return dequeueDog();
        
        int dogtime = dogs->next->val;
        int cattime = cats->next->val;
        if (dogtime < cattime){
            string name = dogs->next->name;
            dogs->next = dogs->next->next;
            return name;
        }else {
            string name = cats->next->name;
            cats->next = cats->next->next;
            return name;
        }
        
    }
    
    string dequeueDog() {
        // Write your code here
        if ( dogs->next == NULL) return "";
        string name = dogs->next->name;
        dogs->next = dogs->next->next;
        return name;
    }
    
    string dequeueCat() {
        // Write your code here
        if ( cats->next == NULL) return "";
        string name = cats->next->name;
        cats->next = cats->next->next;
        return name;
    }
};












