---
title: "Conjunto de registros: Mais sobre atualizações (ODBC) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- records, updating
- transactions, updating recordsets
- ODBC recordsets, updating
- multiuser environments, updates to recordsets
- scrolling, updates to recordsets
- updating recordsets
- recordsets, updating
ms.assetid: 0353a742-d226-4fe2-8881-a7daeffe86cd
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: f996a206ebac40a469f2fc540c5e23ce0f5c2733
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="recordset-more-about-updates-odbc"></a>Conjunto de registros: mais sobre atualizações (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Este tópico explica:  
  
-   [Como outras operações, como transações afetam atualizações](#_core_how_transactions_affect_updates).  
  
-   [As atualizações e as de outros usuários](#_core_your_updates_and_the_updates_of_other_users).  
  
-   [Mais sobre as funções de membro de Update e Delete](#_core_more_about_update_and_delete).  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa busca não foi implementada. Se você tiver implementado a busca de linhas em massa, algumas informações não se aplicam. Por exemplo, você não pode chamar o `AddNew`, **editar**, **excluir**, e **atualização** funções de membro; no entanto, você pode executar transações. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
##  <a name="_core_how_other_operations_affect_updates"></a>Como outras operações afetam atualizações  
 As atualizações são afetadas por transações em vigor no momento da atualização, fechando o conjunto de registros antes da conclusão de uma transação e rolando antes da conclusão de uma transação.  
  
###  <a name="_core_how_transactions_affect_updates"></a>Como as transações afetam atualizações  
 Além de Noções básicas sobre como `AddNew`, **editar**, e **excluir** trabalho, é importante entender como o **BeginTrans**, **CommitTrans**, e **reversão** funções membro de [CDatabase](../../mfc/reference/cdatabase-class.md) funcionam com as funções de atualização de [CRecordset](../../mfc/reference/crecordset-class.md).  
  
 Por padrão, as chamadas para `AddNew` e **editar** afetam a fonte de dados imediatamente quando você chama **atualização**. **Excluir** chamadas entram em vigor imediatamente. Mas você pode estabelecer uma transação e executar um lote dessas chamadas. As atualizações não são permanentes até que você confirme-los. Se você mudar de ideia, você pode reverter a transação em vez de confirmá-la.  
  
 Para obter mais informações sobre transações, consulte [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
###  <a name="_core_how_closing_the_recordset_affects_updates"></a>Como o conjunto de registros de fechamento afeta as atualizações  
 Se você fechar um conjunto de registros ou seus associados `CDatabase` objeto, com uma transação em andamento (você não tiver chamado [CDatabase::CommitTrans](../../mfc/reference/cdatabase-class.md#committrans) ou [CDatabase::Rollback](../../mfc/reference/cdatabase-class.md#rollback)), a transação é revertida Faça automaticamente (a menos que seu banco de dados back-end é o mecanismo de banco de dados Microsoft Jet).  
  
> [!CAUTION]
>  Se você estiver usando o mecanismo de banco de dados Microsoft Jet, fechar um conjunto de registros dentro de uma transação explícita não resulta em liberar qualquer uma das linhas que foram modificadas ou bloqueios que foram colocados até que a transação explícita é confirmada ou revertida. É recomendável que você sempre abertas e fechar conjuntos de registros dentro ou fora de uma transação explícita do Jet.  
  
###  <a name="_core_how_scrolling_affects_updates"></a>Como a rolagem afeta as atualizações  
 Quando você [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) em um conjunto de registros, o buffer de edição é preenchido com cada novo registro atual (o registro anterior não é armazenado primeiro). Rolagem ignora sobre registros excluídos anteriormente. Se você rolar após um `AddNew` ou **editar** chamada sem chamar **atualização**, **CommitTrans**, ou **reversão** primeiro, as alterações são perdidas (sem nenhum aviso para você) como um novo registro é colocado no buffer de edição. O buffer de edição é preenchido com o registro rolado para o registro armazenado é liberado e não ocorre nenhuma alteração na fonte de dados. Isso se aplica a ambos `AddNew` e **editar**.  
  
##  <a name="_core_your_updates_and_the_updates_of_other_users"></a>As atualizações e as atualizações de outros usuários  
 Quando você usar um conjunto de registros para atualizar dados, as atualizações afetam outros usuários. Da mesma forma, as atualizações de outros usuários durante o tempo de vida do seu conjunto de registros afetá-lo.  
  
 Em um ambiente multiusuário, outros usuários podem abrir os conjuntos de registros que contêm alguns dos registros de mesmo que você selecionou no seu conjunto de registros. As alterações em um registro antes de recuperá-lo são refletidas em seu conjunto de registros. Como dynasets recuperam um registro de cada vez que você rola para ele, dynasets refletem as alterações sempre que você rolar para um registro. Instantâneos de recuperar um registro na primeira vez que você rola a ele, para que instantâneos refletem somente as alterações que ocorrem antes de você rolar para o registro inicialmente.  
  
 Registros adicionados por outros usuários depois que você abrir o conjunto de registros não aparecem em seu conjunto de registros, a menos que você repetir a consulta. Se o conjunto de registros é dynaset, modificações feitas por outros usuários, os registros existentes aparecerão na sua dynaset quando você rola para o registro afetado. Se o conjunto de registros é um instantâneo, edições não mostram até que você exige que o instantâneo. Se você quiser ver registros adicionados ou excluídos por outros usuários em seu instantâneo ou registros adicionados por outros usuários em sua dynaset, chame [CRecordset::Requery](../../mfc/reference/crecordset-class.md#requery) para recriar o conjunto de registros. (Observe que as exclusões de outros usuários aparecerão em seu dynaset.) Você também pode chamar **Requery** para ver os registros de adicionar, mas não para ver suas exclusões.  
  
> [!TIP]
>  Para forçar o cache de todo um instantâneo de uma vez, chamar `MoveLast` imediatamente depois de abrir o instantâneo. Em seguida, chame **MoveFirst** para começar a trabalhar com os registros. `MoveLast`é equivalente a rolagem em todos os registros, mas ele recupera uma só vez. No entanto, observe que isso pode reduzir o desempenho e não pode ser necessário para alguns drivers.  
  
 Os efeitos de suas atualizações em outros usuários são semelhantes aos seus efeitos em você.  
  
##  <a name="_core_more_about_update_and_delete"></a>Mais informações sobre atualização e exclusão  
 Esta seção fornece informações adicionais para ajudá-lo a trabalhar com **atualização** e **excluir**.  
  
### <a name="update-success-and-failure"></a>Atualização de êxito e falha  
 Se **atualização** for bem-sucedida, o `AddNew` ou **editar** modo termina. Para iniciar um `AddNew` ou **editar** modo novamente, chamada `AddNew` ou **editar**.  
  
 Se **atualização** falhar (retorna **FALSE** ou lança uma exceção), permanecem em `AddNew` ou **editar** modo, dependendo de qual função é chamado pela última. Você pode fazer o seguinte:  
  
-   Modificar um membro de dados do campo e tente a **atualização** novamente.  
  
-   Chamar `AddNew` para redefinir os membros de dados de campo para Null, defina os valores dos membros de dados de campo e, em seguida, chamar **atualização** novamente.  
  
-   Chamar **editar** para recarregar os valores que estavam no conjunto de registros antes da primeira chamada para `AddNew` ou **editar**, defina os valores dos membros de dados de campo e, em seguida, chamar **atualizar**novamente. Após um bem-sucedido **atualização** chamar (exceto após uma `AddNew` chamar), os membros de dados do campo retêm seus novos valores.  
  
-   Chamar **mover** (incluindo **mover** com um parâmetro de **AFX_MOVE_REFRESH**, ou 0), que libera quaisquer alterações e encerra qualquer `AddNew` ou **editar** modo em vigor.  
  
### <a name="update-and-delete"></a>Update e Delete  
 Esta seção se aplica a ambos **atualização** e **excluir**.  
  
 Em um **atualização** ou **excluir** operação, apenas um registro deve ser atualizado. Esse registro é o registro atual, que corresponde aos valores de dados nos campos do conjunto de registros. Se por alguma razão registros não são afetados ou mais de um registro é afetado, uma exceção será lançada que contém um dos seguintes **RETCODE** valores:  
  
-   **AFX_SQL_ERROR_NO_ROWS_AFFECTED**  
  
-   **AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED**  
  
 Quando essas exceções são lançadas, você permanecerá no `AddNew` ou **editar** estado que estava quando você chamou **atualização** ou **excluir**. Aqui estão os cenários mais comuns em que você vê essas exceções. Provavelmente você ver:  
  
-   **AFX_SQL_ERROR_NO_ROWS_AFFECTED** quando você estiver usando o modo de bloqueio otimista e outro usuário modificou o registro de uma maneira que impede a estrutura que identifica o registro correto para atualizar ou excluir.  
  
-   **AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED** quando a tabela que você está atualizando não tem nenhuma chave primária ou índice exclusivo e você não tem colunas suficientes no conjunto de registros para identificar exclusivamente uma linha da tabela.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)   
 [Registrar troca de campos (RFX)](../../data/odbc/record-field-exchange-rfx.md)   
 [SQL](../../data/odbc/sql.md)   
 [Exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md)