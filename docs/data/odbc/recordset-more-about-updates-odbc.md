---
title: 'Conjunto de registros: Mais informações sobre atualizações (ODBC)'
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
ms.openlocfilehash: c29ff110fc507c4e449b2f3d082d98c159a35107
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397764"
---
# <a name="recordset-more-about-updates-odbc"></a>Conjunto de registros: Mais informações sobre atualizações (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Este tópico explica:

- [Como outras operações, como transações afetam atualizações](#_core_how_transactions_affect_updates).

- [As atualizações e as de outros usuários](#_core_your_updates_and_the_updates_of_other_users).

- [Mais informações sobre as funções de membro de Update e Delete](#_core_more_about_update_and_delete).

> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa buscando não foi implementado. Se você tiver implementado a busca de linhas em massa, algumas informações não se aplica. Por exemplo, você não pode chamar o `AddNew`, `Edit`, `Delete`, e `Update` funções de membro; no entanto, você pode executar transações. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: Buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="_core_how_other_operations_affect_updates"></a> Como outras operações afetam atualizações

As atualizações são afetadas por transações em vigor no momento da atualização, fechando o conjunto de registros antes de concluir uma transação e rolando antes de concluir uma transação.

###  <a name="_core_how_transactions_affect_updates"></a> Como as transações afetam atualizações

Além da compreensão como `AddNew`, `Edit`, e `Delete` trabalho, é importante entender como o `BeginTrans`, `CommitTrans`, e `Rollback` funções de membro [CDatabase](../../mfc/reference/cdatabase-class.md) funcionam com as funções de atualização do [CRecordset](../../mfc/reference/crecordset-class.md).

Por padrão, chama `AddNew` e `Edit` afeta a fonte de dados imediatamente quando você chama `Update`. `Delete` chamadas entram em vigor imediatamente. Mas você pode estabelecer uma transação e executar um lote dessas chamadas. As atualizações não são permanentes até confirmá-las. Se você mudar de ideia, você pode reverter a transação em vez de confirmá-lo.

Para obter mais informações sobre transações, consulte [transação (ODBC)](../../data/odbc/transaction-odbc.md).

###  <a name="_core_how_closing_the_recordset_affects_updates"></a> Como o conjunto de registros de fechamento afeta as atualizações

Se você fechar um conjunto de registros ou de seus associados `CDatabase` objeto, com uma transação em andamento (você não tiver chamado [CDatabase::CommitTrans](../../mfc/reference/cdatabase-class.md#committrans) ou [CDatabase::Rollback](../../mfc/reference/cdatabase-class.md#rollback)), a transação é revertida de volta automaticamente (a menos que seu banco de dados back-end é o mecanismo de banco de dados Microsoft Jet).

> [!CAUTION]
>  Se você estiver usando o mecanismo de banco de dados Microsoft Jet, o fechamento de um conjunto de registros em uma transação explícita não resultar em liberar qualquer uma das linhas que foram modificadas ou bloqueios que foram feitos até que a transação explícita é confirmada ou revertida. É recomendável que você sempre abertas e fechar conjuntos de registros dentro ou fora de uma transação explícita do Jet.

###  <a name="_core_how_scrolling_affects_updates"></a> Como rolar afeta as atualizações

Quando você [conjunto de registros: Rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) em um conjunto de registros, o buffer de edição é preenchido com cada novo registro atual (o registro anterior não for armazenado primeiro). Rolagem ignora sobre registros excluídos anteriormente. Se você rolar após uma `AddNew` ou `Edit` chamada sem chamar `Update`, `CommitTrans`, ou `Rollback` em primeiro lugar, quaisquer alterações serão perdidas (sem nenhum aviso para você) como um novo registro é colocado no buffer de edição. O buffer de edição é preenchido com o registro rolado para o registro armazenado é liberado e não ocorre nenhuma alteração na fonte de dados. Isso se aplica a ambos `AddNew` e `Edit`.

##  <a name="_core_your_updates_and_the_updates_of_other_users"></a> As atualizações e as atualizações de outros usuários

Quando você usa um conjunto de registros para atualizar dados, as atualizações afetam outros usuários. Da mesma forma, as atualizações de outros usuários durante o tempo de vida de seu conjunto de registros afetá-lo.

Em um ambiente multiusuário, outros usuários podem abrir os conjuntos de registros que contêm alguns dos registros de mesmo que você selecionou no seu conjunto de registros. Alterações em um registro antes de recuperá-lo são refletidas no seu conjunto de registros. Como dynasets recuperam um registro de cada vez que você rola a ele, dynasets refletem as alterações sempre que você rolar para um registro. Instantâneos de recuperar um registro na primeira vez que você rola a ele, portanto, instantâneos refletem somente as alterações que ocorrem antes de você rolar para o registro inicialmente.

Registros adicionados por outros usuários depois de abrir o conjunto de registros não aparecem no seu conjunto de registros, a menos que você consulte novamente. Se seu conjunto de registros for um dynaset, as edições em registros existentes por outros usuários aparecem no seu dynaset quando você rolar para o registro afetado. Se seu conjunto de registros é um instantâneo, as edições não mostram até que você consulte novamente o instantâneo. Se você quiser ver os registros adicionados ou excluídos por outros usuários em seu instantâneo ou registros adicionados por outros usuários na sua dynaset, chame [CRecordset::Requery](../../mfc/reference/crecordset-class.md#requery) para recriar o conjunto de registros. (Observe que as exclusões de outros usuários aparecerão em seu dynaset.) Você também pode chamar `Requery` para ver os registros de adicionar, mas não para ver suas exclusões.

> [!TIP]
>  Para forçar o cache de todo um instantâneo de uma vez, chamar `MoveLast` imediatamente depois de abrir o instantâneo. Em seguida, chame `MoveFirst` para começar a trabalhar com os registros. `MoveLast` é equivalente à rolagem em todos os registros, mas ele recupera uma só vez. No entanto, observe que isso pode reduzir o desempenho e não pode ser necessário para alguns drivers.

Os efeitos das suas atualizações sobre os outros usuários são semelhantes aos seus efeitos sobre você.

##  <a name="_core_more_about_update_and_delete"></a> Mais informações sobre atualização e exclusão

Esta seção fornece informações adicionais para ajudar você a trabalhar com `Update` e `Delete`.

### <a name="update-success-and-failure"></a>Sucesso da atualização e falha

Se `Update` for bem-sucedida, o `AddNew` ou `Edit` modo termina. Para iniciar um `AddNew` ou `Edit` modo novamente, chame `AddNew` ou `Edit`.

Se `Update` falhar (retorna FALSE ou gera uma exceção), permanecem no `AddNew` ou `Edit` modo, dependendo de qual função você chamado pela última vez. Você pode fazer o seguinte:

- Modificar um membro de dados do campo e tente a `Update` novamente.

- Chame `AddNew` para redefinir os membros de dados do campo como Null, defina os valores dos membros de dados de campo e, em seguida, chame `Update` novamente.

- Chame `Edit` recarregue os valores que estavam no conjunto de registros antes da primeira chamada para `AddNew` ou `Edit`, defina os valores dos membros de dados de campo e, em seguida, chamar `Update` novamente. Após um bem-sucedido `Update` chamar (exceto após uma `AddNew` chamar), os membros de dados do campo retêm seus novos valores.

- Chame `Move` (incluindo `Move` com um parâmetro de AFX_MOVE_REFRESH ou 0), que libera qualquer altera e encerra qualquer `AddNew` ou `Edit` modo em vigor.

### <a name="update-and-delete"></a>Atualizar e excluir

Esta seção se aplica a ambos `Update` e `Delete`.

Em um `Update` ou `Delete` operação, apenas um registro deve ser atualizado. Esse registro é o registro atual, que corresponde aos valores nos campos do conjunto de registros de dados. Se por alguma razão, não há registros são afetados ou mais de um registro é afetado, uma exceção é gerada que contém um dos seguintes **RETCODE** valores:

- AFX_SQL_ERROR_NO_ROWS_AFFECTED

- AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED

Quando essas exceções forem geradas, você permanecer na `AddNew` ou `Edit` estado em que estava quando você chamou `Update` ou `Delete`. Aqui estão os cenários mais comuns em que você veria essas exceções. Você provavelmente está ver:

- AFX_SQL_ERROR_NO_ROWS_AFFECTED quando você estiver usando o modo de bloqueio otimista e outro usuário modificou o registro de uma maneira que impede que o framework identifica o registro correto para atualizar ou excluir.

- AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED quando a tabela que você está atualizando não tem nenhuma chave primária ou índice exclusivo e você não tem colunas suficientes no conjunto de registros para identificar exclusivamente uma linha da tabela.

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)<br/>
[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[SQL](../../data/odbc/sql.md)<br/>
[Exceções: exceções do banco de dados](../../mfc/exceptions-database-exceptions.md)