#ifndef CUSTOMCONN_H
#define CUSTOMCONN_H

/*!
 * \file
 * \brief Definicja klasy CustomConn
 *
 * Plik zawiera definicję klasy CustomConn, której
 * zadaniem jest uzyskanie połączenia między tą aplikają,
 * a PCV
 */


#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 56789
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
/*!
 * \brief Obsługa połączenia między aplikacjami
 *
 * Klasa CustomConn obługuje połącznie między tą aplikają, a aplikacją PCV w standardzie UDP.
 * Ponad to tworzy środowisko, w którym utrzymywane są informacje na teamt odbieranych wiadomości.
 */
class CustomConn
{
public:
    /*!
    * \brief Inicjalizuje klasę CustomConn
    */
    CustomConn();
    /*!
     * \brief ile zmiennych typu double będzie się zanajdować we wiadomości
     */
    int lenght = 0;

    /*!
     * \brief ile widomości zostało przesłanych od uruchomienia programu
     */
    int messageCnt = 0;


    /*!
    * \brief Inicjalizuje połączenie z aplikacją PCV
    *
    * Metoda ustanawia połączenie z aplikają PCV,
    * opróżnia bufor z wybranego portu i wysyła "handshake"
    *
    * \return 0 dla poprawnego działania
    * \return <0 dla błędów
    */
    int Init();

    /*!
     * \brief Odbiera wiadmość tekstową od aplikacji PCV
     *
     * \deprecated Metoda jest przestarzała i niewykorzystywana
     * w tej iteracji ponieważ aplikacja PCV przesyłała wiadomości tylko w ramach testów
     *
     * \return zwraca odebraną wiadomość tekstową
     */
    string ReciveString();

    /*!
     * \brief Metoda dekoduje widomość z portu, sprawdza, czy jest poprawna i odbiera przesłane wartości
     *
     * Metoda wykonuje \link CustomConn::ReciveMessageCount \endlink i \link CustomConn::IsMessage \endlink, a następnie
     * zapisuje odebrbane wartości do \link CustomConn::RecivedDouble \endlink
     *
     * \return Zwraca 0 jeśli wszystkie wartości zostały przesłane
     * \return Zwraca <0 jeśli widomość ma złą formę
     */
    int ReciveFullMessage();

    /*!
     * \brief Metoda zwraca wybraną jedną z wartości zapisanych w \link CustomConn::RecivedDouble \endlink
     *
     * \param[in] i - liczba określająca, która wartość z tablicy ma zostać wysłana
     *
     * Metoda wydobywa wartości zapisane w tablicy \link CustomConn::RecivedDouble \endlink przez
     * \link CustomConn::ReciveFullMessage \endlink w tej fazie wartości są nieuporządkowane i są to składowe
     * wektora dotyczącego pozycji, następnie prędkości, później orientatcji w kolejności x, y, z
     *
     * \return odczytana wartość z tablicy opisująca jeden z parametrów robota
     */
    double GetDouble(int i);


private:

    /*!
     * \brief socket, z którego są odbierane wartości
     */
    int sock = 0;

    /*!
     * \brief Tablica do której są zapisywane przesłane wartości typu double
     */
    double RecivedDouble[50];



    /*!
     * \brief Metoda sprawdza, kiedy rozpoczyna się i kończy wiadomość
     *
     * \return Zwraca 1, kiedy wykryje nagłówek
     * \return 2 gdy wykryje stopkę
     * \return -1, jeśli żadne z powyższych
     */
    int IsMessage();

    /*!
     * \brief Metoda odczytuje liczby całkowie z widomości
     *
     * Metoda odczytuje ile liczb zmiennoprzecinkowych pojawi się we wiadomości
     *
     * \return Zwracana jest ilość liczb w wiadomości
     */
    int ReciveMessageCount();

    /*!
     * \brief Metoda służy do przesyłania wiadmości tekstowej do aplikacji PCV
     *
     * \param Wiadmość jaka zostanie przesłana do aplikacji PCV
     */
    void Send(const string Message);


};

/*!
 * \brief jest to struktura pomocnicza której zadaniem jest wyświetlanie bajtów w formie Hex
 * \deprecated Klasa była używana do debugowania i teraz nie jest juz potrzebna
 */
struct HexCharStruct
{
    unsigned char c;
    HexCharStruct(unsigned char _c) : c(_c) { }
};

inline std::ostream& operator<<(std::ostream& o, const HexCharStruct& hs)
{
    return (o << std::hex << (int)hs.c);
}

inline HexCharStruct hex(unsigned char _c)
{
    return HexCharStruct(_c);
}

#endif // CUSTOMCONN_H

