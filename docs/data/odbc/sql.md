---
title: SQL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- database classes [C++], SQL statements
- SQL [C++]
- SQL [C++], ODBC
- ODBC [C++], SQL implementation
ms.assetid: e3923bc4-b317-4e0b-afd8-3cd403eb0faf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: df1563d8bb3d53bb405fbb0d89b2b26cc964bd44
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="sql"></a>SQL
SQL (Structured Query Language) é uma maneira de se comunicar com um banco de dados relacional que permite que você defina a consulta, modificar e controla os dados. Usando a sintaxe SQL, você pode construir uma instrução que extrai os registros de acordo com os critérios que você especificar.  
  
> [!NOTE]
>  Essas informações se aplicam às classes MFC ODBC. Se você estiver trabalhando com as classes DAO MFC, consulte o tópico comparação do banco de dados do mecanismo SQL do Microsoft Jet e ANSI SQL na Ajuda do DAO.  
  
 Instruções SQL começam com um verbo de palavra-chave como **criar** ou **selecione**. SQL é uma linguagem muito poderosa; uma única instrução pode afetar uma tabela inteira.  
  
 Existem várias versões do SQL, cada desenvolvidos com um DBMS específico em mente. As classes de banco de dados MFC reconhecem um conjunto de instruções SQL que corresponde ao X / Open e a especificação de rascunho do ambiente de aplicativos comuns SQL acesso grupo (CAE) SQL (1991). Para obter informações sobre a sintaxe das instruções, consulte o Apêndice C no *ODBC SDK* *referência do programador de* no CD de biblioteca do MSDN.  
  
 Este tópico explica:  
  
-   [A relação entre o ODBC e SQL](#_core_open_database_connectivity_.28.odbc.29).  
  
-   [As mais comum palavras-chave SQL usadas pelas classes de banco de dados](#_core_the_database_classes).  
  
-   [Como as classes de banco de dados usam SQL](#_core_how_the_database_classes_use_sql).  
  
##  <a name="_core_open_database_connectivity_.28.odbc.29"></a> Open Database Connectivity (ODBC)  
 As classes de banco de dados são implementadas com o ODBC, que usa SQL em uma interface de nível de chamada em vez de inserir comandos SQL no código. ODBC usa SQL para se comunicar com um [fonte de dados](../../data/odbc/data-source-odbc.md) por meio de drivers ODBC. Esses drivers interpretam o SQL e traduzem-lo, se necessário, para uso com um formato de banco de dados específico, como o Microsoft Access. Para obter mais informações sobre como o ODBC usa SQL, consulte [ODBC](../../data/odbc/odbc-basics.md) e o SDK do ODBC *referência do programador de* no CD de biblioteca do MSDN.  
  
##  <a name="_core_the_database_classes"></a> Classes de banco de dados  
 As classes de banco de dados são projetadas para lhe permitem manipular e atualizar dados em um existente [fonte de dados](../../data/odbc/data-source-odbc.md). O [Assistente de aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md), o [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) (acessados por meio de **Adicionar classe**), e as classes de banco de dados construir a maioria das instruções SQL para você.  
  
 As classes de banco de dados usam uma parte do SQL, conhecida como linguagem de manipulação de dados (DML). Esses comandos permitem trabalhar com toda ou parte da fonte de dados, adicionar novos registros, editar registros e excluir registros. A tabela a seguir lista as palavras-chave SQL mais comuns e as formas como as classes de banco de dados usam-los.  
  
### <a name="some-common-sql-keywords"></a>Algumas palavras-chave SQL comuns  
  
|Palavra-chave SQL|Os assistentes e as classes de banco de dados usá-lo|  
|-----------------|---------------------------------------------|  
|**SELECT**|Para identificar quais tabelas e colunas na fonte de dados devem ser usados.|  
|**WHERE**|Para aplicar um filtro que restringe a seleção.|  
|**ORDER BY**|Para aplicar uma ordem de classificação para o conjunto de registros.|  
|**INSERIR**|Para adicionar novos registros a um conjunto de registros.|  
|**EXCLUIR**|Para excluir registros de um conjunto de registros.|  
|**ATUALIZAÇÃO**|Para modificar os campos de um registro.|  
  
 Além disso, as classes de banco de dados reconhecem ODBC **chamar** instruções que você pode usar para chamar uma consulta predefinida (ou procedimento armazenado) em algumas fontes de dados. O driver de banco de dados ODBC interpreta estas instruções e substitui o comando apropriado para cada DBMS.  
  
> [!NOTE]
>  Suporte de nem todos os DBMSs **chamar** instruções.  
  
 Se as classes não reconhecem uma instrução fornecida pelo usuário em `CRecordset::Open`, ele será interpretado como um nome de tabela.  
  
 Para obter uma explicação de como o framework construa instruções SQL, consulte [conjunto de registros: como conjuntos de registros selecionar registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md) e [SQL: SQL instrução (ODBC do Personalizando seu conjunto de registros)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).  
  
 Bancos de dados SQL usam tipos de dados semelhantes àqueles usados em C e C++. Para uma discussão sobre essas semelhanças, consulte [SQL: SQL e tipos de dados C++ (ODBC)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md).  
  
 Você pode encontrar mais informações sobre SQL, incluindo uma lista de instruções SQL com suporte, tipos de dados, gramática de núcleo SQL e uma lista de leitura recomendada publicações sobre SQL, no *ODBC SDK* *referência do programador*  no CD de biblioteca do MSDN.  
  
##  <a name="_core_how_the_database_classes_use_sql"></a> Como as Classes de banco de dados usam SQL  
 Os conjuntos de registros que deriva as classes de banco de dados usam o ODBC para se comunicar com uma fonte de dados e ODBC recupera os registros da fonte de dados ao enviar instruções SQL. Este tópico explica a relação entre as classes de banco de dados e SQL.  
  
 Um conjunto de registros constrói uma instrução SQL ao criar as partes de uma instrução SQL para um `CString`. A cadeia de caracteres é criada como uma **selecione** instrução, que retorna um conjunto de registros.  
  
 Quando o conjunto de registros chama ODBC para enviar uma instrução SQL para a fonte de dados, o Gerenciador de Driver ODBC transmite a instrução para o driver ODBC e o driver envia para o DBMS subjacente. O DBMS retorna um conjunto de resultados de registros e o driver ODBC retorna os registros para o aplicativo. As classes de banco de dados permitem o acesso de programa derivado do conjunto de resultados de uma classe do C++ fortemente tipado `CRecordset`.  
  
 Os tópicos a seguir fornecem mais informações sobre as classes de banco de dados que usam SQL:  
  
-   [SQL: Personalizando a instrução SQL de seu conjunto de registros (ODBC)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md)  
  
-   [SQL: tipos de dados SQL e C++ (ODBC)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md)  
  
-   [SQL: fazendo chamadas SQL diretas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)  
  
## <a name="see-also"></a>Consulte também  
 [Open Database Connectivity (ODBC)](../../data/odbc/open-database-connectivity-odbc.md)   
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)