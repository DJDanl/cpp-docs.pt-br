---
title: "_com_ptr_t::AddRef | Microsoft Docs"
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
  - "_com_ptr_t::AddRef"
  - "_com_ptr_t.AddRef"
  - "AddRef"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AddRef [C++], ponteiros de interface"
ms.assetid: c104dac3-aad3-40bb-a298-75c6cd0e63a2
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_ptr_t::AddRef
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Chama a função de membro `AddRef` de **IUnknown** no ponteiro de interface encapsulado.  
  
## Sintaxe  
  
```  
  
void AddRef( );  
  
```  
  
## Comentários  
 Chama `IUnknown::AddRef` no ponteiro da interface encapsulada, gerando um erro `E_POINTER` se o ponteiro for **NULL**.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_ptr\_t](../cpp/com-ptr-t-class.md)