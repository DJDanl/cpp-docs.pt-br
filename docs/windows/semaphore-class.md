---
title: Classe de semáforo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Semaphore
dev_langs:
- C++
helpviewer_keywords:
- Semaphore class
ms.assetid: ded53526-17b4-4381-9c60-ea5e77363db6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5101aba24cd8a0ed4f44587ffc4ad9e973099b8a
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39652630"
---
# <a name="semaphore-class"></a>Classe Semaphore
Representa um objeto de sincronização que controla um recurso compartilhado que pode dar suporte a um número limitado de usuários.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class Semaphore : public HandleT<HandleTraits::SemaphoreTraits>  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`SyncLock`|Um sinônimo para uma classe que dá suporte a bloqueios síncronos.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor Semaphore::Semaphore](../windows/semaphore-semaphore-constructor.md)|Inicializa uma nova instância dos **semáforo** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método InvokeHelper::Invoke](../windows/invokehelper-invoke-method.md)|Chama o manipulador de eventos cuja assinatura contém o número especificado de argumentos.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Semaphore::Lock](../windows/semaphore-lock-method.md)|Aguarda até que o objeto atual ou o objeto associado com o identificador especificado, estiver no estado sinalizado ou o intervalo de tempo limite especificado tenha decorrido.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador Semaphore::operator=](../windows/semaphore-operator-assign-operator.md)|Move o identificador especificado de uma **semáforo** objeto atual **semáforo** objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Semaphore`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)