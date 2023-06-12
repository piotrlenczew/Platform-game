Autorzy:
Tomasz Truszkowski 325244
Piotr Lenczewski 325183

Projekt:
Prosta gra platformowa wykonana z pomoc� biblioteki SFML.

Klasy:
Game-   Przechowuje klasy RenderWindow, TileMap, oraz Player, gdzie RenderWindow to klasa z biblioteki sfml umo�liwiaj�ca stworzenie i obs�ug� okna.
		Przy ich pomocy realizuje dwie podstawowe metody update i render:
		Update odpowiada za aktualizowanie obecnej sytuacji w grze: zamkni�cie okna, aktualizacja pozycji gracza, kolizje. 
		Render odpowiada za wy�wietlenie tej sytuacji.
TileMap-	przechowuje w dwuwymiarowej tablicy obiekty klasy Tile
			umo�liwia wczytanie mapy z pliku tekstowego
			format pliku opisany poni�ej
			rysuje na ekran wszystkie Tile
Tile-		klasa abstrakcyjna, kt�ra umo�liwia tworzenie podklas
			ka�da podklasa ma z g�ry okre�lony fragment pliku png, w kt�rym znajduje si� dana tekstura
Player- Przechowuje: 
			textureSheet, kt�ry jest tekstur� zawieraj�c� wszystkie grafiki opsiju�ce gracza
			sprite, kt�ry jest reprezentacj� gracza w oknie
			animationTimer, zapewnia, �e animacje po puszczeniu przycisku rozpoczn� si� od nowa
			spawnpoint, punkt w kt�rym gracz pojawia si� po �mierci
		Podstwowymi zadaniami tej klasy s�: 
			wykrywanie wci�ni�cia przycisk�w
			obliczanie pozycji gracza
			symulacja fizyki
			wy�wietlanie gracza
			animowanie gracza


Jak korzysta� z projektu:
Po zklonowaniu projektu do visual studio, wystarczy w��czy� plik .sln i klikn�� run.
Mapy powinny by� przechowywane w folderze "../Maps/map_" na koniec wystarczy doda� numer mapy
numery musz� by� po kolei, 1, 2, 3 b�dzie dzia�a� 1, 2, 4 nie b�dzie
format pliku tesktowego:
1 linijka: liczba blok�w na szeroko��
2 linijka: liczba blok�w na wysoko��
nast�pne linie to kolejne rz�dy po spacji
przedostatnia linijka x startowy gracza
ostatnia linijka y startowy gracza
Tekstury powinny by� w ../Textures/"
