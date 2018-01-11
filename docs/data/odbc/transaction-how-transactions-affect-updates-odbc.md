---
title: "Transação: Como transações afetam atualizações (ODBC) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- transactions, updating recordsets
- ODBC recordsets, transactions
- transactions, rolling back
- CommitTrans method
- Rollback method, ODBC transactions
ms.assetid: 9e00bbf4-e9fb-4332-87fc-ec8ac61b3f68
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 59eb8aecbf2dd2138c8a0469d71364b55fd82774
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="transaction-how-transactions-affect-updates-odbc"></a>Transação: como as transações afetam atualizações (ODBC)
Atualizações para o [fonte de dados](../../data/odbc/data-source-odbc.md) gerenciados durante as transações com o uso de um buffer de edição (o mesmo método usado fora de transações). Os membros de um conjunto de registros de dados de campo coletivamente servem como um buffer de edição que contém o registro atual, o conjunto de registros faz backup temporariamente durante uma `AddNew` ou **editar**. Durante uma **excluir** operação, o registro atual não é feita em uma transação. Para obter mais informações sobre como atualizações armazenam o registro atual e o buffer de edição, consulte [conjunto de registros: como conjuntos de registros atualização registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).  
  
> [!NOTE]
>  Se você tiver implementado a busca de linhas em massa, você não pode chamar `AddNew`, **editar**, ou **excluir**. Em vez disso, você deve escrever suas próprias funções para executar atualizações para a fonte de dados. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Durante as transações, `AddNew`, **editar**, e **excluir** operações podem ser confirmadas ou revertidas. Os efeitos de **CommitTrans** e **reversão** pode causar a não ser restaurado para o buffer de editar o registro atual. Para certificar-se de que o registro atual é restaurado corretamente, é importante entender como o **CommitTrans** e **reversão** funções membro de `CDatabase` funcionam com as funções de atualização de `CRecordset`.  
  
##  <a name="_core_how_committrans_affects_updates"></a>Como CommitTrans afeta as atualizações  
 A tabela a seguir explica os efeitos de **CommitTrans** em transações.  
  
### <a name="how-committrans-affects-updates"></a>Como CommitTrans afeta as atualizações  
  
|Operação|Status da fonte de dados|  
|---------------|---------------------------|  
|`AddNew`e **atualização**e, em seguida, **CommitTrans**|Novo registro são adicionadas à fonte de dados.|  
|`AddNew`(sem **atualização**) e, em seguida, **CommitTrans**|Novo registro é perdido. Registro não é adicionado à fonte de dados.|  
|**Editar** e **atualização**e, em seguida, **CommitTrans**|Edições confirmadas a fonte de dados.|  
|**Editar** (sem **atualização**) e, em seguida, **CommitTrans**|Edições de registro são perdidas. Registro permanece inalterado na fonte de dados.|  
|**Excluir** , em seguida, **CommitTrans**|Registros excluídos da fonte de dados.|  
  
##  <a name="_core_how_rollback_affects_updates"></a>Como reverter afeta transações  
 A tabela a seguir explica os efeitos de **reversão** em transações.  
  
### <a name="how-rollback-affects-transactions"></a>Como reverter afeta transações  
  
|Operação|Status de registro atual|Você deve também|Status da fonte de dados|  
|---------------|------------------------------|-------------------|---------------------------|  
|`AddNew`e **atualização**, em seguida, **reversão**|Conteúdo do registro atual é armazenado temporariamente para liberar espaço para o novo registro. Novo registro é inserido no buffer de edição. Depois de **atualização** é chamado, atual registro for restaurado para o buffer de edição.||Além da fonte de dados feita por **atualização** é revertida.|  
|`AddNew`(sem **atualização**), em seguida, **reversão**|Conteúdo do registro atual é armazenado temporariamente para liberar espaço para o novo registro. Editar o buffer contém o novo registro.|Chamar `AddNew` novamente para restaurar o buffer de edição para um registro novo e vazio. Ou chamar **mover**(0) para restaurar os valores antigos para o buffer de edição.|Porque **atualização** não foi chamado, nenhuma alteração feita à fonte de dados.|  
|**Editar** e **atualização**, em seguida, **reversão**|Uma versão não editada do registro atual é armazenada temporariamente. Edições são feitas para o conteúdo do buffer de edição. Depois de **atualização** é chamado, o não editados versão do registro é armazenado temporariamente ainda.|*Dynaset*: role fora do registro atual e novamente para restaurar a versão não editada do registro para o buffer de edição.<br /><br /> *Instantâneo*: chamar **Requery** para atualizar o conjunto de registros da fonte de dados.|Altera a fonte de dados feita por **atualização** são revertidas.|  
|**Editar** (sem **atualização**), em seguida, **reversão**|Uma versão não editada do registro atual é armazenada temporariamente. Edições são feitas para o conteúdo do buffer de edição.|Chamar **editar** novamente para restaurar a versão não editada do registro para o buffer de edição.|Porque **atualização** não foi chamado, nenhuma alteração feita à fonte de dados.|  
|**Excluir** , em seguida, **reversão**|Conteúdo do registro atual é excluído.|Chamar **Requery** para restaurar o conteúdo do registro atual da fonte de dados.|A exclusão de dados de fonte de dados é revertida.|  
  
## <a name="see-also"></a>Consulte também  
 [Transação (ODBC)](../../data/odbc/transaction-odbc.md)   
 [Transação (ODBC)](../../data/odbc/transaction-odbc.md)   
 [Transação: Realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md)   
 [Classe CDatabase](../../mfc/reference/cdatabase-class.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)