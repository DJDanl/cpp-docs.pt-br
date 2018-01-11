---
title: Classe SyncLockWithStatusT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT
dev_langs: C++
helpviewer_keywords: SyncLockWithStatusT class
ms.assetid: 4832fd93-0ac8-4168-9404-b43fefea7476
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5b4b007acd6e6b9272a4fc7bb256d302cafeb75c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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