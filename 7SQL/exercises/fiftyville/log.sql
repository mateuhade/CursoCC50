-- Keep a log of any SQL queries you execute as you solve the mystery.

--------------------------Clues and facts:--------------------------
FACTS:
-- A duck was stolen
-- The crime ocurred in July 28 at 10:15am
-- The crime ocurred on the Humphrey Street

CLUES:
-- According to Eugine, the thief withdrew money from an atm at the morning of the crime
-- According to Eugine, the withdrawal was at Leggett Street

-- According to Ruth, the thief went away on his car up to 10 minutes after the crime

-- According to Raymond, the thief took the earliest flight out of fiftyville in the next day
-- According to Raymond, the thief's friend who he called bought the ticket as soon as the duck was stolen

--------------------------Clues and facts:--------------------------

********************************************************************

------------------------------schema--------------------------------
.tables
airports              crime_scene_reports   people
atm_transactions      flights               phone_calls
bakery_security_logs  interviews
bank_accounts         passengers

-- In the table scheme we have the date the report was made and where
-- it was made.
.schema crime_scene_reports
CREATE TABLE crime_scene_reports (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    street TEXT,
    description TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE interviews (
    id INTEGER,
    name TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    transcript TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE people (
    id INTEGER,
    name TEXT,
    phone_number TEXT,
    passport_number INTEGER,
    license_plate TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE bakery_security_logs (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    activity TEXT,
    license_plate TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE airports (
    id INTEGER,
    abbreviation TEXT,
    full_name TEXT,
    city TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE flights (
    id INTEGER,
    origin_airport_id INTEGER,
    destination_airport_id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(origin_airport_id) REFERENCES airports(id),
    FOREIGN KEY(destination_airport_id) REFERENCES airports(id)
);

CREATE TABLE passengers (
    flight_id INTEGER,
    passport_number INTEGER,
    seat TEXT,
    FOREIGN KEY(flight_id) REFERENCES flights(id)
);

CREATE TABLE phone_calls (
    id INTEGER,
    caller TEXT,
    receiver TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    duration INTEGER,
    PRIMARY KEY(id)
);

CREATE TABLE atm_transactions (
    id INTEGER,
    account_number INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    atm_location TEXT,
    transaction_type TEXT,
    amount INTEGER,
    PRIMARY KEY(id)
);

CREATE TABLE bank_accounts (
    account_number INTEGER,
    person_id INTEGER,
    creation_year INTEGER,
    FOREIGN KEY(person_id) REFERENCES people(id)
);





-------------------------------schema---------------------------------

********************************************************************

----------------------------INVESTIGATION:----------------------------

SELECT count(description) FROM crime_scene_reports;
-- 301 Reports


SELECT street, description FROM crime_scene_reports WHERE month = 7
AND day = 28 ORDER BY street;                                                                                                                                                       |
| Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |

SELECT transcript, name FROM interviews WHERE day = 28 AND month = 7;
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|  name   |                                                                                                                                                     transcript                                                                                                                                                      |
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+                                                                                                                     |
| Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| Eugene  | I don''t know the thief''s name, but it was someone I recognized. Earlier this morning, before I arrived at Emma''s bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                              |
| Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

-- PEOPLE WHO LEFT THE BAKERY DURING THE TIME FRAME
SELECT name FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute <= 25
AND minute > 15);

-- ALL PEOPLE IN THE SAME FLIGHT AS SUSPECT
SELECT name FROM people WHERE passport_number IN
(SELECT passport_number FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE flight_id = (SELECT flights.id FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE month = 7 AND day = 29 AND origin_airport_id =
(SELECT id FROM airports WHERE city LIKE 'Fiftyville')
ORDER BY hour, minute LIMIT 1));

-- INFORMATIONS ABOUT SUSPECT FLIGHT
SELECT * FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE month = 7 AND day = 29 AND origin_airport_id =
(SELECT id FROM airports WHERE city LIKE 'Fiftyville')
ORDER BY hour, minute LIMIT 1;

-- ALL PEOPLE IN SUSPECT CALLS
SELECT name FROM people
WHERE phone_number IN
(SELECT caller FROM phone_calls
WHERE duration < 60 AND
month = 7 AND day = 28);

-- PEOPLE WHO DID SUSPECT TRANSACITONS
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN (SELECT account_number
FROM atm_transactions WHERE month = 7 AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw');

-- PEOPLE WHO CULPRIT CALLED DURING INCIDENT
SELECT name FROM people WHERE phone_number =
(SELECT receiver FROM phone_calls
WHERE caller = (SELECT phone_number FROM people
WHERE name = 'Bruce') AND month = 7 AND day = 28);

----------------------------INVESIGATION:----------------------------

*********************************************************************

------------------------------Suspects:------------------------------

-- WITNESSESS:
RAYMOND
EUGENE
RUTH

-- LEFT BAKERY WITHIN TIME FRAME:
VANESSA
BARRY
IMAN
SOFIA
LUCA
DIANA
KELSEY
BRUCE

-- IN SUSPECT FLIGHT
KENNY
SOFIA
TAYLOR
LUCA
KELSEY
EDWARD
BRUCE
DORIS

-- SUSPECT CALLERS
KENNY
SOFIA
BENISTA
TAYLOR
DIANA
KELSEY
BRUCE
CARINA

-- SUSPECT RECEIVERS
JAMES
LARRY
ANNA
JACK
MELISSA
JACQUELINE
PHILIP
ROBIN
DORIS

-- IN SUSPECT TRANSACTIONS
BRUCE
DIANA
BROOKE
KENNY
IMAN
LUCA
TAYLOR
BENISTA

-- MATCHING SUSPECTS (MAIN):
BRUCE

-- MATCHING SUSPECTS (ACCOMPLICE):
-- DORIS
ROBIN (the person who bruce called)
