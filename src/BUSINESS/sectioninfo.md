# BUSINESS LAYER
Összetett business logika
* A Transfer layerből nyeri az adatot
* Használhatja az OwnLibraryt

## Funkciók:
* List Deadlines
* List Tasks (Ordering, sorting!)
* List Projects
* List Employees
* Filter Deadline/Task/Project/Employee
    * by any property they have (cmd autocomplete or drop list?)
* Draw project structure
    * Tasks/Employees/Deadlines(timeline?)

Az empl-kat és takokat is csak egyszer tároljuk valahol és csak mutogatnak egymásra

## Design Patterns
### Mediator
Task exchange between Employees

### Singleton
The application itself

### Deadline, ?Task?: implements State
#### Fields:
Date due;
#### Description:
Állapotváltozáskor önmagát megsemmisítő objektum. Az új állapot egy új osztály azonos ősosztállyal.
* ExpiredDeadline/ActiveDeadline
* ActiveTask/CompletedTask

### Factory
Konstruktor helyett ezzel létrehozni
* DAOFactory
* TaskFactory?

### Strategy
Task listázása priority alapján (sürgősök, kisebb prioritásúak)
* pl. nagyobb priotity-jű taskokat hozzárendeli a szakterületi felelőshöz
    * kisebbek global space-ben, senkihez sem rendelve

### Composite
ProjectOrganizer
* benne van a Project
* egy tasklist (a projecté)
* az employeek (akik részt vesznek, a taskokból kilistázva)

## Used or implemented in OwnLibrary
### Iterator

### Visitor
kell neki egy interface (acceptvisitor)
beadjuk az iteratornak a visitort
a visitor fv-ét meghívjuk az iterator.accpetvisitorban és beadjuk neki a node-ot amire az iterator mutat
Itt:
* taskok prioritásának csökkentése/növelése (pl. predikátumos iterátorral végigjárva adott vector elemeit)  