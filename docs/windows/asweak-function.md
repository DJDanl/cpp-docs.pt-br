---
title: "Fun&#231;&#227;o AsWeak | Microsoft Docs"
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
  - "client/Microsoft::WRL::AsWeak"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função AsWeak"
ms.assetid: a6f10cfc-c1d6-4761-adb9-1a119cc99913
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o AsWeak
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Recupera uma referência fraca para uma instância especificada do.  
  
## Sintaxe  
  
```  
template<  
   typename T  
>  
HRESULT AsWeak(  
   _In_ T* p,  
   _Out_ WeakRef* pWeak  
);  
```  
  
#### Parâmetros  
 `T`  
 Um ponteiro para o tipo de parâmetro `p`.  
  
 `p`  
 Uma instância de um tipo.  
  
 `pWeak`  
 Quando esta operação concluir, um ponteiro para uma referência ao parâmetro `p`fraca.  
  
## Valor de retorno  
 S\_OK, se essa operação é bem\-sucedida; caso contrário, um erro HRESULT que indica a causa da falha.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)