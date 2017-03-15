---
title: "Operador ComPtr::operator== | Microsoft Docs"
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
  - "client/Microsoft::WRL::ComPtr::operator=="
dev_langs: 
  - "C++"
ms.assetid: 6a26e936-29d4-4b7d-b44a-7c575ad07509
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador ComPtr::operator==
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica se dois objetos de ComPtr são iguais.  
  
## Sintaxe  
  
```cpp  
bool operator==(  
   const ComPtr<T>& a,  
   const ComPtr<U>& b  
);  
  
bool operator==(  
   const ComPtr<T>& a,  
   decltype(__nullptr)  
);  
  
bool operator==(  
   decltype(__nullptr),  
   const ComPtr<T>& a  
);  
  
```  
  
#### Parâmetros  
 `a`  
 Uma referência a um objeto de ComPtr.  
  
 `b`  
 Uma referência a outro objeto de ComPtr.  
  
## Valor de retorno  
 O primeiro operador produz `true` se o objeto for igual `a` objeto `b`; caso contrário, `false`.  
  
 O segundo e o terceiro operadores gerenciem `true` se o objeto `a` é igual a `nullptr`; caso contrário, `false`.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)   
 [Classe ComPtr](../windows/comptr-class.md)