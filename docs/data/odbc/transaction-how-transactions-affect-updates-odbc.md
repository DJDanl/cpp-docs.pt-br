---
title: 'Transação: Como as transações afetam as atualizações (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- transactions, updating recordsets
- ODBC recordsets, transactions
- transactions, rolling back
- CommitTrans method
- Rollback method, ODBC transactions
ms.assetid: 9e00bbf4-e9fb-4332-87fc-ec8ac61b3f68
ms.openlocfilehash: d03ec3f71c38f7790d66fbf6f800b7647e080147
ms.sourcegitcommit: 0e3da5cea44437c132b5c2ea522bd229ea000a10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/12/2019
ms.locfileid: "70311841"
---
# <a name="transaction-how-transactions-affect-updates-odbc"></a>Transação: Como as transações afetam as atualizações (ODBC)

As atualizações da [fonte de dados](../../data/odbc/data-source-odbc.md) são gerenciadas durante as transações por meio do uso de um buffer de edição (o mesmo método usado fora das transações). Os membros de dados de campo de um conjunto de registros, coletivamente, servem como um buffer de edição que contém o registro atual, que `AddNew` o `Edit`conjunto de registros faz backup temporariamente durante um ou. Durante uma `Delete` operação, não é feito backup do registro atual em uma transação. Para obter mais informações sobre o buffer de edição e como as atualizações armazenam o [registro atual, consulte conjunto de registros: Como os Recordsets atualizam registros (](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)ODBC).

> [!NOTE]
>  Se você tiver implementado a busca de linha em massa, não `AddNew`será `Edit`possível chamar `Delete`, ou. Em vez disso, você deve escrever suas próprias funções para realizar atualizações na fonte de dados. Para saber mais sobre o fetch de linha em massa, confira [Conjunto de registros: como efetuar fetch de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Durante as transações `AddNew`, `Edit`,, `Delete` e as operações podem ser confirmadas ou revertidas. Os efeitos de `CommitTrans` e `Rollback` podem fazer com que o registro atual não seja restaurado para o buffer de edição. Para garantir que o registro atual seja restaurado corretamente, é importante entender como `CommitTrans` as funções de membro e `Rollback` de `CDatabase` trabalho com as funções de atualização do `CRecordset`.

##  <a name="_core_how_committrans_affects_updates"></a>Como o CommitTrans afeta as atualizações

A tabela a seguir explica os efeitos `CommitTrans` de em transações.

### <a name="how-committrans-affects-updates"></a>Como o CommitTrans afeta as atualizações

|Operação|Status da fonte de dados|
|---------------|---------------------------|
|`AddNew`e `Update`, em seguida,`CommitTrans`|Novo registro é adicionado à fonte de dados.|
|`AddNew`(sem `Update`) e, em seguida,`CommitTrans`|O novo registro é perdido. Registro não adicionado à fonte de dados.|
|`Edit`e `Update`, em seguida,`CommitTrans`|As edições são confirmadas na fonte de dados.|
|`Edit`(sem `Update`) e, em seguida,`CommitTrans`|As edições no registro são perdidas. O registro permanece inalterado na fonte de dados.|
|`Delete`Clique`CommitTrans`|Registros excluídos da fonte de dados.|

##  <a name="_core_how_rollback_affects_updates"></a>Como a reversão afeta as transações

A tabela a seguir explica os efeitos `Rollback` de em transações.

### <a name="how-rollback-affects-transactions"></a>Como a reversão afeta as transações

|Operação|Status do registro atual|Você também deve|Status da fonte de dados|
|---------------|------------------------------|-------------------|---------------------------|
|`AddNew`e `Update`, em seguida,`Rollback`|O conteúdo do registro atual é armazenado temporariamente para liberar espaço para o novo registro. O novo registro é inserido no buffer de edição. Depois `Update` que é chamado, o registro atual é restaurado para o buffer de edição.||Adição à fonte de dados feita `Update` por é invertida.|
|`AddNew`(sem `Update`), então`Rollback`|O conteúdo do registro atual é armazenado temporariamente para liberar espaço para o novo registro. O buffer de edição contém um novo registro.|Chame `AddNew` novamente para restaurar o buffer de edição para um novo registro vazio. Ou chame `Move`(0) para restaurar os valores antigos para o buffer de edição.|Como `Update` não foi chamado, não havia nenhuma alteração feita na fonte de dados.|
|`Edit`e `Update`, em seguida,`Rollback`|Uma versão não editada do registro atual é armazenada temporariamente. São feitas edições no conteúdo do buffer de edição. Depois `Update` que o for chamado, a versão não editada do registro ainda será armazenada temporariamente.|*Dynaset*: Role para fora do registro atual e volte para restaurar a versão não editada do registro para o buffer de edição.<br /><br /> *Instantâneo*: Chame `Requery` para atualizar o conjunto de registros da fonte de dados.|As alterações na fonte de dados `Update` feita por são revertidas.|
|`Edit`(sem `Update`), então`Rollback`|Uma versão não editada do registro atual é armazenada temporariamente. São feitas edições no conteúdo do buffer de edição.|Chame `Edit` novamente para restaurar a versão não editada do registro para o buffer de edição.|Como `Update` não foi chamado, não havia nenhuma alteração feita na fonte de dados.|
|`Delete`Clique`Rollback`|O conteúdo do registro atual é excluído.|Chame `Requery` para restaurar o conteúdo do registro atual da fonte de dados.|A exclusão de dados da fonte de dados é revertida.|

## <a name="see-also"></a>Consulte também

[Transação (ODBC)](../../data/odbc/transaction-odbc.md)<br/>
[Transação: realizar uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
