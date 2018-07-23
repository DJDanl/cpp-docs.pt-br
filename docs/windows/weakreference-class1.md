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
ms.openlocfilehash: a44b992138371ff33a9059990a5ec3e93689c679
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33891640"
---
# <a name="weakreference-class1"></a>WeakReference Class1
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class WeakReference;  
```  
  
## <a name="remarks"></a>Comentários  
 Representa um *referência fraca* que pode ser usado com o tempo de execução do Windows ou o clássico com. Uma referência fraca representa um objeto que pode ou não pode ser acessado.  
  
 Um `WeakReference` objeto mantém um *referência forte*, que é um ponteiro para um objeto e um *contagem de referência forte*, que é o número de cópias da referência de alta segurança que foram distribuídas por o método resolve. Enquanto a contagem de referência forte é diferente de zero, a referência forte é válida e o objeto está acessível. Quando a contagem de referência forte se torna zero, a referência forte é válida e o objeto está inacessível.  
  
 Um objeto WeakReference normalmente é usado para representar um objeto cuja existência é controlada por um aplicativo ou thread externo. Por exemplo, criar um objeto WeakReference de uma referência a um objeto de arquivo. Enquanto o arquivo estiver aberto, a referência forte é válida. Mas, se o arquivo for fechado, a referência forte torna-se inválido.  
  
 Os métodos de WeakReference são thread-safe.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor WeakReference::WeakReference](../windows/weakreference-weakreference-constructor.md)|Inicializa uma nova instância da classe WeakReference.|  
|[Destruidor WeakReference::~WeakReference](../windows/weakreference-tilde-weakreference-destructor.md)|Deinitializes (destrói) a instância atual da classe WeakReference.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método WeakReference::DecrementStrongReference](../windows/weakreference-decrementstrongreference-method.md)|Diminui a forte contagem de referência do objeto WeakReference atual.|  
|[Método WeakReference::IncrementStrongReference](../windows/weakreference-incrementstrongreference-method.md)|Incrementa a contagem de referência forte do objeto WeakReference atual.|  
|[Método WeakReference::Resolve](../windows/weakreference-resolve-method.md)|Define o ponteiro especificado para o valor de referência forte atual se a contagem de referência forte é diferente de zero.|  
|[Método WeakReference::SetUnknown](../windows/weakreference-setunknown-method.md)|Define a referência forte do objeto WeakReference atual para o ponteiro de interface especificado.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `WeakReference`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)