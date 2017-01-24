---
title: "Estrutura XFORM | Microsoft Docs"
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
  - "XFORM"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura XFORM"
ms.assetid: 4fb4ef5b-05d2-4884-82d1-1cb8f7be6302
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura XFORM
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `XFORM` tem o seguinte formato:  
  
## Sintaxe  
  
```  
  
      typedef struct  tagXFORM {  /* xfrm */  
    FLOAT eM11;  
    FLOAT eM12;  
    FLOAT eM21;  
    FLOAT eM22;  
    FLOAT eDx;  
    FLOAT eDy;  
} XFORM;  
```  
  
## Comentários  
 A estrutura de `XFORM` especifica uma transformação de página espaço de mundo\- espaço.  Os membros de **eDx** e de **eDy** especificam os componentes horizontais e verticais de tradução, respectivamente.  A tabela a seguir mostra como os outros membros são usados, dependendo da operação:  
  
|Operação|eM11|eM12|eM21|eM22|  
|--------------|----------|----------|----------|----------|  
|`Rotation`|Cosseno do ângulo de rotação|Seno do ângulo de rotação|Seno negativo do ângulo de rotação|Cosseno do ângulo de rotação|  
|**Aplicando escalas**|Componente na expansão horizontal|Nothing|Nothing|Componente na expansão vertical|  
|**Tesoura**|Nothing|Constante horizontal de proporcionalidade|Constante vertical de proporcionalidade|Nothing|  
|**Reflexão**|Componente horizontal de reflexão|Nothing|Nothing|Componente vertical de reflexão|  
  
## Requisitos  
 **Header:** wingdi.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRgn::CreateFromData](../Topic/CRgn::CreateFromData.md)