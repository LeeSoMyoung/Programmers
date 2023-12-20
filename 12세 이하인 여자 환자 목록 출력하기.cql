// 문제 링크 : https://school.programmers.co.kr/learn/courses/30/lessons/132201

SELECT
    PT_NAME, PT_NO, GEND_CD, AGE, 
    CASE WHEN TLNO IS NULL THEN 'NONE' ELSE TLNO END AS 'TLNO'
FROM PATIENT
WHERE
    GEND_CD = 'W' AND
    AGE <=12
ORDER BY AGE DESC, PT_NAME ASC;
