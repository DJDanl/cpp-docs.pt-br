---
title: "Construtor ComPtr::ComPtr | Microsoft Docs"
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
  - "client/Microsoft::WRL::ComPtr::ComPtr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ComPtr, o construtor"
ms.assetid: eaf70907-beac-458f-a503-2e5e27b0c196
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Construtor ComPtr::ComPtr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa uma nova instância da classe de ComPtr.  As sobrecargas fornecem a opção, copiá\-lo, são movidos, e construtores de conversão.  
  
## Sintaxe  
  
```  
WRL_NOTHROW ComPtr();  
WRL_NOTHROW ComPtr(  
   decltype(__nullptr)  
);  
template<  
   class U  
>  
WRL_NOTHROW ComPtr(  
   _In_opt_ U *other  
);  
WRL_NOTHROW ComPtr(  
   const ComPtr& other  
);  
template<  
   class U  
>  
WRL_NOTHROW ComPtr(  
   const ComPtr<U> &other,  
   typename ENABLE_IF<__is_convertible_to(U*,  
   T*),  
   void *>;  
WRL_NOTHROW ComPtr(  
   _Inout_ ComPtr &&other  
);  
template<  
   class U  
>  
WRL_NOTHROW ComPtr(  
   _Inout_ ComPtr<U>&& other,  
   typename ENABLE_IF<__is_convertible_to(U*,  
   T*),  
   void *>;  
```  
  
#### Parâmetros  
 `U`  
 O tipo do parâmetro de `other` .  
  
 `other`  
 Um objeto do tipo `U`.  
  
## Valor de retorno  
  
## Comentários  
 O primeiro construtor é o construtor padrão, que cria implictly um objeto vazio.  O segundo construtor especifica [\_\_nullptr](../windows/nullptr-cpp-component-extensions.md), que cria explicitamente um objeto vazio.  
  
 O terceiro construtor cria um objeto do objeto especificado por um ponteiro.  
  
 O quarto e o quinto construtores são construtores de cópia.  O quinto construtor copia um objeto se é convertido no tipo atual.  
  
 Os construtores e sexto sétimos são construtores de movimentação.  O sétimo construtor move um objeto se é convertido no tipo atual.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)