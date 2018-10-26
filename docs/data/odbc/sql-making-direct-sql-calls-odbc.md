---
title: 'SQL: Fazendo chamadas SQL diretas (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- SQL, direct calls from ODBC
- SQL, calling directly from ODBC
- ODBC, SQL calls
- SQL calls
- direct SQL calls from ODBC
ms.assetid: 091988d2-f5a5-4c2d-aa09-8779a9fb9607
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2201a8936c1f28221bfcb628139a979e042715b9
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50079214"
---
# <a name="sql-making-direct-sql-calls-odbc"></a>SQL: fazendo chamadas SQL diretas (ODBC)

Este tópico explica:

- Quando usar SQL diretas chama.

- [Como tornar a direcionar o SQL chamadas para a fonte de dados](#_core_making_direct_sql_function_calls).

> [!NOTE]
>  Essas informações se aplicam às classes ODBC do MFC. Se você estiver trabalhando com as classes MFC DAO, consulte o tópico "Comparação do banco de dados de mecanismo de SQL e ANSI SQL do Microsoft Jet" na Ajuda do DAO.

##  <a name="_core_when_to_call_sql_directly"></a> Quando chamar diretamente o SQL

Para criar novas tabelas, Descartar tabelas (excluir), alterar as tabelas existentes, criar índices e executar outras funções SQL que alteram a [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md) esquema, você deve emitir uma instrução SQL diretamente à fonte de dados usando o banco de dados Linguagem de definição (DDL). Quando você usa um Assistente para criar um conjunto de registros para uma tabela (em tempo de design), você pode escolher quais colunas da tabela para representar no conjunto de registros. Isso não permite para colunas que você ou outro usuário da fonte de dados adicionar à tabela mais tarde, depois que seu programa compilado. As classes de banco de dados não têm suporte para DDL diretamente, mas você ainda pode escrever código para associar dinamicamente, uma nova coluna ao seu conjunto de registros em tempo de execução. Para obter informações sobre como fazer essa associação, consulte [conjunto de registros: dinamicamente associação de dados de colunas (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

Você pode usar o DBMS em si para alterar o esquema ou outra ferramenta que lhe permite realizar funções DDL. Você também pode usar chamadas de função ODBC para enviar instruções SQL, como chamar uma consulta predefinida (procedimento armazenado) que não retorna registros.

##  <a name="_core_making_direct_sql_function_calls"></a> Fazendo chamadas de função do SQL diretas

Você pode executar diretamente uma chamada SQL usando um [classe CDatabase](../../mfc/reference/cdatabase-class.md) objeto. Definir sua cadeia de caracteres de instrução SQL (normalmente em um `CString`) e passá-lo para o [CDatabase::](../../mfc/reference/cdatabase-class.md#executesql) a função de membro de seu `CDatabase` objeto. Se você usar chamadas de função ODBC para enviar uma instrução SQL que normalmente retorna registros, os registros são ignorados.

## <a name="see-also"></a>Consulte também

[SQL](../../data/odbc/sql.md)