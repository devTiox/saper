# SPRAWOZDANIE
## Projekt Saper

### Instrukcja
Projekt jest programem odzwierciedlającym gre "saper". Gra generuje plansze z losowo wygenerowanymi minami, gdzie rozmiar planszy i ilość min zależy od poziomu trudności. Celem gry jest odkrycie całej planszy w taki sposób aby nie odkryć żadnego pola z miną. Po odkryciu pola bez miny będzie ono pokazywało ilość min wokół pola, dzieki czemu gracz będzie mógł określić lokalizacje min.

Gra początkowo zapyta o nick(nazwe gracza), która może być ciągiem znaków o maxymalnej długości 100. Następnie o poziom trudności: c-custom(wlasne ustawienia,koniecznosc podania ilosci bomb(nie wiecej niz 75%% planszy dla zachowania sensu rozgrywki)!!), e-easy(latwy 9x9 10 bomb), m-medium(sredni 16x16 40 bomb), h-hard(trudny 16x30 99 bomb).

Po wyborze trybu rozpoczyna się gra: będzie wyświetlana plansza oraz ilość punktów, które będą aktualizowane po każdym ruchu. Aby wybrać ruch należy w terminal podać pozycje y, pozycje x oraz parametr ruchu(m/M jeśli chcemy odkryć pole | f/F jeśli chcemy postawić lub usunąć flagę). 