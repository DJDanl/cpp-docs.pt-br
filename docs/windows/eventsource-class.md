---
title: Classe EventSource | Microsoft Docs
ms.custom: ''
ms.date: 03/22/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::EventSource
dev_langs:
- C++
helpviewer_keywords:
- EventSource class
ms.assetid: 91f1c072-6af4-44e6-b6d8-ac6d0c688dde
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a98d8997ebfb5b21b3e469b2aacca15cde4a5319
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39570529"
---
# <a name="eventsource-class"></a>Classe EventSource
Representa um evento não agile. **EventSource** funções de membro de adicionar, remover e invocar manipuladores de eventos. Para eventos agile, use [AgileEventSource](agileeventsource-class.md). 
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename TDelegateInterface>  
class EventSource;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *TDelegateInterface*  
 A interface para um delegado que representa um manipulador de eventos.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor EventSource::EventSource](../windows/eventsource-eventsource-constructor.md)|Inicializa uma nova instância dos **EventSource** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método EventSource::Add](../windows/eventsource-add-method.md)|Acrescenta o manipulador de eventos representado pela interface delegado especificado ao conjunto de manipuladores de eventos para o atual **EventSource** objeto.|  
|[Método EventSource::GetSize](../windows/eventsource-getsize-method.md)|Recupera o número de manipuladores de eventos associados ao atual **EventSource** objeto|  
|[Método EventSource::InvokeAll](../windows/eventsource-invokeall-method.md)|Chama cada manipulador de eventos associado ao atual **EventSource** usando os argumentos e tipos de argumento especificados do objeto.|  
|[Método EventSource::Remove](../windows/eventsource-remove-method.md)|Exclui o manipulador de eventos, representado pelo token de registro de evento especificado do conjunto de manipuladores de eventos associados ao atual **EventSource** objeto.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados EventSource::addRemoveLock_](../windows/eventsource-addremovelock-data-member.md)|Sincroniza o acesso para o [targets _](../windows/eventsource-targets-data-member.md) matriz ao adicionar, remover ou invocar manipuladores de eventos.|  
|[Membro de dados EventSource::targets_](../windows/eventsource-targets-data-member.md)|Uma matriz de um ou mais manipuladores de eventos.|  
|[Membro de dados EventSource::targetsPointerLock_](../windows/eventsource-targetspointerlock-data-member.md)|Sincroniza o acesso a membros de dados internos, mesmo quando os manipuladores de eventos para esse EventSource estão sendo adicionados, removidos ou invocado.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `EventSource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Event. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)  
 [Classe AgileEventSource](agileeventsource-class.md)