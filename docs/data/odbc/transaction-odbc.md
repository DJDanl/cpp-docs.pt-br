---
title: "Transa&#231;&#227;o (ODBC) | Microsoft Docs"
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
  - "bancos de dados [C++], transações"
  - "ODBC [C++], transações"
  - "conjuntos de registros ODBC [C++], transações"
  - "conjuntos de registros ODBC [C++], atualizando"
  - "conjunto de registros [C++], transações"
  - "conjunto de registros [C++], atualizando"
  - "transações [C++], Classes MFC ODBC"
ms.assetid: a2ec0995-2029-45f2-8092-6efd6f2a77f4
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Transa&#231;&#227;o (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Uma transação é uma maneira de clustering, ou o lote, uma série de atualizações a [fonte de dados](../../data/odbc/data-source-odbc.md) de modo que todos foram confirmados imediatamente ou nenhuma são confirmados se você reverte a transação.  Se você não usar uma transação, as alterações da fonte de dados serão confirmadas automaticamente em vez de ser sob demanda confirmada.  
  
> [!NOTE]
>  Nem todos os drivers da base de dados ODBC oferecem suporte a transações.  Chame a função de membro de `CanTransact` do objeto de [CDatabase](../../mfc/reference/cdatabase-class.md) ou de [CRecordset](../Topic/CRecordset%20Class.md) para determinar se o driver suporta transações de um base de dados determinado.  Observe que `CanTransact` não informa se a fonte de dados oferece suporte completo da transação.  Você também deve chamar `CDatabase::GetCursorCommitBehavior` e `CDatabase::GetCursorRollbackBehavior` depois de **CommitTrans** e **Reverter** para verificar o efeito da transação no objeto aberto de `CRecordset` .  
  
 As chamadas a funções de membro de `AddNew` e de **Editar** de um objeto de `CRecordset` afetam a fonte de dados imediatamente quando você chama **Atualizar**.  as chamadas de**Excluir** também entram em vigor imediatamente.  Em contraste, você pode usar chamadas que consiste de uma transação vários a `AddNew`, a **Editar**, a **Atualizar**, e a **Excluir**, que são executados mas não confirmadas até que você chame **CommitTrans** explicitamente.  Estabelecendo uma transação, você pode executar uma série dessas chamadas para reter a capacidade de rolá\-los posteriores.  Se um recurso importante estiver indisponível ou alguma outra condição evitar que toda a transação seja concluída, você poderá reverter a transação em vez de confirme\-a.  Nesse caso, nenhuma das mudanças pertencentes à influência de transação a fonte de dados.  
  
> [!NOTE]
>  Atualmente, a classe `CRecordset` não oferece suporte a atualizações à fonte de dados se você tiver implementado buscar em massa de linha.  Isso significa que você não pode fazer chamadas a `AddNew`, a **Editar**, a **Excluir**, ou a **Atualizar**.  Porém, você pode gravar possui funções para executar atualizações e para chamar essas funções dentro de uma determinada transação.  Para obter mais informações sobre a linha em massa que pesquisa, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
> [!NOTE]
>  Além de afetar seu conjunto de registros, as transações afetam instruções SQL executadas diretamente desde que você use ODBC **HDBC** associado ao objeto de `CDatabase` ou ODBC **HSTMT** baseado nesse **HDBC**.  
  
 As transações são particularmente úteis quando você tem vários registros que devem ser atualizados ao mesmo tempo.  Nesse caso, você quiser evitar uma transação meia concluída, como poderá acontecer se uma exceção foi gerada antes da última atualização esteve feita.  Agrupar essas atualizações em uma transação permite uma recuperação \(reversão\) de alterações e retorna que os registros ao pretransaction indicam.  Por exemplo, se uma das transferências monetárias bancárias de conta Para explicar B, a remover da e o depósito a B deve ter êxito para processar corretamente os fundos ou a transação inteira deve falhar.  
  
 Nas classes da base de dados, você executa transações em objetos de `CDatabase` .  Um objeto de `CDatabase` representa uma conexão a uma fonte de dados, e um ou mais conjuntos de registros associadas a esse objeto de `CDatabase` funcionam em tabelas de base de dados com as funções de membro do conjunto de registros.  
  
> [!NOTE]
>  Só um nível de transações tem suporte.  Não é possível aninhar transações ou não puder objetos base de dados de um múltiplo de período da transação.  
  
 Os tópicos a seguir fornecem mais informações sobre como as transações são executadas:  
  
-   [Transação: Executando uma transação em um conjunto de registros \(ODBC\)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md)  
  
-   [Transação: Como atualizações de influência de transações \(ODBC\)](../../data/odbc/transaction-how-transactions-affect-updates-odbc.md)  
  
## Consulte também  
 [Conectividade de banco de dados aberto \(ODBC\)](../Topic/Open%20Database%20Connectivity%20\(ODBC\).md)