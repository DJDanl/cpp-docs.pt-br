---
title: "M&#233;todo ActivationFactory::Release | Microsoft Docs"
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
  - "module/Microsoft::WRL::ActivationFactory::Release"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método de liberação"
ms.assetid: 5bc25ff0-ee3c-4a2d-a9b6-2d8f158033ad
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo ActivationFactory::Release
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Diminui a contagem de referência do objeto atual de ActivationFactory.  
  
## Sintaxe  
  
```  
STDMETHOD_(  
   ULONG,  
   Release  
)();  
```  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que descreve a falha.  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe ActivationFactory](../windows/activationfactory-class.md)