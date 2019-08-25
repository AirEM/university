#ifndef IDMAKER_H
#define IDMAKER_H


class IdMaker
{
public:
    static int getLightID()
    {
        static int light_id = -1;
        return light_id--;
    }

    static int getFiguretID()
    {
        static int light_id = 1;
        return light_id--;
    }

    // Other non-static member functions
private:
    IdMaker() {}                                  // Private constructor
    ~IdMaker() {}
    IdMaker(const IdMaker&);                 // Prevent copy-construction
    IdMaker& operator=(const IdMaker&);
};

#endif // IDMAKER_H
