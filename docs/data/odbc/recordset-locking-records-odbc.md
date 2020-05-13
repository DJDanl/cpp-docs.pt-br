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
ms.openlocfilehash: abd5f817ad321241df2d8565bd6bf346c0792088
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366960"
---
# <a name="recordset-locking-records-odbc"></a>Conjunto de registros: bloqueando registros (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica:

- [Os tipos de bloqueio de registros disponíveis.](#_core_record.2d.locking_modes)

- [Como bloquear registros em seu conjunto de registros durante atualizações](#_core_locking_records_in_your_recordset).

Quando você usa um conjunto de registros para atualizar um registro na fonte de dados, seu aplicativo pode bloquear o registro para que nenhum outro usuário possa atualizar o registro ao mesmo tempo. O estado de um registro atualizado por dois usuários ao mesmo tempo é indefinido, a menos que o sistema possa garantir que dois usuários não podem atualizar um registro simultaneamente.

> [!NOTE]
> Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você implementou a busca em linha em massa, algumas das informações não se aplicam. Por exemplo, você `Edit` não `Update` pode chamar as funções e membro. Para obter mais informações sobre a busca de linhas em massa, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="record-locking-modes"></a><a name="_core_record.2d.locking_modes"></a>Modos de bloqueio de registro

As classes de banco de dados fornecem dois [modos de bloqueio de registros:](../../mfc/reference/crecordset-class.md#setlockingmode)

- Bloqueio otimista (o padrão)

- Bloqueio pessimista

A atualização de um registro ocorre em três etapas:

1. Você começa a operação chamando a função [Editar](../../mfc/reference/crecordset-class.md#edit) membro.

1. Você muda os campos apropriados do registro atual.

1. Você encerra a operação — e normalmente comete a atualização — chamando a função de membro [Update.](../../mfc/reference/crecordset-class.md#update)

O bloqueio otimista bloqueia o registro `Update` na fonte de dados apenas durante a chamada. Se você usar bloqueio otimista em um ambiente `Update` multiusuário, o aplicativo deve lidar com uma condição de falha. Bloqueio pessimista bloqueia o `Edit` registro assim que você `Update` liga e não o `CDBException` libera até que você ligue `Update`(falhas são indicadas através do mecanismo, não por um valor de FALSE devolvido por ). O bloqueio pessimista tem uma penalidade de desempenho potencial para outros usuários, pois o `Update` acesso simultâneo ao mesmo registro pode ter que esperar até a conclusão do processo do seu aplicativo.

## <a name="locking-records-in-your-recordset"></a><a name="_core_locking_records_in_your_recordset"></a>Bloqueando registros em seu conjunto de registros

Se você quiser alterar o modo de [bloqueio](#_core_record.2d.locking_modes) de um objeto de conjunto `Edit`de gravações a partir do padrão, você deve alterar o modo antes de chamar .

#### <a name="to-change-the-current-locking-mode-for-your-recordset"></a>Para alterar o modo de bloqueio atual para o seu conjunto de registros

1. Ligue para a função de membro `CRecordset::pessimistic` `CRecordset::optimistic` [SetLockingMode,](../../mfc/reference/crecordset-class.md#setlockingmode) especificando ou .

O novo modo de bloqueio permanece em vigor até que você o altere novamente ou o conjunto de registros seja fechado.

> [!NOTE]
> Relativamente poucos drivers ODBC atualmente suportam bloqueio pessimista.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: realizando uma junção (ODBC)](../../data/odbc/recordset-performing-a-join-odbc.md)<br/>
[Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)
