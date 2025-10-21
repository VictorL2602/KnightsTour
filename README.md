# Knight’s Tour

Mit program viser hvor mange felter en ridder (knight) kan opnå på et skakbræt, hvis den altid tager det første mulige træk, også kendt som greedy-metoden.

## Programmets opbygning
- Programmet laver et 8x8 bræt som kan ændres med "#define SIZE" i header-filen.  
- Ridderen starter på hvert felt en gang.  
- Den prøver at flytte sig efter sine 8 mulige træk (2+1-bevægelser).  
- Hvis et træk er muligt tager den det første der virker.  
- Den tæller hvor mange felter den når før den sidder fast.  
- Resultatet printes som en tabel hvor hvert tal viser hvor langt ridderen nåede fra det startfelt.

- OBS!! Jeg er blevet mindet om at en knight hedder en springer på dansk, og ikke ridder, så se bort fra den fejl... :)
