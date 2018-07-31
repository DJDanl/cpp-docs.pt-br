---
title: 'SQL: SQL e tipos de dados do C++ (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- data types [C++], SQL vs. C++
- SQL data types [C++]
- SQL [C++], vs. C++ data types
ms.assetid: 066e0070-d4da-435c-9c4b-f7cab3352c86
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8b978356cead1f9b74ce59e58ab0191f5e00105b
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39340762"
---
# <a name="sql-sql-and-c-data-types-odbc"></a>SQL: tipos de dados SQL e C++ (ODBC)
> [!NOTE]
>  Essas informações se aplicam às classes ODBC do MFC. Se você estiver trabalhando com as classes MFC DAO, consulte o tópico "Comparação do banco de dados de mecanismo de SQL e ANSI SQL do Microsoft Jet" na Ajuda do DAO.  
  
 A tabela a seguir mapeia tipos de dados SQL ANSI para tipos de dados C++. Isso aumenta a informação de idioma de C fornecida no Apêndice D dos *ODBC SDK* *referência do programador* no CD da biblioteca MSDN. Os assistentes de gerenciam a maioria dos mapeamento de tipo de dados para você. Se você não usar um assistente, você pode usar as informações de mapeamento para ajudá-lo a escrever o código de troca de campo manualmente.  
  
### <a name="ansi-sql-data-types-mapped-to-c-data-types"></a>Tipos de dados SQL ANSI mapeados para tipos de dados C++  
  
|Tipo de dados SQL ANSI|Tipo de dados em C++|  
|------------------------|---------------------|  
|**CHAR**|`CString`|  
|**DECIMAL**|`CString` 1|  
|**SMALLINT**|**int**|  
|**REAL**|**float**|  
|**INTEGER**|**long**|  
|**FLOAT**|**double**|  
|**DOUBLE**|**double**|  
|**NUMERIC**|`CString` 1|  
|**VARCHAR**|`CString`|  
|**LONGVARCHAR**|`CLongBinary`, `CString` 2|  
|**BIT**|**BOOL**|  
|**TINYINT**|**BYTE**|  
|**BIGINT**|`CString` 1|  
|**BINÁRIO**|`CByteArray`|  
|**VARBINARY**|`CByteArray`|  
|**LONGVARBINARY**|`CLongBinary`, `CByteArray` 3|  
|**DATE**|`CTime`, `CString`|  
|**TEMPO**|`CTime`, `CString`|  
|**TIMESTAMP**|`CTime`, `CString`|  
  
 1. ANSI **decimais** e **NUMÉRICO** mapeados para `CString` porque **SQL_C_CHAR** é o tipo de transferência ODBC padrão.  
  
 2. Dados de caractere além de 255 caracteres serão truncados por padrão quando mapeado para `CString`. Você pode estender o comprimento de truncamento, configurando explicitamente o *nMaxLength* argumento de `RFX_Text`.  
  
 3. Dados binários, além de 255 caracteres são truncados por padrão quando mapeado para `CByteArray`. Você pode estender o comprimento de truncamento, configurando explicitamente o *nMaxLength* argumento de `RFX_Binary`.  
  
 Se você não estiver usando a biblioteca de cursores ODBC, você pode encontrar um problema ao tentar atualizar dois ou mais campos de comprimento variável longa usando o driver ODBC do Microsoft SQL Server e as classes de banco de dados ODBC do MFC. Os tipos de ODBC **SQL_LONGVARCHAR** e **SQL_LONGVARBINARY**, são mapeados para texto e imagem tipos do SQL Server. Um `CDBException` será lançada se você atualizar dois ou mais campos de comprimento variável longa na mesma chamada `CRecordset::Update`. Portanto, não atualizar várias colunas longas simultaneamente com `CRecordset::Update`. Você pode atualizar várias colunas longas simultaneamente com a API ODBC `SQLPutData`. Você também pode usar a biblioteca de cursores ODBC, mas isso não é recomendado para drivers, como o driver do SQL Server, que oferecem suporte a cursores e não é necessário para a biblioteca de cursores.  
  
 Se você estiver usando a biblioteca de cursores ODBC com as classes de banco de dados ODBC do MFC e o driver ODBC do Microsoft SQL Server, um **ASSERT** podem ocorrer juntamente com um `CDBException` se uma chamada para `CRecordset::Update` segue uma chamada para `CRecordset::Requery`. Em vez disso, chame `CRecordset::Close` e `CRecordset::Open` em vez de `CRecordset::Requery`. Outra solução é não usar a biblioteca de cursores ODBC, porque o SQL Server e o driver ODBC do SQL Server oferecem suporte nativo para cursores de modo nativo e a biblioteca de cursores ODBC não é necessária.  
  
## <a name="see-also"></a>Consulte também  
 [SQL](../../data/odbc/sql.md)   
 [SQL: fazendo chamadas SQL diretas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)