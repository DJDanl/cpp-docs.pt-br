---
title: 'Transação: Como as transações afetam atualizações (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- transactions, updating recordsets
- ODBC recordsets, transactions
- transactions, rolling back
- CommitTrans method
- Rollback method, ODBC transactions
ms.assetid: 9e00bbf4-e9fb-4332-87fc-ec8ac61b3f68
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 21e6511a66129cb172ff10fedfa563bc4d663d19
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46078511"
---
# <a name="transaction-how-transactions-affect-updates-odbc"></a>Transação: como as transações afetam atualizações (ODBC)

Atualizações para o [fonte de dados](../../data/odbc/data-source-odbc.md) são gerenciados durante as transações com o uso de um buffer de edição (o mesmo método usado fora de transações). Os membros de dados do campo de um conjunto de registros coletivamente servem como um buffer de edição que contém o registro atual, o que o conjunto de registros faz backup temporariamente durante um `AddNew` ou `Edit`. Durante um `Delete` operação, o registro atual não é feita em uma transação. Para obter mais informações sobre como atualizações de armazenam o registro atual e o buffer de edição, consulte [conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).  
  
> [!NOTE]
>  Se você tiver implementado a busca de linhas em massa, você não pode chamar `AddNew`, `Edit`, ou `Delete`. Em vez disso, você deve escrever suas próprias funções para executar atualizações à fonte de dados. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
Durante as transações, `AddNew`, `Edit`, e `Delete` operações podem ser confirmadas ou revertidas. Os efeitos das `CommitTrans` e `Rollback` pode fazer com que o registro atual a não ser restaurado para o buffer de edição. Para certificar-se de que o registro atual é restaurado corretamente, é importante entender como o `CommitTrans` e `Rollback` funções de membro `CDatabase` funcionam com as funções de atualização de `CRecordset`.  
  
##  <a name="_core_how_committrans_affects_updates"></a> Como CommitTrans afeta as atualizações  

A tabela a seguir explica os efeitos da `CommitTrans` em transações.  
  
### <a name="how-committrans-affects-updates"></a>Como CommitTrans afeta as atualizações  
  
|Operação|Status da fonte de dados|  
|---------------|---------------------------|  
|`AddNew` e `Update`e, em seguida, `CommitTrans`|Novo registro são adicionados à fonte de dados.|  
|`AddNew` (sem `Update`) e, em seguida, `CommitTrans`|Novo registro é perdido. Registro não é adicionado à fonte de dados.|  
|`Edit` e `Update`e, em seguida, `CommitTrans`|O compromisso de fonte de dados de edições.|  
|`Edit` (sem `Update`) e, em seguida, `CommitTrans`|Edições para o registro serão perdidas. Registro permanece inalterado na fonte de dados.|  
|`Delete` Em seguida `CommitTrans`|Registros excluídos da fonte de dados.|  
  
##  <a name="_core_how_rollback_affects_updates"></a> Como afeta a reversão de transações  

A tabela a seguir explica os efeitos da `Rollback` em transações.  
  
### <a name="how-rollback-affects-transactions"></a>Como afeta a reversão de transações  
  
|Operação|Status de registro atual|Também é necessário|Status da fonte de dados|  
|---------------|------------------------------|-------------------|---------------------------|  
|`AddNew` e `Update`, em seguida, `Rollback`|Conteúdo do registro atual é armazenado temporariamente para liberar espaço para o novo registro. Novo registro é inserido no buffer de edição. Depois de `Update` é chamado, o atual registro é restaurado para o buffer de edição.||Adição a fonte de dados feita por `Update` é invertida.|  
|`AddNew` (sem `Update`), em seguida, `Rollback`|Conteúdo do registro atual é armazenado temporariamente para liberar espaço para o novo registro. Editar o buffer contém o novo registro.|Chamar `AddNew` novamente para restaurar o buffer de edição para um registro de novo, vazio. Ou ligue para `Move`(0) para restaurar os valores antigos para o buffer de edição.|Porque `Update` não foi chamado, não houve alterações feitas à fonte de dados.|  
|`Edit` e `Update`, em seguida, `Rollback`|Uma versão não editada do registro atual é armazenada temporariamente. Edições são feitas para o conteúdo do buffer de edição. Depois de `Update` é chamado, a não editado versão do registro é armazenado ainda temporariamente.|*Dynaset*: role fora do registro atual e voltando para restaurar a versão não editada do registro para o buffer de edição.<br /><br /> *Instantâneo*: chamar `Requery` para atualizar o conjunto de registros da fonte de dados.|Altera a fonte de dados feita por `Update` são revertidas.|  
|`Edit` (sem `Update`), em seguida, `Rollback`|Uma versão não editada do registro atual é armazenada temporariamente. Edições são feitas para o conteúdo do buffer de edição.|Chamar `Edit` novamente para restaurar a versão não editado do registro para o buffer de edição.|Porque `Update` não foi chamado, não houve alterações feitas à fonte de dados.|  
|`Delete` Em seguida `Rollback`|Conteúdo do registro atual é excluído.|Chamar `Requery` para restaurar o conteúdo do registro atual da fonte de dados.|Exclusão de dados da fonte de dados é revertida.|  
  
## <a name="see-also"></a>Consulte também  

[Transação (ODBC)](../../data/odbc/transaction-odbc.md)<br/>
[Transação (ODBC)](../../data/odbc/transaction-odbc.md)<br/>
[Transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)