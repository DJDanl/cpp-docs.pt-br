---
title: Classe SRWLock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::SRWLock
dev_langs:
- C++
helpviewer_keywords:
- SRWLock class
ms.assetid: 4fa250e3-5f29-4b06-ac24-61b6c04ade93
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 23881f2065276aa7ae7b6ee95b5449abb07dd2de
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39641947"
---
# <a name="srwlock-class"></a>Classe SRWLock
Representa um bloqueio de leitor/gravador reduzido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class SRWLock;  
```  
  
## <a name="remarks"></a>Comentários  
 Um bloqueio de leitor/gravador reduzido é usado para sincronizar o acesso entre threads para um objeto ou recurso. Para obter mais informações, consulte [funções de sincronização](http://msdn.microsoft.com/9b6359c2-0113-49b6-83d0-316ad95aba1b).  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|||  
|-|-|  
|`SyncLockExclusive`|Sinônimo de um **SRWLock** objeto que é adquirido em modo exclusivo.|  
|`SyncLockShared`|Sinônimo de um **SRWLock** objeto que é adquirido no modo compartilhado.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SRWLock::SRWLock](../windows/srwlock-srwlock-constructor.md)|Inicializa uma nova instância dos **SRWLock** classe.|  
|[Destruidor SRWLock::~SRWLock](../windows/srwlock-tilde-srwlock-destructor.md)|Realiza o desligamento de uma instância das **SRWLock** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método SRWLock::LockExclusive](../windows/srwlock-lockexclusive-method.md)|Adquire uma **SRWLock** objeto no modo exclusivo.|  
|[Método SRWLock::LockShared](../windows/srwlock-lockshared-method.md)|Adquire uma **SRWLock** objeto no modo compartilhado.|  
|[Método SRWLock::TryLockExclusive](../windows/srwlock-trylockexclusive-method.md)|Tenta adquirir um **SRWLock** objeto no modo exclusivo para o atual ou especificada **SRWLock** objeto.|  
|[Método SRWLock::TryLockShared](../windows/srwlock-trylockshared-method.md)|Tenta adquirir um **SRWLock** objeto no modo compartilhado para o atual ou especificada **SRWLock** objeto.|  
  
### <a name="protected-data-member"></a>Membro de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados SRWLock::SRWLock_](../windows/srwlock-srwlock-data-member.md)|Contém a variável subjacente de bloqueio atual **SRWLock** objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SRWLock`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)