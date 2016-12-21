---
title: "_pAtlModule | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATLBASE/_pAtlModule"
  - "_pAtlModule"
  - "ATL::_pAtlModule"
  - "ATL._pAtlModule"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Variável de _pAtlModule"
  - "variável de pAtlModule"
ms.assetid: 0ecde3a9-3f4d-4c7b-bb54-713ce05c4777
caps.latest.revision: 13
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _pAtlModule
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma variável global que armazena um ponteiro para o módulo atual.  
  
## Sintaxe  
  
```  
__declspec(selectany) CAtlModule * _pAtlModule  
```  
  
## Comentários  
 Os métodos em esta variável global podem ser usados para fornecer funcionalidade que a classe \(agora obsoleta\) [CComModule](../../atl/reference/ccommodule-class.md) fornecido no Visual C\+\+ 6,0.  
  
## Exemplo  
 [!code-cpp[NVC_ATL_Windowing#97](../../atl/codesnippet/CPP/patlmodule_1.cpp)]  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Variáveis globais](../Topic/ATL%20Global%20Variables.md)