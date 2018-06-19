---
title: Classe EventTargetArray | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::EventTargetArray
dev_langs:
- C++
helpviewer_keywords:
- EventTargetArray class
ms.assetid: e3cadb7c-2160-4cbb-a2f8-c28733d1e96d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4461004a1681d9095449c51fb9cb3973d5017693
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33881303"
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