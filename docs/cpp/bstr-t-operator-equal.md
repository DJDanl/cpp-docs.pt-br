---
title: "_bstr_t::operator = | Microsoft Docs"
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
  - "_bstr_t::operator="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador =, com objetos Visual C++ específicos"
  - "Operador =, bstr"
  - "operator=, bstr"
ms.assetid: fb31bb1b-ce29-4388-b5fd-8dac830cf18a
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _bstr_t::operator =
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Atribui um novo valor a um objeto `_bstr_t` existente.  
  
## Sintaxe  
  
```  
  
      _bstr_t& operator=(  
   const _bstr_t& s1   
) throw ( );  
_bstr_t& operator=(  
   const char* s2   
);  
_bstr_t& operator=(  
   const wchar_t* s3   
);  
_bstr_t& operator=(  
   const _variant_t& var   
);  
```  
  
#### Parâmetros  
 *s1*  
 Um objeto `_bstr_t` a ser atribuído a um objeto existente `_bstr_t`.  
  
 *s2*  
 Uma cadeia de caracteres multibyte a ser atribuída a um objeto `_bstr_t` existente.  
  
 `s3`  
 Uma cadeia de caracteres Unicode a ser atribuída a um objeto `_bstr_t` existente.  
  
 `var`  
 Um objeto `_variant_t` a ser atribuído a um objeto existente `_bstr_t`.  
  
 **FIM de Específico da Microsoft**  
  
## Exemplo  
 Consulte [\_bstr\_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo de uso de `operator=`.  
  
## Consulte também  
 [Classe \_bstr\_t](../cpp/bstr-t-class.md)