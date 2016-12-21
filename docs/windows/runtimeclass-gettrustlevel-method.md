---
title: "M&#233;todo RuntimeClass::GetTrustLevel | Microsoft Docs"
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
  - "implements/Microsoft::WRL::RuntimeClass::GetTrustLevel"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetTrustLevel"
ms.assetid: bd90407e-6dd7-41c3-9ea0-c402c276014a
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo RuntimeClass::GetTrustLevel
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém o nível de confiança do objeto atual de RuntimeClass.  
  
## Sintaxe  
  
```  
STDMETHOD(  
   GetTrustLevel  
)(_Out_ TrustLevel* trustLvl);  
```  
  
## Parâmetros  
 `trustLvl`  
 Quando esta operação concluir, o nível de confiança do objeto atual de RuntimeClass.  
  
## Valor de retorno  
 Sempre S\_OK.  
  
## Comentários  
 Um erro de afirmar é emitido se o \_\_WRL\_FORCE\_INSPECTABLE\_CLASS\_MACRO de \_\_WRL\_STRICT\_\_or não é definido.  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)