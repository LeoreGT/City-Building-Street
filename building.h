#ifndef __BUILDING_T_H__
#define __BUILDING_T_H__

#include <string>

using namespace std;

template <class B>
class Building_t
{
  public:
    Building_t();
    ~Building_t();
    Building_t(const Building_t<B>& _existingBuilding);
    const Building_t<B>& operator=(const Building_t<B>& _building);

    void SetBuildingID(const B& _newBuilding);
    B& GetBuildingID();
    void PrintBuildingID() const;

  private:
    B m_bID;
};

/* ------------------------------------- */

template <class B>
Building_t<B>::Building_t() //default CTOR
{}

/* ------------------------------------- */

template <class B>
Building_t<B>::~Building_t() //DTOR
{}

/* ------------------------------------- */

template <class B>
Building_t<B>::Building_t(const Building_t& _existingBuilding) //Copy CTOR
{
  m_bID = _existingBuilding.m_bID;
}

/* ------------------------------------- */

template <class B>
const Building_t<B>& Building_t<B>::operator=(const Building_t<B>& _existingBuilding) //operator=
{
  m_bID = _existingBuilding.m_bID;
  return *this;
}

/* ------------------------------------- */

template <class B>
void Building_t<B>::SetBuildingID(const B& _newID) //Set Building ID
{
  m_bID = _newID;
}

/* ------------------------------------- */

template <class B>
B& Building_t<B>::GetBuildingID() //Get Building ID
{
  return m_bID;
}

/* ------------------------------------- */

template <class B>
void Building_t<B>::PrintBuildingID() const //Get Building ID
{
  cout << m_bID << endl;
}

/* ------------------------------------- */

#endif /* __BUILDING_T_H__ */
