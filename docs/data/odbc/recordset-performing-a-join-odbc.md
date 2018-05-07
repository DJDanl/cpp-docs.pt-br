---
title: 'Conjunto de registros: Realizando uma junção (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- joins [C++], in recordsets
- data binding [C++], recordset columns
- recordsets [C++], binding data
- data binding [C++], columns in recordsets
- filters [C++], join conditions for recordsets
- ODBC recordsets [C++], joins
- recordsets [C++], joining tables
ms.assetid: ca720900-a156-4780-bf01-4293633bea64
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0be740a57f5c455b971dd23575401c666bf0723c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="recordset-performing-a-join-odbc"></a>Conjunto de registros: realizando uma junção (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
## <a name="what-a-join-is"></a>O que é uma junção  
 A operação de junção, uma tarefa comum de acesso a dados, permite que você trabalhe com dados de mais de uma tabela usando um objeto recordset único. Unir duas ou mais tabelas produz um conjunto de registros que pode conter colunas de cada tabela, mas aparecerá como uma única tabela para seu aplicativo. Às vezes, a associação usa todas as colunas de todas as tabelas, mas, às vezes, o SQL **selecione** cláusula em uma junção usa apenas algumas das colunas de cada tabela. As classes de banco de dados oferecem suporte a junções de somente leitura, mas não é atualizáveis junções.  
  
 Para selecionar registros que contêm colunas de tabelas unidas, você precisa dos seguintes itens:  
  
-   Uma lista de tabela que contém os nomes de todas as tabelas unidas.  
  
-   Uma lista de coluna que contém os nomes de todas as colunas participantes. Colunas com o mesmo nome mas de tabelas diferentes são qualificadas pelo nome da tabela.  
  
-   Um filtro (SQL **onde** cláusula) que especifica as colunas em que as tabelas são unidas. Esse filtro assume a forma "Table1.KeyCol = Table2.KeyCol" e, na verdade, realiza a junção.  
  
 Você pode associar mais de duas tabelas da mesma maneira por vários pares de colunas, cada par unidas com a palavra-chave SQL que corresponda **AND**.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Declarando uma classe para uma consulta predefinida (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md)   
 [Conjunto de registros: Declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)   
 [Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md)