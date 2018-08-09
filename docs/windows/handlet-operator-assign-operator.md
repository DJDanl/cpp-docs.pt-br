---
title: 'Handlet:: Operator operador = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleT::operator=
dev_langs:
- C++
helpviewer_keywords:
- operator= operator
ms.assetid: 9e42dcca-30fa-4e8b-8954-802fd64a5595
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fa253bec9f150d08f699333cd5d5f6d4538fc2d6
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39653151"
---
# <a name="handletoperator-operator"></a>Operador HandleT::operator=
Move o valor de especificado **HandleT** objeto atual **HandleT** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
HandleT& operator=(  
   _Inout_ HandleT&& h  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *h*  
 Uma referência rvalue para um identificador.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma referência ao atual **HandleT** objeto.  
  
## <a name="remarks"></a>Comentários  
 Esta operação invalida a **HandleT** objeto especificado pelo parâmetro *h*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HandleT](../windows/handlet-class.md)