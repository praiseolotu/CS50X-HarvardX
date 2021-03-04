-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find out the description of the crime that took place on that particular day
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";

-- Find out the transcript of the 3 witness and their names
SELECT name, transcript FROM interviews WHERE day = 28 AND month = 7 AND transcript LIKE "%courthouse%";

-- To get license plate number for all cars that left the court house
    SELECT activity, hour, minute,license_plate FROM courthouse_security_logs
    WHERE day = 28 AND month = 7 AND hour >= 10 AND hour < 12 AND activity
    LIKE "%exit%" AND minute >= 15 AND minute < 25;

-- Find names of people with car license number
SELECT name FROM people WHERE license_plate IN (
SELECT license_plate FROM courthouse_security_logs
WHERE day = 28 AND month = 7 AND hour >= 10
AND hour < 12 AND activity LIKE "%exit%" AND minute >= 15 AND minute < 25);

-- Get the id of every calls less than 60 seconds
SELECT id, duration,caller, receiver FROM phone_calls WHERE duration <  60 AND day = 28 AND month = 7;

-- Find the phone number of Ernest
SELECT phone_number FROM people WHERE license_plate IN (
SELECT license_plate FROM courthouse_security_logs
WHERE day = 28 AND month = 7 AND hour >= 10
AND hour < 12 AND activity LIKE "%exit%" AND minute >= 15 AND minute < 25);

-- Ernest number is (367) 555-5533
-- From our query I found out that Ernest called this number (375) 555-8161 with 45 seconds

-- Get the person Ernest called, the persons name is Berthold
SELECT name, phone_number FROM people WHERE phone_number LIKE "(375) 555-8161";

-- Get the destination airport id for the earliest flight on 29 July
SELECT destination_airport_id FROM flights WHERE day = 29 AND month = 7 AND year = 2020 ORDER BY hour, minute LIMIT 1;

-- Get the city they both ran to

SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE day = 29 AND month = 7 AND year = 2020 ORDER BY hour, minute LIMIT 1);