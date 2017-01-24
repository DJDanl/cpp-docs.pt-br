---
title: "Operador ComPtr::operator= | Microsoft Docs"
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
  - "client/Microsoft::WRL::ComPtr::operator="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador operator="
ms.assetid: 1a0c2752-f7d8-4819-9443-07b88b69ef02
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador ComPtr::operator=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Atribui um valor a ComPtr atual.  
  
## Sintaxe  
  
```  
WRL_NOTHROW ComPtr& operator=(  
   decltype(__nullptr)  
);  
WRL_NOTHROW ComPtr& operator=(  
   _In_opt_ T *other  
);  
template <  
   typename U  
>  
WRL_NOTHROW ComPtr& operator=(  
   _In_opt_ U *other  
);  
WRL_NOTHROW ComPtr& operator=(  
   const ComPtr &other  
);  
template<  
   class U  
>  
WRL_NOTHROW ComPtr& operator=(  
   const ComPtr<U>& other  
);  
WRL_NOTHROW ComPtr& operator=(  
   _Inout_ ComPtr &&other  
);  
template<  
   class U  
>  
WRL_NOTHROW ComPtr& operator=(  
   _Inout_ ComPtr<U>&& other  
);  
```  
  
#### Parâmetros  
 `U`  
 Uma classe.  
  
 `other`  
 Um ponteiro, uma referência, ou uma referência de rvalue a um tipo ou a outro ComPtr.  
  
## Valor de retorno  
 Uma referência ao ComPtr atual.  
  
## Comentários  
 A primeira versão desse operador atribui um valor vazio a ComPtr atual.  
  
 Na segunda versão, se o ponteiro de interface de atribuição não é o mesmo que o ponteiro atual da interface de ComPtr, o segundo ponteiro de interface é atribuído ao ComPtr atual.  
  
 Na terceira versão, o ponteiro de interface de atribuição será atribuído ao ComPtr atual.  
  
 Na quarta versão, se o ponteiro da interface de atribuição de valor não é o mesmo que o ponteiro atual da interface de ComPtr, o segundo ponteiro de interface é atribuído ao ComPtr atual.  
  
 A quinta versão é um operador de cópia; uma referência a um ComPtr é atribuída ao ComPtr atual.  
  
 A sexta versão é um operador de cópia que usa a semântica de movimentação; uma referência de rvalue a um ComPtr se qualquer tipo estático é convertida e atribuída ao ComPtr atual.  
  
 A sétima versão é um operador de cópia que usa a semântica de movimentação; uma referência de rvalue a um ComPtr de tipo estático `U` é convertida em e atribuída ao ComPtr atual.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)