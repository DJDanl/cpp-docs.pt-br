---
title: 'Método: Internalclose | Microsoft Docs'
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
ms.openlocfilehash: 7b0aef97645d515a03dcf2cab90eedc06f07971c
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33874139"
---
# <a name="handletinternalclose-method"></a>Método HandleT::InternalClose
Fecha o objeto HandleT atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
virtual bool InternalClose();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se o HandleT atual foi fechada com êxito; Caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 InternalClose() está protegida.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)