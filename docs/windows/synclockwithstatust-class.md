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
ms.openlocfilehash: 51e5a66358890fc20731fb5cb657616484e19db4
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33890974"
---
# <a name="synclockwithstatust-class"></a>Classe SyncLockWithStatusT
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename SyncTraits  
>  
class SyncLockWithStatusT : public SyncLockT<SyncTraits>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `SyncTraits`  
 Um tipo que pode levar exclusivo ou compartilhado a propriedade de um recurso.  
  
## <a name="remarks"></a>Comentários  
 Representa um tipo que pode levar exclusivo ou compartilhado a propriedade de um recurso.  
  
 A classe SyncLockWithStatusT é usada para implementar o [Mutex](../windows/mutex-class1.md) e [semáforo](../windows/semaphore-class.md) classes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SyncLockWithStatusT::SyncLockWithStatusT](../windows/synclockwithstatust-synclockwithstatust-constructor.md)|Inicializa uma nova instância da classe SyncLockWithStatusT.|  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SyncLockWithStatusT::SyncLockWithStatusT](../windows/synclockwithstatust-synclockwithstatust-constructor.md)|Inicializa uma nova instância da classe SyncLockWithStatusT.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método SyncLockWithStatusT::GetStatus](../windows/synclockwithstatust-getstatus-method.md)|Recupera o status de espera do objeto SyncLockWithStatusT atual.|  
|[Método SyncLockWithStatusT::IsLocked](../windows/synclockwithstatust-islocked-method.md)|Indica se o objeto SyncLockWithStatusT atual possui um recurso. ou seja, é o objeto SyncLockWithStatusT *bloqueado*.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados SyncLockWithStatusT::status_](../windows/synclockwithstatust-status-data-member.md)|Mantém o resultado da operação após uma operação de bloqueio de espera em um objeto com base no objeto SyncLockWithStatusT atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SyncLockT`  
  
 `SyncLockWithStatusT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)