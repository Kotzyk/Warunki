ilosc = [(1, 4), (2, 6), (3, 5), (4, 5), (5, 6), (6, 7), (7, 2), (8, 4), (9, 2), (10, 3), (11, 2), (12, 3), (13, 2),
         (14, 3), (15, 1), (16, 3), (17, 1), (18, 1)]

for (x, y) in ilosc:
    for b in range(1, y + 1):
        f = open("Skrypty/" + str(x) + "-" + str(b) + ".sql.csv", "r")
        lines = f.readlines()
        f.close()
        f = open("Skrypty/" + str(x) + "-" + str(b) + ".sql.csv", "w")
        for line in lines:
            if line.count("rows affected")==0:
                f.write(line)

        f.close()