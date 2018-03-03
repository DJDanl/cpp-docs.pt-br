---
title: Classe SyncLockT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT
dev_langs:
- C++
helpviewer_keywords:
- SyncLockT class
ms.assetid: a967f6f7-3555-43d1-b210-2bb65d63d15e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3f3a9794f7b00a2029f6706db3a846ba127a4d5e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="synclockt-class"></a>Classe SyncLockT
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename SyncTraits  
>  
class SyncLockT;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `SyncTraits`  
 O tipo que pode apropriar-se de um recurso.  
  
## <a name="remarks"></a>Comentários  
 Representa um tipo que pode levar exclusivo ou compartilhado a propriedade de um recurso.  
  
 A classe SyncLockT é usada, por exemplo, para ajudar a implementar o [SRWLock](../windows/srwlock-class.md) classe.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SyncLockT::SyncLockT](../windows/synclockt-synclockt-constructor.md)|Inicializa uma nova instância da classe SyncLockT.|  
|[Destruidor SyncLockT::~SyncLockT](../windows/synclockt-tilde-synclockt-destructor.md)|Deinitializes uma instância da classe SyncLockT.|  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SyncLockT::SyncLockT](../windows/synclockt-synclockt-constructor.md)|Inicializa uma nova instância da classe SyncLockT.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método SyncLockT::IsLocked](../windows/synclockt-islocked-method.md)|Indica se o objeto SyncLockT atual possui um recurso. ou seja, é o objeto SyncLockT *bloqueado*.|  
|[Método SyncLockT::Unlock](../windows/synclockt-unlock-method.md)|Libera o controle do recurso mantido pelo objeto SyncLockT atual, se houver.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados SyncLockT::sync_](../windows/synclockt-sync-data-member.md)|Contém o recurso subjacente representado pela classe SyncLockT.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SyncLockT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)   
 [Classe SRWLock](../windows/srwlock-class.md)