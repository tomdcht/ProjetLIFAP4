#include <vector>

class Entity{
    private:
        double posx, posy;
        int damage;
        int PV;

    public:
        Entity();
        ~Entity();

        std::vector<double> GetPos() const;
        void SetPos(int _posx, int _posy);



};