---
title: "Estrutura HANDLENullTraits | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura HANDLENullTraits"
ms.assetid: 88a29a14-c516-40cb-a0ca-ee897a668623
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura HANDLENullTraits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define características comuns de um identificador não inicializada.  
  
## Sintaxe  
  
```  
struct HANDLENullTraits;  
```  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`Type`|Um sinônimo para a ALÇA.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método HANDLENullTraits::Close](../windows/handlenulltraits-close-method.md)|Fecha o identificador especificado.|  
|[Método HANDLENullTraits::GetInvalidValue](../windows/handlenulltraits-getinvalidvalue-method.md)|Representa um identificador inválido.|  
  
## Hierarquia de Herança  
 `HANDLENullTraits`  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)