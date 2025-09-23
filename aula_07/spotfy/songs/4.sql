-- No 4.sql, escreva uma consulta SQL que liste os nomes de quaisquer músicas que tenham dançabilidade, energia e valência maior que 0,75.
-- Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
Resp:SELECT * FROM songs WHERE energy > 0.75 AND valence > 0.75 AND danceability > 0.75;
