---
title: "Estrutura _ATL_COM_MODULE70 | Microsoft Docs"
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
  - "ATL::_ATL_COM_MODULE70"
  - "ATL._ATL_COM_MODULE70"
  - "_ATL_COM_MODULE70"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura _ATL_COM_MODULE70"
  - "Estrutura ATL_COM_MODULE70"
ms.assetid: 5b0b2fd0-bdeb-4c7e-8870-78fa69ace6e6
caps.latest.revision: 15
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura _ATL_COM_MODULE70
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado pelo código COM\- relacionadas em ATL.  
  
## Sintaxe  
  
```  
  
      struct _ATL_COM_MODULE70{  
   UINT cbSize;  
   HINSTANCE m_hInstTypeLib;  
   _ATL_OBJMAP_ENTRY** m_ppAutoObjMapFirst;  
   _ATL_OBJMAP_ENTRY** m_ppAutoObjMapLast;  
   CRITICAL_SECTION m_csObjMap;  
};  
```  
  
## Membros  
 `cbSize`  
 O tamanho da estrutura, usado para o controle de versão.  
  
 `m_hInstTypeLib`  
 A instância de identificador para a biblioteca de tipos para este módulo.  
  
 **m\_ppAutoObjMapFirst**  
 Endereço do elemento da matriz que indica o início de entradas de mapa do objeto para este módulo.  
  
 **m\_ppAutoObjMapLast**  
 Endereço do elemento da matriz que indica o fim de entradas de mapa do objeto para este módulo.  
  
 `m_csObjMap`  
 Seção crítica para serializar o acesso às entradas de mapa do objeto.  Usado internamente por ATL.  
  
## Comentários  
 [\_ATL\_COM\_MODULE](../Topic/_ATL_COM_MODULE.md) é definido como um typedef de `_ATL_COM_MODULE70`.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)