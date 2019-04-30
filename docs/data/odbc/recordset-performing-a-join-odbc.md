---
title: 'Conjunto de registros: Realizando uma junção (ODBC)'
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
ms.openlocfilehash: 9e589f00ec0512794d14accc6bb33c0e7adbd378
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397714"
---
# <a name="recordset-performing-a-join-odbc"></a>Conjunto de registros: Realizando uma junção (ODBC)

Este tópico se aplica às classes ODBC do MFC.

## <a name="what-a-join-is"></a>O que é uma junção

A operação de junção, uma tarefa comum de acesso a dados, permite que você trabalhe com dados de mais de uma tabela usando um objeto de conjunto de registros único. Unir duas ou mais tabelas produz um conjunto de registros pode conter colunas de cada tabela, mas aparecerá como uma única tabela para seu aplicativo. Às vezes, a associação usa todas as colunas de todas as tabelas, mas, às vezes, o SQL **selecionar** cláusula em uma junção usa apenas algumas das colunas de cada tabela. As classes de banco de dados dão suporte a junções de somente leitura, mas as junções não é atualizáveis.

Para selecionar registros que contêm colunas de tabelas unidas, você precisa dos seguintes itens:

- Uma lista de tabela que contém os nomes de todas as tabelas que estão sendo unidas.

- Uma lista de colunas que contém os nomes de todas as colunas participantes. Colunas com o mesmo nome mas de tabelas diferentes são qualificadas pelo nome da tabela.

- Um filtro (SQL **onde** cláusula) que especifica as colunas no qual as tabelas são unidas. Esse filtro assume a forma "Table1.KeyCol = Table2.KeyCol" e, na verdade, realiza a junção.

Você pode associar mais de duas tabelas da mesma forma por vários pares de colunas, cada par associado da palavra-chave SQL que corresponda **AND**.

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: declarar uma classe para uma consulta predefinida (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md)<br/>
[Conjunto de registros: declarar uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)<br/>
[Conjunto de registros: repetir consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md)