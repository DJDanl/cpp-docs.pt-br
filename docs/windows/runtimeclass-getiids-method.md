---
title: "M&#233;todo RuntimeClass::GetIids | Microsoft Docs"
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
  - "implements/Microsoft::WRL::RuntimeClass::GetIids"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetIids"
ms.assetid: 826a67d1-ebc4-4940-b5d5-7cd66885e4a1
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo RuntimeClass::GetIids
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém uma matriz que contém as IDs de interface implementados pelo objeto atual de RuntimeClass.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   GetIids  
)  
   (_Out_ ULONG *iidCount,   
   _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids);  
```  
  
#### Parâmetros  
 `iidCount`  
 Quando esta operação concluir, o número total de elementos na matriz `iids`.  
  
 `iids`  
 Quando esta operação concluir, um ponteiro para uma matriz de IDs da interface.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; se não, E\_OUTOFMEMORY.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)