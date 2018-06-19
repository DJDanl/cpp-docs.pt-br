---
title: Classe de evento (biblioteca de modelos C++ do Windows Runtime) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Event
dev_langs:
- C++
ms.assetid: 55dfc9fc-62d4-4bb2-9d85-5b6dd88569e8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 12c9e5bfe01de0a9864ff1e94364e0c42178ad11
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33872920"
---
# <a name="event-class-windows-runtime-c-template-library"></a>Classe Event (Biblioteca em Tempo de Execução C++ do Windows Runtime )
Representa um evento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class Event : public HandleT<HandleTraits::EventTraits>;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor Event::Event (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/event-event-constructor-windows-runtime-cpp-template-library.md)|Inicializa uma nova instância da classe de evento.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador Event::operator=](../windows/event-operator-assign-operator.md)|Atribui a referência de evento especificada para a instância atual do evento.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `HandleT`  
  
 `Event`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)