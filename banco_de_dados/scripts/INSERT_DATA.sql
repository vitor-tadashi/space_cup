USE space_cup

BEGIN TRANSACTION

	INSERT INTO SC_Faculdade VALUES ('FIAP')

	INSERT INTO SC_Fiscal VALUES ('Paola Oliveira', '40553691821')

	INSERT INTO SC_Endereco VALUES ('Avenida Lins de Vasconcelos', '02807000', 1020)

	INSERT INTO SC_Evento VALUES (GETDATE(), 'Space Cup 2017', 1, 1, 1)

	INSERT INTO SC_Turma VALUES ('2SIS', 'Sistemas de Informação', 1)

	INSERT INTO SC_Foguete VALUES ('Apollo 13', 0.15, 0.8)

	INSERT INTO SC_Equipe VALUES ('Hopper', 1, 1)

	INSERT INTO SC_Aluno VALUES ('Leonardo Miranda', 1)
	INSERT INTO SC_Aluno VALUES ('Tamyris Miranda', 1)
	INSERT INTO SC_Aluno VALUES ('Caique Cury', 1)
	INSERT INTO SC_Aluno VALUES ('Lucas Jordão', 1)
	INSERT INTO SC_Aluno VALUES ('Bianca Caravajo', 1)

	INSERT INTO SC_Lancamento VALUES (20, 40, 10, 50, 45, 30, 100, 10, 15, 11, 20, GETDATE(), 100, 90, 50, 1)

COMMIT