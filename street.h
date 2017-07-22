#ifndef __STREET_T_H__
#define __STREET_T_H__

#include <string>
#include <vector>

#include "building.h"

#define SUCCESS  0
#define MISMATCH 1

using namespace std;

template <class S, class B>
class Street_t
{
  public:
    Street_t();
    ~Street_t();

    void SetStreetID(const S& _newID);
    S& GetStreetID();

    bool AddBuilding2Street(Building_t<B>& _newBuilding);
    const Building_t<B>& GetBuilding(const B& _existingBuilding);
    void PrintStreetID() const;
    size_t CountBuildingsOnStreet() const;

    Street_t(const Street_t<S, B>& _existingStreet);
    const Street_t<S, B>& operator=(const Street_t<S, B>& _existingStreet);

  private:
    S m_sID;
    vector<Building_t<B> > m_buildings;
};

/* ------------------------------------- */

template <class S, class B>
Street_t<S, B>::Street_t() //default CTOR
{}

/* ------------------------------------- */

template <class S, class B>
Street_t<S, B>::~Street_t() //DTOR
{}

/* ------------------------------------- */

template <class S, class B>
Street_t<S, B>::Street_t(const Street_t& _existingStreet) //Copy CTOR
{
  m_sID = _existingStreet.m_sID;
}

/* ------------------------------------- */

template <class S, class B>
const Street_t<S, B>& Street_t<S, B>::operator=(const Street_t<S, B>& _existingStreet) //operator=
{
  m_sID = _existingStreet.m_sID;
  return *this;
}

/* ------------------------------------- */

template <class S, class B>
void Street_t<S, B>::SetStreetID(const S& _newID) //Set Street ID
{
  m_sID = _newID;
}

/* ------------------------------------- */

template <class S, class B>
S& Street_t<S, B>::GetStreetID() //Get Street ID
{
  return m_sID;
}

/* ------------------------------------- */

template <class S, class B>
bool Street_t<S, B>::AddBuilding2Street(Building_t<B>& _newBuilding)
{
  // Building_t<B>& bfirst = m_buildings.front();

  // B& firstID = bfirst.GetBuildingID();
  // B& newID = _newBuilding.GetBuildingID();

  // // if ((m_buildings.size() != 0) && (typeid(firstID) != typeid(newID))) //checks for type mismatch
  // {
  //   return MISMATCH;
  // }

  m_buildings.push_back(_newBuilding); //add new street
  return SUCCESS;
}

/* ------------------------------------- */

template <class S, class B>
const Building_t<B>& Street_t<S, B>::GetBuilding(const B& _existingBuildingID)
{
  typename vector<Building_t<B> >::iterator it;
  for (it = m_buildings.begin(); it != m_buildings.end(); ++it) //search through m_buildings
  {
    if (it->GetBuildingID() == _existingBuildingID) //if the ID is equal, return that iterator
    {
      return *it;
    }
    throw _existingBuildingID;
  }
}
/* ------------------------------------- */

template <class S, class B>
void Street_t<S, B>::PrintStreetID() const
{
  cout << m_sID << endl;
}

/* ------------------------------------- */

template <class S, class B>
size_t Street_t<S, B>::CountBuildingsOnStreet() const
{
  return m_buildings.size();
}

/* ------------------------------------- */

#endif /* __STREET_T_H__ */
