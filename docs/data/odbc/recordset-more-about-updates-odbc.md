---
title: 'Conjunto de registros: mais sobre atualizações (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- records, updating
- transactions, updating recordsets
- ODBC recordsets, updating
- multiuser environments, updates to recordsets
- scrolling, updates to recordsets
- updating recordsets
- recordsets, updating
ms.assetid: 0353a742-d226-4fe2-8881-a7daeffe86cd
ms.openlocfilehash: 955b26137ce976514d84f95f4d819779b93bd78a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368681"
---
# <a name="recordset-more-about-updates-odbc"></a>Conjunto de registros: mais sobre atualizações (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica:

- [Como outras operações, como transações, afetam as atualizações.](#_core_how_transactions_affect_updates)

- [Suas atualizações e as de outros usuários.](#_core_your_updates_and_the_updates_of_other_users)

- [Mais sobre as funções de membro Atualizar e Excluir](#_core_more_about_update_and_delete).

> [!NOTE]
> Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você implementou a busca em linha em massa, algumas das informações não se aplicam. Por exemplo, você `AddNew`não `Edit` `Delete`pode `Update` chamar as funções de membro; no entanto, você pode realizar transações. Para obter mais informações sobre a busca de linhas em massa, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="how-other-operations-affect-updates"></a><a name="_core_how_other_operations_affect_updates"></a>Como outras operações afetam atualizações

Suas atualizações são afetadas por transações em vigor no momento da atualização, fechando o conjunto de registros antes de concluir uma transação e rolando antes de concluir uma transação.

### <a name="how-transactions-affect-updates"></a><a name="_core_how_transactions_affect_updates"></a>Como as transações afetam as atualizações

Além de `AddNew` `Edit`entender `Delete` como , e trabalhar, `BeginTrans`é `CommitTrans`importante `Rollback` entender como as funções do [CDatabase](../../mfc/reference/cdatabase-class.md) e membro funcionam com as funções de atualização do [CRecordset](../../mfc/reference/crecordset-class.md).

Por padrão, `AddNew` chamadas `Edit` para e afetar a `Update`fonte de dados imediatamente quando você chama . `Delete`chamadas fazem efeito imediatamente. Mas você pode estabelecer uma transação e executar um lote de tais chamadas. As atualizações não são permanentes até que você as comprometa. Se você mudar de idéia, você pode reverter a transação em vez de cometê-la.

Para obter mais informações sobre transações, consulte [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

### <a name="how-closing-the-recordset-affects-updates"></a><a name="_core_how_closing_the_recordset_affects_updates"></a>Como fechar o conjunto de registros afeta atualizações

Se você fechar um conjunto `CDatabase` de registros ou seu objeto associado, com uma transação em andamento (você não chamou [de CDatabase::CommitTrans](../../mfc/reference/cdatabase-class.md#committrans) ou [CDatabase:::Rollback),](../../mfc/reference/cdatabase-class.md#rollback)a transação será revertida automaticamente (a menos que o backend do banco de dados seja o mecanismo de banco de dados do Microsoft Jet).

> [!CAUTION]
> Se você estiver usando o mecanismo de banco de dados Microsoft Jet, fechar um conjunto de registros dentro de uma transação explícita não resulta na liberação de nenhuma das linhas que foram modificadas ou bloqueios que foram colocados até que a transação explícita seja cometida ou revertida. Recomenda-se que você sempre abra e feche os registros dentro ou fora de uma transação explícita da Jet.

### <a name="how-scrolling-affects-updates"></a><a name="_core_how_scrolling_affects_updates"></a>Como a rolagem afeta as atualizações

Quando você [grava: Rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) em um conjunto de registros, o buffer de edição é preenchido com cada novo registro atual (o registro anterior não é armazenado primeiro). A rolagem pula os registros previamente excluídos. Se você rolar `AddNew` `Edit` após uma `Update` `CommitTrans`ou `Rollback` chamada sem ligar, ou primeiro, quaisquer alterações serão perdidas (sem aviso para você) à medida que um novo registro for trazido para o buffer de edição. O buffer de edição é preenchido com o registro rolado para, o registro armazenado é liberado e nenhuma alteração ocorre na fonte de dados. Isso se aplica `AddNew` `Edit`a ambos e .

## <a name="your-updates-and-the-updates-of-other-users"></a><a name="_core_your_updates_and_the_updates_of_other_users"></a>Suas atualizações e atualizações de outros usuários

Quando você usa um conjunto de registros para atualizar dados, suas atualizações afetam outros usuários. Da mesma forma, as atualizações de outros usuários durante a vida útil do seu conjunto de registros afetam você.

Em um ambiente multiusuário, outros usuários podem abrir conjuntos de registros que contenham alguns dos mesmos registros selecionados em seu conjunto de registros. Alterações em um registro antes de recuperá-lo são refletidas no seu conjunto de registros. Como os dynasets recuperam um registro cada vez que você rola para ele, os dynasets refletem alterações cada vez que você rola para um registro. Os snapshots recuperam um registro na primeira vez que você rola até ele, então os instantâneos refletem apenas as alterações que ocorrem antes de você rolar para o registro inicialmente.

Os registros adicionados por outros usuários após a abertura do conjunto de registros não aparecem em seu conjunto de registros, a menos que você requery. Se o seu conjunto de registros for um dynaset, as edições dos registros existentes por outros usuários aparecerão no seu dynaset quando você rolar para o registro afetado. Se o seu conjunto de registros for um instantâneo, as edições não aparecerão até que você reaver o snapshot. Se você quiser ver registros adicionados ou excluídos por outros usuários em seu snapshot ou registros adicionados por outros usuários em seu dynaset, ligue para [CRecordset::Requery](../../mfc/reference/crecordset-class.md#requery) para reconstruir o conjunto de registros. (Observe que as exclusões de outros usuários aparecem em seu dynaset.) Você também `Requery` pode ligar para ver registros que você adiciona, mas não para ver suas exclusões.

> [!TIP]
> Para forçar o cache de um `MoveLast` instantâneo inteiro de uma vez, ligue imediatamente após abrir o instantâneo. Então `MoveFirst` ligue para começar a trabalhar com os registros. `MoveLast`é equivalente a rolar sobre todos os registros, mas ele recupera todos de uma vez. Note, no entanto, que isso pode reduzir o desempenho e pode não ser necessário para alguns drivers.

Os efeitos de suas atualizações em outros usuários são semelhantes aos seus efeitos sobre você.

## <a name="more-about-update-and-delete"></a><a name="_core_more_about_update_and_delete"></a>Mais sobre atualização e exclusão

Esta seção fornece informações adicionais para ajudá-lo a trabalhar `Update` e `Delete`.

### <a name="update-success-and-failure"></a>Atualizar sucesso e fracasso

Se `Update` for bem `AddNew` `Edit` sucedido, o modo ou termina. Para começar `AddNew` `Edit` um ou `AddNew` modo `Edit`novamente, ligue ou .

Se `Update` falhar (retorna FALSO ou lançar `AddNew` uma `Edit` exceção), você permanecerá dentro ou modo, dependendo de qual função você chamou por último. Você pode fazer o seguinte:

- Modifique um membro de `Update` dados de campo e tente novamente.

- Chamada `AddNew` para redefinir os membros de dados de campo para Nulo, definir os valores dos membros de dados de campo e, em seguida, chamar `Update` novamente.

- Chamada `Edit` para recarregar os valores que estavam `AddNew` no `Edit`conjunto de registros antes da primeira `Update` chamada para ou , definir os valores dos membros de dados de campo e, em seguida, chamar novamente. Após uma `Update` chamada bem `AddNew` sucedida (exceto após uma chamada), os membros de dados de campo mantêm seus novos valores.

- Chamada `Move` (inclusive `Move` com um parâmetro de AFX_MOVE_REFRESH, ou 0), `AddNew` que `Edit` libera quaisquer alterações e termina qualquer ou modo em vigor.

### <a name="update-and-delete"></a>Atualizar e excluir

Esta seção se `Update` `Delete`aplica a ambos e .

Em `Update` uma `Delete` operação ou ou, um único registro deve ser atualizado. Esse registro é o registro atual, que corresponde aos valores de dados nos campos do conjunto de registros. Se por alguma razão nenhum registro for afetado ou mais de um registro for afetado, uma exceção será lançada contendo um dos seguintes valores **RETCODE:**

- AFX_SQL_ERROR_NO_ROWS_AFFECTED

- AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED

Quando essas exceções são lançadas, `Edit` você permanece no `Update` `AddNew` ou `Delete`estado em que estava quando ligou ou . Aqui estão os cenários mais comuns em que você veria essas exceções. É mais provável que você veja:

- AFX_SQL_ERROR_NO_ROWS_AFFECTED quando você está usando o modo de bloqueio otimista e outro usuário modificou o registro de uma forma que impede que a estrutura identifique o registro correto para atualizar ou excluir.

- AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED quando a tabela que você está atualizando não tem nenhuma chave primária ou índice único e você não tem colunas suficientes no conjunto de registros para identificar exclusivamente uma linha de tabela.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)<br/>
[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[SQL](../../data/odbc/sql.md)<br/>
[Exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md)
