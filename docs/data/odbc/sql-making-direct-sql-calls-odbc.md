---
title: 'SQL: Fazendo chamadas SQL diretas (ODBC) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- SQL, direct calls from ODBC
- SQL, calling directly from ODBC
- ODBC, SQL calls
- SQL calls
- direct SQL calls from ODBC
ms.assetid: 091988d2-f5a5-4c2d-aa09-8779a9fb9607
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4c5debd5017c2c9c9cad240f831fdf6e02be98ef
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="sql-making-direct-sql-calls-odbc"></a>SQL: fazendo chamadas SQL diretas (ODBC)
Este tópico explica:  
  
-   Quando usar SQL diretas chama.  
  
-   [Como você faz SQL direta chamadas para a fonte de dados](#_core_making_direct_sql_function_calls).  
  
> [!NOTE]
>  Essas informações se aplicam às classes MFC ODBC. Se você estiver trabalhando com as classes DAO MFC, consulte o tópico "Comparação do banco de dados do mecanismo de SQL e ANSI SQL do Microsoft Jet" na Ajuda do DAO.  
  
##  <a name="_core_when_to_call_sql_directly"></a>Quando a chamada SQL diretamente  
 Para criar novas tabelas, Descartar tabelas (excluir), alterar as tabelas existentes, criar índices e executar outras funções SQL que alteram o [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md) esquema, você deverá emitir uma instrução SQL diretamente à fonte de dados usando o banco de dados Definition Language (DDL). Quando você usar um Assistente para criar um conjunto de registros para uma tabela (em tempo de design), você pode escolher quais colunas da tabela para representar no conjunto de registros. Isso não permite para colunas que você ou outro usuário da fonte de dados adicionar à tabela posteriormente, depois que o programa foi compilado. As classes de banco de dados não oferecem suporte a DDL diretamente, mas você ainda pode escrever código para associar uma nova coluna para o conjunto de registros dinamicamente em tempo de execução. Para obter informações sobre como fazer essa associação, consulte [conjunto de registros: dinamicamente associação de dados de colunas (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).  
  
 Você pode usar o DBMS em si para alterar o esquema ou outra ferramenta que permite realizar funções DDL. Você também pode usar chamadas de função ODBC para enviar instruções SQL, como chamar uma consulta predefinida (procedimento armazenado) que não retorna registros.  
  
##  <a name="_core_making_direct_sql_function_calls"></a>Fazer chamadas de função SQL diretas  
 Você pode executar diretamente uma chamada SQL usando um [classe CDatabase](../../mfc/reference/cdatabase-class.md) objeto. Configurar a cadeia de caracteres de instrução SQL (normalmente em um `CString`) e passá-lo para o [CDatabase::](../../mfc/reference/cdatabase-class.md#executesql) função membro de seu `CDatabase` objeto. Se você usar chamadas de função ODBC para enviar uma instrução SQL que normalmente retorna registros, os registros serão ignorados.  
  
## <a name="see-also"></a>Consulte também  
 [SQL](../../data/odbc/sql.md)