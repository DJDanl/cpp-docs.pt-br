---
title: "M&#233;todo HString::GetAddressOf | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HString::GetAddressOf"
dev_langs: 
  - "C++"
ms.assetid: 6050decf-5f99-49f0-9497-1c8192c485ae
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo HString::GetAddressOf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Recupera um ponteiro para o identificador subjacente de HSTRING.  
  
## Sintaxe  
  
```  
HSTRING* GetAddressOf() throw()  
```  
  
## Valor de Retorno  
 Um ponteiro para o identificador de HSTRING subjacente.  
  
## Comentários  
 Após esta operação, o valor da cadeia de caracteres do identificador de HSTRING subjacente é destruído.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HString](../windows/hstring-class.md)