---
title: 'SQL: fazendo chamadas SQL diretas (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- SQL, direct calls from ODBC
- SQL, calling directly from ODBC
- ODBC, SQL calls
- SQL calls
- direct SQL calls from ODBC
ms.assetid: 091988d2-f5a5-4c2d-aa09-8779a9fb9607
ms.openlocfilehash: 9240a227cdc4004d1e6e2b7ac26946ca233b71ec
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212622"
---
# <a name="sql-making-direct-sql-calls-odbc"></a>SQL: fazendo chamadas SQL diretas (ODBC)

Este tópico explica:

- Quando usar chamadas SQL diretas.

- [Como fazer chamadas SQL diretas para a fonte de dados](#_core_making_direct_sql_function_calls).

> [!NOTE]
>  Essas informações aplicam-se às classes ODBC do MFC. Se você estiver trabalhando com as classes do MFC DAO, consulte o tópico "comparação do Microsoft Jet Mecanismo de Banco de Dados SQL e ANSI SQL" na ajuda do DAO.

##  <a name="when-to-call-sql-directly"></a><a name="_core_when_to_call_sql_directly"></a>Quando chamar o SQL diretamente

Para criar novas tabelas, descartar (excluir) tabelas, alterar tabelas existentes, criar índices e executar outras funções do SQL que alteram o esquema de [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md) , você deve emitir uma instrução SQL diretamente para a fonte de dados usando o DDL (linguagem de definição de dados). Quando você usa um assistente para criar um conjunto de registros para uma tabela (em tempo de Design), pode escolher quais colunas da tabela representar no conjunto de registros. Isso não permite que as colunas que você ou outro usuário da fonte de dados adicionem à tabela posteriormente, depois que o programa tiver sido compilado. As classes de banco de dados não dão suporte ao DDL diretamente, mas você ainda pode escrever código para associar uma nova coluna ao conjunto de registros dinamicamente, em tempo de execução. Para obter informações sobre como fazer essa associação, consulte [conjunto de registros: vinculação dinâmica de colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

Você pode usar o próprio DBMS para alterar o esquema ou outra ferramenta que permite executar funções DDL. Você também pode usar chamadas de função ODBC para enviar instruções SQL, como chamar uma consulta predefinida (procedimento armazenado) que não retorna registros.

##  <a name="making-direct-sql-function-calls"></a><a name="_core_making_direct_sql_function_calls"></a>Fazendo chamadas de função SQL diretas

Você pode executar diretamente uma chamada SQL usando um objeto de [classe CDatabase](../../mfc/reference/cdatabase-class.md) . Configure sua cadeia de caracteres de instrução SQL (geralmente em um `CString`) e passe-a para a função de membro [CDatabase:: ExecuteSQL](../../mfc/reference/cdatabase-class.md#executesql) do seu objeto `CDatabase`. Se você usar chamadas de função ODBC para enviar uma instrução SQL que normalmente retorna registros, os registros são ignorados.

## <a name="see-also"></a>Confira também

[SQL](../../data/odbc/sql.md)
