-- cat log.sql | sqlite3 fiftyville.db rodar o banco aqui.

-- Informações:
-- O roubo ocorreu dia 28 de julho(7)
-- Aconteceu na Chamberlin Street street

-- Objetivos:
-- Quem é o ladrão:
-- Onde ele escapou para onde ele foi:
-- O cumplice dele:

-- 1 passo: Descobrir tabelas existentes:
-- SELECT name
-- FROM sqlite_master
-- WHERE type = 'table'
--   AND name NOT LIKE 'sqlite_%';

-- +----------------------+
-- |         name         |
-- +----------------------+
-- | crime_scene_reports  |
-- | interviews           |
-- | atm_transactions     |
-- | bank_accounts        |
-- | airports             |
-- | flights              |
-- | passengers           |
-- | phone_calls          |
-- | people               |
-- | bakery_security_logs |
-- +----------------------+

-- Pela descrição deste o pato foi roubado ID = 295
-- select * from crime_scene_reports where month = 7 and day = 28 and year = 2023;
-- Já essa não me trouxe nada de interessante.
-- select * from crime_scene_reports where street like '%Chamberlin%';
-- 295
-- 2023
-- 7
-- 28
-- Humphrey Street
-- O roubo do pato do CS50 ocorreu às 10h15 na padaria da Humphrey Street. Entrevistas foram conduzidas hoje com três testemunhas que estavam presentes no momento — cada uma de suas transcrições menciona a padaria.

-- select * from interviews where month = 7 and day = 28 and year = 2023;
-- 161 Ruth 2023 7 28 Cerca de dez minutos após o roubo, vi o ladrão entrar em um carro no estacionamento da padaria e sair dirigindo. Se houver imagens das câmeras de segurança do estacionamento da padaria, talvez você queira verificar quais carros saíram nesse intervalo de tempo.
-- 162	Eugênio	2023	7	28	Não sei o nome do ladrão, mas era alguém que eu reconheci. Hoje de manhã, antes de chegar à padaria da Emma, eu estava passando pelo caixa eletrônico na Leggett Street e vi o ladrão lá, sacando dinheiro.
-- 163	Raimundo	2023	7	28	Quando o ladrão estava saindo da padaria, ele ligou para alguém e falou por menos de um minuto. Durante a ligação, ouvi o ladrão dizer que planejava pegar o primeiro voo que saísse de Fiftyville amanhã. O ladrão então pediu à pessoa do outro lado da linha que comprasse a passagem de voo.

-- select * from atm_transactions limit 10;

-- Quem é o ladrão:
-- SELECT person_id FROM bank_accounts WHERE account_number = 81061156;
-- SELECT * FROM people WHERE id = 438727;

-- SELECT *
-- FROM passengers
-- WHERE flight_id = 36;

-- SELECT person_id
-- FROM bank_accounts
-- WHERE account_number = 81061156;

SELECT *
FROM phone_calls
WHERE year = 2023
  AND month = 7
  AND day = 28
  AND (caller = '(338) 555-6650' OR receiver = '(338) 555-6650')
  AND duration < 60;


-- Onde ele escapou para onde ele foi:
SELECT
  f.id,
  f.year,
  f.month,
  f.day,
  f.hour,
  f.minute,
  origin.city AS origin_city,
  dest.city AS destination_city
FROM flights f
JOIN airports origin ON f.origin_airport_id = origin.id
JOIN airports dest ON f.destination_airport_id = dest.id
WHERE origin.city = 'Fiftyville'
  AND f.year = 2023
  AND f.month = 7
  AND f.day = 29
ORDER BY f.hour, f.minute
LIMIT 1;


-- O cumplice dele:
-- SELECT * FROM passengers WHERE flight_id = <id_do_voo_do_ladrão>;

-- select * from passengers limit 10;


