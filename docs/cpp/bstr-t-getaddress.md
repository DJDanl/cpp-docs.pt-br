---
title: "_bstr_t::GetAddress | Microsoft Docs"
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
  - "_bstr_t::GetAddress"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetAddress"
ms.assetid: 09bc9180-867e-4ee5-b22a-8339dc663142
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _bstr_t::GetAddress
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Libera qualquer cadeia de caracteres existente e retorna o endereço de uma cadeia de caracteres recém\-alocada.  
  
## Sintaxe  
  
```  
  
BSTR* GetAddress( );  
  
```  
  
## Valor de retorno  
 Um ponteiro para o `BSTR` encapsulado por `_bstr_t`.  
  
## Comentários  
 `GetAddress` afeta todos os objetos `_bstr_t` que compartilham um `BSTR`.  Mais de um `_bstr_t` pode compartilhar um `BSTR` com o uso do construtor de cópia e de `operator=`.  
  
## Exemplo  
 Consulte [\_bstr\_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo do uso de `GetAddress`.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_bstr\_t](../cpp/bstr-t-class.md)