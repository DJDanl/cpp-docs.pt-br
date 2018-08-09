---
title: 'Método asyncbase:: Fireprogress | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::FireProgress
dev_langs:
- C++
helpviewer_keywords:
- FireProgress method
ms.assetid: 4512bef6-0ebc-4465-9b8a-4c9dfa82084c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 35faad82357b0f449d407787840c865b798427f1
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39642003"
---
# <a name="asyncbasefireprogress-method"></a>Método AsyncBase::FireProgress
Invoca o manipulador de eventos de andamento atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
void FireProgress(  
   const typename ProgressTraits::Arg2Type arg  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *arg*  
 O método de manipulador de eventos para invocar.  
  
## <a name="remarks"></a>Comentários  
 `ProgressTraits` é derivado de [estrutura ArgTraitsHelper](../windows/argtraitshelper-structure.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)