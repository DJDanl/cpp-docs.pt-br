---
title: Classe SyncLockWithStatusT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT
dev_langs:
- C++
helpviewer_keywords:
- SyncLockWithStatusT class
ms.assetid: 4832fd93-0ac8-4168-9404-b43fefea7476
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bd514b1684571fb12a19265b57e6d5b92b8c7edd
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40011543"
---
# <a name="synclockwithstatust-class"></a>Classe SyncLockWithStatusT
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <  
   typename SyncTraits  
>  
class SyncLockWithStatusT : public SyncLockT<SyncTraits>;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *SyncTraits*  
 Um tipo que pode levar exclusivo ou a propriedade compartilhada de um recurso.  
  
## <a name="remarks"></a>Comentários  
 Representa um tipo que pode levar exclusivo ou a propriedade compartilhada de um recurso.  
  
 O **SyncLockWithStatusT** classe é usada para implementar o [Mutex](../windows/mutex-class1.md) e [semáforo](../windows/semaphore-class.md) classes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SyncLockWithStatusT::SyncLockWithStatusT](../windows/synclockwithstatust-synclockwithstatust-constructor.md)|Inicializa uma nova instância dos **SyncLockWithStatusT** classe.|  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SyncLockWithStatusT::SyncLockWithStatusT](../windows/synclockwithstatust-synclockwithstatust-constructor.md)|Inicializa uma nova instância dos **SyncLockWithStatusT** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método SyncLockWithStatusT::GetStatus](../windows/synclockwithstatust-getstatus-method.md)|Recupera o status de espera do atual **SyncLockWithStatusT** objeto.|  
|[Método SyncLockWithStatusT::IsLocked](../windows/synclockwithstatust-islocked-method.md)|Indica se o atual **SyncLockWithStatusT** objeto possui um recurso, ou seja, o **SyncLockWithStatusT** objeto é *bloqueado*.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados SyncLockWithStatusT::status_](../windows/synclockwithstatust-status-data-member.md)|Contém o resultado da operação de espera adjacente após uma operação de bloqueio em um objeto com base no atual **SyncLockWithStatusT** objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SyncLockT`  
  
 `SyncLockWithStatusT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)