---
title: "_com_ptr_t::Release | Microsoft Docs"
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
  - "_com_ptr_t.Release"
  - "_com_ptr_t::Release"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método de liberação"
ms.assetid: db448b34-0efa-4f02-b701-ad1ca3ae6ca5
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_ptr_t::Release
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Chama a função de membro **Release** de **IUnknown** no ponteiro de interface encapsulado.  
  
## Sintaxe  
  
```  
  
void Release( );  
  
```  
  
## Comentários  
 Chama `IUnknown::Release` no ponteiro da interface encapsulado, gerando um erro `E_POINTER` se o ponteiro da interface for **NULL**.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_ptr\_t](../cpp/com-ptr-t-class.md)