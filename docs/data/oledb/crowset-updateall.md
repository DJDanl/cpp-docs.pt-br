---
title: "CRowset::UpdateAll | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CRowset::UpdateAll"
  - "ATL.CRowset.UpdateAll"
  - "CRowset<TAccessor>.UpdateAll"
  - "ATL.CRowset<TAccessor>.UpdateAll"
  - "UpdateAll"
  - "CRowset.UpdateAll"
  - "ATL::CRowset<TAccessor>::UpdateAll"
  - "CRowset<TAccessor>::UpdateAll"
  - "ATL::CRowset::UpdateAll"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método UpdateAll"
ms.assetid: e5b26c0a-40fc-4c91-a293-5084951788e6
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::UpdateAll
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Passa todas as alterações pendentes feitas em todas as linhas desde que o a última busca ou **Atualizar** a chamada.  
  
## Sintaxe  
  
```  
  
      HRESULT UpdateAll(   
   DBCOUNTITEM* pcRows = NULL,   
   HROW** pphRow = NULL,   
   DBROWSTATUS** ppStatus = NULL    
) throw( );  
```  
  
#### Parâmetros  
 `pcRows`  
 \[out\] ponteiro do local onde `UpdateAll` retorna o número de linhas que tentou atualizar, se necessário.  
  
 `pphRow`  
 \[out\] o ponteiro da memória na qual `UpdateAll` retorna a alça da linha ele tentou atualizar.  Nenhuma identificador é retornada se `pphRow` for nulo.  
  
 `ppStatus`  
 \[out\] ponteiro do local onde **Atualizar** retorna o valor de status de linha.  Nenhum status será retornado se `ppStatus` for nulo.  
  
## Comentários  
 Passa todas as alterações pendentes feitas em todas as linhas desde que as linhas foi buscado ou atualizado usando [Atualização](../Topic/CRowset::Update.md) ou `UpdateAll`.  `UpdateAll` atualizará cada linha que foi alterada, independentemente de se ainda tem o identificador para eles \(consulte `pphRow`\) ou não.  
  
 Por exemplo, se você usou **Inserir** para inserir cinco linhas em um conjunto de linhas, chame **Atualizar** cinco vezes `UpdateAll` ou chamar uma vez para todas atualizá\-las.  
  
 Esse método exige a interface opcional `IRowsetUpdate`, que pode não haver suporte em todos os provedores; nesse caso, o método retornará **E\_NOINTERFACE**.  Você também deve definir **DBPROP\_IRowsetUpdate** a `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [IRowsetUpdate::Update](https://msdn.microsoft.com/en-us/library/ms719709.aspx)   
 [CRowset::SetData](../../data/oledb/crowset-setdata.md)   
 [CRowset::Update](../Topic/CRowset::Update.md)