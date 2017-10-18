static constexpr const char* CREATE_TABLE_EMPLOYEES = 
    "CREATE TABLE EMPLOYEES("           \
    "NAME           TEXT    NOT NULL,"  \
    "ADDRESS        CHAR(50),"          \
    "EMAIL          CHAR(50),"          \
    "PHONE          CHAR(20));"           ;

static constexpr const char* CREATE_TABLE_TASKS = 
    "CREATE TABLE TASKS("                  \
    "NAME           CHAR(50)    NOT NULL,"  \
    "TYPE           CHAR(50)    NOT NULL,"  \
    "PRIORITY       INT         NOT NULL,"  \
    "DEADLINE       DATE        NOT NULL,"  \
    "DESC           CHAR(200));"          ;

static constexpr const char* CREATE_TABLE_PROJECTS = 
    "CREATE TABLE PROJECTS("            \
    "NAME           TEXT    NOT NULL,"  \
    "DESC           CHAR(50));"          ;

static constexpr const char* CREATE_TABLE_MEETING = 
    "CREATE TABLE MEETING("             \
    "DESC           CHAR(100),"         \
    "DATE           DATETIME);"           ;

static constexpr const char* CREATE_TABLE_ATTENDS = 
    "CREATE TABLE ATTENDS("       \
    "EMP_ID INT       NOT NULL,"  \
    "MTNG_ID INT      NOT NULL);"  ;

static constexpr const char* CREATE_TABLE_BELONGS = 
    "CREATE TABLE BELONGS("      \
    "EMP_ID INT      NOT NULL,"  \
    "TSK_ID INT      NOT NULL);" ;

static constexpr const char* CREATE_TABLE_CONTAINS = 
    "CREATE TABLE CONTAINS("      \
    "TASKS_ID INT      NOT NULL," \
    "PROJ_ID INT       NOT NULL);" ;

static constexpr const char* INSERT_INTO_PROJECTS[20] = {
    "INSERT INTO PROJECTS\n" \
    "VALUES('Elso debreceni csata', 'Elso vilaghaboru nagy csatai');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Masodik debreceni csata', 'Elso vilaghaboru nagy csatai');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Torok haboruk', 'Vegvari harcok');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Doberdoi csata', 'Elso vilaghaboru nagy csatai');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Nandorfehervari csata', 'Vegvari harcok');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('1956. oktober', '1956');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Muhi csata', 'Sajat');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Muhi csata', 'Leíras');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Mohacs', 'Vegvari harcok');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Vasvari beke', 'Vegvari harcok');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Szolnoki var', 'A szolnoki var');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Egri csata', 'Vegvari harcok');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Limanovai csata', 'Elso vilaghaboru nagy csatai');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Belgradi csata', 'Elso vilaghaboru nagy csatai');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Elso doberdoi csata', 'Elso vilaghaboru nagy csatai');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Masodik doberdoi csata', 'Elso vilaghaboru nagy csatai');" ,
    "INSERT INTO PROJECTS\n" \
    "VALUES('Bukaresti csata', 'Elso vilaghaboru nagy csatai');"
};

static constexpr const char* INSERT_INTO_TASKS[20] = {    
    "INSERT INTO TASKS\n"\
    "VALUES ('Varmodell', '3D modellezes', '10', '2012-01-01', 'Az egri var 3D modelljenek kidolgozasa.');",
    "INSERT INTO TASKS\n"\
    "VALUES ('agyuloves', '3D animacio', '5', '2012-01-01', 'Korabeli agyuk elsutesenek animalasa.');",
    "INSERT INTO TASKS\n"\
    "VALUES ('Terkepanimacio', '2D animacio', '7', '2012-01-01', 'Eger kornyekenek, a torok es magyar erok helyzetenek kirajzolasa, mozgasuk megjelenítese.');",
    "INSERT INTO TASKS\n"\
    "VALUES ('T-34', '3D modellezes', '6', '2012-01-01', 'Szovjet T-34 tank 3D modellje.');",
    "INSERT INTO TASKS\n"\
    "VALUES ('Tatar zene', 'Hangstudio', '3', '2012-01-01', 'Korabeli tatar harci zenek video alafestesnek.');"
};
static constexpr const char* INSERT_INTO_EMPLOYEES[20] = {        
    "INSERT INTO EMPLOYEES\n" \
    "VALUES('Nagy Aladar', 'Miskolc Nagy utca 1.', 'nagyaladar@ceg.hu', '06204596733');" ,
    "INSERT INTO EMPLOYEES\n" \
    "VALUES('Kis Andras', 'Budapest Kis utca 10.', 'kisandras@ceg.hu', '06204596543');" ,
    "INSERT INTO EMPLOYEES\n" \
    "VALUES('Kovacs Janos', 'Budapest Fo utca 14.', 'kovacsjanos@ceg.hu', '06204567368');" ,
    "INSERT INTO EMPLOYEES\n" \
    "VALUES('Maszat Aranka', 'Godollo Petofi utca 11.', 'maszataranka@ceg.hu', '06204598276');" ,
    "INSERT INTO EMPLOYEES\n" \
    "VALUES('Bogre Peter', 'Piliscsaba Kossuth utca 31.', 'bogrepeter@ceg.hu', '06204539517');" 
};