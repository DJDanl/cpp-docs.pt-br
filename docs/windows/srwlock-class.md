---
title: Classe SRWLock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::SRWLock
dev_langs:
- C++
helpviewer_keywords:
- SRWLock class
ms.assetid: 4fa250e3-5f29-4b06-ac24-61b6c04ade93
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1325a089739b3820009aa239f56805264dbb6b83
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="srwlock-class"></a>Classe SRWLock
Representa um bloqueio de leitor/gravador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class SRWLock;  
```  
  
## <a name="remarks"></a>Comentários  
 Um bloqueio de leitor/gravador é usado para sincronizar o acesso entre threads para um objeto ou recurso. Para obter mais informações, consulte [funções de sincronização](http://msdn.microsoft.com/en-us/9b6359c2-0113-49b6-83d0-316ad95aba1b).  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|||  
|-|-|  
|**SyncLockExclusive**|Sinônimo de um objeto de SRWLock que é adquirido em modo exclusivo.|  
|**SyncLockShared**|Sinônimo de um objeto de SRWLock que é adquirido no modo compartilhado.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SRWLock::SRWLock](../windows/srwlock-srwlock-constructor.md)|Inicializa uma nova instância da classe SRWLock.|  
|[Destruidor SRWLock::~SRWLock](../windows/srwlock-tilde-srwlock-destructor.md)|Deinitializes uma instância da classe SRWLock.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método SRWLock::LockExclusive](../windows/srwlock-lockexclusive-method.md)|Obtém um objeto SRWLock em modo exclusivo.|  
|[Método SRWLock::LockShared](../windows/srwlock-lockshared-method.md)|Obtém um objeto SRWLock no modo compartilhado.|  
|[Método SRWLock::TryLockExclusive](../windows/srwlock-trylockexclusive-method.md)|Tenta adquirir um objeto SRWLock em modo exclusivo para o objeto SRWLock especificado ou atual.|  
|[Método SRWLock::TryLockShared](../windows/srwlock-trylockshared-method.md)|Tenta adquirir um objeto SRWLock no modo compartilhado para o objeto SRWLock especificado ou atual.|  
  
### <a name="protected-data-member"></a>Membro de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados SRWLock::SRWLock_](../windows/srwlock-srwlock-data-member.md)|Contém a variável subjacente de bloqueio para o objeto SRWLock atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SRWLock`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)