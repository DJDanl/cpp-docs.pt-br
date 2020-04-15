---
title: 'Transação: como as transações afetam atualizações (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- transactions, updating recordsets
- ODBC recordsets, transactions
- transactions, rolling back
- CommitTrans method
- Rollback method, ODBC transactions
ms.assetid: 9e00bbf4-e9fb-4332-87fc-ec8ac61b3f68
ms.openlocfilehash: 8a87176ecb20beaf46583e1190b0ad458d508b31
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376429"
---
# <a name="transaction-how-transactions-affect-updates-odbc"></a>Transação: como as transações afetam atualizações (ODBC)

As atualizações na fonte de [dados](../../data/odbc/data-source-odbc.md) são gerenciadas durante as transações através do uso de um buffer de edição (o mesmo método usado fora das transações). Os membros de dados de campo de um conjunto de registros servem coletivamente como um buffer `AddNew` `Edit`de edição que contém o registro atual, que o conjunto de registros recua temporariamente durante um ou . Durante `Delete` uma operação, o registro atual não é feito em backup dentro de uma transação. Para obter mais informações sobre o buffer de edição e como as atualizações armazenam o registro atual, consulte [Recordset: How Recordsets Update Records (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).

> [!NOTE]
> Se você implementou a busca de `AddNew` `Edit`linhas `Delete`em massa, você não pode chamar , ou . Em vez disso, você deve escrever suas próprias funções para executar atualizações na fonte de dados. Para obter mais informações sobre a busca de linhas em massa, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Durante as `AddNew` `Edit`transações, `Delete` e as operações podem ser cometidas ou revertidas. Os efeitos `CommitTrans` `Rollback` e podem fazer com que o registro atual não seja restaurado no buffer de edição. Para garantir que o registro atual seja devidamente restaurado, `CommitTrans` `Rollback` é importante `CDatabase` entender como o membro `CRecordset`e o membro funcionam com as funções de atualização de .

## <a name="how-committrans-affects-updates"></a><a name="_core_how_committrans_affects_updates"></a>Como o CommitTrans afeta as atualizações

A tabela a seguir `CommitTrans` explica os efeitos das transações.

### <a name="how-committrans-affects-updates"></a>Como o CommitTrans afeta as atualizações

|Operação|Status da fonte de dados|
|---------------|---------------------------|
|`AddNew`e `Update`, e então`CommitTrans`|Novos registros são adicionados à fonte de dados.|
|`AddNew`(sem), `Update`e depois`CommitTrans`|Novo recorde está perdido. Registro não adicionado à fonte de dados.|
|`Edit`e `Update`, e então`CommitTrans`|Edições comprometidas com a fonte de dados.|
|`Edit`(sem), `Update`e depois`CommitTrans`|As edições para o registro estão perdidas. O registro permanece inalterado na fonte de dados.|
|`Delete`Então`CommitTrans`|Registros excluídos da fonte de dados.|

## <a name="how-rollback-affects-transactions"></a><a name="_core_how_rollback_affects_updates"></a>Como a reversão afeta as transações

A tabela a seguir `Rollback` explica os efeitos das transações.

### <a name="how-rollback-affects-transactions"></a>Como a reversão afeta as transações

|Operação|Status do registro atual|Você também deve|Status da fonte de dados|
|---------------|------------------------------|-------------------|---------------------------|
|`AddNew`e, `Update`em seguida,`Rollback`|O conteúdo do registro atual é armazenado temporariamente para abrir espaço para um novo registro. Novo registro é inserido no buffer de edição. Depois `Update` que é chamado, o registro atual é restaurado para o buffer de edição.||A adição à `Update` fonte de dados feita por é invertida.|
|`AddNew`(sem `Update`), então`Rollback`|O conteúdo do registro atual é armazenado temporariamente para abrir espaço para um novo registro. Editar buffer contém novo registro.|Ligue `AddNew` novamente para restaurar o buffer de edição para um novo registro vazio. Ou `Move`ligue (0) para restaurar os valores antigos para o buffer de edição.|Como `Update` não foi chamado, não houve alterações na fonte de dados.|
|`Edit`e, `Update`em seguida,`Rollback`|Uma versão não editada do registro atual é armazenada temporariamente. As edições são feitas ao conteúdo do buffer de edição. Depois `Update` que é chamado, a versão não editada do registro ainda é armazenada temporariamente.|*Dynaset*: Role o registro atual e volte para restaurar a versão não editada do registro no buffer de edição.<br /><br /> *Instantâneo*: `Requery` Chamada para atualizar o conjunto de registros a partir da fonte de dados.|As alterações na `Update` fonte de dados feitas por são invertidas.|
|`Edit`(sem `Update`), então`Rollback`|Uma versão não editada do registro atual é armazenada temporariamente. As edições são feitas ao conteúdo do buffer de edição.|Ligue `Edit` novamente para restaurar a versão não editada do registro para o buffer de edição.|Como `Update` não foi chamado, não houve alterações na fonte de dados.|
|`Delete`Então`Rollback`|O conteúdo do registro atual é excluído.|Chamada `Requery` para restaurar o conteúdo do registro atual a partir da fonte de dados.|A exclusão dos dados da fonte de dados é revertida.|

## <a name="see-also"></a>Confira também

[Transação (ODBC)](../../data/odbc/transaction-odbc.md)<br/>
[Transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
