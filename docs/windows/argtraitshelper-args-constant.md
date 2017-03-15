---
title: "Constante ArgTraitsHelper::args | Microsoft Docs"
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
  - "event/Microsoft::WRL::Details::ArgTraitsHelper::args"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "constante args"
ms.assetid: 1c0efa32-c072-43e3-bbd9-a3f6aec069a2
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Constante ArgTraitsHelper::args
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
static const int args = Traits::args;  
```  
  
## Comentários  
 Ajuda [ArgTraitsHelper::args](../windows/argtraitshelper-args-constant.md) mantém a contagem do número de parâmetros no método invocar de uma interface de delegação.  
  
## Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Estrutura ArgTraitsHelper](../windows/argtraitshelper-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)