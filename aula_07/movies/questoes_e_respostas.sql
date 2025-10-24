Em 1.sql, escreva uma consulta SQL para listar os títulos de todos os filmes lançados em 2008.
Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
SELECT name
FROM movies
WHERE year = 2008;


Em 2.sql, escreva uma consulta SQL para determinar o ano de nascimento de Emma Stone.
Sua consulta deve gerar uma tabela com uma única coluna e uma única linha (sem incluir o cabeçalho) contendo o ano de nascimento de Emma Stone.
Você pode presumir que há apenas uma pessoa no banco de dados com o nome Emma Stone.
select * from people where name like '%Emma Stone%';




Em 3.sql, escreva uma consulta SQL para listar os títulos de todos os filmes com data de lançamento igual ou posterior a 2018, em ordem alfabéticaSua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
Os filmes lançados em 2018 devem ser incluídos, assim como os filmes com datas de lançamento no futuro.
select c.title from movies c where year >= 2018 ORDER BY c.title ASC;




Em 4.sql, escreva uma consulta SQL para determinar o número de filmes com uma classificação IMDb de 10,0.
Sua consulta deve gerar uma tabela com uma única coluna e uma única linha (sem incluir o cabeçalho) contendo o número de filmes com uma classificação de 10,0.
select count(*) as qtd_filmes_10 from movies m inner join
ratings r on m.id = r.movie_id where r.rating = 10.0;




Em 5.sql, escreva uma consulta SQL para listar os títulos e anos de lançamento de todos os filmes de Harry Potter, em ordem cronológica.
Sua consulta deve gerar uma tabela com duas colunas, uma para o título de cada filme e outra para o ano de lançamento de cada filme.
Você pode presumir que o título de todos os filmes de Harry Potter começará com as palavras “Harry Potter” e que se o título de um filme começar com as palavras “Harry Potter”, é um filme de Harry Potter.
select m.title,m.year from movies m where m.title like '%Harry Potter%'
ORDER BY m.year ASC;



Em 6.sql, escreva uma consulta SQL para determinar a avaliação média de todos os filmes lançados em 2012.
Sua consulta deve gerar uma tabela com uma única coluna e uma única linha (sem incluir o cabeçalho) contendo a classificação média.

select SUM(r.votes) / COUNT(*) as media_votos from movies m inner join
ratings r on m.id = r.movie_id where m.year = 2012;



Em 7.sql, escreva uma consulta SQL para listar todos os filmes lançados em 2010 e suas classificações, em ordem decrescente por classificação. 
Para filmes com a mesma classificação, ordene-os em ordem alfabética por título.
Sua consulta deve gerar uma tabela com duas colunas, uma para o título de cada filme e outra para a classificação de cada filme.
Filmes sem classificação não devem ser incluídos no resultado.

select m.title as nome, r.rating as classificacao from movies m inner join
ratings r on m.id = r.movie_id where m.year = 2010 ORDER BY r.rating DESC, m.title ASC;




Em 8.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram Toy Story.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
Você pode presumir que há apenas um filme no banco de dados com o título Toy Story.

select p.name from people p inner join
directors d on p.id = d.person_id
inner join movies m on m.id = d.movie_id
inner join stars s on s.movie_id = m.id
where m.title like '%Toy Story%' GROUP BY p.name;


Em 9.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme lançado em 2004, ordenado por ano de nascimento.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
Pessoas com o mesmo ano de nascimento podem ser listadas em qualquer ordem.
Não precisa se preocupar com pessoas que não têm ano de nascimento listado, desde que aqueles que têm ano de nascimento estejam listados em ordem.
Se uma pessoa apareceu em mais de um filme em 2004, ela só deve aparecer uma vez nos resultados.

select p.name,p.birth from people p inner join
directors d on p.id = d.person_id
inner join movies m on m.id = d.movie_id
inner join stars s on s.movie_id = m.id
where m.year = 2004 GROUP BY p.name ORDER BY p.birth ASC;



Em 10.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que dirigiram um filme que recebeu uma classificação de pelo menos 9,0.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
Se uma pessoa dirigiu mais de um filme que recebeu uma classificação de pelo menos 9,0, eles só devem aparecer em seus resultados uma vez.

select p.name,r.rating from people p inner join
directors d on p.id = d.person_id
inner join movies m on m.id = d.movie_id
inner join ratings r on r.movie_id = m.id
where r.rating >= 9.0 GROUP BY p.name;


Em 11.sql, escreva uma consulta SQL para listar os títulos dos cinco filmes com melhor classificação (em ordem) que Chadwick Boseman estrelou, começando com os de maior classificação.
Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
Você pode presumir que há apenas uma pessoa no banco de dados com o nome Chadwick Boseman.

select m.title,r.rating from people p inner join
stars s on p.id = s.person_id
inner join movies m on m.id = s.movie_id
inner join ratings r on r.movie_id = m.id
where p.name like '%Chadwick Boseman%' ORDER BY r.rating DESC LIMIT 5;


Em 12.sql, escreva uma consulta SQL para listar os títulos de todos os filmes em que Johnny Depp e Helena Bonham Carter estrelaram juntos.
Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
Você pode presumir que há apenas uma pessoa no banco de dados com o nome Johnny Depp.
Você pode presumir que há apenas uma pessoa no banco de dados com o nome Helena Bonham Carter.


select m.title from people p inner join
stars s on p.id = s.person_id
inner join movies m on m.id = s.movie_id
where p.name like '%Johnny Depp%' AND p.name like '%Helena Bonham Carter%' GROUP BY m.title;

Em 13.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme no qual Kevin Bacon também estrelou.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
Pode haver várias pessoas chamadas Kevin Bacon no banco de dados. Certifique-se de selecionar apenas Kevin Bacon nascido em 1958.
O próprio Kevin Bacon não deve ser incluído na lista resultante.

SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
WHERE m.id IN (
    SELECT m2.id
    FROM movies m2
    JOIN stars s2 ON m2.id = s2.movie_id
    JOIN people p2 ON s2.person_id = p2.id
    WHERE p2.name = 'Kevin Bacon'
      AND p2.birth = 1958
)
AND p.name != 'Kevin Bacon';
