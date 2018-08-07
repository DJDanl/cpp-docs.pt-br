---
title: Classe ModuleBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ModuleBase
dev_langs:
- C++
helpviewer_keywords:
- ModuleBase class
ms.assetid: edce7591-6893-46f7-94a7-382827775548
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b298bcab4c2b3547f2b285fe21d4967f4696fb9d
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39605052"
---
# <a name="modulebase-class"></a>Classe ModuleBase
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class ModuleBase;  
```  
  
## <a name="remarks"></a>Comentários  
 Representa a classe base do [módulo](../windows/module-class.md) classes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor ModuleBase::ModuleBase](../windows/modulebase-modulebase-constructor.md)|Inicializa uma instância da classe `Module`.|  
|[Destruidor ModuleBase::~ModuleBase](../windows/modulebase-tilde-modulebase-destructor.md)|A instância atual do realiza o desligamento de `Module` classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ModuleBase::DecrementObjectCount](../windows/modulebase-decrementobjectcount-method.md)|Quando implementado, diminui o número de objetos rastreados pelo módulo.|  
|[Método ModuleBase::IncrementObjectCount](../windows/modulebase-incrementobjectcount-method.md)|Quando implementado, incrementa o número de objetos controlados pelo módulo.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ModuleBase`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)