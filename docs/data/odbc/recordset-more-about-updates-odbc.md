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
ms.openlocfilehash: f11c723e4589cb28a3f38100050a69a78fc0809e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212843"
---
# <a name="recordset-more-about-updates-odbc"></a>Conjunto de registros: mais sobre atualizações (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica:

- [Como outras operações, como transações, afetam as atualizações](#_core_how_transactions_affect_updates).

- [Suas atualizações e as de outros usuários](#_core_your_updates_and_the_updates_of_other_users).

- [Mais sobre as funções de membro Update e Delete](#_core_more_about_update_and_delete).

> [!NOTE]
>  Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. Se você tiver implementado a busca de linha em massa, algumas das informações não se aplicarão. Por exemplo, você não pode chamar as funções de membro `AddNew`, `Edit`, `Delete`e `Update`; no entanto, você pode executar transações. Para obter mais informações sobre a busca de linha em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="how-other-operations-affect-updates"></a><a name="_core_how_other_operations_affect_updates"></a>Como outras operações afetam as atualizações

Suas atualizações são afetadas por transações em vigor no momento da atualização, fechando o conjunto de registros antes de concluir uma transação e rolando antes de concluir uma transação.

###  <a name="how-transactions-affect-updates"></a><a name="_core_how_transactions_affect_updates"></a>Como as transações afetam as atualizações

Além de entender como `AddNew`, `Edit`e `Delete` funcionam, é importante entender como as funções de membro `BeginTrans`, `CommitTrans`e `Rollback` do [CDatabase](../../mfc/reference/cdatabase-class.md) funcionam com as funções de atualização do [CRecordset](../../mfc/reference/crecordset-class.md).

Por padrão, as chamadas para `AddNew` e `Edit` afetam a fonte de dados imediatamente quando você chama `Update`. `Delete` chamadas entram em vigor imediatamente. Mas você pode estabelecer uma transação e executar um lote de tais chamadas. As atualizações não são permanentes até você confirmá-las. Se você mudar de ideia, poderá reverter a transação em vez de confirmá-la.

Para obter mais informações sobre transações, consulte [transação (ODBC)](../../data/odbc/transaction-odbc.md).

###  <a name="how-closing-the-recordset-affects-updates"></a><a name="_core_how_closing_the_recordset_affects_updates"></a>Como o fechamento do conjunto de registros afeta as atualizações

Se você fechar um conjunto de registros ou seu objeto `CDatabase` associado, com uma transação em andamento (você não chamou [CDatabase:: CommitTrans](../../mfc/reference/cdatabase-class.md#committrans) ou [CDatabase:: Rollback](../../mfc/reference/cdatabase-class.md#rollback)), a transação será revertida automaticamente (a menos que o back-end do banco de dados seja o mecanismo de banco de dados Microsoft Jet).

> [!CAUTION]
>  Se você estiver usando o mecanismo de banco de dados do Microsoft Jet, fechar um conjunto de registros dentro de uma transação explícita não resultará na liberação de nenhuma das linhas que foram modificadas ou bloqueios que foram colocados até que a transação explícita seja confirmada ou revertida. É recomendável que você sempre abra e feche conjuntos de registros dentro ou fora de uma transação Jet explícita.

###  <a name="how-scrolling-affects-updates"></a><a name="_core_how_scrolling_affects_updates"></a>Como a rolagem afeta as atualizações

Quando você faz o [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) em um conjunto de registros, o buffer de edição é preenchido com cada novo registro atual (o registro anterior não é armazenado primeiro). A rolagem ignora os registros excluídos anteriormente. Se você rolar após uma chamada de `AddNew` ou `Edit` sem chamar `Update`, `CommitTrans`ou `Rollback` primeiro, todas as alterações serão perdidas (sem nenhum aviso a você), pois um novo registro é trazido para o buffer de edição. O buffer de edição é preenchido com o registro rolado para, o registro armazenado é liberado e nenhuma alteração ocorre na fonte de dados. Isso se aplica a `AddNew` e `Edit`.

##  <a name="your-updates-and-the-updates-of-other-users"></a><a name="_core_your_updates_and_the_updates_of_other_users"></a>Suas atualizações e as atualizações de outros usuários

Quando você usa um conjunto de registros para atualizar dados, suas atualizações afetam outros usuários. Da mesma forma, as atualizações de outros usuários durante o tempo de vida do conjunto de registros afetam você.

Em um ambiente multiusuário, outros usuários podem abrir conjuntos de registros que contêm alguns dos mesmos registros que você selecionou em seu conjunto de registros. As alterações em um registro antes de você recuperá-lo são refletidas no conjunto de registros. Como os dynasets recuperam um registro cada vez que você rola para ele, os dynasets refletem as alterações cada vez que você rola para um registro. Os instantâneos recuperam um registro na primeira vez que você rola para ele, de modo que os instantâneos refletem apenas as alterações que ocorrem antes de rolar para o registro inicialmente.

Os registros adicionados por outros usuários após você abrir o conjunto de registros não aparecem no conjunto de registros, a menos que você faça outra consulta. Se o conjunto de registros for um dynaset, as edições nos registros existentes por outros usuários aparecerão em seu dynaset quando você rolar para o registro afetado. Se o conjunto de registros for um instantâneo, as edições não serão exibidas até que você repita a consulta do instantâneo. Se você quiser ver os registros adicionados ou excluídos por outros usuários em seu instantâneo ou registros adicionados por outros usuários em seu dynaset, chame [CRecordset:: requerer](../../mfc/reference/crecordset-class.md#requery) para recompilar o conjunto de registros. (Observe que as exclusões de outros usuários aparecem em seu dynaset). Você também pode chamar `Requery` para ver os registros que você adicionar, mas não para ver suas exclusões.

> [!TIP]
>  Para forçar o cache de um instantâneo inteiro de uma vez, chame `MoveLast` imediatamente depois de abrir o instantâneo. Em seguida, chame `MoveFirst` para começar a trabalhar com os registros. `MoveLast` é equivalente a rolar todos os registros, mas recupera todos eles de uma só vez. Observe, no entanto, que isso pode reduzir o desempenho e pode não ser necessário para alguns drivers.

Os efeitos de suas atualizações em outros usuários são semelhantes aos seus efeitos.

##  <a name="more-about-update-and-delete"></a><a name="_core_more_about_update_and_delete"></a>Mais sobre atualização e exclusão

Esta seção fornece informações adicionais para ajudá-lo a trabalhar com `Update` e `Delete`.

### <a name="update-success-and-failure"></a>Êxito na atualização e falha

Se `Update` tiver sucesso, o `AddNew` ou o modo de `Edit` terminará. Para iniciar um modo de `AddNew` ou de `Edit` novamente, chame `AddNew` ou `Edit`.

Se `Update` falhar (retorna FALSE ou gera uma exceção), você permanecerá no modo `AddNew` ou `Edit`, dependendo da função que você chamou por último. Você pode fazer o seguinte:

- Modifique um membro de dados de campo e tente a `Update` novamente.

- Chame `AddNew` para redefinir os membros de dados de campo como NULL, defina os valores dos membros de dados de campo e, em seguida, chame `Update` novamente.

- Chame `Edit` para recarregar os valores que estavam no conjunto de registros antes da primeira chamada para `AddNew` ou `Edit`, defina os valores dos membros de dados de campo e, em seguida, chame `Update` novamente. Após uma chamada de `Update` bem-sucedida (exceto após uma chamada de `AddNew`), os membros dos dados de campo retêm seus novos valores.

- Chame `Move` (incluindo `Move` com um parâmetro de AFX_MOVE_REFRESH, ou 0), que libera quaisquer alterações e termina qualquer `AddNew` ou modo de `Edit` em vigor.

### <a name="update-and-delete"></a>Atualizar e excluir

Esta seção se aplica a `Update` e `Delete`.

Em uma operação `Update` ou `Delete`, somente um registro deve ser atualizado. Esse registro é o registro atual, que corresponde aos valores de dados nos campos do conjunto de registros. Se, por alguma razão, nenhum registro for afetado ou mais de uma gravação for afetada, uma exceção será gerada contendo um dos seguintes valores de **RETCODE** :

- AFX_SQL_ERROR_NO_ROWS_AFFECTED

- AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED

Quando essas exceções são geradas, você permanece no estado `AddNew` ou `Edit` em que estava quando você chamou `Update` ou `Delete`. Aqui estão os cenários mais comuns em que você veria essas exceções. Você tem mais probabilidade de ver:

- AFX_SQL_ERROR_NO_ROWS_AFFECTED quando você estiver usando o modo de bloqueio otimista e outro usuário tiver modificado o registro de uma maneira que impeça a estrutura de identificar o registro correto a ser atualizado ou excluído.

- AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED quando a tabela que você está atualizando não tem nenhuma chave primária ou índice exclusivo e você não tem colunas suficientes no conjunto de registros para identificar exclusivamente uma linha de tabela.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)<br/>
[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[SQL](../../data/odbc/sql.md)<br/>
[Exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md)
