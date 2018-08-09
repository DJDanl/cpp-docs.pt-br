---
title: Classe SyncLockT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT
dev_langs:
- C++
helpviewer_keywords:
- SyncLockT class
ms.assetid: a967f6f7-3555-43d1-b210-2bb65d63d15e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b1eb11480657d731a4667722572e921f405c0845
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40012136"
---
# <a name="synclockt-class"></a>Classe SyncLockT
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <  
   typename SyncTraits  
>  
class SyncLockT;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *SyncTraits*  
 O tipo que pode assumir a propriedade de um recurso.  
  
## <a name="remarks"></a>Comentários  
 Representa um tipo que pode levar exclusivo ou a propriedade compartilhada de um recurso.  
  
 O **SyncLockT** classe é usada, por exemplo, para ajudar a implementar o [SRWLock](../windows/srwlock-class.md) classe.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SyncLockT::SyncLockT](../windows/synclockt-synclockt-constructor.md)|Inicializa uma nova instância dos **SyncLockT** classe.|  
|[Destruidor SyncLockT::~SyncLockT](../windows/synclockt-tilde-synclockt-destructor.md)|Realiza o desligamento de uma instância das **SyncLockT** classe.|  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SyncLockT::SyncLockT](../windows/synclockt-synclockt-constructor.md)|Inicializa uma nova instância dos **SyncLockT** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método SyncLockT::IsLocked](../windows/synclockt-islocked-method.md)|Indica se o atual **SyncLockT** objeto possui um recurso, ou seja, o **SyncLockT** objeto é *bloqueado*.|  
|[Método SyncLockT::Unlock](../windows/synclockt-unlock-method.md)|Libera o controle do recurso mantido por atual **SyncLockT** do objeto, se houver.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados SyncLockT::sync_](../windows/synclockt-sync-data-member.md)|Contém o recurso subjacente representado pela **SyncLockT** classe.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SyncLockT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)   
 [Classe SRWLock](../windows/srwlock-class.md)