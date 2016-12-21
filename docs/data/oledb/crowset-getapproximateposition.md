---
title: "CRowset::GetApproximatePosition | Microsoft Docs"
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
  - "ATL::CRowset::GetApproximatePosition"
  - "ATL::CRowset<TAccessor>::GetApproximatePosition"
  - "CRowset.GetApproximatePosition"
  - "CRowset::GetApproximatePosition"
  - "GetApproximatePosition"
  - "ATL.CRowset.GetApproximatePosition"
  - "CRowset<TAccessor>::GetApproximatePosition"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetApproximatePosition"
ms.assetid: 8f9ccd41-0590-468e-b202-6731d0f99d21
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::GetApproximatePosition
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna a posição aproximada de uma linha que corresponde a um medidor.  
  
## Sintaxe  
  
```  
  
      HRESULT GetApproximatePosition(   
   const CBookmarkBase* pBookmark,   
   DBCOUNTITEM* pPosition,   
   DBCOUNTITEM* pcRows    
) throw( );  
```  
  
#### Parâmetros  
 `pBookmark`  
 \[in\] ponteiro de medidor a um que identifica a linha cuja posição deve ser encontrada.  **nulo** se apenas a contagem de linhas é necessária.  
  
 *pPosition*  
 \[out\] ponteiro do local onde `GetApproximatePosition` retorna a posição da linha.  **nulo** se a posição não é necessária.  
  
 `pcRows`  
 \[out\] ponteiro do local onde `GetApproximatePosition` retorna o número total de linhas.  **nulo** se a contagem de linhas não é necessária.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Esse método exige a interface opcional `IRowsetScroll`, que pode não haver suporte em todos os provedores; nesse caso, o método retornará **E\_NOINTERFACE**.  Você também deve definir **DBPROP\_IRowsetScroll** a `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas.  
  
 Para obter informações sobre como usar o marca um endereço da Internet\) dos consumidores, consulte [Usando indicadores](../../data/oledb/using-bookmarks.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [IRowsetScroll::GetApproximatePosition](https://msdn.microsoft.com/en-us/library/ms712901.aspx)