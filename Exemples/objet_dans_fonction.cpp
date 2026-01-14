#include <iostream>

class Point
{
    private:
        int _x, _y;
    
    public:
        Point(int x, int y) : _x(x), _y(y) {}
        void save(void) {
            saveInDataBase(this);
        }

        void print(void) {
            Afficher(this);
        }

        friend void saveInDataBase(Point* p);
        friend void Afficher(Point* p); 
};

void saveInDataBase(Point* p) {
    std::cout << "Sauvegarde du point (" << p->_x << ", " << p->_y << ") dans la base de données." << std::endl;
}

void Afficher(Point *p) {
    std::cout << "Point(" << p->_x << ", " << p->_y << ")" << std::endl;
}

int main(void)
{
    Point p(10, 5);
    p.save();
    p.print();
    return 0;
}
