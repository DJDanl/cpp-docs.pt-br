---
title: 'Conjunto de registros: Adicionando registros em massa (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC recordsets, adding records
- recordsets, adding records
- bulk record additions to recordsets
ms.assetid: 4685f656-14b9-4f10-a1c5-147b2b89a0b4
ms.openlocfilehash: a2c3eab8bb4c0e8db76fceb5a2dafd16a4a07079
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59038603"
---
# <a name="recordset-adding-records-in-bulk-odbc"></a>Conjunto de registros: Adicionando registros em massa (ODBC)

Este tópico se aplica às classes ODBC do MFC.

O MFC [CRecordset](../../mfc/reference/crecordset-class.md) classe tem uma nova otimização que melhora a eficiência ao adicionar novos registros em massa para uma tabela.

> [!NOTE]
> Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa buscando não foi implementado. Se você estiver usando a busca de linhas em massa, consulte [conjunto de registros: Buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Uma nova opção para o *dwOptions* parâmetro para o [{1&gt;crecordset::Open&lt;1](../../mfc/reference/crecordset-class.md#open) função de membro, `optimizeBulkAdd`, melhora o desempenho quando você está adicionando vários registros consecutivamente sem chamar `Requery` ou `Close`. Somente os campos que são sujos antes do primeiro `Update` chamada são marcados como sujos para subsequentes `AddNew` / `Update` chamadas.

Se você estiver usando as classes de banco de dados para aproveitar o `::SQLSetPos` função ODBC API para adicionar, editar, e exclusão de registros, essa otimização é desnecessária.

Se a biblioteca de cursores ODBC é carregada ou o driver ODBC não oferece suporte à adição, edição e exclusão por meio de `::SQLSetPos`, essa otimização deve melhorar em massa adicionar de desempenho. Para ativar essa otimização, defina as *dwOptions* parâmetro no `Open` chamar para seu conjunto de registros para o seguinte:

```
appendOnly | optimizeBulkAdd
```

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: Adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)<br/>
[Conjunto de registros: Bloqueio de registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)