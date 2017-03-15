---
title: "Operadores relacionais _variant_t | Microsoft Docs"
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
  - "_variant_t::operator=="
  - "_variant_t.operator!="
  - "_variant_t::operator!="
  - "_variant_t.operator=="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador !="
  - "Operador ==, com objetos Visual C++ específicos"
  - "Operador !=, operadores relacionais"
  - "Operador !=, variante"
  - "Operador ==, variante"
  - "operator!=, operadores relacionais"
  - "operator!=, variante"
  - "operator==, variante"
  - "operadores relacionais, Classe _variant_t"
ms.assetid: 141bacb8-41a2-44dd-b3c0-4ad1f884f4ea
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores relacionais _variant_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Compare dois objetos `_variant_t` em termos de igualdade ou desigualdade.  
  
## Sintaxe  
  
```  
  
      bool operator==(  
   const VARIANT& varSrc   
) const;  
bool operator==(  
   const VARIANT* pSrc   
) const;  
bool operator!=(  
   const VARIANT& varSrc   
) const;  
bool operator!=(  
   const VARIANT* pSrc   
) const;  
```  
  
#### Parâmetros  
 *varSrc*  
 Um **VARIANT** a ser comparado com o objeto `_variant_t`.  
  
 `pSrc`  
 Ponteiro para o **VARIANT** a ser comparado com o objeto `_variant_t`.  
  
## Valor de retorno  
 Retorna **true** se a comparação se mantiver; caso contrário,**false**.  
  
## Comentários  
 Compara um objeto `_variant_t` com **VARIANT**, testando a igualdade ou desigualdade.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_variant\_t](../cpp/variant-t-class.md)