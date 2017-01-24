---
title: "Estrutura _ATL_WIN_MODULE70 | Microsoft Docs"
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
  - "_ATL_WIN_MODULE70"
  - "ATL::_ATL_WIN_MODULE70"
  - "ATL._ATL_WIN_MODULE70"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura _ATL_WIN_MODULE70"
  - "Estrutura ATL_WIN_MODULE70"
ms.assetid: a0aaf3ea-ca77-46ec-bd53-4dfb61dffbea
caps.latest.revision: 15
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura _ATL_WIN_MODULE70
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado pelo código na janela em ATL.  
  
## Sintaxe  
  
```  
  
      struct _ATL_WIN_MODULE70{  
   UNIT cbSize;  
   CRITICAL_SECTION m_csWindowCreate;  
   _AtlCreateWndData* m_pCreateWndList;  
   CSimpleArray<ATOM> m_rgWindowClassAtoms;  
};  
```  
  
## Membros  
 `cbSize`  
 O tamanho da estrutura, usado para o controle de versão.  
  
 `m_csWindowCreate`  
 Usado para serializar acesso ao código de registro da janela.  Usado internamente por ATL.  
  
 **m\_pCreateWndList**  
 Usado para associar o windows em seus objetos.  Usado internamente por ATL.  
  
 **m\_rgWindowClassAtoms**  
 Usado para controlar registros da classe da janela de modo que eles possam ser corretamente desregistrado na finalização.  Usado internamente por ATL.  
  
## Comentários  
 [\_ATL\_WIN\_MODULE](../Topic/_ATL_WIN_MODULE.md) é definido como um typedef de `_ATL_WIN_MODULE70`.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)