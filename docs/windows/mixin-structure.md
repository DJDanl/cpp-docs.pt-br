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
ms.openlocfilehash: 8fb5fa5288829ef51bf818ad8b7cf3b46edb59bf
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40014280"
---
# <a name="mixin-structure"></a>Estrutura MixIn
Garante que uma classe de tempo de execução deriva de interfaces do COM clássico, em seguida e as interfaces de tempo de execução do Windows, se houver.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<  
   typename Derived,  
   typename MixInType,  
   bool hasImplements = __is_base_of(Details::ImplementsBase,  
   MixInType)  
>  
struct MixIn;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Derivado*  
 Um tipo derivado de [implementa](../windows/implements-structure.md) estrutura.  
  
 *MixInType*  
 Um tipo base.  
  
 *hasImplements*  
 **Verdadeiro** se *MixInType* é derivado do tipo base; a implementação atual **falsos** caso contrário.  
  
## <a name="remarks"></a>Comentários  
 Se uma classe é derivada de tempo de execução do Windows e interfaces de classe COM, a lista de declarações de classe deve primeiro liste qualquer interface de tempo de execução do Windows e, em seguida, interfaces de qualquer COM clássico. **Mescla** garante que as interfaces são especificadas na ordem correta.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `MixIn`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)