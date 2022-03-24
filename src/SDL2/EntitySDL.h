#ifndef _ENTITYSDL_H_
#define _ENTITYSDL_H_

#include "../core/Entity.h"
#include "SDL2/SDL_image.h"

class EntitySDL:public Entity{
    private:

    public:
        EntitySDL();
        ~EntitySDL();

        void Show(const char* img);
};

#endif // _ENTITYSDL_H_