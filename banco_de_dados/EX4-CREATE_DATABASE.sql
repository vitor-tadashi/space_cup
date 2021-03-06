CREATE DATABASE space_cup

GO

USE space_cup

CREATE TABLE SC_Faculdade
  (	
    ID_FACULDADE INT NOT NULL IDENTITY PRIMARY KEY,
    NOME         VARCHAR(80) NOT NULL
  );
  
  
  CREATE TABLE SC_Fiscal
  ( 
	ID_FISCAL INT NOT NULL IDENTITY PRIMARY KEY, 
	NOME VARCHAR(80) NOT NULL,
	CPF VARCHAR(11)
  );
  
    
  CREATE TABLE SC_Endereco
  (
    ID_ENDERECO INT NOT NULL IDENTITY PRIMARY KEY,
    LOGRADOURO  VARCHAR(80) NOT NULL,
    CEP         VARCHAR(80) NOT NULL,
    NUMERO      INT NOT NULL
  );  
  
  
  CREATE TABLE SC_Evento
  (
    ID_EVENTO    INT NOT NULL IDENTITY PRIMARY KEY,
    DATA         DATETIME NOT NULL,
	NOME_EVENTO	 VARCHAR(80),
    ID_FACULDADE INT NOT NULL FOREIGN KEY REFERENCES SC_Faculdade(ID_FACULDADE),
    ID_ENDERECO  INT NOT NULL FOREIGN KEY REFERENCES SC_Endereco(ID_ENDERECO),
    ID_FISCAL    INT NOT NULL FOREIGN KEY REFERENCES SC_Fiscal(ID_FISCAL)
  );
  
  
  CREATE TABLE SC_Turma
  (
    ID_TURMA     INT NOT NULL IDENTITY PRIMARY KEY,
    NOME_TURMA   VARCHAR(80) NOT NULL,
    ID_FACULDADE INT NOT NULL FOREIGN KEY REFERENCES SC_Faculdade(ID_FACULDADE)
  );
  
  
  CREATE TABLE SC_Foguete
  (
    ID_FOGUETE INT NOT NULL IDENTITY PRIMARY KEY,
    NOME       VARCHAR(80) NOT NULL,
    PESO       FLOAT NOT NULL,
    ALTURA     FLOAT NOT NULL
	--ALTRUA
  );
  
  
  CREATE TABLE SC_Equipe
  (
    ID_EQUIPE  INT NOT NULL IDENTITY PRIMARY KEY,
    NOME       VARCHAR(80) NOT NULL,
    ID_TURMA   INT NOT NULL FOREIGN KEY (ID_TURMA) REFERENCES SC_Turma(ID_TURMA),
    ID_FOGUETE INT NOT NULL FOREIGN KEY REFERENCES SC_Foguete(ID_FOGUETE)
  );


CREATE TABLE SC_Aluno
  (
    MATRICULA INT NOT NULL IDENTITY PRIMARY KEY,
    NOME      VARCHAR(80) NOT NULL,
    ID_EQUIPE INT NOT NULL FOREIGN KEY REFERENCES SC_Equipe(ID_EQUIPE)

  );


CREATE TABLE SC_Lancamento
  (
    ID_LANCAMENTO        INT NOT NULL IDENTITY PRIMARY KEY,
    ALTITUDE_MAXIMA      FLOAT NOT NULL,
    VELOCIDADE_MAXIMA    FLOAT NOT NULL,
    TEMPO_PROPULSAO      FLOAT NOT NULL,
    PICO_ACELERACAO      FLOAT NOT NULL,
    ACELERACAO_MEDIA     FLOAT NOT NULL,
    TEMPO_APOGEU_DESCIDA FLOAT NOT NULL,
    DISTANCIA_ALVO       FLOAT NOT NULL,
    TEMPO_EJECAO         FLOAT NOT NULL,
    ALTITUDE_EJECAO      FLOAT NOT NULL,
    TAXA_DESCIDA         FLOAT NOT NULL,
    DURACAO_VOO          FLOAT NOT NULL,
    DATA                 DATETIME NOT NULL,
    DISTANCIA_ATE_ALVO   FLOAT NOT NULL,
    ANGULO               FLOAT NOT NULL,
    VELOCIDADE_VENTO     INT NOT NULL,
    ID_FOGUETE   INT NOT NULL FOREIGN KEY REFERENCES SC_Foguete(ID_FOGUETE)
	
  );