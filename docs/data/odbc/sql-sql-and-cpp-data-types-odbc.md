---
title: "SQL: tipos de dados SQL e C++ (ODBC) | Microsoft Docs"
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
  - "tipos de dados [C++], SQL vs. C++"
  - "SQL [C++], vs. tipos de dados C++"
  - "tipos de dados SQL [C++]"
ms.assetid: 066e0070-d4da-435c-9c4b-f7cab3352c86
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SQL: tipos de dados SQL e C++ (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Essas informações são aplicadas às classes de MFC ODBC.  Se você estiver trabalhando com as classes de MFC DAO, consulte o tópico “comparação do Microsoft Jet Mecanismo de Base de dados SQL e ANSI SQL” na ajuda de DAO.  
  
 A tabela a seguir mapeia os tipos de dados SQL ANSI para tipos de dados C\+\+.  Isso aumenta as informações da linguagem C fornecida no Apêndice D do *ODBC SDK* *Referência do Programador* no CD da Biblioteca MSDN.  Os assistentes gerenciam a maioria de mapeamento de tipo de dados.  Se você não usar um assistente, você pode usar as informações de mapeamento para ajudar a escrever manualmente o código de troca do campo.  
  
### Tipos de dados SQL ANSI mapeados para tipos de dados do C\+\+  
  
|Tipo de dados SQL ANSI|Tipo de dado em C\+\+|  
|----------------------------|---------------------------|  
|**CHAR**|`CString`|  
|**DECIMAL**|`CString` 1|  
|**SMALLINT**|`int`|  
|`REAL`|**float**|  
|**INTEGER**|**long**|  
|**FLOAT**|**double**|  
|**DOUBLE**|**double**|  
|**NUMERIC**|`CString` 1|  
|**VARCHAR**|`CString`|  
|**LONGVARCHAR**|`CLongBinary`, `CString` 2|  
|**BIT**|**BOOL**|  
|**TINYINT**|**BYTE**|  
|**BIGINT**|`CString` 1|  
|**BINARY**|`CByteArray`|  
|**VARBINARY**|`CByteArray`|  
|**LONGVARBINARY**|`CLongBinary`, `CByteArray` 3|  
|**DATE**|`CTime`, `CString`|  
|**TIME**|**CTime, CString**|  
|**TIMESTAMP**|**CTime, CString**|  
  
 1.  Mapa de ANSI **DECIMAL** e de **NUMERIC** a `CString` porque **SQL\_C\_CHAR** é o tipo de transferência do ODBC da opção.  
  
 2.  Os dados de caracteres que excede 255 caracteres serão truncados por padrão quando mapeados para `CString`.  Você pode estender o comprimento de truncamento definindo explicitamente o argumento de `nMaxLength` de `RFX_Text`.  
  
 3.  Os dados binários além de 255 caracteres serão truncados por padrão quando mapeados para `CByteArray`.  Você pode estender o comprimento de truncamento definindo explicitamente o argumento de `nMaxLength` de `RFX_Binary`.  
  
 Se você não estiver usando a biblioteca de cursores ODBC, poderá encontrar um problema ao tentar atualizar campos de comprimento variável duas ou mais longos usando o driver ODBC do Microsoft SQL Server e classes de base de dados de MFC ODBC.  Os tipos de ODBC, **SQL\_LONGVARCHAR** e **SQL\_LONGVARBINARY**, o mapa em texto e imagem tipos do SQL Server.  `CDBException` será lançada se você atualiza campos de comprimento variável duas ou mais longos na mesma chamada a `CRecordset::Update`.  Consequentemente, não atualizar várias colunas longas simultaneamente com `CRecordset::Update`.  Você pode atualizar várias colunas longas simultaneamente com a API ODBC **SQLPutData**.  Você também pode usar a biblioteca de cursores ODBC, mas isso não é recomendado para os drivers, como o driver do SQL Server, que oferecem suporte a cursores e não precisam da biblioteca de cursores.  
  
 Se você estiver usando a biblioteca de cursores ODBC com as classes da base de dados de MFC ODBC e o driver ODBC do Microsoft SQL Server, **DECLARAR** pode acontecer juntos com `CDBException` se uma chamada a `CRecordset::Update` segue uma chamada a `CRecordset::Requery`.  Em vez disso, chame `CRecordset::Close` e `CRecordset::Open` em vez de `CRecordset::Requery`.  Outra solução não é usar a biblioteca de cursores ODBC, como o SQL Server e o driver ODBC do SQL Server fornece suporte nativo para cursores de maneira nativa e a biblioteca de cursores ODBC não é necessária.  
  
## Consulte também  
 [SQL](../../data/odbc/sql.md)   
 [SQL: fazendo chamadas SQL diretas \(ODBC\)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)