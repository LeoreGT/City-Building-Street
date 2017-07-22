#ifndef __CITY_T_H__
#define __CITY_T_H__

#include <string>
#include <list>

#include "street.h"

#define SUCCESS  0
#define MISMATCH 1

using namespace std;

template <class C, class S, class B>
class City_t
{
  public:
    City_t();
    ~City_t();

    void SetCityID(const C& _newID);
    const C& GetCityID() const;

    bool AddStreet(Street_t<S, B>& _newStreet);
    const Street_t<S, B>& GetStreet(const S& _existingStreet) const;
    void PrintCityID() const;
    size_t CountStreetsInCity() const;

    City_t(const City_t<C, S, B>& _existingCity);
    const City_t<C, S, B>& operator=(const City_t<C, S, B>& _existingCity);

  private:
    C m_cID;
    list<Street_t<S, B> > m_streets;
};

/* ------------------------------------- */

template <class C, class S, class B>
City_t<C, S, B>::City_t() //default CTOR
{}

/* ------------------------------------- */

template <class C, class S, class B>
City_t<C, S, B>::~City_t() //DTOR DDELETE ITERATORS
{}

/* ------------------------------------- */

template <class C, class S, class B>
City_t<C, S, B>::City_t(const City_t& _existingCity) //Copy CTOR
{
  m_cID = _existingCity.m_cID;
}

/* ------------------------------------- */

template <class C, class S, class B>
const City_t<C, S, B>& City_t<C, S, B>::operator=(const City_t<C, S, B>& _existingCity) //operator=
{
    m_cID = _existingCity.m_cID;
    return *this;
}

/* ------------------------------------- */

template <class C, class S, class B>
void City_t<C, S, B>::SetCityID(const C& _newID) //Set City ID
{
  m_cID = _newID;
}

/* ------------------------------------- */

template <class C, class S, class B>
const C& City_t<C, S, B>::GetCityID() const //Get City ID
{
  return m_cID;
}

/* ------------------------------------- */

template <class C, class S, class B>
bool City_t<C, S, B>::AddStreet(Street_t<S, B>& _newStreet) //Add Street
{
  // Street_t<S, B>& cfirst = m_streets.front();
  // C& firstID = cfirst.GetStreetID();
  // C& newID = _newStreet.GetStreetID();

  // if ((m_streets.size() != 0) && (typeid(firstID) != typeid(newID))) //checks for type mismatch
  // {
  //   return MISMATCH;
  // }

  m_streets.push_front(_newStreet); //add new street to the front
  return SUCCESS;
}

/* ------------------------------------- */

template <class C, class S, class B>
const Street_t<S, B>& City_t<C, S, B>::GetStreet(const S& _existingStreet) const //Get Street
{
  typename list<Street_t<S, B> >::iterator it;
  for (it = m_streets.begin(); it != m_streets.end(); ++it) //search through m_streets
  {
    if (it->GetStreetID() == _existingStreet) //if the ID is equal, return that iterator
    {
      return *it;
    }
    throw _existingStreet;
  }
}

/* ------------------------------------- */

template <class C, class S, class B>
void City_t<C, S, B>::PrintCityID() const
{
  cout << m_cID << endl;
}

/* ------------------------------------- */

template <class C, class S, class B>
size_t City_t<C, S, B>::CountStreetsInCity() const
{
  return m_streets.size();
}

/* ------------------------------------- */

#endif /* __CITY_T_H__ */
