---
title: Estrutura RuntimeClassFlags | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClassFlags
dev_langs:
- C++
helpviewer_keywords:
- RuntimeClassFlags structure
ms.assetid: 7098d605-bd14-4d51-82f4-3def8296a938
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 823244b54513e4f6b2901bc29984604f65eb9a11
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40018030"
---
# <a name="runtimeclassflags-structure"></a>Estrutura RuntimeClassFlags
Contém o tipo para uma instância de um [RuntimeClass](../windows/runtimeclass-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <  
   unsigned int flags  
>  
struct RuntimeClassFlags;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *flags*  
 Um [enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante RuntimeClassFlags::value](../windows/runtimeclassflags-value-constant.md)|Contém uma [enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `RuntimeClassFlags`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)