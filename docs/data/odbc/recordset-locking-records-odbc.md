---
title: 'Conjunto de registros: bloqueando registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- locks [C++], recordsets
- optimistic locking
- pessimistic locking in ODBC
- recordsets [C++], locking records
- optimistic locking, ODBC
- ODBC recordsets [C++], locking records
- data [C++], locking
ms.assetid: 8fe8fcfe-b55a-41a8-9136-94a7cd1e4806
ms.openlocfilehash: d4e80816a131c997e9f5bfaa34f025394b05a358
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212856"
---
# <a name="recordset-locking-records-odbc"></a>Conjunto de registros: bloqueando registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica:

- [Os tipos de bloqueio de registro disponíveis](#_core_record.2d.locking_modes).

- [Como bloquear registros em seu conjunto de registros durante as atualizações](#_core_locking_records_in_your_recordset).

Quando você usa um conjunto de registros para atualizar um registro na fonte de dados, seu aplicativo pode bloquear o registro para que nenhum outro usuário possa atualizar o registro ao mesmo tempo. O estado de um registro atualizado por dois usuários ao mesmo tempo é indefinido, a menos que o sistema possa garantir que dois usuários não possam atualizar um registro simultaneamente.

> [!NOTE]
>  Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você tiver implementado a busca de linha em massa, algumas das informações não se aplicarão. Por exemplo, você não pode chamar as funções de membro `Edit` e `Update`. Para obter mais informações sobre a busca de linha em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="record-locking-modes"></a><a name="_core_record.2d.locking_modes"></a>Modos de bloqueio de registros

As classes de banco de dados fornecem dois [modos de bloqueio de registro](../../mfc/reference/crecordset-class.md#setlockingmode):

- Bloqueio otimista (o padrão)

- Bloqueio pessimista

A atualização de um registro ocorre em três etapas:

1. Você inicia a operação chamando a função [Editar](../../mfc/reference/crecordset-class.md#edit) membro.

1. Você altera os campos apropriados do registro atual.

1. Você encerra a operação — e normalmente confirma a atualização — chamando a função de membro de [atualização](../../mfc/reference/crecordset-class.md#update) .

O bloqueio otimista bloqueia o registro na fonte de dados somente durante a chamada de `Update`. Se você usar o bloqueio otimista em um ambiente multiusuário, o aplicativo deverá lidar com uma condição de falha de `Update`. O bloqueio pessimista bloqueia o registro assim que você chama `Edit` e não o libera até que você chame `Update` (as falhas são indicadas por meio do mecanismo de `CDBException`, não por um valor FALSE retornado pelo `Update`). O bloqueio pessimista tem uma penalidade de desempenho potencial para outros usuários, pois o acesso simultâneo ao mesmo registro pode ter que esperar até a conclusão do processo de `Update` do seu aplicativo.

##  <a name="locking-records-in-your-recordset"></a><a name="_core_locking_records_in_your_recordset"></a>Bloqueando registros em seu conjunto de registros

Se você quiser alterar o [modo de bloqueio](#_core_record.2d.locking_modes) de um objeto Recordset do padrão, deverá alterar o modo antes de chamar `Edit`.

#### <a name="to-change-the-current-locking-mode-for-your-recordset"></a>Para alterar o modo de bloqueio atual do conjunto de registros

1. Chame a função de membro [Setlockmode](../../mfc/reference/crecordset-class.md#setlockingmode) , especificando `CRecordset::pessimistic` ou `CRecordset::optimistic`.

O novo modo de bloqueio permanecerá em vigor até que você o altere novamente ou o conjunto de registros seja fechado.

> [!NOTE]
>  Relativamente poucos drivers ODBC dão suporte ao bloqueio pessimista no momento.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: realizando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md)<br/>
[Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)
