---
title: Classe EventSource | Microsoft Docs
ms.custom: ''
ms.date: 03/22/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::EventSource
dev_langs:
- C++
helpviewer_keywords:
- EventSource class
ms.assetid: 91f1c072-6af4-44e6-b6d8-ac6d0c688dde
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 531c4ec218f7e3b694a41cd465090a5b1787c41a
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="eventsource-class"></a>Classe EventSource
Representa um evento não agile. Funções de membro de EventSource adicionar, removem e invocar os manipuladores de eventos. Para eventos agile, use [AgileEventSource](agileeventsource-class.md). 
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename TDelegateInterface>  
class EventSource;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TDelegateInterface`  
 A interface para um delegado que representa um manipulador de eventos.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor EventSource::EventSource](../windows/eventsource-eventsource-constructor.md)|Inicializa uma nova instância da classe EventSource.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método EventSource::Add](../windows/eventsource-add-method.md)|Anexa o manipulador de eventos representado pela interface delegado especificado para o conjunto de manipuladores de eventos para o objeto de EventSource atual.|  
|[Método EventSource::GetSize](../windows/eventsource-getsize-method.md)|Recupera o número de manipuladores de eventos associados ao objeto de EventSource atual|  
|[Método EventSource::InvokeAll](../windows/eventsource-invokeall-method.md)|Chama cada manipulador de eventos associado ao objeto de EventSource atual usando os argumentos e tipos de argumento especificados.|  
|[Método EventSource::Remove](../windows/eventsource-remove-method.md)|Exclui o manipulador de eventos representado pelo token de registro de evento especificado da coleção de manipuladores de eventos associados ao objeto de EventSource atual.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados EventSource::addRemoveLock_](../windows/eventsource-addremovelock-data-member.md)|Sincroniza o acesso para o [targets _](../windows/eventsource-targets-data-member.md) matriz durante a adição, remoção ou chamar manipuladores de eventos.|  
|[Membro de dados EventSource::targets_](../windows/eventsource-targets-data-member.md)|Uma matriz de um ou mais manipuladores de eventos.|  
|[Membro de dados EventSource::targetsPointerLock_](../windows/eventsource-targetspointerlock-data-member.md)|Sincroniza o acesso a membros de dados internos, mesmo quando os manipuladores de eventos para essa EventSource estão sendo adicionados, removidos ou invocado.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `EventSource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft:: wrl](../windows/microsoft-wrl-namespace.md)
[AgileEventSource classe](agileeventsource-class.md)