#pragma once
#include <map>
#include <set>

enum City
{
    Algiers,
    Atlanta,
    Baghdad,
    Bangkok,
    Beijing,
    Bogota,
    BuenosAires,
    Cairo,
    Chennai,
    Chicago,
    Delhi,
    Essen,
    HoChiMinhCity,
    HongKong,
    Istanbul,
    Jakarta,
    Johannesburg,
    Karachi,
    KePasio,
    Khartoum,
    Kinshasa,
    Kolkata,
    Lagos,
    Lima,
    London,
    LosAngeles,
    Madrid,
    Manila,
    MexicoCity,
    Miami,
    Milan,
    Montreal,
    Moscow,
    Mumbai,
    NewYork,
    Osaka,
    Paris,
    Riyadh,
    SanFrancisco,
    Santiago,
    SaoPaulo,
    Seoul,
    Shanghai,
    StPetersburg,
    Sydney,
    Taipei,
    Tehran,
    Tokyo,
    Washington
};

inline std::string CitytoString(City c)
{
    switch (c)
    {
    case Algiers:
        return "Algiers";
    case Atlanta:
        return "Atlanta";
    case Baghdad:
        return "Baghdad";
    case Bangkok:
        return "Bangkok";
    case Beijing:
        return "Beijing";
    case Bogota:
        return "Bogota";
    case BuenosAires:
        return "BuenosAires";
    case Cairo:
        return "Cairo";
    case Chennai:
        return "Chennai";
    case Chicago:
        return "Chicago";
    case Delhi:
        return "Delhi";
    case Essen:
        return "Essen";
    case HoChiMinhCity:
        return "HoChiMinhCity";
    case HongKong:
        return "HongKong";
    case Istanbul:
        return "Istanbul";
    case Jakarta:
        return "Jakarta";
    case Johannesburg:
        return "Johannesburg";
    case Karachi:
        return "Karachi";
    case KePasio:
        return "KePasio";
    case Khartoum:
        return "Khartoum";
    case Kinshasa:
        return "Kinshasa";
    case Kolkata:
        return "Kolkata";
    case Lagos:
        return "Lagos";
    case Lima:
        return "Lima";
    case London:
        return "London";
    case LosAngeles:
        return "LosAngeles";
    case Madrid:
        return "Madrid";
    case Manila:
        return "Manila";
    case MexicoCity:
        return "MexicoCity";
    case Miami:
        return "Miami";
    case Milan:
        return "Milan";
    case Montreal:
        return "Montreal";
    case Moscow:
        return "Moscow";
    case Mumbai:
        return "Mumbai";
    case NewYork:
        return "NewYork";
    case Osaka:
        return "Osaka";
    case Paris:
        return "Paris";
    case Riyadh:
        return "Riyadh";
    case SanFrancisco:
        return "SanFrancisco";
    case Santiago:
        return "Santiago";
    case SaoPaulo:
        return "SaoPaulo";
    case Seoul:
        return "Seoul";
    case Shanghai:
        return "Shanghai";
    case StPetersburg:
        return "StPetersburg";
    case Sydney:
        return "Sydney";
    case Taipei:
        return "Taipei";
    case Tehran:
        return "Tehran";
    case Tokyo:
        return "Tokyo";
    case Washington:
        return "Washington";
    }
    return "None";
}
inline City StringtoCity(std::string city)
{
    if (city == "Algiers")
        return Algiers;
    else if (city == "Atlanta")
        return Atlanta;
    else if (city == "Baghdad")
        return Baghdad;
    else if (city == "Bangkok")
        return Bangkok;
    else if (city == "Beijing")
        return Beijing;
    else if (city == "Bogota")
        return Bogota;
    else if (city == "BuenosAires")
        return BuenosAires;
    else if (city == "Cairo")
        return Cairo;
    else if (city == "Chennai")
        return Chennai;
    else if (city == "Chicago")
        return Chicago;
    else if (city == "Delhi")
        return Delhi;
    else if (city == "Essen")
        return Essen;
    else if (city == "HoChiMinhCity")
        return HoChiMinhCity;
    else if (city == "HongKong")
        return HongKong;
    else if (city == "Istanbul")
        return Istanbul;
    else if (city == "Jakarta")
        return Jakarta;
    else if (city == "Johannesburg")
        return Johannesburg;
    else if (city == "Karachi")
        return Karachi;
    else if (city == "Khartoum")
        return Khartoum;
    else if (city == "Kinshasa")
        return Kinshasa;
    else if (city == "Kolkata")
        return Kolkata;
    else if (city == "Lagos")
        return Lagos;
    else if (city == "Lima")
        return Lima;
    else if (city == "London")
        return London;
    else if (city == "LosAngeles")
        return LosAngeles;
    else if (city == "Madrid")
        return Madrid;
    else if (city == "Manila")
        return Manila;
    else if (city == "MexicoCity")
        return MexicoCity;
    else if (city == "Miami")
        return Miami;
    else if (city == "Milan")
        return Milan;
    else if (city == "Montreal")
        return Montreal;
    else if (city == "Moscow")
        return Moscow;
    else if (city == "Mumbai")
        return Mumbai;
    else if (city == "NewYork")
        return NewYork;
    else if (city == "Osaka")
        return Osaka;
    else if (city == "Paris")
        return Paris;
    else if (city == "Riyadh")
        return Riyadh;
    else if (city == "SanFrancisco")
        return SanFrancisco;
    else if (city == "Santiago")
        return Santiago;
    else if (city == "SaoPaulo")
        return SaoPaulo;
    else if (city == "Seoul")
        return Seoul;
    else if (city == "Shanghai")
        return Shanghai;
    else if (city == "StPetersburg")
        return StPetersburg;
    else if (city == "Sydney")
        return Sydney;
    else if (city == "Taipei")
        return Taipei;
    else if (city == "Tehran")
        return Tehran;
    else if (city == "Tokyo")
        return Tokyo;
    else if (city == "Washington")
        return Washington;
    return Algiers;
}
