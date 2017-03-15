---
title: "M&#233;todo RuntimeClassBaseT::AsIID | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::RuntimeClassBaseT::AsIID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AsIID"
ms.assetid: 90d7df8a-cf9e-4eef-8837-bc1a25f3fa1a
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo RuntimeClassBaseT::AsIID
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template<  
   typename T  
>  
__forceinline static HRESULT AsIID(  
   _In_ T* implements,  
   REFIID riid,  
   _Deref_out_ void **ppvObject  
);  
```  
  
#### Parâmetros  
 `T`  
 Um tipo que implementa a ID da interface especificada pelo parâmetro `riid`.  
  
 `implements`  
 Uma variável do tipo especificado pelo parâmetro `T`do modelo.  
  
 `riid`  
 A ID da interface a ser recuperado.  
  
 `ppvObject`  
 Se essa operação é bem\-sucedida, ponteiro\-à\-um\- um ponteiro para a interface especificada pelo parâmetro `riid`.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que descreve o erro.  
  
## Comentários  
 Recupera um ponteiro para a ID da interface especificada  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Estrutura RuntimeClassBaseT](../windows/runtimeclassbaset-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)