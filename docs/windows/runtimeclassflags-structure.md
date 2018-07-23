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
ms.openlocfilehash: 05166be14680b14d704095f5f1c9375bd97da7d5
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892020"
---
# <a name="runtimeclassflags-structure"></a>Estrutura RuntimeClassFlags
Contém o tipo de uma instância de um [RuntimeClass](../windows/runtimeclass-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   unsigned int flags  
>  
struct RuntimeClassFlags;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `flags`  
 Um [enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante RuntimeClassFlags::value](../windows/runtimeclassflags-value-constant.md)|Contém uma [enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `RuntimeClassFlags`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)