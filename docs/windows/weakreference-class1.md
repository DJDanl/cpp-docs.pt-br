---
title: WeakReference Class1 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::WeakReference
dev_langs:
- C++
helpviewer_keywords:
- WeakReference class
ms.assetid: 3f4c956b-dbbd-49b1-8cfa-9509a9956c97
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 78b9a62838508c2e97bdd04f56778a622343e6f1
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40012284"
---
# <a name="weakreference-class1"></a>WeakReference Class1
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
class WeakReference;  
```  
  
## <a name="remarks"></a>Comentários  
 Representa uma *referência fraca* que pode ser usado com o tempo de execução do Windows ou o com clássico. Uma referência fraca representa um objeto que pode ou não ser acessível.  
  
 Um **WeakReference** objeto mantém uma *referência forte*, que é um ponteiro para um objeto e uma *contagem de referência forte*, que é o número de cópias de forte referência que foram distribuídas pelo `Resolve()` método. Embora a contagem de referência forte é diferente de zero, a referência forte é válida e o objeto está acessível. Quando a contagem de referência forte se torna zero, a referência forte é inválida e o objeto está inacessível.  
  
 Um **WeakReference** objeto normalmente é usado para representar um objeto cuja existência é controlada por um aplicativo ou thread externo. Por exemplo, construir uma **WeakReference** objeto a partir de uma referência a um objeto de arquivo. Enquanto o arquivo estiver aberto, a referência forte é válida. Mas, se o arquivo é fechado, a referência forte se torna inválida.  
  
 O **WeakReference** métodos são thread-safe.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor WeakReference::WeakReference](../windows/weakreference-weakreference-constructor.md)|Inicializa uma nova instância dos **WeakReference** classe.|  
|[Destruidor WeakReference::~WeakReference](../windows/weakreference-tilde-weakreference-destructor.md)|Realiza o desligamento (destrói) a instância atual do **WeakReference** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método WeakReference::DecrementStrongReference](../windows/weakreference-decrementstrongreference-method.md)|Diminui a contagem de referência forte do atual **WeakReference** objeto.|  
|[Método WeakReference::IncrementStrongReference](../windows/weakreference-incrementstrongreference-method.md)|Incrementa a contagem de referência forte do atual **WeakReference** objeto.|  
|[Método WeakReference::Resolve](../windows/weakreference-resolve-method.md)|Define o ponteiro especificado para o valor atual de referência forte se a contagem de referência forte for diferente de zero.|  
|[Método WeakReference::SetUnknown](../windows/weakreference-setunknown-method.md)|Define a referência forte do atual **WeakReference** objeto para o ponteiro de interface especificado.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `WeakReference`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)