---
title: 'SQL: tipos de dados SQL e C++ (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- data types [C++], SQL vs. C++
- SQL data types [C++]
- SQL [C++], vs. C++ data types
ms.assetid: 066e0070-d4da-435c-9c4b-f7cab3352c86
ms.openlocfilehash: cffe44b832ac1eb28d368072b8f0e92ea9f57feb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374476"
---
# <a name="sql-sql-and-c-data-types-odbc"></a>SQL: tipos de dados SQL e C++ (ODBC)

> [!NOTE]
> Essas informações aplicam-se às classes ODBC do MFC. Se você estiver trabalhando com as classes DAO do MFC, consulte o tópico "Comparação do Microsoft Jet Database Engine SQL e DOSI SQL" na Ajuda da DAO.

A tabela a seguir mapeia os tipos de dados ANSI SQL para os tipos de dados C++. Isso aumenta as informações de linguagem C dadas no apêndice D da *referência do programador* *ODBC SDK* no CD da Biblioteca MSDN. Os assistentes gerenciam a maioria do mapeamento de tipo de dados para você. Se você não usar um assistente, você pode usar as informações de mapeamento para ajudá-lo a escrever o código de troca de campo manualmente.

### <a name="ansi-sql-data-types-mapped-to-c-data-types"></a>Tipos de dados ANSI SQL mapeados para tipos de dados C++

|Tipo de dados ANSI SQL|Tipo de dados em C++|
|------------------------|---------------------|
|**Char**|`CString`|
|**Decimal**|`CString`1|
|**Smallint**|**int**|
|**Real**|**float**|
|**Inteiro**|**Longas**|
|**Flutuar**|**double**|
|**Duplo**|**double**|
|**Numérico**|`CString`1|
|**Varchar**|`CString`|
|**LONGVARCHAR**|`CLongBinary`, `CString` 2|
|**Pouco**|**Bool**|
|**Tinyint**|**Byte**|
|**Bigint**|`CString`1|
|**Binário**|`CByteArray`|
|**Varbinary**|`CByteArray`|
|**LONGVARBINARY**|`CLongBinary`, `CByteArray` 3|
|**Data**|`CTime`, `CString`|
|**Tempo**|`CTime`, `CString`|
|**Timestamp**|`CTime`, `CString`|

1. Mapa ANSI **DECIMAL** e `CString` **NUMERIC** para porque **SQL_C_CHAR** é o tipo de transferência Padrão ODBC.

2. Os dados de caracteres além de 255 caracteres são truncados por padrão quando mapeados para `CString`. Você pode estender o comprimento de truncamento definindo `RFX_Text`explicitamente o argumento *nMaxLength* de .

3. Dados binários além de 255 caracteres são `CByteArray`truncados por padrão quando mapeados para . Você pode estender o comprimento de truncamento definindo `RFX_Binary`explicitamente o argumento *nMaxLength* de .

Se você não estiver usando a biblioteca do cursor ODBC, você pode encontrar um problema ao tentar atualizar dois ou mais campos de comprimento variável longos usando o driver ODBC do Microsoft SQL Server e as classes de banco de dados MFC ODBC. Os tipos ODBC, **SQL_LONGVARCHAR** e **SQL_LONGVARBINARY,** mapeiam para os tipos de sql server de texto e imagem. A `CDBException` é lançada se você atualizar dois ou mais campos `CRecordset::Update`de comprimento variável longos na mesma chamada para . Portanto, não atualize várias colunas `CRecordset::Update`longas simultaneamente com . Você pode atualizar várias colunas longas simultaneamente `SQLPutData`com a API ODBC . Você também pode usar a biblioteca do cursor ODBC, mas isso não é recomendado para drivers, como o driver SQL Server, que suportam cursors e não precisam da biblioteca do cursor.

Se você estiver usando a biblioteca do cursor ODBC com as classes de banco de dados MFC ODBC e `CRecordset::Update` o driver `CRecordset::Requery`Microsoft SQL Server ODBC, um **ASSERT** pode ocorrer juntamente com uma `CDBException` chamada para seguir uma chamada para . Em vez `CRecordset::Close` `CRecordset::Open` disso, `CRecordset::Requery`ligue e ao invés de . Outra solução é não usar a biblioteca do cursor ODBC, porque o SQL Server e o driver SQL Server ODBC fornecem suporte nativo para cursors nativamente e a biblioteca de cursor ODBC não é necessária.

## <a name="see-also"></a>Confira também

[SQL](../../data/odbc/sql.md)<br/>
[SQL: fazendo chamadas SQL diretas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)
