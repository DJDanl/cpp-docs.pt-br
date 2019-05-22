---
title: SQL
ms.date: 05/09/2019
helpviewer_keywords:
- database classes [C++], SQL statements
- SQL [C++]
- SQL [C++], ODBC
- ODBC [C++], SQL implementation
ms.assetid: e3923bc4-b317-4e0b-afd8-3cd403eb0faf
ms.openlocfilehash: 68c01623ef97e89623dff3f46a952c75ea31a774
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707824"
---
# <a name="sql"></a>SQL

A Linguagem SQL é uma maneira de se comunicar com um banco de dados relacional que permite que você defina, consulte, modifique e controle os dados. Usando a sintaxe SQL, é possível construir uma instrução que extrai registros de acordo com os critérios que você especifica.

> [!NOTE]
>  Essas informações aplicam-se às classes ODBC do MFC. Se estiver trabalhando com as classes DAO do MFC, confira o tópico Comparação do SQL e SQL ANSI do Mecanismo de Banco de Dados Jet da Microsoft na Ajuda do DAO.

As instruções SQL começam com um verbo de palavra-chave como **CREATE** ou **SELECT**. O SQL é uma linguagem muito avançada; uma instrução única pode afetar toda uma tabela.

Existem muitas versões do SQL, cada uma desenvolvida com um DBMS específico em mente. As classes do banco de dados do MFC reconhecem um conjunto de instruções SQL que corresponde à especificação de rascunho do SQL CAE (Common Applications Environment) do Grupo de Acesso do SQL (1991) e ao X/Open. Para saber mais sobre a sintaxe dessas instruções, confira o Apêndice C na *Referência do Programador* *do SDK ODBC* no CD da Biblioteca MSDN.

Este tópico explica:

- [A relação entre ODBC e SQL](#_core_open_database_connectivity_.28.odbc.29).

- [As palavras-chave SQL mais comuns usadas pelas classes de banco de dados](#_core_the_database_classes).

- [Como as classes de banco de dados usam o SQL](#_core_how_the_database_classes_use_sql).

##  <a name="_core_open_database_connectivity_.28.odbc.29"></a> ODBC

As classes de banco de dados são implementadas com a ODBC, que usa o SQL em uma interface de nível de chamada em vez de inserir comandos SQL no código. A ODBC usa o SQL para se comunicar com uma [fonte de dados](../../data/odbc/data-source-odbc.md) por meio de drivers ODBC. Esses drivers interpretam o SQL e o convertem, se necessário, para uso com um formato de banco de dados específico, como o Microsoft Access. Para saber mais sobre como a ODBC usa o SQL, confira [ODBC](../../data/odbc/odbc-basics.md) e a *Referência do Programador* do SDK ODBC no CD da Biblioteca MSDN.

##  <a name="_core_the_database_classes"></a> Classes de Banco de Dados

> [!NOTE] 
> O Assistente de consumidor ODBC do MFC não está disponível no Visual Studio 2019 e posterior. É possível criar um consumidor manualmente.

As classes de banco de dados são criadas para permitir que você manipule e atualize dados em uma [fonte de dados](../../data/odbc/data-source-odbc.md) existente. O [Assistente de Aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md), o [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) (acessado por meio de **Adicionar Classe**) e as classes de banco de dados constroem a maioria das instruções SQL para você.

As classes de banco de dados usam uma parte do SQL conhecida como DML (Linguagem de Manipulação de Dados). Esses comandos permitem que você trabalhe com toda a fonte de dados ou com parte dela, adicione novos registros e edite e exclua registros existentes. A tabela a seguir lista as palavras-chave SQL mais comuns e as maneiras como as classes de banco de dados as usam.

### <a name="some-common-sql-keywords"></a>Algumas palavras-chave SQL comuns

|Palavra-chave SQL|O assistente e as classes de banco de dados a usam|
|-----------------|---------------------------------------------|
|**SELECT**|Para identificar quais tabelas e colunas na fonte de dados devem ser usadas.|
|**WHERE**|Para aplicar um filtro que restringe a seleção.|
|**ORDER BY**|Para aplicar uma ordem de classificação ao conjunto de registros.|
|**INSERT**|Para adicionar novos registros a um conjunto de registros.|
|**DELETE**|Para excluir registros de um conjunto de registros.|
|**UPDATE**|Para modificar os campos de um registro.|

Além disso, as classes de banco de dados reconhecem as instruções **CALL** ODBC, que podem ser usadas para chamar uma consulta predefinida (ou procedimento armazenado) em algumas fontes de dados. O driver do banco de dados ODBC interpreta essas instruções e substitui o comando adequado para cada DBMS.

> [!NOTE]
>  Nem todos os DBMSs dão suporte a instruções **CALL**.

Se as classes não puderem reconhecer uma instrução fornecida pelo usuário em `CRecordset::Open`, ela será interpretada como um nome de tabela.

Para obter uma explicação de como a estrutura constrói instruções SQL, confira [Conjunto de registros: como os conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md) e [SQL: como personalizar a instrução SQL do seu conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).

Os bancos de dados SQL usam tipos de dados semelhantes aos usados em C e C++. Para ver uma discussão dessas semelhanças, confira [SQL: tipos de dados SQL e C++ (ODBC)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md).

É possível encontrar mais informações sobre o SQL, incluindo uma lista de instruções SQL compatível, tipos de dados, gramática principal do SQL e uma lista de leitura de publicações recomendadas na *Referência do Programador* do *SDK ODBC* no CD da Biblioteca MSDN.

##  <a name="_core_how_the_database_classes_use_sql"></a> Como as classes de banco de dados usam o SQL

Os conjuntos de registros derivados das classes de banco de dados usam a ODBC para se comunicar com uma fonte de dados e a ODBC recupera os registros da fonte de dados por meio do envio de instruções SQL. Este tópico explica a relação entre as classes de banco de dados e o SQL.

Um conjunto de registros constrói uma instrução SQL combinando as partes de uma instrução SQL em um `CString`. A cadeia de caracteres é construída como uma instrução **SELECT**, que retorna um conjunto de registros.

Quando o conjunto de registros chama a ODBC para enviar uma instrução SQL à fonte de dados, o Gerenciador de Driver ODBC passa a instrução para o driver ODBC e ele a envia para o DBMS subjacente. O DBMS retorna um conjunto de resultados de registros e o driver ODBC retorna os registros para o aplicativo. As classes de banco de dados permitem que seu programa acesse o conjunto de resultados em uma classe C++ fortemente tipada derivada de `CRecordset`.

Os tópicos a seguir fornecem mais informações sobre como as classes de banco de dados usam o SQL:

- [SQL: Como personalizar a instrução SQL do seu conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md)

- [SQL: tipos de dados SQL e C++ (ODBC)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md)

- [SQL: fazer chamadas SQL diretas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)

## <a name="see-also"></a>Consulte também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)