#pragma once

#include "Resource.hpp"

using namespace std;

class ResourceManager
{

public:
    Resource* wskaznik;

    ResourceManager() : wskaznik(new Resource) {}
    ~ResourceManager() { delete wskaznik; }

    double get() { return wskaznik->get(); }

    ResourceManager(const ResourceManager& r) : wskaznik(r.wskaznik)
    {
        wskaznik = new Resource(*r.wskaznik);
    }

    ResourceManager& operator=(const ResourceManager& r)
    {
        if (wskaznik == r.wskaznik)
            return *this;
        delete wskaznik;
        wskaznik = new Resource(*r.wskaznik);
        return *this;
    }

    ResourceManager(ResourceManager&& r) : wskaznik(r.wskaznik)
    {
        wskaznik   = r.wskaznik;
        r.wskaznik = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& r)
    {
        if (wskaznik == r.wskaznik)
            return *this;
        delete wskaznik;
        wskaznik   = r.wskaznik;
        r.wskaznik = nullptr;
        return *this;
    };
};
