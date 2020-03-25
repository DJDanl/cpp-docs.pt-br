---
title: 'Conjunto de registros: adicionando registros em massa (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC recordsets, adding records
- recordsets, adding records
- bulk record additions to recordsets
ms.assetid: 4685f656-14b9-4f10-a1c5-147b2b89a0b4
ms.openlocfilehash: f561cb0275933a973e97ef0518148e81e14a0234
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213012"
---
# <a name="recordset-adding-records-in-bulk-odbc"></a>Conjunto de registros: adicionando registros em massa (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

A classe MFC [CRecordset](../../mfc/reference/crecordset-class.md) tem uma nova otimização que melhora a eficiência quando você está adicionando novos registros em massa a uma tabela.

> [!NOTE]
> Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você estiver usando a busca de linha em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Uma nova opção para o parâmetro *dwOptions* para a função de membro [CRecordset:: Open](../../mfc/reference/crecordset-class.md#open) , `optimizeBulkAdd`, melhora o desempenho quando você está adicionando vários registros consecutivamente sem chamar `Requery` ou `Close`. Somente os campos que estão sujos antes da primeira chamada de `Update` são marcados como sujos para `AddNew`subsequentes /`Update` chamadas.

Se você estiver usando as classes de banco de dados para aproveitar a `::SQLSetPos` função da API ODBC para adicionar, editar e excluir registros, essa otimização será desnecessária.

Se a biblioteca de cursores ODBC for carregada ou o driver ODBC não oferecer suporte à adição, edição e exclusão por meio de `::SQLSetPos`, essa otimização deverá melhorar o desempenho de adição em massa. Para ativar essa otimização, defina o parâmetro *dwOptions* na chamada `Open` para o conjunto de registros como o seguinte:

```
appendOnly | optimizeBulkAdd
```

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)<br/>
[Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)
