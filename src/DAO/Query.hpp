static constexpr const char* CREATE_TABLE_EMPLOYEES = 
    "CREATE TABLE EMPLOYEES("           \
    "NAME           TEXT    PRIMARY KEY NOT NULL,"  \
    "ADDRESS        CHAR(50),"          \
    "EMAIL          CHAR(50),"          \
    "PHONE          CHAR(20));"           ;

static constexpr const char* CREATE_TABLE_TASKS = 
    "CREATE TABLE TASKS("                  \
    "NAME           CHAR(50)    PRIMARY KEY NOT NULL,"  \
    "TYPE           CHAR(50)    NOT NULL,"  \
    "PRIORITY       INT         NOT NULL,"  \
    "DEADLINE      DATE        NOT NULL,"  \
    "DESC           CHAR(200));"          ;

static constexpr const char* CREATE_TABLE_PROJECTS = 
    "CREATE TABLE PROJECTS("            \
    "NAME           TEXT   PRIMARY KEY  NOT NULL,"  \
    "DESC           CHAR(50));"          ;

static constexpr const char* CREATE_TABLE_MEETING = 
    "CREATE TABLE MEETING("             \
    "DESC           CHAR(100),"         \
    "DATE           DATETIME);"           ;

static constexpr const char* CREATE_TABLE_ATTENDS = 
    "CREATE TABLE ATTENDS("       \
    "EMP_ID INT       NOT NULL,"  \
    "MTNG_ID INT     NOT NULL);"  ;

static constexpr const char* CREATE_TABLE_BELONGS = 
    "CREATE TABLE BELONGS("      \
    "EMP_ID INT      NOT NULL,"  \
    "TSK_ID INT      NOT NULL);" ;

static constexpr const char* CREATE_TABLE_CONTAINS = 
    "CREATE TABLE CONTAINS("      \
    "TASKS_ID INT      NOT NULL," \
    "PROJ_ID INT      NOT NULL);" ;

static constexpr const char* INSERT_INTO_PROJECTS[20] = {
    "INSERT INTO PROJECTS\n" \
    "VALUES('Első debreceni csata', 'Első világháború nagy csatái');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Második debreceni csata', 'Első világháború nagy csatái');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Török háborúk', 'Végvári harcok');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Doberdói csata', 'Első világháború nagy csatái');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Nándorfehérvári csata', 'Végvári harcok');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('1956. október', '1956');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Muhi csata', 'Saját');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Muhi csata', 'Leírás');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Mohács', 'Végvári harcok');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Vasvári béke', 'Végvári harcok');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Szolnoki vár', 'A szolnoki vár');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Egri csata', 'Végvári harcok');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Limanovai csata', 'Első világháború nagy csatái');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Belgrádi csata', 'Első világháború nagy csatái');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Első doberdói csata', 'Első világháború nagy csatái');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Második doberdói csata', 'Első világháború nagy csatái');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Bukaresti csata', 'Első világháború nagy csatái');"
};

static constexpr const char* INSERT_INTO_TASKS[20] = {    
    "INSERT INTO TASKS\n"\
    "VALUES ('Vármodell', '3D modellezés', '10', '2012-01-01', 'Az egri vár 3D modelljének kidolgozása.');",
    "INSERT INTO TASKS\n"\
    "VALUES ('Ágyúlövés', '3D animáció', '5', '2012-01-01', 'Korabeli ágyúk elsütésének animálása.');",
    "INSERT INTO TASKS\n"\
    "VALUES ('Térképanimáció', '2D animáció', '7', '2012-01-01', 'Eger környékének, a török és magyar erők helyzetének kirajzolása, mozgásuk megjelenítése.');",
    "INSERT INTO TASKS\n"\
    "VALUES ('T-34', '3D modellezés', '6', '2012-01-01', 'Szovjet T-34 tank 3D modellje.');",
    "INSERT INTO TASKS\n"\
    "VALUES ('Tatár zene', 'Hangstúdió', '3', '2012-01-01', 'Korabeli tatár harci zenék videó aláfestésnek.');"
};
static constexpr const char* INSERT_INTO_EMPLOYEES[20] = {        
    "INSERT INTO EMPLOYEES\n" \
    "VALUES('Nagy Aladár', 'Miskolc Nagy utca 1.', 'nagyaladar@ceg.hu', '06204596733');" ,
    "INSERT INTO EMPLOYEES\n" \
    "VALUES('Kis András', 'Budapest Kis utca 10.', 'kisandras@ceg.hu', '06204596543');" ,
    "INSERT INTO EMPLOYEES\n" \
    "VALUES('Kovács János', 'Budapest Fő utca 14.', 'kovacsjanos@ceg.hu', '06204567368');" ,
    "INSERT INTO EMPLOYEES\n" \
    "VALUES('Maszat Aranka', 'Gödöllő Petőfi utca 11.', 'maszataranka@ceg.hu', '06204598276');" ,
    "INSERT INTO EMPLOYEES\n" \
    "VALUES('Bögre Péter', 'Piliscsaba Kossuth utca 31.', 'bogrepeter@ceg.hu', '06204539517');" 
};