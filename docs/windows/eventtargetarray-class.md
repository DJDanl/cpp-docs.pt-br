---
title: Classe EventTargetArray | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::EventTargetArray
dev_langs:
- C++
helpviewer_keywords:
- EventTargetArray class
ms.assetid: e3cadb7c-2160-4cbb-a2f8-c28733d1e96d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ac591a1d27792d3b825336ed46e38fa5d002fa73
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="eventtargetarray-class"></a>Classe EventTargetArray
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class EventTargetArray : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<ClassicCom>, IUnknown>;  
```  
  
## <a name="remarks"></a>Comentários  
 Representa uma matriz de manipuladores de eventos.  
  
 Os manipuladores de eventos que são associados com um [EventSource](../windows/eventsource-class.md) objeto são armazenados em um membro de dados EventTargetArray protegido.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor EventTargetArray::EventTargetArray](../windows/eventtargetarray-eventtargetarray-constructor.md)|Inicializa uma nova instância da classe EventTargetArray.|  
|[Destruidor EventTargetArray::~EventTargetArray](../windows/eventtargetarray-tilde-eventtargetarray-destructor.md)|Deinitializes classe EventTargetArray atual.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método EventTargetArray::AddTail](../windows/eventtargetarray-addtail-method.md)|Anexa o manipulador de eventos especificado ao final da matriz interna de manipuladores de eventos.|  
|[Método EventTargetArray::Begin](../windows/eventtargetarray-begin-method.md)|Obtém o endereço do primeiro elemento da matriz interna de manipuladores de eventos.|  
|[Método EventTargetArray::End](../windows/eventtargetarray-end-method.md)|Obtém o endereço do último elemento da matriz interna de manipuladores de eventos.|  
|[Método EventTargetArray::Length](../windows/eventtargetarray-length-method.md)|Obtém o número atual de elementos da matriz interna de manipuladores de eventos.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `EventTargetArray`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)