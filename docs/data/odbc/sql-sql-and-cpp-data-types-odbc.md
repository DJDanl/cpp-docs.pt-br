---
title: 'SQL: tipos de dados SQL e C++ (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- data types [C++], SQL vs. C++
- SQL data types [C++]
- SQL [C++], vs. C++ data types
ms.assetid: 066e0070-d4da-435c-9c4b-f7cab3352c86
ms.openlocfilehash: 70796db02f8ff3fcfd67694fb596722664e8f904
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86404249"
---
# <a name="sql-sql-and-c-data-types-odbc"></a>SQL: tipos de dados SQL e C++ (ODBC)

> [!NOTE]
> Essas informações aplicam-se às classes ODBC do MFC. Se você estiver trabalhando com as classes do MFC DAO, consulte o tópico "comparação do Microsoft Jet Mecanismo de Banco de Dados SQL e ANSI SQL" na ajuda do DAO.

A tabela a seguir mapeia os tipos de dados SQL ANSI para tipos de dados do C++. Isso aumenta as informações da linguagem C fornecidas no Apêndice D da documentação de [referência do programador de ODBC](/sql/odbc/reference/odbc-programmer-s-reference) . Os assistentes gerenciam a maioria dos mapeamentos de tipo de dados para você. Se você não usar um assistente, poderá usar as informações de mapeamento para ajudá-lo a escrever o código de troca de campo manualmente.

### <a name="ansi-sql-data-types-mapped-to-c-data-types"></a>Tipos de dados ANSI SQL mapeados para tipos de dados do C++

|Tipo de dados SQL ANSI|Tipo de dados em C++|
|------------------------|---------------------|
|**º**|`CString`|
|**VÍRGULA**|`CString`uma|
|**SMALLINT**|**int**|
|**FOTO**|**float**|
|**VALORES**|**Longas**|
|**FLOAT**|**double**|
|**Clique**|**double**|
|**NUMERIC**|`CString`uma|
|**VARCHAR**|`CString`|
|**LONGVARCHAR**|`CLongBinary`, `CString` 2|
|**PARTE**|**BOOL**|
|**TINYINT**|**MINUCIOSA**|
|**BIGINT**|`CString`uma|
|**BINÁRIO**|`CByteArray`|
|**VARBINARY**|`CByteArray`|
|**LONGVARBINARY**|`CLongBinary`, `CByteArray` 3|
|**DATE**|`CTime`, `CString`|
|**MOMENTO**|`CTime`, `CString`|
|**timestamp**|`CTime`, `CString`|

1. ANSI **decimal** e **numérico** de mapa para `CString` porque **SQL_C_CHAR** é o tipo de transferência ODBC padrão.

2. Os dados de caractere além de 255 caracteres são truncados por padrão quando mapeados para `CString` . Você pode estender o comprimento do truncamento definindo explicitamente o argumento *nMaxLength* de `RFX_Text` .

3. Os dados binários além de 255 caracteres são truncados por padrão quando mapeados para `CByteArray` . Você pode estender o comprimento do truncamento definindo explicitamente o argumento *nMaxLength* de `RFX_Binary` .

Se você não estiver usando a biblioteca de cursores ODBC, poderá encontrar um problema ao tentar atualizar dois ou mais campos de comprimento variável longos usando o Microsoft SQL Server driver ODBC e as classes de banco de dados ODBC do MFC. Os tipos de ODBC, **SQL_LONGVARCHAR** e **SQL_LONGVARBINARY**, são mapeados para tipos de SQL Server de texto e imagem. Um `CDBException` será gerado se você atualizar dois ou mais campos de comprimento variável longos na mesma chamada para `CRecordset::Update` . Portanto, não atualize várias colunas longas simultaneamente com `CRecordset::Update` . Você pode atualizar várias colunas longas simultaneamente com a API ODBC `SQLPutData` . Você também pode usar a biblioteca de cursores ODBC, mas isso não é recomendado para drivers, como o driver de SQL Server, que dá suporte a cursores e não precisam da biblioteca de cursores.

Se você estiver usando a biblioteca de cursores ODBC com as classes de banco de dados ODBC do MFC e o Microsoft SQL Server driver ODBC, uma **declaração** poderá ocorrer junto com um `CDBException` se uma chamada para `CRecordset::Update` seguir uma chamada para `CRecordset::Requery` . Em vez disso, chame `CRecordset::Close` e `CRecordset::Open` em vez de `CRecordset::Requery` . Outra solução é não usar a biblioteca de cursores ODBC, porque o SQL Server e o driver ODBC SQL Server fornecem suporte nativo para cursores nativamente e a biblioteca de cursores ODBC não é necessária.

## <a name="see-also"></a>Confira também

[SQL](../../data/odbc/sql.md)<br/>
[SQL: fazendo chamadas SQL diretas (ODBC)](../../data/odbc/sql-making-direct-sql-calls-odbc.md)
