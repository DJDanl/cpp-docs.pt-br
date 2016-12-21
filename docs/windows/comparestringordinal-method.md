---
title: "M&#233;todo CompareStringOrdinal | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::Details::CompareStringOrdinal"
dev_langs: 
  - "C++"
ms.assetid: ffa997fd-8cd7-40a5-b9e7-f55d40b072f4
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo CompareStringOrdinal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```cpp  
  
inline INT32 CompareStringOrdinal(  
   HSTRING lhs,   
   HSTRING rhs)  
```  
  
#### Parâmetros  
 `lhs`  
 O primeiro HSTRING a ser comparado.  
  
 `rhs`  
 O segundo HSTRING a ser comparado.  
  
## Valor de retorno  
  
|Valor|Condição|  
|-----------|--------------|  
|\-1|`lhs` é menor que `rhs`.|  
|0|`lhs` é igual a `rhs`.|  
|1|`lhs` é maior que `rhs`.|  
  
## Comentários  
 Compara dois objetos especificados de HSTRING e retorna um inteiro que indica a posição relativa em uma ordem de classificação.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)