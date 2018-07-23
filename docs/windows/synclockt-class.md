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
ms.openlocfilehash: e05a1be5d84db52573d3c3235936ecf82dde5894
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892846"
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