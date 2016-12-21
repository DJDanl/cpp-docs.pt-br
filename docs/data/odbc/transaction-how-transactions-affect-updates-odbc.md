---
title: "Transa&#231;&#227;o: como as transa&#231;&#245;es afetam atualiza&#231;&#245;es (ODBC) | Microsoft Docs"
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
  - "Método CommitTrans"
  - "conjunto de registros ODBC, transações"
  - "Método Rollback, transações ODBC"
  - "transações, revertendo"
  - "transações, atualizando conjuntos de registros"
ms.assetid: 9e00bbf4-e9fb-4332-87fc-ec8ac61b3f68
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Transa&#231;&#227;o: como as transa&#231;&#245;es afetam atualiza&#231;&#245;es (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As atualizações a [fonte de dados](../../data/odbc/data-source-odbc.md) são gerenciadas durante transações com o uso de um buffer edition \(o mesmo método usado fora das transações\).  Os membros de dados do campo de um conjunto de registros servem coletivamente como um buffer da edição do que contém o registro atual, que o conjunto de registros faz backup temporariamente durante `AddNew` ou **Editar**.  Durante uma operação de **Excluir** , o registro atual não é feito backup em uma transação.  Para obter mais informações sobre o buffer de edição e como as atualizações armazena o registro atual, consulte [Conjunto de registros: Como registros de atualização dos conjuntos de registros \(ODBC\)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).  
  
> [!NOTE]
>  Se você implementar a linha em massa que pesquisa, você não pode chamar `AddNew`, **Editar**, ou **Excluir**.  Você deve em vez de escrever suas próprias funções para executar atualizações à fonte de dados.  Para obter mais informações sobre a linha em massa que pesquisa, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Transações pendentes, `AddNew`, **Editar**, e as operações de **Excluir** pode ser confirmada ou revertida.  Os efeitos de **CommitTrans** e de **Reverter** podem causar o registro atual a não ser restaurado ao buffer de edição.  Para verificar se o registro atual é restaurado corretamente, é importante compreender como as funções de membro de **CommitTrans** e de **Reverter** de `CDatabase` funcionam com as funções de atualização de `CRecordset`.  
  
##  <a name="_core_how_committrans_affects_updates"></a> Como CommitTrans afeta atualizações  
 A tabela a seguir explica os efeitos de **CommitTrans** em transações.  
  
### Como CommitTrans afeta atualizações  
  
|Operação|Status da fonte de dados|  
|--------------|------------------------------|  
|`AddNew` e **Atualizar**e, em seguida **CommitTrans**|O registro novo é adicionado à fonte de dados.|  
|`AddNew` \(sem **Atualizar**\) e, em seguida **CommitTrans**|O registro novo é perdido.  Registro não adicionado à fonte de dados.|  
|**Editar** e **Atualizar**e, em seguida **CommitTrans**|Edições confirmadas na fonte de dados.|  
|**Editar** \(sem **Atualizar**\) e, em seguida **CommitTrans**|As edições do registro serão perdidas.  O registro permanece inalterado na fonte de dados.|  
|**Excluir** em **CommitTrans**|Registros excluídos da fonte de dados.|  
  
##  <a name="_core_how_rollback_affects_updates"></a> Como a reversão afeta transações  
 A tabela a seguir explica os efeitos de **Reverter** em transações.  
  
### Como a reversão afeta transações  
  
|Operação|Status do registro atual|Você também deve|Status da fonte de dados|  
|--------------|------------------------------|----------------------|------------------------------|  
|`AddNew` **Atualizar**e, em seguida **Reverter**|O conteúdo do registro atual são armazenados temporariamente para liberar espaço para o novo registro.  O registro novo é inserido no buffer de edição.  Depois que **Atualizar** é chamado, o registro atual é restaurado ao buffer de edição.||A adição à fonte de dados feita por **Atualizar** é invertida.|  
|`AddNew` \(sem **Atualizar**\), em **Reverter**|O conteúdo do registro atual são armazenados temporariamente para liberar espaço para o novo registro.  O buffer de edição contém o novo registro.|Chame `AddNew` novamente para restaurar o buffer a uma vazia, novo registro de edição.  Ou chamada **Mover**\(0\) para restaurar os valores antigos para o buffer de edição.|Como **Atualizar** não foi chamado, não havia nenhuma alteração feita na fonte de dados.|  
|**Editar Atualizar**e, em seguida **Reverter**|Uma versão não editada do registro atual são armazenados temporariamente.  As edições serão feitas ao conteúdo do buffer de edição.  Depois que **Atualizar** é chamado, a versão não editada do registro estiver armazenada ainda temporariamente.|*Dynaset*: Role fora do registro atual volta para a restauração a versão não editada registro do buffer de edição.<br /><br /> *Instantâneo*: Chame **Requery** para atualizar o conjunto de registros na fonte de dados.|As alterações na fonte de dados feita por **Atualizar** são revertidas.|  
|**Editar** \(sem **Atualizar**\), em **Reverter**|Uma versão não editada do registro atual são armazenados temporariamente.  As edições serão feitas ao conteúdo do buffer de edição.|Chame **Editar** novamente para restaurar a versão não editada do registro ao buffer de edição.|Como **Atualizar** não foi chamado, não havia nenhuma alteração feita na fonte de dados.|  
|**Excluir** em **Reverter**|O conteúdo do registro atual é excluído.|Chame **Requery** para restaurar o conteúdo do registro atual da fonte de dados.|A exclusão de dados da fonte de dados é invertida.|  
  
## Consulte também  
 [Transação \(ODBC\)](../../data/odbc/transaction-odbc.md)   
 [Transação \(ODBC\)](../../data/odbc/transaction-odbc.md)   
 [Transação: realizando uma transação em um conjunto de registros \(ODBC\)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md)   
 [Classe de CDatabase](../../mfc/reference/cdatabase-class.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)