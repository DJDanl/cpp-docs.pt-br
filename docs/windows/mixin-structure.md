---
title: Estrutura MixIn | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::MixIn
dev_langs:
- C++
helpviewer_keywords:
- MixIn structure
ms.assetid: 47e2df9b-3a2e-4ae8-8ba3-b1fd3aa73566
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b20dac5f189a51a1610da45e43e03e51ff1c3610
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33876157"
---
# <a name="mixin-structure"></a>Estrutura MixIn
Garante que uma classe de tempo de execução deriva de tempo de execução do Windows, se houver e a clássico, em seguida, COM interfaces.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<  
   typename Derived,  
   typename MixInType,  
   bool hasImplements = __is_base_of(Details::ImplementsBase,  
   MixInType)  
>  
struct MixIn;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Derived`  
 Um tipo derivado de [implementa](../windows/implements-structure.md) estrutura.  
  
 `MixInType`  
 Um tipo base.  
  
 `hasImplements`  
 `true` Se `MixInType` é derivado do tipo base; a implementação atual `false` caso contrário.  
  
## <a name="remarks"></a>Comentários  
 Se uma classe é derivada de tempo de execução do Windows e interfaces de classe COM, a lista de declaração de classe deve listar primeiro as interfaces de tempo de execução do Windows e, em seguida, qualquer clássico COM interfaces. Mesclado assegura que as interfaces são especificadas na ordem correta.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `MixIn`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)