---
title: "SQL: fazendo chamadas SQL diretas (ODBC) | Microsoft Docs"
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
  - "chamadas SQL diretas de ODBC"
  - "ODBC, Chamadas SQL"
  - "Chamadas SQL"
  - "SQL, chamando diretamente de ODBC"
  - "SQL, chamadas diretas de ODBC"
ms.assetid: 091988d2-f5a5-4c2d-aa09-8779a9fb9607
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SQL: fazendo chamadas SQL diretas (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico explica:  
  
-   Quando usar chamadas diretos do SQL.  
  
-   [Como você faz chamadas diretos do SQL à fonte de dados](#_core_making_direct_sql_function_calls).  
  
> [!NOTE]
>  Essas informações são aplicadas às classes de MFC ODBC.  Se você estiver trabalhando com as classes de MFC DAO, consulte o tópico “comparação do Microsoft Jet Mecanismo de Base de dados SQL e ANSI SQL” na ajuda de DAO.  
  
##  <a name="_core_when_to_call_sql_directly"></a> Para chamar diretamente SQL  
 Para criar novas tabelas, remover tabelas \(de exclusão\), modificar tabelas existentes, crie índices, e executar outro SQL funções que modificam o esquema de [Fonte de dados \(ODBC\)](../../data/odbc/data-source-odbc.md) , você deverá emitir uma instrução SQL diretamente à fonte de dados \(DDL\) usando a linguagem de definição da base de dados.  Quando você usar um assistente para criar um conjunto de registros para uma tabela \(em tempo de design\), você pode escolher quais colunas da tabela para representar no conjunto de registros.  Isso não permite colunas ou outro usuário da fonte de dados adiciona à tabela posteriormente, depois que seu programa foi compilado.  As classes de base de dados do não oferecem suporte a DDL diretamente, mas você ainda pode escrever o código dinamicamente para associar uma nova coluna ao conjunto de registros, em tempo de execução.  Para obter informações sobre como fazer essa associação, consulte [Conjunto de registros: associando dinamicamente colunas de dados \(ODBC\)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).  
  
 Você pode usar o DBMS próprio para alterar o esquema ou outra ferramenta que permite executar funções de DDL.  Você também pode usar chamadas de função ODBC para enviar instruções SQL, como chamar uma consulta predefinido \(procedimento armazenado\) que não retorna registros.  
  
##  <a name="_core_making_direct_sql_function_calls"></a> Para fazer chamadas de função diretas do SQL  
 Você pode executar diretamente uma chamada de SQL usando um objeto de [Classe de CDatabase](../../mfc/reference/cdatabase-class.md) .  Configure a cadeia de caracteres da instrução SQL \(normalmente em `CString`\) e passar para a função de membro de [CDatabase::ExecuteSQL](../Topic/CDatabase::ExecuteSQL.md) do objeto de `CDatabase` .  Se você usar chamadas de função ODBC para enviar uma instrução SQL que normalmente retorne os registros, os registros são ignorados.  
  
## Consulte também  
 [SQL](../../data/odbc/sql.md)