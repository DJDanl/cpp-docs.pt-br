---
title: "Operador ComPtrRef::operator!= | Microsoft Docs"
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
  - "client/Microsoft::WRL::Details::ComPtrRef::operator!="
dev_langs: 
  - "C++"
ms.assetid: ab3093cc-6fbd-4039-890a-6df1cde992b6
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador ComPtrRef::operator!=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```cpp  
  
bool operator!=(  
   const Details::ComPtrRef<ComPtr<T>>& a,  
   const Details::ComPtrRef<ComPtr<U>>& b  
);  
  
bool operator!=(  
   const Details::ComPtrRef<ComPtr<T>>& a,  
   decltype(__nullptr)  
);  
  
bool operator!=(  
   decltype(__nullptr),  
   const Details::ComPtrRef<ComPtr<T>>& a  
);  
  
bool operator!=(  
   const Details::ComPtrRef<ComPtr<T>>& a,  
   void* b  
);  
  
bool operator!=(  
   void* b,  
   const Details::ComPtrRef<ComPtr<T>>& a  
);  
```  
  
#### Parâmetros  
 `a`  
 Uma referência a um objeto de ComPtrRef.  
  
 `b`  
 Uma referência a outro objeto de ComPtrRef, ou um ponteiro para um objeto`void*`anônima \(\).  
  
## Valor de retorno  
 O primeiro operador produz `true` se o objeto não é igual `a` objeto `b`; caso contrário, `false`.  
  
 O segundo e o terceiro operadores gerenciem `true` se o objeto `a` não é igual a `nullptr`; caso contrário, `false`.  
  
 O quarto e o quinto operadores gerenciem `true` se o objeto não é igual `a` objeto `b`; caso contrário, `false`.  
  
## Comentários  
 Indica se dois objetos de ComPtrRef não são iguais.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)   
 [Classe ComPtrRef](../Topic/ComPtrRef%20Class.md)