---
title: "Construtor WeakRef::WeakRef | Microsoft Docs"
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
  - "client/Microsoft::WRL::WeakRef::WeakRef"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "WeakRef, o construtor"
ms.assetid: 589f87e0-8dcc-4e82-aab2-f2f66f1ec47c
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Construtor WeakRef::WeakRef
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa uma nova instância da classe de WeakRef.  
  
## Sintaxe  
  
```  
WeakRef();  
WeakRef(  
   decltype(__nullptr)  
);  
  
WeakRef(  
   _In_opt_ IWeakReference* ptr  
);  
  
WeakRef(  
   const ComPtr<IWeakReference>& ptr  
);  
  
WeakRef(  
   const WeakRef& ptr  
);  
  
WeakRef(  
   _Inout_ WeakRef&& ptr  
);  
```  
  
#### Parâmetros  
 `ptr`  
 Um ponteiro, uma referência rvalue\-, ou uma referência a um objeto existente que inicializa o objeto atual de WeakRef.  
  
## Comentários  
 O primeiro construtor inicializa um objeto vazio de WeakRef.  O segundo construtor inicializa um objeto de WeakRef de um ponteiro para a interface de IWeakReference.  O terceiro construtor inicializa um objeto de WeakRef de uma referência a um objeto\< de ComPtr\> IWeakReference.  O quarto e o quinto construtores inicializar um objeto de WeakRef de outro objeto de WeakRef.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)