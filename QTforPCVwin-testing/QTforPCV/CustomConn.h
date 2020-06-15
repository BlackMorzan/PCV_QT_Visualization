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
 * Klasy CustomConn obługuje połącznie
 * między tą aplikają, a PCV
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
    * \return int o wartości 0 dla poprawnego działania,
    * dla błędów wartośc ujemna
    */
    int Init();

    /*!
     * \brief Odbiera serię znaków
     *
     * \deprecated Metoda jest przestarzała i niewykorzystywana
     * w tej iteracji
     *
     * \return zwraca serię znaków z bufora portu
     */
    string ReciveString();

    /*!
     * \brief Metoda dekoduje widomość z portu, sprawdza, czy jest poprawna i odbiera przesłane wartości
     * \return int o wartości 0 dla poprawnego działania,
     * dla błędów wartośc ujemna
     */
    int ReciveFullMessage();

    /*!
     * \brief Metoda zwraca jedną z oddczytanych wartości
     * \param i oznacza, która ze zmiennych ma zostać odczytana
     * \return odczytana wartość typu double
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
     * \brief metoda sprawdza, kiedy rozpoczyna się i kończy wiadomość
     * \return zwraca 1, kiedy wykryje nagłówek. 2 gdy wykryje stopkę, -1, jeśli żadne z powyższych
     */
    int IsMessage();

    /*!
     * \brief metoda odczytuje wartość intiger z widomości
     *
     * metoda jest używana do odczytywania ile wartości zmiennoprzecinkowych pojawi się we wiadomości i
     * numeru wiadmości.
     *
     * \return zwracana jest wartość odczytaną z wiadomości
     */
    int ReciveMessageCount();

    /*!
     * \brief metoda służy do przesyłania wiadmości tekstowej do aplikacji PCV
     *
     * \param Łańcuch znaków, który ma zostać przesłany
     */
    void Send(string Message);


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

