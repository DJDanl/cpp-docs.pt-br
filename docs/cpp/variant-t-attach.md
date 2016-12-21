---
title: "_variant_t::Attach | Microsoft Docs"
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
  - "_variant_t::Attach"
  - "_variant_t.Attach"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Attach"
  - "objeto VARIANT"
  - "objeto VARIANT, anexar"
ms.assetid: 2f02bd08-2306-4477-aa88-d2a5dee2b859
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _variant_t::Attach
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Anexa um objeto **VARIANT** ao objeto `_variant_t`.  
  
## Sintaxe  
  
```  
  
      void Attach(  
   VARIANT& varSrc   
);  
```  
  
#### Parâmetros  
 *varSrc*  
 Um objeto **VARIANT** a ser anexado a esse objeto `_variant_t`.  
  
## Comentários  
 Assume a propriedade do objeto **VARIANT** encapsulando\-o.  Essa função de membro libera qualquer **VARIANT**encapsulado existente, copia o **VARIANT** fornecido e define seu **VARTYPE** como `VT_EMPTY` para garantir que seus recursos só possam ser liberados pelo destruidor `_variant_t`.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_variant\_t](../cpp/variant-t-class.md)