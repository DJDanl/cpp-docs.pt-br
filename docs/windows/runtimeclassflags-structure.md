---
title: Estrutura RuntimeClassFlags | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::RuntimeClassFlags
dev_langs: C++
helpviewer_keywords: RuntimeClassFlags structure
ms.assetid: 7098d605-bd14-4d51-82f4-3def8296a938
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: c06443bebdd808ed8e37208a9db2636ce97f775d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)