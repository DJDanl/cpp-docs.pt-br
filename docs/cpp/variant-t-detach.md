---
title: "_variant_t::Detach | Microsoft Docs"
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
  - "_variant_t::Detach"
  - "_variant_t.Detach"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Detach"
  - "objeto VARIANT"
  - "objeto VARIANT, desanexar"
ms.assetid: c348ac08-62cf-4657-a16f-974a79c12158
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _variant_t::Detach
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Desanexa o objeto **VARIANT** encapsulado deste objeto `_variant_t`.  
  
## Sintaxe  
  
```  
  
VARIANT Detach( );  
  
```  
  
## Valor de retorno  
 A **VARIANT**encapsulada.  
  
## Comentários  
 Extrai e retorna a **VARIANT**encapsulada e, em seguida, limpa esse objeto `_variant_t` sem destruí\-lo.  Essa função membro remove a **VARIANT** do encapsulamento e define **VARTYPE** deste objeto `_variant_t` como `VT_EMPTY`.  Cabe a você liberar a **VARIANT** retornada chamando a função [VariantClear](http://msdn.microsoft.com/pt-br/28741d81-8404-4f85-95d3-5c209ec13835).  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_variant\_t](../cpp/variant-t-class.md)