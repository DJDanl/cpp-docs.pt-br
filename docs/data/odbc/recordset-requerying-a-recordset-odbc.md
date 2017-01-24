---
title: "Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC) | Microsoft Docs"
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
  - "conjunto de registros ODBC, consultando"
  - "conjuntos de registros, consultando"
  - "atualizando conjuntos de registros"
  - "Método Requery"
  - "consultando conjuntos de registros novamente"
ms.assetid: 4ebc3b5b-5b91-4f51-a967-245223c6b8e1
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica como usar um objeto que você consulte novamente \(ou seja, atualizar\) próprio recordset da base de dados do e quando você pode querer fazer isso com a função de membro de [Você consulte novamente](../Topic/CRecordset::Requery.md) .  
  
 As principais razões para consultar um conjunto de registros são:  
  
-   Coloque o conjunto de registros atualizado com relação aos registros adicionados por você ou por outros usuários e registros excluídos por outros usuários \(os que você exclui são refletidas no conjunto de registros\).  
  
-   Atualizar o conjunto de registros com base em alterações em valores de parâmetro.  
  
##  <a name="_core_bringing_the_recordset_up_to_date"></a> Trazendo o conjunto de registros atualizado  
 Frequentemente, você desejará que você consulte novamente o objeto do conjunto de registros para colocá\-lo atualizado.  Em um ambiente de base de dados multiusuário, outros usuários podem fazer modificações aos dados durante a vida do conjunto de registros.  Para obter mais informações sobre quando o conjunto de registros reflete as alterações feitas por outros usuários e quando os conjuntos de registros de outros usuários refletem as alterações, consulte [Conjunto de registros: Como registros de atualização dos conjuntos de registros \(ODBC\)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) e [Dynaset](../../data/odbc/dynaset.md).  
  
##  <a name="_core_requerying_based_on_new_parameters"></a> A nova consulta com base em novos parâmetros  
 Outro — e — igualmente importante uso frequente de [Você consulte novamente](../Topic/CRecordset::Requery.md) é selecionar um novo conjunto de registros com base em alterações em valores de parâmetro.  
  
> [!TIP]
>  A velocidade de consulta provavelmente é significativamente mais rápida se você chamar com **Requery** alterar valores de parâmetro do que se você chamar **Abrir** novamente.  
  
##  <a name="_core_requerying_dynasets_vs.._snapshots"></a> Consultar Dynasets em instantâneos  
 Como os dynasets são significados apresentar um conjunto de registros com dados atualizados dinâmicos, você deseja carregar dynasets de você consulte novamente com frequência para refletir as adições de outros usuários.  Os instantâneos, por outro lado, são úteis porque você pode seguramente confiar no seu conteúdo estático ao preparar relatórios, calcular totais, e assim por diante.  Ainda, você pode querer às vezes que você consulte novamente um instantâneo também.  Em um ambiente multiusuário, os dados de instantâneo podem perder a sincronização com a fonte de dados como outros usuários alterem o base de dados.  
  
#### Que você consulte novamente um objeto do conjunto de registros  
  
1.  Chame a função de membro de [Você consulte novamente](../Topic/CRecordset::Requery.md) do objeto.  
  
 Como alternativa, você pode fechar e reabrir o conjunto de registros original.  Em ambos os casos, o novo conjunto de registros representa o estado atual da fonte de dados.  
  
 Para obter um exemplo, consulte [Exibições do registro: Preenchendo uma caixa de listagem de um segundo conjunto de registros](../../data/filling-a-list-box-from-a-second-recordset-mfc-data-access.md).  
  
> [!TIP]
>  Para otimizar o desempenho de **Requery** , evite alterar [filtro](../../data/odbc/recordset-filtering-records-odbc.md) ou [tipo](../../data/odbc/recordset-sorting-records-odbc.md)conjunto de registros.  Modificando apenas o valor de parâmetro antes de chamar **Requery**.  
  
 Se a chamada de **Requery** falhar, você pode repetir a chamada; se não, seu aplicativo deve terminar normalmente.  Uma chamada para **Requery** ou a **Abrir** pode falhar por qualquer um de vários motivos.  Talvez um erro de rede ocorre; ou, durante a chamada, depois que os dados existentes são liberados mas antes que novos dados são obtidos, outro usuário pode obter acesso exclusivo; a tabela ou do seu conjunto de registros depende pôde ser excluída.  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: associando dinamicamente colunas de dados \(ODBC\)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)   
 [Conjunto de registros: criando e fechando conjuntos de registros \(ODBC\)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md)