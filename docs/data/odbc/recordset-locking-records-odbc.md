---
title: "Conjunto de registros: bloqueando registros (ODBC) | Microsoft Docs"
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
  - "dados [C++], locking"
  - "bloqueios [C++], conjuntos de registros"
  - "conjuntos de registros ODBC [C++], bloqueando registros"
  - "bloqueio otimista"
  - "bloqueio otimista, ODBC"
  - "bloqueio pessimista em ODBC"
  - "conjunto de registros [C++], bloqueando registros"
ms.assetid: 8fe8fcfe-b55a-41a8-9136-94a7cd1e4806
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: bloqueando registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica:  
  
-   [Os tipos de bloqueio de registro disponíveis](#_core_record.2d.locking_modes).  
  
-   [Como bloquear registros no conjunto de registros durante atualizações](#_core_locking_records_in_your_recordset).  
  
 Quando você usa um conjunto de registros para atualizar um registro na fonte de dados do, o aplicativo pode bloquear o registro para que nenhum outro usuário poderá atualizar o registro ao mesmo tempo.  O estado de um registro atualizado por dois usuários é o mesmo tempo indefinido a menos que o sistema possa garantir que dois usuários não podem atualizar um registro simultaneamente.  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` no qual a busca de linhas do volume não foi implementado.  Se você implementar a linha em massa que pesquisa, algumas das informações não se aplica.  Por exemplo, você não pode chamar funções de membro de **Editar** e de **Atualizar** .  Para obter mais informações sobre a linha em massa que pesquisa, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
##  <a name="_core_record.2d.locking_modes"></a> Modos de bloqueio interfaces  
 As classes base de dados de fornece dois [modos de bloqueio interfaces](../Topic/CRecordset::SetLockingMode.md):  
  
-   Bloqueio otimista \(padrão\)  
  
-   Bloqueio pessimista  
  
 Atualizar um registro ocorre em três etapas:  
  
1.  Você inicia a operação chamando a função de membro de [Edição](../Topic/CRecordset::Edit.md) .  
  
2.  Modifique os campos adequados do registro atual.  
  
3.  Você encerra a operação — e confirmar normalmente a atualização — chamando a função de membro de [Atualização](../Topic/CRecordset::Update.md) .  
  
 O bloqueio otimista bloqueia o registro na fonte de dados somente durante a chamada de **Atualizar** .  Se você usar o bloqueio otimista em um ambiente multiusuário, o aplicativo deve tratar uma condição de falha de **Atualizar** .  O bloqueio pessimista bloqueia o registro para que você chamar **Editar** e não o libera até que você chame **Atualizar** \(falhas são indicadas por meio do mecanismo de `CDBException` , não por um valor de **Falso** retornados por **Atualizar**\).  O bloqueio pessimista tem uma caneta de desempenho potencial para outros usuários, porque o acesso simultâneo ao mesmo registro pode ter que esperar até a conclusão do processo de **Atualizar** do seu aplicativo.  
  
##  <a name="_core_locking_records_in_your_recordset"></a> Bloqueando registros no conjunto de registros  
 Se você quiser alterar [modo de bloqueio](#_core_record.2d.locking_modes) de um objeto recordset da opção, você deve alterar o modo antes de chamar **Editar**.  
  
#### Para alterar o modo de bloqueio atual para o conjunto de registros  
  
1.  Chame a função de membro de [SetLockingMode](../Topic/CRecordset::SetLockingMode.md) , especificando **CRecordset::pessimistic** ou **CRecordset::optimistic**.  
  
 O novo modo de bloqueio permanece em vigor até que você o modifique novamente ou o conjunto de registros é fechado.  
  
> [!NOTE]
>  Relativamente poucos drivers ODBC oferecem suporte atualmente o bloqueio pessimista.  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: realizando uma junção \(ODBC\)](../Topic/Recordset:%20Performing%20a%20Join%20\(ODBC\).md)   
 [Conjunto de registros: adicionando, atualizando e excluindo registros \(ODBC\)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)