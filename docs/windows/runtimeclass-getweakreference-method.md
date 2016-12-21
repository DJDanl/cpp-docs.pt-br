---
title: "M&#233;todo RuntimeClass::GetWeakReference | Microsoft Docs"
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
  - "implements/Microsoft::WRL::RuntimeClass::GetWeakReference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetWeakReference"
ms.assetid: 26656ace-7f20-4364-87c9-4a75dd30912e
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo RuntimeClass::GetWeakReference
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém um ponteiro para o objeto de referência flexível para o objeto atual de RuntimeClass.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   GetWeakReference  
)(_Deref_out_ IWeakReference **weakReference);  
```  
  
#### Parâmetros  
 `weakReference`  
 Quando esta operação concluir, um ponteiro para um objeto de referência flexível.  
  
## Valor de retorno  
 Sempre S\_OK.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)