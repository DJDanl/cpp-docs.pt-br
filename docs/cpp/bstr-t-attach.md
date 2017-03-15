---
title: "_bstr_t::Attach | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_bstr_t::Attach"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Attach"
ms.assetid: 8cad867e-40fc-435b-841f-0d412c2f58d3
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _bstr_t::Attach
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Vincula um wrapper `_bstr_t` a um `BSTR`.  
  
## Sintaxe  
  
```  
  
      void Attach(  
   BSTR s  
);  
```  
  
#### Parâmetros  
 *s*  
 Um `BSTR` a ser associado ou atribuído à variável `_bstr_t`.  
  
## Comentários  
 Se o `_bstr_t` estava associado anteriormente a outro `BSTR`, o `_bstr_t` limpará o recurso `BSTR`, se nenhuma outra variável `_bstr_t` estiver usando o `BSTR`.  
  
## Exemplo  
 Consulte [\_bstr\_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo usando **Attach**.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_bstr\_t](../cpp/bstr-t-class.md)