---
title: "Conjunto de registros: mais sobre atualiza&#231;&#245;es (ODBC) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ambientes multiusuário, atualizações para conjuntos de registros"
  - "conjunto de registros ODBC, atualizando"
  - "registros, atualizando"
  - "conjuntos de registros, atualizando"
  - "rolagem, atualizações para conjuntos de registros"
  - "transações, atualizando conjuntos de registros"
  - "atualizando conjuntos de registros"
ms.assetid: 0353a742-d226-4fe2-8881-a7daeffe86cd
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: mais sobre atualiza&#231;&#245;es (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica:  
  
-   [Como outras operações, como transações, atualizações do](#_core_how_transactions_affect_updates).  
  
-   [As atualizações e as de outros usuários](#_core_your_updates_and_the_updates_of_other_users).  
  
-   [Mais sobre as funções de membro de atualização e exclusão](#_core_more_about_update_and_delete).  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` no qual a busca de linhas do volume não foi implementado.  Se você implementar a linha em massa que pesquisa, algumas das informações não se aplica.  Por exemplo, você não pode chamar `AddNew`, **Editar**, **Excluir**, e as funções de membro de **Atualizar** ; porém, você pode executar transações.  Para obter mais informações sobre a linha em massa que pesquisa, consulte [Conjunto de registros: recuperando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
##  <a name="_core_how_other_operations_affect_updates"></a> Como outras atualizações de influência de operações  
 As atualizações são afetadas por transações em vigor no momento da atualização, fechando o conjunto de registros antes de concluir uma transação, e rolando antes de concluir uma transação.  
  
###  <a name="_core_how_transactions_affect_updates"></a> Como atualizações de influência de transações  
 Além de entender como `AddNew`, **Editar**, e o trabalho de **Excluir** , é importante entender como **BeginTrans**, **CommitTrans**, e as funções de membro de **Reverter** de [CDatabase](../../mfc/reference/cdatabase-class.md) funcionam com as funções de atualização de [CRecordset](../Topic/CRecordset%20Class.md).  
  
 Por padrão, as chamadas para `AddNew` e **Editar** afetam a fonte de dados imediatamente quando você chama **Atualizar**.  as chamadas de**Excluir** entram em vigor imediatamente.  Mas você pode estabelecer uma transação e executar um lote dessas chamadas.  As atualizações não são permanentes até que você confirme as.  Se você alterar ideia, você poderá reverter a transação em vez de confirme\-a.  
  
 Para obter mais informações sobre transações, consulte [Transação \(ODBC\)](../../data/odbc/transaction-odbc.md).  
  
###  <a name="_core_how_closing_the_recordset_affects_updates"></a> Como fechar o conjunto de registros afeta atualizações  
 Se você fechar um conjunto de registros, ou seu objeto associado de `CDatabase` , com uma transação em andamento \(não chamou [CDatabase::CommitTrans](../Topic/CDatabase::CommitTrans.md) ou [CDatabase::Rollback](../Topic/CDatabase::Rollback.md)\), a transação será revertida automaticamente \(a menos que a back\-end da base de dados é o mecanismo de base de dados do Microsoft Jet\).  
  
> [!CAUTION]
>  Se você estiver usando o mecanismo de base de dados do Microsoft Jet, fechar um conjunto de registros dentro de uma transação explícita não resulta em liberar qualquer das linhas que foram modificadas ou de bloqueios que foram enfileirados e esperarão até que a transação seja confirmada ou revertida.  É recomendável que você sempre abrir e fechar os conjuntos de registros internos ou fora de uma transação explícita do Jet.  
  
###  <a name="_core_how_scrolling_affects_updates"></a> Como rolar afeta atualizações  
 Quando você [Conjunto de registros: rolando \(ODBC\)](../Topic/Recordset:%20Scrolling%20\(ODBC\).md) em um conjunto de registros, o buffer de edição é preenchido com cada novo registro atual \(o registro anterior não está armazenado primeiro\).  Rolar ignora sobre os registros excluídos anteriormente.  Se você rolar após uma chamada de `AddNew` ou de **Editar** sem chamar **Atualizar**, **CommitTrans**, ou **Reverter** primeiro, todas as alterações serão perdidas \(sem um aviso ao\) como um registro novo é colocado no buffer de edição.  O buffer de edição é preenchido com o registro rolado, o registro armazenado é liberado, e nenhuma alteração ocorre na fonte de dados.  Isso se aplica a `AddNew` e a **Editar**.  
  
##  <a name="_core_your_updates_and_the_updates_of_other_users"></a> As atualizações e as atualizações de outros usuários  
 Quando você usa um conjunto de registros para atualizar dados, suas atualizações afetam outros usuários.  De maneira semelhante, as atualizações de outros usuários durante o tempo de vida do conjunto de registros afetam\-no.  
  
 Em um ambiente multiusuário, outros usuários podem abrir os conjuntos de registros que contêm alguns dos mesmos registros que você selecionou no conjunto de registros.  As alterações de um registro antes que você recupere o são refletidas no conjunto de registros.  Como os dynasets que recuperam um registro cada vez que você rolagem, os dynasets refletem alterações cada vez que você rolar um registro.  Os instantâneos recuperam um registro na primeira vez que você rolar, de forma que os instantâneos refletem somente as alterações que ocorrem antes que você rolar o registro inicialmente.  
  
 Os registros adicionados por outros usuários depois que você abre o conjunto de registros não aparecem no conjunto de registros a menos que você você consulte novamente.  Se o conjunto de registros é um dynaset, as edições a registros existentes por outros usuários aparecem no dynaset quando você percorrer o registro afetado.  Se o conjunto de registros é um instantâneo, as edições não aparecem até que você você consulte novamente o instantâneo.  Se você quiser ver os registros adicionados ou excluídos por outros usuários no instantâneo, ou os registros adicionados por outros usuários no dynaset, chame [CRecordset::Requery](../Topic/CRecordset::Requery.md) para recriar o conjunto de registros. \(Observe que as exclusões de outros usuários aparecem no dynaset.\) Você também pode chamar **Requery** para ver os registros que você adiciona, mas não ver suas exclusões.  
  
> [!TIP]
>  Para forçar imediatamente o cachê de um instantâneo inteiro, chame `MoveLast` imediatamente depois que você abre o instantâneo.  Chame **MoveFirst** para começar a trabalhar com os registros.  `MoveLast` é equivalente a navegação sobre todos os registros, mas fazer de uma vez.  Observe, entretanto, que isso pode reduzir o desempenho e não pode ser necessário para alguns drivers.  
  
 Os efeitos das atualizações em outros usuários são semelhantes a seus efeitos no.  
  
##  <a name="_core_more_about_update_and_delete"></a> Mais sobre a atualização e exclusão  
 Esta seção fornece informações adicionais para ajudá\-lo a trabalhar com **Atualizar** e **Excluir**.  
  
### Êxito e falha da atualização  
 Se **Atualizar** tiver êxito, o modo de `AddNew` ou de **Editar** termina.  Para reiniciar um modo de `AddNew` ou de **Editar** , chame `AddNew` ou **Editar**.  
  
 Se **Atualizar** falha \(retorna **Falso** ou lançar uma exceção\), você permanecerá em `AddNew` ou no modo de **Editar** , dependendo da função você chamou o último.  Você pode fazer o seguinte:  
  
-   Modificar um membro de dados do campo **Atualizar** e tente novamente.  
  
-   `AddNew` chame para redefinir os membros de dados do campo em branco, define os valores dos membros de dados do campo e, em seguida **Atualizar** novamente.  
  
-   Chame **Editar** para recarregar os valores avaliados no conjunto de registros antes da primeira chamada para `AddNew` ou a **Editar**, define os valores dos membros de dados do campo, e chamar **Atualizar** novamente.  Após uma chamada bem\-sucedida de **Atualizar** \(exceto depois que uma chamada de `AddNew` \), os membros de dados do campo retém os novos valores.  
  
-   Chame **Mover** \(que inclui **Mover** com um parâmetro de **AFX\_MOVE\_REFRESH**, ou 0\), que libera todas as alterações e termina qualquer modo de `AddNew` ou de **Editar** aplicado.  
  
### Atualização e exclusão  
 Esta seção é aplicada a **Atualizar** e a **Excluir**.  
  
 Em uma operação de **Atualizar** ou de **Excluir** , um e apenas um registros devem ser atualizados.  O registro é o registro atual, que corresponde aos valores de dados nos campos do conjunto de registros.  Se por alguma razão nenhum registro é afetado ou mais de um registro é afetado, será lançada uma exceção que contém um dos seguintes valores de **RETCODE** :  
  
-   **AFX\_SQL\_ERROR\_NO\_ROWS\_AFFECTED**  
  
-   **AFX\_SQL\_ERROR\_MULTIPLE\_ROWS\_AFFECTED**  
  
 Quando essas exceções são geradas, você permanecerá no estado de `AddNew` ou de **Editar** você estava quando você chamou **Atualizar** ou **Excluir**.  Aqui estão os cenários mais comuns em que você veria estas exceções.  Você provavelmente de consulte:  
  
-   **AFX\_SQL\_ERROR\_NO\_ROWS\_AFFECTED** quando você estiver usando o modo otimista de bloqueio e outro usuário alterou o registro de uma maneira que impedisse que a estrutura identifica o registro correto para atualizar ou excluir.  
  
-   **AFX\_SQL\_ERROR\_MULTIPLE\_ROWS\_AFFECTED** quando a tabela que você está atualizando não tem nenhum chave primária ou índice exclusivo e não têm colunas suficientes no conjunto de registros para identificar exclusivamente uma linha da tabela.  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: como conjuntos de registros selecionam registros \(ODBC\)](../Topic/Recordset:%20How%20Recordsets%20Select%20Records%20\(ODBC\).md)   
 [Registrar troca de campos \(RFX\)](../../data/odbc/record-field-exchange-rfx.md)   
 [SQL](../../data/odbc/sql.md)   
 [Exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md)