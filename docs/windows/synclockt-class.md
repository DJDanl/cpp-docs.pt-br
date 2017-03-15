---
title: "Classe SyncLockT | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe SyncLockT"
ms.assetid: a967f6f7-3555-43d1-b210-2bb65d63d15e
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe SyncLockT
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template <  
   typename SyncTraits  
>  
class SyncLockT;  
```  
  
#### Parâmetros  
 `SyncTraits`  
 O tipo que pode assumir a propriedade de um recurso.  
  
## Comentários  
 Representa um tipo que possa assumir a propriedade exclusiva ou compartilhada de um recurso.  
  
 A classe de SyncLockT é usada, por exemplo, para ajudar a implementar a classe de [SRWLock](../windows/srwlock-class.md) .  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor SyncLockT::SyncLockT](../Topic/SyncLockT::SyncLockT%20Constructor.md)|Inicializa uma nova instância da classe de SyncLockT.|  
|[Destruidor SyncLockT::~SyncLockT](../windows/synclockt-tilde-synclockt-destructor.md)|Deinitializes uma instância da classe de SyncLockT.|  
  
### Construtores Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor SyncLockT::SyncLockT](../Topic/SyncLockT::SyncLockT%20Constructor.md)|Inicializa uma nova instância da classe de SyncLockT.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método SyncLockT::IsLocked](../windows/synclockt-islocked-method.md)|Indica se o objeto atual de SyncLockT possui um recurso; isto é, o objeto de SyncLockT *é bloqueada*.|  
|[Método SyncLockT::Unlock](../windows/synclockt-unlock-method.md)|O controle de versões de recursos mantidos pelo objeto atual de SyncLockT, se houver.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados SyncLockT::sync\_](../Topic/SyncLockT::sync_%20Data%20Member.md)|Mantém o recurso subjacente representado pela classe de SyncLockT.|  
  
## Hierarquia de Herança  
 `SyncLockT`  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)   
 [Classe SRWLock](../windows/srwlock-class.md)