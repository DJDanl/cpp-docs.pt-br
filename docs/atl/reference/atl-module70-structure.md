---
title: "Estrutura _ATL_MODULE70 | Microsoft Docs"
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
  - "_ATL_MODULE70"
  - "ATL::_ATL_MODULE70"
  - "ATL._ATL_MODULE70"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura _ATL_MODULE70"
  - "Estrutura ATL_MODULE70"
ms.assetid: b059b2c8-dfd1-4ac9-b07d-39df638cc7b3
caps.latest.revision: 16
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura _ATL_MODULE70
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Contém os dados usados por cada módulo de ATL.  
  
## Sintaxe  
  
```  
  
      struct _ATL_MODULE70{  
   UINT cbSize;  
   LONG m_nLockCnt;  
   _ATL_TERMFUNC_ELEM* m_pTermFuncs;  
   CComCriticalSection m_csStaticDataInitAndTypeInfo;  
};  
```  
  
## Membros  
 `cbSize`  
 O tamanho da estrutura, usado para o controle de versão.  
  
 `m_nLockCnt`  
 Fazer referência a contagem para determinar quanto tempo o módulo deve permanecer ativa.  
  
 **m\_pTermFuncs**  
 Controla as funções que foram registrados para serem chamados quando ATL finaliza.  
  
 **m\_csStaticDataInitAndTypeInfo**  
 Usado para coordenar acesso a dados internos em situações de vários segmentos.  
  
## Comentários  
 [\_ATL\_MODULE](../Topic/_ATL_MODULE.md) é definido como um typedef de `_ATL_MODULE70`.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)