---
title: "Classe Semaphore | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::Semaphore"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe Semaphore"
ms.assetid: ded53526-17b4-4381-9c60-ea5e77363db6
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe Semaphore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um objeto de sincronização que controla um recurso compartilhado que pode dar suporte a um número limitado de usuários.  
  
## Sintaxe  
  
```  
class Semaphore : public HandleT<HandleTraits::SemaphoreTraits>  
```  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`SyncLock`|Um sinônimo para uma classe que suporte bloqueios síncronas.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor Semaphore::Semaphore](../windows/semaphore-semaphore-constructor.md)|Inicializa uma nova instância da classe de semáforo.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método InvokeHelper::Invoke](../windows/invokehelper-invoke-method.md)|Chama o manipulador de eventos cuja assinatura contém o número especificado de argumentos.|  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método Semaphore::Lock](../windows/semaphore-lock-method.md)|Aguarde até que o objeto atual, ou o objeto associado com o identificador especificado, estejam no estado sinalizado ou o intervalo de tempo limite especificado tiver decorrido.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador Semaphore::operator\=](../windows/semaphore-operator-assign-operator.md)|Move o identificador especificado de um objeto do sinal para o objeto atual de semáforo.|  
  
## Hierarquia de Herança  
 `Semaphore`  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../Topic/Microsoft::WRL::Wrappers%20Namespace.md)