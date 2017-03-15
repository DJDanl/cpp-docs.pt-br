---
title: "Estrutura SRWLockExclusiveTraits | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HandleTraits::SRWLockExclusiveTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura SRWLockExclusiveTraits"
ms.assetid: 38a996ef-c2d7-4886-b413-a426ecee8f05
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura SRWLockExclusiveTraits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve características comuns da classe de SRWLock no modo de bloqueio exclusivo.  
  
## Sintaxe  
  
```  
struct SRWLockExclusiveTraits;  
```  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`Type`|Sinônimo para um ponteiro para a classe de [SRWLOCK](../windows/srwlock-class.md) .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método SRWLockExclusiveTraits::GetInvalidValue](../windows/srwlockexclusivetraits-getinvalidvalue-method.md)|Recupera um objeto de SRWLockExclusiveTraits que sempre é inválido.|  
|[Método SRWLockExclusiveTraits::Unlock](../windows/srwlockexclusivetraits-unlock-method.md)|Controle exclusivo das versões do objeto especificado de SRWLock.|  
  
## Hierarquia de Herança  
 `SRWLockExclusiveTraits`  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::HandleTraits  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers::HandleTraits](../windows/microsoft-wrl-wrappers-handletraits-namespace.md)