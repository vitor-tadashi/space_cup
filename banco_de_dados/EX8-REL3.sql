SELECT EV.DATA AS ANOEVENTO,
	   EN.LOGRADOURO + ' ' + CAST(EN.NUMERO AS VARCHAR) + ' - ' + EN.CEP AS LOCALEVENTO,
	   E.NOME AS NOMEEQUIPE
  FROM SC_EVENTO EV
       INNER JOIN SC_ENDERECO EN ON EV.ID_ENDERECO = EN.ID_ENDERECO
	   INNER JOIN SC_FACULDADE FC ON EV.ID_FACULDADE = FC.ID_FACULDADE
	   INNER JOIN SC_TURMA T ON T.ID_FACULDADE = FC.ID_FACULDADE
       INNER JOIN SC_EQUIPE E ON E.ID_TURMA = T.ID_TURMA
 WHERE YEAR(EV.DATA) >= 2015 AND YEAR(EV.DATA) <= 2017