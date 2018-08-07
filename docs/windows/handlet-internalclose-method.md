---
title: 'Método handlet:: Internalclose | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleT::InternalClose
dev_langs:
- C++
helpviewer_keywords:
- InternalClose method
ms.assetid: fe693c02-aa1f-4e00-8bdd-a0d7d736da0b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a54b61902c8994397c7bd6effa74a90d43c7e512
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39568635"
---
# <a name="handletinternalclose-method"></a>Método HandleT::InternalClose
Fecha o atual **HandleT** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
virtual bool InternalClose();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se o atual **HandleT** fechado com êxito; caso contrário, **false**.  
  
## <a name="remarks"></a>Comentários  
 **InternalClose()** está **protegidos**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)