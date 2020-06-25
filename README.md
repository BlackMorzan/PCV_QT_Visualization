# PCV_QT_Visualization

Program współpracujący z aplikacją [PCV](https://github.com/BlackMorzan/Prepraration_Cell_Viewer). Podczas tego projektu badałem możliwości komunikacji TCP i UDP podczas korzystania z Unity i zapoznałem się na narzędziami dostępnymi w środowisku QT. 

Efekem tej pracy jest aplikacja okienkowa stworzona w środowisku QT, która wyświetla w postaci wykresów zmiany położenia, prędkości i rotacji efektora robota apliakcji PCV i wizualizuje jego obroty za pomocą prostego obiektu stworzonego z pomocą biblioteki OpenGL. 

Projekt zawiera dokumentacje generowaną za pomocą programu doxygen która opisuje wszystkie klasy i metody. 

# Środowisko

Ta aplikacja została storzona na Linux-owy system operacyjny i pracan nad nią częściowo opierała się na pracy w Windows(C#, Unity), a częściowo na Ubuntu 18.04 (C++, QT, OpenGL, Doxygen)

# Połączenie

Finalnie aplikacje komunikują się za pomocą protokołu TCP, gdzie aplikacja PCV jest serwerem, a PCV_QT_Vis klientem.

# ScreenShots

![SCR1](https://github.com/BlackMorzan/PCV_QT_Visualization/blob/master/QTforPCVwin-testing/SS_QTfor_PCV/Screenshot_QT_1.png)
![SCR2](https://github.com/BlackMorzan/PCV_QT_Visualization/blob/master/QTforPCVwin-testing/SS_QTfor_PCV/Screenshot_QT_2.png)
![SCR3](https://github.com/BlackMorzan/PCV_QT_Visualization/blob/master/QTforPCVwin-testing/SS_QTfor_PCV/Screenshot_QT_3.png)

