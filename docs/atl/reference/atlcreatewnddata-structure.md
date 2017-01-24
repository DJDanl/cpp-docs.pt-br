---
title: "Estrutura de _AtlCreateWndData | Microsoft Docs"
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
  - "ATL::_AtlCreateWndData"
  - "ATL._AtlCreateWndData"
  - "_AtlCreateWndData"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura de _AtlCreateWndData"
  - "Estrutura de AtlCreateWndData"
ms.assetid: 76ed5382-bfbf-4b8b-8a29-912688dfd2ae
caps.latest.revision: 15
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura de _AtlCreateWndData
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa estrutura contém dados de instância da classe no código na janela em ATL.  
  
## Sintaxe  
  
```  
  
      struct _AtlCreateWndData{  
   void* m_pThis;  
   DWORD m_dwThreadID;  
   _AtlCreateWndData* m_pNext;  
};  
```  
  
## Membros  
 **m\_pThis**  
 O ponteiro de **this** usado para obter acesso à instância de classe nos procedimentos da janela.  
  
 `m_dwThreadID`  
 A identificação de O segmento de instância da classe atual.  
  
 **m\_pNext**  
 Ponteiro para o próximo objeto de `_AtlCreateWndData` .  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)