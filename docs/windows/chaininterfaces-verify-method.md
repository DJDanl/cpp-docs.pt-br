---
title: "M&#233;todo ChainInterfaces::Verify | Microsoft Docs"
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
  - "implements/Microsoft::WRL::ChainInterfaces::Verify"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Verify"
ms.assetid: c591e130-8686-4130-ba69-1aaedc250038
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo ChainInterfaces::Verify
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Verifica se cada interface definida por `I0` parâmetros do modelo com `I9` herde IUnknown e\/ou de IInspectable, e que `I0` herda de `I1` com `I9`.  
  
## Sintaxe  
  
```  
WRL_NOTHROW __forceinline static void Verify();  
```  
  
## Comentários  
 Se a operação de verificação falhará, `static_assert` emite uma mensagem de erro que descreve a falha.  
  
## Comentários  
 Os parâmetros `I0` e `I1` de modelo são necessários, e os parâmetros `I2` com `I9` são opcionais.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)