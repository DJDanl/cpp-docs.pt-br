---
title: 'SQL: Tipos de dados C++ (ODBC) e SQL | Microsoft Docs'
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
ms.openlocfilehash: 6a137c4f648f518420d06f5cbd98ea189a030aee
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="sql-sql-and-c-data-types-odbc"></a>SQL: tipos de dados SQL e C++ (ODBC)
> [!NOTE]
>  Essas informações se aplicam às classes MFC ODBC. Se você estiver trabalhando com as classes DAO MFC, consulte o tópico "Comparação do banco de dados do mecanismo de SQL e ANSI SQL do Microsoft Jet" na Ajuda do DAO.  
  
 A tabela a seguir mapeia tipos de dados ANSI SQL para tipos de dados C++. Isso aumenta as informações de linguagem C fornecidas no Apêndice D do *ODBC SDK* *referência do programador de* no CD de biblioteca do MSDN. Os assistentes de gerenciam a maioria das mapeamento de tipo de dados para você. Se você não usar um assistente, você pode usar as informações de mapeamento para ajudá-lo a escrever o código de troca de campos manualmente.  
  
### <a name="ansi-sql-data-types-mapped-to-c-data-types"></a>Tipos de dados SQL ANSI mapeados para tipos de dados C++  
  
|Tipo de dados do SQL ANSI|Tipo de dados em C++|  
|------------------------|---------------------|  
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
|**BINÁRIO**|`CByteArray`|  
|**VARBINARY**|`CByteArray`|  
|**LONGVARBINARY**|`CLongBinary`, `CByteArray` 3|  
|**DATE**|`CTime`, `CString`|  
|**TEMPO**|**CTime, CString**|  
|**TIMESTAMP**|**CTime, CString**|  
  
 1. ANSI **DECIMAL** e **NUMÉRICO** mapear para `CString` porque **SQL_C_CHAR** é o tipo de transferência ODBC padrão.  
  
 2. Os dados de caractere além de 255 caracteres serão truncados por padrão quando mapeado para `CString`. Você pode estender o tamanho do truncamento definindo explicitamente o `nMaxLength` argumento de `RFX_Text`.  
  
 3. Dados binários, além de 255 caracteres estão truncados por padrão quando mapeado para `CByteArray`. Você pode estender o tamanho do truncamento definindo explicitamente o `nMaxLength` argumento de `RFX_Binary`.  
  
 Se você não estiver usando a biblioteca de cursores ODBC, você pode encontrar um problema ao tentar atualizar dois ou mais campos de comprimento variável de tempo usando o driver ODBC do Microsoft SQL Server e as classes de banco de dados ODBC MFC. Os tipos ODBC, **SQL_LONGVARCHAR** e **SQL_LONGVARBINARY**, mapear para texto e imagem tipos do SQL Server. Um `CDBException` é gerada se você atualizar dois ou mais campos de comprimento variável de tempo na mesma chamada `CRecordset::Update`. Portanto, não atualizar várias colunas longas simultaneamente com `CRecordset::Update`. Você pode atualizar várias colunas longas simultaneamente com a API ODBC **SQLPutData**. Você também pode usar a biblioteca de cursores ODBC, mas isso não é recomendado para drivers, como o driver do SQL Server, que oferecem suporte a cursores e não é necessário para a biblioteca de cursores.  
  
 Se você estiver usando a biblioteca de cursores ODBC com as classes de banco de dados ODBC MFC e o driver ODBC do Microsoft SQL Server, um **ASSERT** podem ocorrer juntamente com um `CDBException` se uma chamada para `CRecordset::Update` segue uma chamada para `CRecordset::Requery`. Em vez disso, chame `CRecordset::Close` e `CRecordset::Open` em vez de `CRecordset::Requery`. Outra solução é não usar a biblioteca de cursores ODBC, porque o SQL Server e o driver ODBC do SQL Server fornecem suporte nativo para cursores de modo nativo e a biblioteca de cursores ODBC não é necessária.  
  
## <a name="see-also"></a>Consulte também  
 [SQL](../../data/odbc/sql.md)   
 [SQL: fazendo chamadas SQL diretas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)