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
ms.openlocfilehash: e2421e047d217fdc7a138509385399fa37d36a1f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374507"
---
# <a name="sql-making-direct-sql-calls-odbc"></a>SQL: fazendo chamadas SQL diretas (ODBC)

Este tópico explica:

- Quando usar chamadas SQL diretas.

- [Como você faz chamadas SQL diretas para a fonte de dados](#_core_making_direct_sql_function_calls).

> [!NOTE]
> Essas informações aplicam-se às classes ODBC do MFC. Se você estiver trabalhando com as classes DAO do MFC, consulte o tópico "Comparação do Microsoft Jet Database Engine SQL e DOSI SQL" na Ajuda da DAO.

## <a name="when-to-call-sql-directly"></a><a name="_core_when_to_call_sql_directly"></a>Quando ligar diretamente para o SQL

Para criar novas tabelas, soltar tabelas (excluir), alterar tabelas existentes, criar índices e executar outras funções SQL que alteram o esquema [de Origem de Dados (ODBC),](../../data/odbc/data-source-odbc.md) você deve emitir uma declaração SQL diretamente na fonte de dados usando ODL (Database Definition Language). Quando você usa um assistente para criar um conjunto de registros para uma tabela (na hora do projeto), você pode escolher quais colunas da tabela representar no conjunto de registros. Isso não permite que as colunas que você ou outro usuário da fonte de dados adicionem à tabela mais tarde, depois que seu programa tiver sido compilado. As classes de banco de dados não suportam dDL diretamente, mas você ainda pode escrever código para vincular uma nova coluna ao seu conjunto de registros dinamicamente, em tempo de execução. Para obter informações sobre como fazer essa vinculação, consulte [Recordset: Dynamically Binding Data Columns (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

Você pode usar o próprio DBMS para alterar o esquema ou outra ferramenta que permite executar funções DDL. Você também pode usar chamadas de função ODBC para o envio de instruções SQL, como chamar uma consulta predefinida (procedimento armazenado) que não retorna registros.

## <a name="making-direct-sql-function-calls"></a><a name="_core_making_direct_sql_function_calls"></a>Fazendo chamadas diretas de função SQL

Você pode executar diretamente uma chamada SQL usando um objeto [CDatabase Class.](../../mfc/reference/cdatabase-class.md) Configure a seqüência de declaração SQL (geralmente em a `CString`) e passe-a para a função [cdatabase::ExecuteSQL](../../mfc/reference/cdatabase-class.md#executesql) membro do seu `CDatabase` objeto. Se você usar chamadas de função ODBC para enviar uma declaração SQL que normalmente retorna registros, os registros serão ignorados.

## <a name="see-also"></a>Confira também

[SQL](../../data/odbc/sql.md)
