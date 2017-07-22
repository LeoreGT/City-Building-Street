#include <iostream>

#include "mu_test.h"
#include "building.h"
#include "street.h"
#include "city.h"

/* ------------------------------------- */

UNIT(SET_BUILDING_ID)
  string b1Name = "Huisache";
  int b2Name = 4934;

  Building_t<string> b1;
  Building_t<int> b2;

  b1.SetBuildingID(b1Name);
  b2.SetBuildingID(b2Name);

  ASSERT_THAT(b1.GetBuildingID() == "Huisache");
  ASSERT_THAT(b2.GetBuildingID() == 4934);
END_UNIT

/* ------------------------------------- */

UNIT(EQ_OPERATOR_BUILDING)
  string b1Name = "Heatherglen";
  Building_t<string> b1, b2;
  b1.SetBuildingID(b1Name);

  b2 = b1;

  ASSERT_THAT(b1.GetBuildingID() == b2.GetBuildingID());
END_UNIT

/* ------------------------------------- */

UNIT(SET_STREET_ID)
  string s1Name = "JongShan";
  int s2Name = 120;

  Street_t<string, string> s1;
  Street_t<int, int> s2;

  s1.SetStreetID(s1Name);
  s2.SetStreetID(s2Name);

  ASSERT_THAT(s1.GetStreetID() == "JongShan");
  ASSERT_THAT(s2.GetStreetID() == 120);
END_UNIT

/* ------------------------------------- */

UNIT(EQ_OPERATOR_STREET)
  string s1Name = "Huisache";
  Street_t<string, string> s1, s2;
  s1.SetStreetID(s1Name);

  s2 = s1;

  ASSERT_THAT(s1.GetStreetID() == s2.GetStreetID());
END_UNIT

/* ------------------------------------- */

UNIT(SET_CITY_ID)
  string c1Name = "JongShan";
  int c2Name = 4934;

  City_t<string, string, string> c1;
  City_t<int, int, string> c2;

  c1.SetCityID(c1Name);
  c2.SetCityID(c2Name);

  ASSERT_THAT(c1.GetCityID() == "JongShan");
  ASSERT_THAT(c2.GetCityID() == 4934);
END_UNIT

/* ------------------------------------- */

UNIT(EQ_OPERATOR_CITY)
  string c1Name = "Huisache";
  City_t<string, string, string> c1, c2;
  c1.SetCityID(c1Name);

  c2 = c1;

  ASSERT_THAT(c1.GetCityID() == c2.GetCityID());
END_UNIT

/* ------------------------------------- */

UNIT(ASSIGN_BUILDING_TO_STREET)
  Building_t<string> b1;
  Building_t<int> b2;
  Street_t<string, string> s1;
  Street_t<int, int> s2;

  b1.SetBuildingID("Huisache");
  b2.SetBuildingID(4934);

  s1.SetStreetID("JongShan");
  s2.SetStreetID(120);

  s1.AddBuilding2Street(b1);
  ASSERT_THAT(1 == s1.CountBuildingsOnStreet());

  s2.AddBuilding2Street(b2);
  ASSERT_THAT(1 == s2.CountBuildingsOnStreet());
END_UNIT

/* ------------------------------------- */

UNIT(ASSIGN_STREET_TO_CITY)
  Street_t<string, string> s1;
  Street_t<int, int> s2;
  City_t<string, string, string> c1;
  City_t<int, int, int> c2;

  s1.SetStreetID("Huisache");
  s2.SetStreetID(4934);

  c1.SetCityID("LuoDong");
  c2.SetCityID(6);

  c1.AddStreet(s1);
  ASSERT_THAT(1 == c1.CountStreetsInCity());

  c2.AddStreet(s2);
  ASSERT_THAT(1 == c2.CountStreetsInCity());
END_UNIT

/* ------------------------------------- */

UNIT(ASSIGN_ALL_THREE)
  Building_t<string> b1;
  Building_t<int> b2;
  Street_t<string, string> s1;
  Street_t<int, int> s2;
  City_t<string, string, string> c1;
  City_t<int, int, int> c2;

  b1.SetBuildingID("Huisache");
  b2.SetBuildingID(4934);

  s1.SetStreetID("JongShan");
  s2.SetStreetID(120);

  c1.SetCityID("LuoDong");
  c2.SetCityID(6);

  s1.AddBuilding2Street(b1);
  s2.AddBuilding2Street(b2);
  c1.AddStreet(s1);
  c2.AddStreet(s2);

  ASSERT_THAT(1 == s1.CountBuildingsOnStreet());
  ASSERT_THAT(1 == s2.CountBuildingsOnStreet());
  ASSERT_THAT(1 == c1.CountStreetsInCity());
  ASSERT_THAT(1 == c2.CountStreetsInCity());
END_UNIT

/* ------------------------------------- */

TEST_SUITE(CITY_TEST)
  TEST(SET_BUILDING_ID)
  TEST(EQ_OPERATOR_BUILDING)
  TEST(SET_STREET_ID)
  TEST(EQ_OPERATOR_STREET)
  TEST(SET_CITY_ID)
  TEST(EQ_OPERATOR_CITY)
  TEST(ASSIGN_BUILDING_TO_STREET)
  TEST(ASSIGN_STREET_TO_CITY)
  TEST(ASSIGN_ALL_THREE)
END_SUITE

/* ------------------------------------- */
