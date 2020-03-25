---
title: 'Conjunto de registros: realizando uma junção (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- joins [C++], in recordsets
- data binding [C++], recordset columns
- recordsets [C++], binding data
- data binding [C++], columns in recordsets
- filters [C++], join conditions for recordsets
- ODBC recordsets [C++], joins
- recordsets [C++], joining tables
ms.assetid: ca720900-a156-4780-bf01-4293633bea64
ms.openlocfilehash: 7e8d42f2b96911cd57aca7c132b53ed7c10162be
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212791"
---
# <a name="recordset-performing-a-join-odbc"></a>Conjunto de registros: realizando uma junção (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

## <a name="what-a-join-is"></a>O que é uma junção

A operação de junção, uma tarefa comum de acesso a dados, permite que você trabalhe com dados de mais de uma tabela usando um único objeto Recordset. Unir duas ou mais tabelas gera um conjunto de registros que pode conter colunas de cada tabela, mas aparece como uma única tabela para seu aplicativo. Às vezes, a junção usa todas as colunas de todas as tabelas, mas às vezes a cláusula SQL **Select** em uma junção usa apenas algumas das colunas de cada tabela. As classes de banco de dados dão suporte a junções somente leitura, mas não a junções atualizáveis.

Para selecionar registros que contêm colunas de tabelas unidas, você precisa dos seguintes itens:

- Uma lista de tabelas que contém os nomes de todas as tabelas que estão sendo Unidas.

- Uma lista de colunas que contém os nomes de todas as colunas participantes. Colunas com o mesmo nome, mas de tabelas diferentes, são qualificadas pelo nome da tabela.

- Um filtro (cláusula **Where** do SQL) que especifica as colunas nas quais as tabelas são unidas. Esse filtro usa o formato "Table1. KeyCol = Table2. KeyCol" e, na verdade, realiza a junção.

Você pode unir mais de duas tabelas da mesma maneira, equivalendo a vários pares de colunas, cada par Unido pela palavra-chave SQL **e**.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: declarando uma classe para uma consulta predefinida (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md)<br/>
[Conjunto de registros: declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)<br/>
[Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md)
