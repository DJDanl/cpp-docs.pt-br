---
title: "SQL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de banco de dados [C++], instruções SQL"
  - "ODBC [C++], implementação de SQL"
  - "SQL [C++]"
  - "SQL [C++], ODBC"
ms.assetid: e3923bc4-b317-4e0b-afd8-3cd403eb0faf
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SQL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

SQL \(linguagem SQL\) é um modo de se comunicar com um base de dados relacional que permite definir, de consulta, modificar, e controlar os dados.  Usando a sintaxe SQL, você poderá criar uma instrução que registros de extrações de acordo com critérios especificados.  
  
> [!NOTE]
>  Essas informações são aplicadas às classes de MFC ODBC.  Se você estiver trabalhando com as classes de MFC DAO, consulte a comparação do tópico do Microsoft Jet Mecanismo de Base de dados SQL e ANSI SQL na ajuda de DAO.  
  
 As instruções SQL começam com um verbo da palavra\-chave como **CRIAR** ou **SELECIONAR**.  SQL é uma linguagem muito poderoso; uma única instrução pode afetar uma tabela inteira.  
  
 Várias versões do SQL existirem, cada um desenvolvido com o DBMS específico em mente.  As classes da base de dados de MFC reconhecem um conjunto de instruções SQL que corresponde à especificação comuns de rascunho do SQL \(CAE\) do ambiente de aplicativos do grupo X\/Open e de acesso do SQL \(1991\).  Para obter informações sobre a sintaxe dessas instruções, consulte o apêndice C em ODBC programmer's reference *SDK* no CD da Biblioteca MSDN.  
  
 Este tópico explica:  
  
-   [A relação entre ODBC e SQL](#_core_open_database_connectivity_.28.odbc.29).  
  
-   [As palavras\-chave mais comuns do SQL usados por base de dados de classificação](#_core_the_database_classes).  
  
-   [Como as classes base de dados do SQL](#_core_how_the_database_classes_use_sql).  
  
##  <a name="_core_open_database_connectivity_.28.odbc.29"></a> ODBC \(ODBC\)  
 As classes de base de dados forem implementadas com ODBC, que usa o SQL em uma interface de nível de chamada em vez de comandos SQL inserido no código.  ODBC SQL usa para se comunicar com [fonte de dados](../../data/odbc/data-source-odbc.md) pelos drivers ODBC.  Esses drivers interpretam SQL e traduzem\-no se necessário, para uso com um formato específico de base de dados do, como o Microsoft Access.  Para obter mais informações sobre como ODBC usa SQL, consulte [ODBC](../../data/odbc/odbc-basics.md) e *a referência do programador* de ODBC SDK no CD da Biblioteca MSDN.  
  
##  <a name="_core_the_database_classes"></a> Classes base de dados do  
 As classes de base de dados são criadas para você manipular e atualizar dados em [fonte de dados](../../data/odbc/data-source-odbc.md)existente.  [Assistente do aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md), [Assistente do consumidor MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) \(acessado com **Adicionar Classe**\), e as classes da base de dados constroem a maioria das instruções SQL para você.  
  
 As classes da base de dados usam uma parte do SQL conhecida como a linguagem de manipulação de dados \(DML\).  Esses comandos permitem trabalhar com todo ou parte da fonte de dados, adicione novos registros, registros, editar e excluir registros.  A tabela a seguir lista as palavras\-chave mais comuns do SQL e as formas as classes base de dados de usá\-los.  
  
### Algumas palavras\-chave comuns do SQL  
  
|Palavras\-chave SQL|O uso dos assistentes e as classes base de dados do|  
|-------------------------|---------------------------------------------------------|  
|**SELECT**|Para identificar quais tabelas e colunas na fonte de dados devem ser usada.|  
|**WHERE**|Para aplicar um filtro que aperfeiçoar a seleção.|  
|**ORDER BY**|Para aplicar uma ordem de classificação ao conjunto de registros.|  
|**INSERIR**|Para adicionar novos registros em um conjunto de registros.|  
|**DELETE**|Para excluir registros de um conjunto de registros.|  
|**UPDATE**|Para alterar os campos de um registro.|  
  
 Além disso, as classes de base de dados reconhecem as instruções ODBC **CALL** , que você pode usar para chamar uma consulta predefinido \(ou o procedimento armazenado\) em algumas fontes de dados.  O driver da base de dados de ODBC interpreta estas instruções e substitui o comando apropriado para cada DBMS.  
  
> [!NOTE]
>  Nem todas as instruções de **CALL** de suporte de DBMSs.  
  
 Se as classes não pode reconhecer uma instrução fornecida pelo usuário em `CRecordset::Open`, ele será interpretado como um nome de tabela.  
  
 Para obter uma explicação de como a estrutura constrói instruções SQL, consulte [Conjunto de registros: Como os conjuntos de registros selecione os registros \(ODBC\)](../Topic/Recordset:%20How%20Recordsets%20Select%20Records%20\(ODBC\).md) e [SQL: Personalizando a instrução SQL do conjunto de registros \(ODBC\)](../../data/odbc/sql-customizing-your-recordset’s-sql-statement-odbc.md).  
  
 Tipos de dados de uso de bases de dados do SQL semelhantes a usados em C e C\+\+ 2.0 em.  Para obter uma descrição dessas semelhanças, consulte [SQL: SQL e tipos de dados do C\+\+ \(ODBC\)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md).  
  
 Você pode encontrar mais informações sobre o SQL, inclusive uma lista de instruções SQL com suporte, tipos de dados, de núcleo do SQL gramática, e uma lista de leitura de publicações recomendadas sobre o SQL, em ODBC programmer's reference *SDK* no CD da Biblioteca MSDN.  
  
##  <a name="_core_how_the_database_classes_use_sql"></a> Como as classes base de dados do SQL  
 Os conjuntos de registros que você se deriva de uso ODBC das classes base de dados do se comunicar com uma fonte de dados, ODBC e recuperar registros da fonte de dados de envio instruções SQL.  Este tópico explica a relação entre as classes da base de dados do e do SQL.  
  
 Um conjunto de registros constrói uma instrução SQL acumulando partes de uma instrução SQL em `CString`.  A cadeia de caracteres é criada como uma instrução de **SELECIONAR** , que retorna um conjunto de registros.  
  
 Quando o conjunto de registros ODBC chama para enviar uma instrução SQL à fonte de dados, o gerenciador de driver ODBC transmite a instrução ao driver ODBC e o driver envia ao DBMS subjacente.  O DBMS retorna um conjunto de resultados de registros, e o driver ODBC retorna os registros para o aplicativo.  As classes da base de dados permitem que o acesso de programa do conjunto de resultados em uma classe fortemente tipado C\+\+ se derivadas de `CRecordset`.  
  
 Os tópicos a seguir fornecem mais informações sobre como as classes da base de dados usam SQL:  
  
-   [SQL: Personalizando a instrução SQL do conjunto de registros \(ODBC\)](../../data/odbc/sql-customizing-your-recordset’s-sql-statement-odbc.md)  
  
-   [SQL: SQL e tipos de dados do C\+\+ \(ODBC\)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md)  
  
-   [SQL: Fazer chamadas diretos do SQL \(ODBC\)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)  
  
## Consulte também  
 [Conectividade de banco de dados aberto \(ODBC\)](../Topic/Open%20Database%20Connectivity%20\(ODBC\).md)   
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)