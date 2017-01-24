---
title: "Fun&#231;&#227;o GetActivationFactory | Microsoft Docs"
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
  - "module/Microsoft::WRL::Details::GetActivationFactory"
  - "client/ABI::Windows::Foundation::GetActivationFactory"
  - "client/Windows::Foundation::GetActivationFactory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função GetActivationFactory"
ms.assetid: 5736d285-6beb-42aa-8788-e261c0010afe
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o GetActivationFactory
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Recupera uma fábrica de ativação do tipo especificado pelo parâmetro do modelo.  
  
## Sintaxe  
  
```  
template<  
   typename T  
>  
inline HRESULT GetActivationFactory(  
   _In_ HSTRING activatableClassId,  
   _Out_ Microsoft::WRL::Details::ComPtrRef<T> factory  
);  
```  
  
#### Parâmetros  
 `T`  
 Um parâmetro de modelo que especifica o tipo de fábrica de ativação.  
  
 `activatableClassId`  
 O nome da classe que a fábrica de ativação pode gerar.  
  
 `factory`  
 Quando esta operação concluir, uma referência à fábrica de ativação do tipo `T`.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um erro HRESULT que indica como essa operação falhou.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Windows::Foundation  
  
## Consulte também  
 [Namespace Windows::Foundation](../Topic/Windows::Foundation%20Namespace.md)