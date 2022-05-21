-- Prepare data - Postgres
-- DROP TABLE world;
CREATE TABLE IF NOT EXISTS "leetcode"."leetcode".world(
    name varchar(255), 
    continent varchar(255), 
    area bigint, 
    population bigint, 
    gdp bigint
);
TRUNCATE TABLE world;
INSERT INTO "leetcode".world(name, continent, area, population, gdp) VALUES ('Afghanistan', 'Asia', '652230', '25500100', '20343000000');
INSERT INTO "leetcode".world(name, continent, area, population, gdp) VALUES ('Albania', 'Europe', '28748', '2831741', '12960000000');
INSERT INTO "leetcode".world(name, continent, area, population, gdp) VALUES ('Algeria', 'Africa', '2381741', '37100000', '188681000000');
INSERT INTO "leetcode".world(name, continent, area, population, gdp) VALUES ('Andorra', 'Europe', '468', '78115', '3712000000');
INSERT INTO "leetcode".world(name, continent, area, population, gdp) VALUES ('Angola', 'Africa', '1246700', '20609294', '100990000000');

-- Solution
SELECT name,population,area FROM leetcode.world WHERE area>=3000000 or population>=25000000;

-- Solution 2
SELECT name,population,area FROM leetcode.world WHERE area>=3000000 UNION
SELECT name,population,area FROM leetcode.world WHERE population>=25000000;