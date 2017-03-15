---
title: "M&#233;todo Implements::CanCastTo | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Implements::CanCastTo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CanCastTo"
ms.assetid: a8e85c7d-4dcd-446d-bebc-a97da46ce44a
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Implements::CanCastTo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém um ponteiro para a interface especificada.  
  
## Sintaxe  
  
```  
__forceinline HRESULT CanCastTo(  
   REFIID riid,  
   _Deref_out_ void **ppv  
);  
```  
  
#### Parâmetros  
 `riid`  
 Uma referência a uma ID de interface  
  
 `ppv`  
 Se tiver êxito, um ponteiro para a interface especificada por `riid`.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que indica o erro, como E\_NOINTERFACE.  
  
## Comentários  
 Essa é uma função interna de auxiliar que executa uma operação de QueryInterface.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Implementa estrutura](../Topic/Implements%20Structure.md)