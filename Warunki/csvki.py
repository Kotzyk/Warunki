ilosc = [(1, 4), (2, 6), (3, 5), (4, 5), (5, 6), (6, 7), (7, 2), (8, 4), (9, 2), (10, 3), (11, 2), (12, 3), (13, 2),
         (14, 3), (15, 1), (16, 3), (17, 1), (18, 1)]

for (x, y) in ilosc:
        for b in range(1,y+1):
            try:
                f = open("Skrypty/" + str(x) + "-" + str(b) + ".sql", "w")
                f.write(
                    "SELECT p.IdWydziału, p.IdKierunku, Semestr, IdPrzedmiotu, NazwaPrzedmiotu, Godzin, ECTS, "+
                    "(Stawka * Godzin) AS Koszt" +
                    "FROM Przedmioty p " +
                    "INNER JOIN Stawki s " +
                    "ON s.IdKierunku = p.IdKierunku AND s.IdWydziału = p.IdWydziału" +
                    " WHERE p.IdWydziału = " + str(x) +
                    " AND p.IdKierunku = " + str(b))
                f.truncate()
                f.close()
            except FileNotFoundError:
                pass
