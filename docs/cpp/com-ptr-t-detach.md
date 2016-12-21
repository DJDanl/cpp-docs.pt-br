---
title: "_com_ptr_t::Detach | Microsoft Docs"
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
  - "_com_ptr_t::Detach"
  - "_com_ptr_t.Detach"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Detach"
ms.assetid: 0652053e-af37-44e9-a278-2522212ebfed
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_ptr_t::Detach
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Extrai e retorna o ponteiro de interface encapsulado.  
  
## Sintaxe  
  
```  
  
Interface* Detach( ) throw( );  
  
```  
  
## Comentários  
 Extrai e retorna o ponteiro de interface encapsulado, e depois limpa o armazenamento de ponteiro encapsulado para **NULL**.  Isso remove o ponteiro de interface do encapsulamento.  Cabe a você chamar **Release** no ponteiro de interface retornado.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_ptr\_t](../cpp/com-ptr-t-class.md)