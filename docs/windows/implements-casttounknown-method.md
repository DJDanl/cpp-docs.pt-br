---
title: 'Método: casttounknown | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Implements::CastToUnknown
dev_langs:
- C++
helpviewer_keywords:
- CastToUnknown method
ms.assetid: ca3324f7-4136-406b-8698-7389f4f3d3c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 857d13736a92bbbc2c6f1228b3444081ffc18de5
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33874480"
---
# <a name="implementscasttounknown-method"></a>Método Implements::CastToUnknown
Obtém um ponteiro para a interface IUnknown subjacente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__forceinline IUnknown* CastToUnknown();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Esta operação sempre terá êxito e retorna o ponteiro IUnknown.  
  
## <a name="remarks"></a>Comentários  
 Função auxiliar interno.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura Implements](../windows/implements-structure.md)