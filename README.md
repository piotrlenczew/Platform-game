Autorzy:
Tomasz Truszkowski 325244
Piotr Lenczewski 325183

Projekt:
Prosta gra platformowa wykonana z pomoc¹ biblioteki SFML.

Klasy:
Game-   Przechowuje klasy RenderWindow, TileMap, oraz Player, gdzie RenderWindow to klasa z biblioteki sfml umo¿liwiaj¹ca stworzenie i obs³ugê okna.
		Przy ich pomocy realizuje dwie podstawowe metody update i render:
		Update odpowiada za aktualizowanie obecnej sytuacji w grze: zamkniêcie okna, aktualizacja pozycji gracza, kolizje. 
		Render odpowiada za wyœwietlenie tej sytuacji.
TileMap-	przechowuje w dwuwymiarowej tablicy obiekty klasy Tile
			umo¿liwia wczytanie mapy z pliku tekstowego
			format pliku opisany poni¿ej
			rysuje na ekran wszystkie Tile
Tile-		klasa abstrakcyjna, która umo¿liwia tworzenie podklas
			ka¿da podklasa ma z góry okreœlony fragment pliku png, w którym znajduje siê dana tekstura
Player- Przechowuje: 
			textureSheet, który jest tekstur¹ zawieraj¹c¹ wszystkie grafiki opsiju¹ce gracza
			sprite, który jest reprezentacj¹ gracza w oknie
			animationTimer, zapewnia, ¿e animacje po puszczeniu przycisku rozpoczn¹ siê od nowa
			spawnpoint, punkt w którym gracz pojawia siê po œmierci
		Podstwowymi zadaniami tej klasy s¹: 
			wykrywanie wciœniêcia przycisków
			obliczanie pozycji gracza
			symulacja fizyki
			wyœwietlanie gracza
			animowanie gracza


Jak korzystaæ z projektu:
Po zklonowaniu projektu do visual studio, wystarczy w³¹czyæ plik .sln i klikn¹æ run.
Mapy powinny byæ przechowywane w folderze "../Maps/map_" na koniec wystarczy dodaæ numer mapy
numery musz¹ byæ po kolei, 1, 2, 3 bêdzie dzia³aæ 1, 2, 4 nie bêdzie
format pliku tesktowego:
1 linijka: liczba bloków na szerokoœæ
2 linijka: liczba bloków na wysokoœæ
nastêpne linie to kolejne rzêdy po spacji
przedostatnia linijka x startowy gracza
ostatnia linijka y startowy gracza
Tekstury powinny byæ w ../Textures/"
