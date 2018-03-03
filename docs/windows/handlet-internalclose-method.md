---
title: "Método: Internalclose | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleT::InternalClose
dev_langs:
- C++
helpviewer_keywords:
- InternalClose method
ms.assetid: fe693c02-aa1f-4e00-8bdd-a0d7d736da0b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c91d3a6eb2c03b70ca50b28189e4ab4530a2e3bc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="handletinternalclose-method"></a>Método HandleT::InternalClose
Fecha o objeto HandleT atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
virtual bool InternalClose();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 `true`Se o HandleT atual foi fechada com êxito; Caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 InternalClose() está protegida.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)