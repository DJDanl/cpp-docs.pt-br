---
title: "Fun&#231;&#227;o ActivateInstance | Microsoft Docs"
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
  - "client/Windows::Foundation::ActivateInstance"
  - "client/ABI::Windows::Foundation::ActivateInstance"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função ActivateInstance"
ms.assetid: 8cfd1dd9-5fda-4cc2-acf8-d40e783b3875
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o ActivateInstance
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os registros e recupera uma instância de um tipo especificado definido em uma ID especificada da classe  
  
## Sintaxe  
  
```  
template<  
   typename T  
>  
inline HRESULT ActivateInstance(  
   _In_ HSTRING activatableClassId,  
   _Out_ Microsoft::WRL::Details::ComPtrRef<T> instance  
);  
```  
  
#### Parâmetros  
 `T`  
 Um tipo a ser ativado.  
  
 `activatableClassId`  
 O nome da ID da classe que define o parâmetro `T`.  
  
 `instance`  
 Quando esta operação concluir, uma referência a uma instância de `T`.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um erro HRESULT que indica a causa do erro.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Windows::Foundation  
  
## Consulte também  
 [Namespace Windows::Foundation](../Topic/Windows::Foundation%20Namespace.md)